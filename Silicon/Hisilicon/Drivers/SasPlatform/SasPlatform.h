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



#ifndef _SAS_PLATFORM_H_
#define _SAS_PLATFORM_H_

#include <Uefi.h>
#include <PiDxe.h>
#include <Guid/EventGroup.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/PcdLib.h>
#include <Library/IoLib.h>
#include <Library/ArmLib.h>
#include <Library/DxeServicesTableLib.h>

#include <Library/ReportStatusCodeLib.h>
#include <Protocol/PlatformSasProtocol.h>



typedef struct {
  UINTN                       Signature;
  EFI_HANDLE                  Handle;
  HISI_PLATFORM_SAS_PROTOCOL  SasPlatformProtocol;
} SAS_PLATFORM_INSTANCE;


#endif    // _SAS_PLATFORM_H_

