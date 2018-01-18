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

extern UEFI_OS_BOOT_FILE  mUefiOsBootFiles[];

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


VOID
PrintDevicePath (
  CHAR16                      *PreStr,
  EFI_DEVICE_PATH_PROTOCOL    *Path
  )
{
  CHAR16                              *DevicePathTxt;
  EFI_STATUS                          Status;
  EFI_DEVICE_PATH_TO_TEXT_PROTOCOL    *DevicePathToTextProtocol;

  DevicePathTxt = NULL;
  Status = gBS->LocateProtocol (&gEfiDevicePathToTextProtocolGuid, NULL, (VOID **)&DevicePathToTextProtocol);
  if (!EFI_ERROR (Status)) {
    DevicePathTxt = DevicePathToTextProtocol->ConvertDevicePathToText (Path, FALSE, TRUE);
    DEBUG ((DEBUG_ERROR, "%s DevPath:[%s]\n", PreStr, DevicePathTxt));
  }

  if (DevicePathTxt != NULL) {
    FreePool (DevicePathTxt);
  }

  return ;
}

CHAR16 *
GetGptNodeText (
  EFI_DEVICE_PATH_PROTOCOL    *Path
  )
{
  CHAR16     *NodeText;

  while (!IsDevicePathEnd (Path)) {
    NodeText = ConvertDeviceNodeToText (Path, TRUE, TRUE);
    if (StrStr (NodeText, L"GPT") != NULL) {
      return NodeText;
    }

    if (NodeText != NULL) {
      FreePool (NodeText);
    }

    Path = NextDevicePathNode (Path);
  }

  return NULL;
}

BOOLEAN
IsPartitionGuidEqual (
  EFI_DEVICE_PATH_PROTOCOL    *OptionPath,
  EFI_DEVICE_PATH_PROTOCOL    *FilePath
  )
{
  CHAR16                                 *OptionGptText;
  CHAR16                                 *FileGptText;

  OptionGptText = GetGptNodeText (OptionPath);
  FileGptText = GetGptNodeText (FilePath);
  if ((OptionGptText != NULL) && (FileGptText != NULL) && (StrCmp (OptionGptText, FileGptText) == 0)) {
    return TRUE;
  }

  if (OptionGptText != NULL) {
    FreePool (OptionGptText);
  }
  if (FileGptText != NULL) {
    FreePool (FileGptText);
  }

  return FALSE;
}

/* If a partition exist a valid grub, OsBootLib will create a Option after bios firmware upgraded,
 * and then installing the same OS on the same partition will create anothor Option. the two Options
 * are superfluous, the Option added by OsBootLib should be remove.
 *
 * It's allowed of creating several Option in the same GPT by installing OS.
 */
VOID
RemoveSuperfluousOption (
  EFI_BOOT_MANAGER_LOAD_OPTION *BootOptions,
  UINT16                       *OptionDelFlags,
  UINTN                        BootOptionCount
  )
{
  EFI_STATUS                   Status;
  UINTN                        Index;

  for (Index = 1; Index < BootOptionCount; Index++) {
    if (OptionDelFlags[Index] == 0) {
      if ((IsPartitionGuidEqual (BootOptions[0].FilePath, BootOptions[Index].FilePath)) &&
          (IsOptionAddedByOsBootLib (BootOptions[Index].Description))) {
        OptionDelFlags[Index] = 1;

        Status = EfiBootManagerDeleteLoadOptionVariable (BootOptions[Index].OptionNumber, LoadOptionTypeBoot);
        if (EFI_ERROR (Status)) {
          DEBUG ((DEBUG_ERROR, "DeleteLoadOptionVariable: %r\n", Status));
          continue;
        }

        PrintDevicePath (L"Del Option(du),", BootOptions[Index].FilePath);
      }
    }
  }

  return;
}

UINTN
GetOptionPositionWithoutGpt (
  VOID
  )
{
  UINTN                             Index;
  UINTN                             BootOptionCount;
  EFI_BOOT_MANAGER_LOAD_OPTION      *BootOptions;

  BootOptions = EfiBootManagerGetLoadOptions (
                  &BootOptionCount, LoadOptionTypeBoot
                  );
  for (Index = 0; Index < BootOptionCount; Index++) {
    if (GetGptNodeText (BootOptions[Index].FilePath) == NULL) {
      return Index;
    }
  }

  return 0;
}

CHAR16 *
GetFileTextByDevicePath (
  EFI_DEVICE_PATH_PROTOCOL    *DevicePath
  )
{
  CHAR16                                 *FileString;

  FileString = NULL;

  while (!IsDevicePathEnd (DevicePath)) {
    if (MEDIA_DEVICE_PATH == DevicePathType (DevicePath) &&
        MEDIA_FILEPATH_DP == DevicePathSubType (DevicePath)) {
      FileString = ConvertDeviceNodeToText (DevicePath, TRUE, TRUE);
      break;
    }
    DevicePath = NextDevicePathNode (DevicePath);
  }

  return FileString;
}


/**
  Check same boot option by device path.

*/
BOOLEAN
BeHaveSameBootOptionByDP (
  EFI_DEVICE_PATH_PROTOCOL    *DevicePath,
  CHAR16                      *FileName
  )
{
  UINTN                        Index;
  UINTN                        ValidPathSize;
  BOOLEAN                      Found;
  EFI_BOOT_MANAGER_LOAD_OPTION *BootOptions;
  UINTN                        BootOptionCount;

  if (NULL == DevicePath) {
    return FALSE;
  }

  BootOptions = EfiBootManagerGetLoadOptions (&BootOptionCount, LoadOptionTypeBoot);

  Found = FALSE;
  for (Index = 0; Index < BootOptionCount; Index++) {
    /* If a partition exist a valid Option, then the new Option should not be added.
     * After installation, some iso will create several valid grub file, like
     * \EFI\centos\shimaa64.efi, \EFI\BOOT\BOOTAA64.EFI.
     */
    if(IsPartitionGuidEqual (BootOptions[Index].FilePath, DevicePath)) {
      DEBUG ((DEBUG_ERROR, "Get the same Option(GPT).\n"));
      Found = TRUE;
      break;
    }

    /* If DevicePath of new Option is matched in exist Option and file name of
     * new Option is EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64, then the new Option should be ignored.
     */
    ValidPathSize = GetDevicePathSize (BootOptions[Index].FilePath) - END_DEVICE_PATH_LENGTH;
    if ((CompareMem (BootOptions[Index].FilePath, DevicePath,  ValidPathSize) == 0) &&
        (StrCmp (FileName, EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64) == 0))
    {
      DEBUG ((DEBUG_ERROR, "Get the same Option.\n"));
      Found = TRUE;
      break;
    }
  }

  EfiBootManagerFreeLoadOptions (BootOptions, BootOptionCount);

  return Found;
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
  BOOLEAN                                Invalid;
  EFI_DEVICE_PATH_PROTOCOL*              DevicePathNode;
  CHAR16                                 *FileString;

  Invalid = TRUE;
  if (NULL == OptionDp) {
    return FALSE;
  }

  OptionDpSize = GetDevicePathSize (OptionDp);
  if (OptionDpSize == 0) {
    return FALSE;
  }

  //
  // Os BootOption should be File Device Path.
  //
  DevicePathNode = OptionDp;
  FileString = GetFileTextByDevicePath (DevicePathNode);
  if (FileString == NULL) {
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
    FreePool (FileString);
    return FALSE;
  }

  for (Index = 0; Index < NumberFileSystemHandles; Index++) {
    Status = gBS->HandleProtocol (
                        FileSystemHandles[Index],
                        &gEfiBlockIoProtocolGuid,
                        (VOID **) &BlkIo
                        );
    if (EFI_ERROR (Status)) {
      continue;
    }

    FileSystemDP = FileDevicePath (FileSystemHandles[Index], FileString);
    /* If Partition is existed and the grub file is existed, then the Option is valid. */
    if ((CompareMem ((VOID *) OptionDp, (VOID *) FileSystemDP, OptionDpSize) == 0) ||
         (IsPartitionGuidEqual (OptionDp, FileSystemDP))) {
      Hdr.Union  = &HdrData;
      Status = OsBootGetImageHeader (
                   FileSystemHandles[Index],
                   FileString,
                   &DosHeader,
                   Hdr
                    );
      if (!EFI_ERROR (Status) &&
          EFI_IMAGE_MACHINE_TYPE_SUPPORTED (Hdr.Pe32->FileHeader.Machine) &&
          Hdr.Pe32->OptionalHeader.Subsystem == EFI_IMAGE_SUBSYSTEM_EFI_APPLICATION) {
        DEBUG ((DEBUG_ERROR, "BeValidOsBootOption (),Get Bootable file :%s.\n", FileString));
        Invalid = FALSE;
        break;
      }
    }

    if (FileSystemDP != NULL) {
      FreePool (FileSystemDP);
    }
  }

  if (NumberFileSystemHandles != 0) {
    FreePool (FileSystemHandles);
  }
  if (FileString != NULL) {
    FreePool (FileString);
  }

  return Invalid;
}

