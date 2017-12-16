/** @file
*
*  Copyright (c) 2017, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2017, Linaro Limited. All rights reserved.
*
*  This program and the accompanying materials
*  are licensed and made available under the terms and conditions of the BSD License
*  which accompanies this distribution.  The full text of the license may be found at
*  http://opensource.org/licenses/bsd-license.php
*
*  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
*  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
*
**/

#include "OsBoot.h"

UEFI_OS_BOOT_FILE  mUefiOsBootFiles[] = {
    {EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64,    L"Uefi Default Boot"},
    {L"\\BOOT\\EFI\\EFI\\CENTOS\\grubaa64.efi",    L"Uefi CENTOS Boot"},
    {L"\\EFI\\centos\\grubaa64.efi",    L"Uefi CentOS Grub Boot"},
    {L"\\EFI\\debian\\grubaa64.efi",    L"Uefi Debian Grub Boot"},
    {L"\\EFI\\GRUB2\\GRUBAA64.EFI",    L"Hisilicon Linux Boot"},
    {L"\\EFI\\Microsoft\\Boot\\bootmgfw.efi",    L"Uefi Windows Boot"},
    {L"\\EFI\\redhat\\grub.efi",    L"Uefi Redhat Boot"},
    {L"\\EFI\\SuSE\\elilo.efi",    L"Uefi SuSE Boot"},
    {L"\\EFI\\ubuntu\\grubaa64.efi",    L"Uefi Ubuntu Grub Boot"},
    {L"\\EFI\\ubuntu\\shimx64.efi",    L"Uefi Ubuntu Shimx64 Boot"},
    {L"\\EFI\\ubuntu\\grubx64.efi",    L"Uefi Ubuntu Grubx64 Boot"},
    {L"\\EFI\\ubuntu\\shim.efi",    L"Uefi Ubuntu Shim Boot"},
    {L"\\EFI\\ubuntu\\grub.efi",    L"Uefi Ubuntu Grub Boot"},
    {L"\\EFI\\fedora\\shim.efi",    L"Uefi Fedora Shim Boot"}
};


/**
    Remove invalid OS boot options, and then add new ones.

*/
EFI_STATUS
AdjustOsBootOrder (
  VOID
  )
{
  EFI_STATUS  Status;

  Status = RemoveInvalidOsBootOptions ();
  if (EFI_ERROR(Status)) {
    return Status;
  }

  Status = CreateOsBootOptions ();
  return Status;
}


/**
    Remove UEFI OS boot options when it is disappeared in system.

*/
EFI_STATUS
RemoveInvalidOsBootOptions (
  VOID
  )
{
  EFI_STATUS          Status = EFI_SUCCESS;
  UINTN               Index;
  UINTN               OptionOrderSize;
  UINT16              *OptionOrder;
  UINT16              *NewOptionOrder;
  CHAR16              OptionName[20];
  BDS_COMMON_OPTION   *Option;
  LIST_ENTRY          BootOptionList;
  UINTN               NewOrderCount;

  OptionOrder = BdsLibGetVariableAndSize (
                              L"BootOrder",
                              &gEfiGlobalVariableGuid,
                              &OptionOrderSize
                              );
  if (OptionOrder == NULL) {
     DEBUG((DEBUG_ERROR,"%a - %d error\n", __FUNCTION__, __LINE__));
    return EFI_NOT_FOUND;
  }
  //
  //Check All BootOption.
  //
  InitializeListHead (&BootOptionList);
  for (Index = 0; Index < OptionOrderSize / sizeof (UINT16); Index++) {
    UnicodeSPrint (OptionName, sizeof (OptionName), L"Boot%04x", OptionOrder[Index]);
    Option = BdsLibVariableToOption (&BootOptionList, OptionName);
    if (Option == NULL) {
      continue;
    }

    if (BeInvalidOsBootOption(Option->DevicePath)) {
      OptionOrder[Index] = 0xFFFF;
      //
      // Remove invalid BootOption.
      //
      Status = gRT->SetVariable (
                              OptionName,
                              &gEfiGlobalVariableGuid,
                              EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
                              0,
                              NULL
                              );
      DEBUG((DEBUG_ERROR, "RemoveInvalidOsBootOptions (), Remove Empty BootOption :%s-%r.\n", Option->Description, Status));
    }
    RemoveEntryList (&Option->Link);
    FreePool (Option->DevicePath);
    FreePool (Option->Description);
    FreePool (Option->LoadOptions);
    FreePool (Option);
  }
  //
  //Adjust New BootOrder.
  //
  NewOptionOrder = NULL;
  NewOptionOrder = AllocateZeroPool (OptionOrderSize);
  if (NULL == NewOptionOrder) {
    FreePool (OptionOrder);
    return EFI_OUT_OF_RESOURCES;
  }

  NewOrderCount = 0;
  for (Index = 0; Index < OptionOrderSize / sizeof (UINT16); Index++) {
    if (0xFFFF != OptionOrder[Index]) {
      NewOptionOrder[NewOrderCount] = OptionOrder[Index];
      NewOrderCount ++;
    }
  }
  if (OptionOrderSize != (NewOrderCount * sizeof (UINT16))) {
    Status = gRT->SetVariable (
                              L"BootOrder",
                              &gEfiGlobalVariableGuid,
                              EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
                              NewOrderCount * sizeof(UINT16),
                              NewOptionOrder
                              );
    DEBUG((DEBUG_INFO, "RemoveInvalidOsBootOptions (),Set New BootOrder :%r.\n", Status));
  }

  FreePool (NewOptionOrder);
  FreePool (OptionOrder);

  return Status;
}


/**
  Try to find UEFI OSs and create the boot options which haven't been listed in BootOrder.

*/
EFI_STATUS
CreateOsBootOptions (
  VOID
  )
{
  EFI_STATUS                             Status;
  EFI_HANDLE                             *FileSystemHandles;
  UINTN                                  NumberFileSystemHandles;
  UINTN                                  Index, Count;
  EFI_DEVICE_PATH_PROTOCOL               *OsFileDP;
  EFI_BLOCK_IO_PROTOCOL                  *BlkIo;
  UINTN                                  MaxFiles;
  EFI_IMAGE_OPTIONAL_HEADER_UNION        HdrData;
  EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION    Hdr;
  EFI_IMAGE_DOS_HEADER                   DosHeader;
  LIST_ENTRY                             BootLists;
  UINTN                                  OptionOrderSize;
  UINT16                                 *OptionOrder;

  //
  //Check BootOrder firstly.
  //
  OptionOrder = BdsLibGetVariableAndSize (
                              L"BootOrder",
                              &gEfiGlobalVariableGuid,
                              &OptionOrderSize
                              );
  if (OptionOrder == NULL) {
   DEBUG((DEBUG_ERROR, "%a - %d error\n", __FUNCTION__, __LINE__));
    return EFI_NOT_FOUND;
  }
  FreePool (OptionOrder);

  EfiBootManagerConnectAll ();
  //
  //Look for file system to find default Os boot load.
  //
  Status = gBS->LocateHandleBuffer (
                                ByProtocol,
                                &gEfiSimpleFileSystemProtocolGuid,
                                NULL,
                                &NumberFileSystemHandles,
                                &FileSystemHandles
                                );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  MaxFiles = sizeof (mUefiOsBootFiles) / sizeof (UEFI_OS_BOOT_FILE);
  for (Index = 0; Index < NumberFileSystemHandles; Index++) {
    Status = gBS->HandleProtocol (
                        FileSystemHandles[Index],
                        &gEfiBlockIoProtocolGuid,
                        (VOID **) &BlkIo
                        );
    if (EFI_ERROR (Status)) {
      continue;
    }

    Hdr.Union = &HdrData;
    for (Count = 0; Count < MaxFiles; Count++) {
      //
      //Read Boot File Path to check validation.
      //
      Status = OsBootGetImageHeader (
                    FileSystemHandles[Index],
                    mUefiOsBootFiles[Count].FilePathString,
                    &DosHeader,
                    Hdr
                    );
      if (!EFI_ERROR (Status) &&
          EFI_IMAGE_MACHINE_TYPE_SUPPORTED (Hdr.Pe32->FileHeader.Machine) &&
          Hdr.Pe32->OptionalHeader.Subsystem == EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION) {

        OsFileDP = NULL;
        OsFileDP = FileDevicePath (FileSystemHandles[Index], mUefiOsBootFiles[Count].FilePathString);
        if (!BeHaveSameBootOptionByDP (OsFileDP)) {
          //
          // Create new BootOption if it is not present.
          //
          DEBUG((DEBUG_INFO, "CreateOsBootOptions (), Make New Boot Option :%s.\n", mUefiOsBootFiles[Count].Description));
          InitializeListHead (&BootLists);
          BdsLibRegisterNewOption (&BootLists, OsFileDP, mUefiOsBootFiles[Count].Description, L"BootOrder");
        }

        if(OsFileDP != NULL) {
          FreePool (OsFileDP);
          OsFileDP = NULL;
        }
      }
    }
  }

  if (NumberFileSystemHandles != 0) {
    FreePool (FileSystemHandles);
  }

  return EFI_SUCCESS;
}

