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

/**
  Read file the headers of dos, image, optional header.

  @param  Device                SimpleFileSystem device handle
  @param  FileSize                File size
  @param  DosHeader             Pointer to dos header
  @param  Hdr                   The buffer in which to return the PE32, PE32+, or TE header.

  @retval EFI_SUCCESS           Successfully get the File.
  @retval EFI_LOAD_ERROR        File is not a valid image file.

**/
EFI_STATUS
ReadDosHeader (
  EFI_FILE_HANDLE                      ThisFile,
  UINT64                               FileSize,
  EFI_IMAGE_DOS_HEADER                 *DosHeader,
  EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION  *Hdr
  )
{
  EFI_STATUS     Status;
  UINTN          BufferSize;
  //
  // Read dos header
  //
  BufferSize = sizeof (EFI_IMAGE_DOS_HEADER);
  Status = ThisFile->Read (ThisFile, &BufferSize, DosHeader);
  if (EFI_ERROR (Status) ||
      BufferSize < sizeof (EFI_IMAGE_DOS_HEADER) ||
      FileSize <= DosHeader->e_lfanew ||
      DosHeader->e_magic != EFI_IMAGE_DOS_SIGNATURE) {
    Status = EFI_LOAD_ERROR;
    DEBUG ((DEBUG_ERROR, "%a(%d):error!\n", __FUNCTION__,__LINE__));
    goto ErrReadDos;
  }

  //
  // Move to PE signature
  //
  Status = ThisFile->SetPosition (ThisFile, DosHeader->e_lfanew);
  if (EFI_ERROR (Status)) {
    Status = EFI_LOAD_ERROR;
    DEBUG((DEBUG_ERROR, "%a(%d):error!\n", __FUNCTION__,__LINE__));
    goto ErrReadDos;
  }

  //
  // Read and check PE signature
  //
  BufferSize = sizeof (EFI_IMAGE_OPTIONAL_HEADER_UNION);
  Status = ThisFile->Read (ThisFile, &BufferSize, (VOID*)(Hdr->Pe32));
  if (EFI_ERROR (Status) ||
      BufferSize < sizeof (EFI_IMAGE_OPTIONAL_HEADER_UNION) ||
      Hdr->Pe32->Signature != EFI_IMAGE_NT_SIGNATURE) {
    Status = EFI_LOAD_ERROR;
    DEBUG((DEBUG_ERROR, "%a(%d):error!\n", __FUNCTION__,__LINE__));
    goto ErrReadDos;
  }

ErrReadDos:
  return Status;
}

/**
  Get the headers (dos, image, optional header) from an image

  @param  Device                SimpleFileSystem device handle
  @param  FileName              File name for the image
  @param  DosHeader             Pointer to dos header
  @param  Hdr                   The buffer in which to return the PE32, PE32+, or TE header.

  @retval EFI_SUCCESS           Successfully get the machine type.
  @retval EFI_NOT_FOUND         The file is not found.
  @retval EFI_LOAD_ERROR        File is not a valid image file.

**/
EFI_STATUS
EFIAPI
OsBootGetImageHeader (
  IN  EFI_HANDLE                            Device,
  IN  CHAR16                                *FileName,
  OUT EFI_IMAGE_DOS_HEADER                  *DosHeader,
  OUT EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION   Hdr
  )
{
  EFI_STATUS                                Status;
  EFI_SIMPLE_FILE_SYSTEM_PROTOCOL           *Volume;
  EFI_FILE_HANDLE                           Root;
  EFI_FILE_HANDLE                           ThisFile;
  UINTN                                     BufferSize;
  UINT64                                    FileSize;
  EFI_FILE_INFO                             *Info;
  BOOLEAN                                   Condition = TRUE;//pclint

  Root = NULL;
  ThisFile = NULL;
  //
  // Handle the file system interface to the device
  //
  Status = gBS->HandleProtocol (
                             Device,
                             &gEfiSimpleFileSystemProtocolGuid,
                            (VOID *) &Volume
             );
  if (EFI_ERROR (Status)) {
    DEBUG((DEBUG_ERROR, "%a(%d):error ret :%r !\n", __FUNCTION__,__LINE__,Status));
    goto Done;
  }

  Status = Volume->OpenVolume (
                               Volume,
                               &Root
                               );
  if (EFI_ERROR (Status)) {
    DEBUG((DEBUG_ERROR, "%a(%d):error ret :%r !\n", __FUNCTION__,__LINE__,Status));
       Root = NULL;
       goto Done;
  }

  if (Root == NULL) {
    Status = EFI_LOAD_ERROR;
    DEBUG((DEBUG_ERROR, "%a(%d):error ret :%r !\n", __FUNCTION__,__LINE__,Status));
    goto Done;
  }
  Status = Root->Open (Root, &ThisFile, FileName, EFI_FILE_MODE_READ, 0);
  if (EFI_ERROR (Status)) {
    DEBUG((DEBUG_ERROR, "%a(%d):file not found ret :%r !\n", __FUNCTION__,__LINE__,Status));
    goto Done;
  }

  if (ThisFile == NULL) {
    DEBUG((DEBUG_ERROR, "%a(%d):error ret :%r !\n", __FUNCTION__,__LINE__,Status));
    Status = EFI_LOAD_ERROR;
    goto Done;
  }
  //
  // Get file size
  //
  BufferSize = SIZE_OF_EFI_FILE_INFO + 200;
  do {
       Info = NULL;
       Status = gBS->AllocatePool (EfiBootServicesData, BufferSize, (VOID **) &Info);
       if (EFI_ERROR (Status)) {
       goto Done;
       }
       Status = ThisFile->GetInfo (
                                  ThisFile,
                                  &gEfiFileInfoGuid,
                                  &BufferSize,
                                  Info
                                   );
      if (!EFI_ERROR (Status)) {
       break;
       }
       if (Status != EFI_BUFFER_TOO_SMALL) {
        FreePool (Info);
       goto Done;
       }
      FreePool (Info);
  } while (Condition);

  FileSize = Info->FileSize;
  FreePool (Info);

  Status = ReadDosHeader(ThisFile, FileSize, DosHeader, &Hdr);
  if (EFI_ERROR (Status)) {
    DEBUG((DEBUG_ERROR, "%a(%d):error ret :%r !\n", __FUNCTION__,__LINE__,Status));
    goto Done;
  }
  //
  // Check PE32 or PE32+ magic
  //
  if (Hdr.Pe32->OptionalHeader.Magic != EFI_IMAGE_NT_OPTIONAL_HDR32_MAGIC &&
       Hdr.Pe32->OptionalHeader.Magic != EFI_IMAGE_NT_OPTIONAL_HDR64_MAGIC) {
        Status = EFI_LOAD_ERROR;
       DEBUG((DEBUG_ERROR, "%a(%d):error ret :%r !\n", __FUNCTION__,__LINE__,Status));
       goto Done;
  }

 Done:
  if (ThisFile != NULL) {
     ThisFile->Close (ThisFile);
  }
  if (Root != NULL) {
       Root->Close (Root);
  }
  return Status;
}




/**
  Check same boot option by device path.

*/
BOOLEAN
BeHaveSameBootOptionByDP (
  EFI_DEVICE_PATH_PROTOCOL    *DevicePath
  )
{
  EFI_STATUS                          Status = EFI_SUCCESS;
  UINTN                               Index;
  UINTN                               OptionOrderSize;
  UINT16                              *OptionOrder;
  CHAR16                              OptionName[20];
  BDS_COMMON_OPTION                   *Option;
  LIST_ENTRY                          BootOptionList;
  EFI_DEVICE_PATH_TO_TEXT_PROTOCOL    *DevicePathToTextProtocol;
  CHAR16*                             DevicePathTxt = NULL;
  CHAR16*                             OptionDpTxt = NULL;
  BOOLEAN                             bFound;

  if (NULL == DevicePath) {
    return FALSE;
  }

  OptionOrder = BdsLibGetVariableAndSize (
                              L"BootOrder",
                              &gEfiGlobalVariableGuid,
                              &OptionOrderSize
                              );
  if (OptionOrder == NULL) {
    DEBUG((DEBUG_ERROR, "%a - %d error\n", __FUNCTION__, __LINE__));
    return FALSE;
  }

  Status = gBS->LocateProtocol(&gEfiDevicePathToTextProtocolGuid, NULL, (VOID **)&DevicePathToTextProtocol);
  if (EFI_ERROR (Status)) {
    FreePool(OptionOrder);
    return FALSE;
  }
  DevicePathTxt = NULL;
  DevicePathTxt = DevicePathToTextProtocol->ConvertDevicePathToText (DevicePath, TRUE, TRUE);

  InitializeListHead (&BootOptionList);
  bFound = FALSE;
  for (Index = 0; Index < OptionOrderSize / sizeof (UINT16); Index++) {
    UnicodeSPrint (OptionName, sizeof (OptionName), L"Boot%04x", OptionOrder[Index]);
    Option = NULL;
    Option = BdsLibVariableToOption (&BootOptionList, OptionName);
    if (Option == NULL) {
      continue;
    }

    OptionDpTxt = NULL;
    OptionDpTxt = DevicePathToTextProtocol->ConvertDevicePathToText (Option->DevicePath, TRUE, TRUE);
    if((NULL != OptionDpTxt) && !StrnCmp(DevicePathTxt, OptionDpTxt, StrLen(DevicePathTxt))) {
      DEBUG((DEBUG_ERROR, "BeHaveSameBootOptionByDP (), Get the same Option.\n"));
      bFound = TRUE;
      break;
    }

    if(OptionDpTxt != NULL) {
      FreePool (OptionDpTxt);
      OptionDpTxt= NULL;
    }

    RemoveEntryList(&Option->Link);
    if (NULL != Option) {
      FreePool(Option);
    }

  }

  if(DevicePathTxt != NULL) {
    FreePool (DevicePathTxt);
  }
  FreePool (OptionOrder);

  return bFound;
}



/**
  Check Os Boot Option if exist in current system.

*/
BOOLEAN
BeInvalidOsBootOption (
  EFI_DEVICE_PATH_PROTOCOL    *OptionDp
  )
{
  EFI_STATUS                             Status;
  EFI_HANDLE                             *FileSystemHandles;
  UINTN                                  NumberFileSystemHandles;
  UINTN                                  Index;
  EFI_DEVICE_PATH_PROTOCOL               *FileSystemDP;
  UINTN                                  OptionDpSize;
  EFI_BLOCK_IO_PROTOCOL                  *BlkIo;
  EFI_IMAGE_OPTIONAL_HEADER_UNION        HdrData;
  EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION    Hdr;
  EFI_IMAGE_DOS_HEADER                   DosHeader;
  BOOLEAN                                bFound;
  EFI_DEVICE_PATH_PROTOCOL*              DevicePathNode;
  CHAR16                                 *FilePathString;

  if (NULL == OptionDp) {
    return FALSE;
  }
  OptionDpSize = GetDevicePathSize (OptionDp);
  if (0 == OptionDpSize) {
    return FALSE;
  }
  //
  // Os BootOption should be File Device Path.
  //
  bFound = FALSE;
  DevicePathNode = OptionDp;
  while (!IsDevicePathEnd (DevicePathNode)) {
    if (MEDIA_DEVICE_PATH == DevicePathType(DevicePathNode) &&
        MEDIA_FILEPATH_DP == DevicePathSubType (DevicePathNode)) {
      bFound = TRUE;
      FilePathString = NULL;
      FilePathString = ConvertDeviceNodeToText (DevicePathNode, TRUE, TRUE);
      break;
    }
    DevicePathNode = NextDevicePathNode (DevicePathNode);
  }
  if (!bFound) {
    return FALSE;
  }

  //
  // File should be exsiting in system.
  //
  Status = gBS->LocateHandleBuffer (
                                ByProtocol,
                                &gEfiSimpleFileSystemProtocolGuid,
                                NULL,
                                &NumberFileSystemHandles,
                                &FileSystemHandles
                                );
  if (EFI_ERROR (Status)) {
    return FALSE;
  }

   bFound = FALSE;
  for (Index = 0; Index < NumberFileSystemHandles; Index++) {
    Status = gBS->HandleProtocol (
                        FileSystemHandles[Index],
                        &gEfiBlockIoProtocolGuid,
                        (VOID **) &BlkIo
                        );
    if (EFI_ERROR (Status)) {
      continue;
    }

    FileSystemDP = FileDevicePath (FileSystemHandles[Index], FilePathString);
    if (0 == CompareMem ((VOID *) OptionDp, (VOID *) FileSystemDP, OptionDpSize)) {
      Hdr.Union  = &HdrData;
      Status = OsBootGetImageHeader (
                   FileSystemHandles[Index],
                   FilePathString,
                   &DosHeader,
                   Hdr
                    );
      if (!EFI_ERROR (Status) &&
          EFI_IMAGE_MACHINE_TYPE_SUPPORTED (Hdr.Pe32->FileHeader.Machine) &&
          Hdr.Pe32->OptionalHeader.Subsystem == EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION) {
        DEBUG((DEBUG_ERROR, "BeValidOsBootOption (),Get Bootable file :%s.\n", FilePathString));
        bFound = TRUE;
        break;
      }
    }
  }
  if (NumberFileSystemHandles != 0) {
    FreePool (FileSystemHandles);
  }
  if (FilePathString != NULL) {
    FreePool (FilePathString);
  }

  if (bFound) {
    return FALSE;
  } else {
    return TRUE;
  }
}

