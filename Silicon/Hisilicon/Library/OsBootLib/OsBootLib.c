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
    {EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64,      L"Uefi Default Boot"},
    {L"\\BOOT\\EFI\\EFI\\CENTOS\\grubaa64.efi",  L"Uefi CENTOS Boot"},
    {L"\\EFI\\centos\\grubaa64.efi",             L"Uefi CentOS Grub Boot"},
    {L"\\EFI\\debian\\grubaa64.efi",             L"Uefi Debian Grub Boot"},
    {L"\\EFI\\GRUB2\\GRUBAA64.EFI",              L"Hisilicon Linux Boot"},
    {L"\\EFI\\Microsoft\\Boot\\bootmgfw.efi",    L"Uefi Windows Boot"},
    {L"\\EFI\\redhat\\grub.efi",                 L"Uefi Redhat Boot"},
    {L"\\EFI\\SuSE\\elilo.efi",                  L"Uefi SuSE Boot"},
    {L"\\EFI\\ubuntu\\grubaa64.efi",             L"Uefi Ubuntu Grub Boot"},
    {L"\\EFI\\ubuntu\\shimx64.efi",              L"Uefi Ubuntu Shimx64 Boot"},
    {L"\\EFI\\ubuntu\\grubx64.efi",              L"Uefi Ubuntu Grubx64 Boot"},
    {L"\\EFI\\ubuntu\\shim.efi",                 L"Uefi Ubuntu Shim Boot"},
    {L"\\EFI\\ubuntu\\grub.efi",                 L"Uefi Ubuntu Grub Boot"},
    {L"\\EFI\\fedora\\shim.efi",                 L"Uefi Fedora Shim Boot"}
};

BOOLEAN
IsOptionAddedByOsBootLib (
  UINT16                       *OptionDescription
  )
{
  UINTN                        Index;

  for (Index = 0; Index < (sizeof (mUefiOsBootFiles) / sizeof (UEFI_OS_BOOT_FILE)); Index++) {
    if (StrCmp (mUefiOsBootFiles[Index].Description, OptionDescription) == 0) {
      return TRUE;
    }
  }

  return FALSE;
}

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
  if (EFI_ERROR (Status)) {
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
  EFI_STATUS                   Status;
  UINTN                        Index;
  UINT16                       *OptionDelFlags;
  EFI_BOOT_MANAGER_LOAD_OPTION *BootOptions;
  UINTN                        BootOptionCount;

  BootOptions = EfiBootManagerGetLoadOptions (&BootOptionCount, LoadOptionTypeBoot);
  OptionDelFlags = AllocateZeroPool (BootOptionCount * sizeof(UINT16));
  if (OptionDelFlags == NULL) {
    goto exit;
  }

  for (Index = 0; Index < BootOptionCount; Index++) {
    if (OptionDelFlags[Index] == 0) {
      if (BeInvalidOsBootOption (BootOptions[Index].FilePath)) {
        Status = EfiBootManagerDeleteLoadOptionVariable (BootOptions[Index].OptionNumber, LoadOptionTypeBoot);
        if (EFI_ERROR (Status)) {
          DEBUG ((DEBUG_ERROR, "DeleteLoadOptionVariable: %r\n", Status));
          continue;
        }
        PrintDevicePath (L"Del Option,", BootOptions[Index].FilePath);
      } else {
        RemoveSuperfluousOption (&BootOptions[Index], OptionDelFlags, BootOptionCount - Index);
      }
    }
  }

  exit:
  if (OptionDelFlags != NULL) {
    FreePool (OptionDelFlags);
  }
  EfiBootManagerFreeLoadOptions (BootOptions, BootOptionCount);

  return EFI_SUCCESS;
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
  EFI_BOOT_MANAGER_LOAD_OPTION           NewOption;

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
        PrintDevicePath (L"Exist", OsFileDP);
        if (!BeHaveSameBootOptionByDP (OsFileDP, mUefiOsBootFiles[Count].FilePathString)) {
          //
          // Create new BootOption if it is not present.
          //
          DEBUG ((DEBUG_INFO, "CreateOsBootOptions (), Make New Boot Option :%s.\n", mUefiOsBootFiles[Count].Description));
          Status = EfiBootManagerInitializeLoadOption (
                     &NewOption,
                     LoadOptionNumberUnassigned,
                     LoadOptionTypeBoot,
                     LOAD_OPTION_ACTIVE,
                     mUefiOsBootFiles[Count].Description,
                     OsFileDP,
                     NULL,
                     0
                     );
          ASSERT_EFI_ERROR (Status);
          Status = EfiBootManagerAddLoadOptionVariable (&NewOption, GetOptionPositionWithoutGpt ());
          ASSERT_EFI_ERROR (Status);
          EfiBootManagerFreeLoadOption (&NewOption);
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

