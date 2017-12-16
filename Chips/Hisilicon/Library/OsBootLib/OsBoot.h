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

#ifndef _OS_BOOT_H_
#define _OS_BOOT_H_

#include <PiDxe.h>
#include <PlatformArch.h>
#include <Uefi.h>
#include <Guid/FileInfo.h>
#include <Guid/GlobalVariable.h>
#include <IndustryStandard/PeImage.h>
#include <Library/ArmLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/DevicePathLib.h>
#include <Library/GenericBdsLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/OsBootLib.h>
#include <Library/PcdLib.h>
#include <Library/PerformanceLib.h>
#include <Library/PrintLib.h>
#include <Library/TimerLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiBootManagerLib.h>
#include <Protocol/BlockIo.h>
#include <Protocol/DevicePath.h>
#include <Protocol/DevicePathFromText.h>
#include <Protocol/DevicePathToText.h>
#include <Protocol/FirmwareVolume2.h>
#include <Protocol/SimpleFileSystem.h>

typedef struct {
  CHAR16    *FilePathString;
  CHAR16    *Description;
  }UEFI_OS_BOOT_FILE;

/**
  Check same boot option by device path.

*/
BOOLEAN
BeHaveSameBootOptionByDP (
  EFI_DEVICE_PATH_PROTOCOL    *DevicePath
  );

/**
    Remove UEFI OS boot options when it is disappeared in system.

*/
EFI_STATUS
RemoveInvalidOsBootOptions (
  VOID
  );


/**
  Check Os Boot Option if exist in current system.

*/
BOOLEAN
BeInvalidOsBootOption (
  EFI_DEVICE_PATH_PROTOCOL    *OptionDp
  );

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
  IN  EFI_HANDLE                  Device,
  IN  CHAR16                      *FileName,
  OUT EFI_IMAGE_DOS_HEADER        *DosHeader,
  OUT EFI_IMAGE_OPTIONAL_HEADER_PTR_UNION   Hdr
  );

#endif
