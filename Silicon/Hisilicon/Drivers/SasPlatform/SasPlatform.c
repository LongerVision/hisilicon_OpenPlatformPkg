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


#include "SasPlatform.h"
#include <Library/OemDevicePath.h>
#include <Library/DevicePathLib.h>

#define SAS0BusAddr 0xc3000000
#define SAS1BusAddr 0xa2000000
#define SAS2BusAddr 0xa3000000

#define SAS0ResetAddr 0xc0000000
#define SAS1ResetAddr 0xa0000000
#define SAS2ResetAddr 0xa0000000

HISI_PLATFORM_SAS_PROTOCOL mSasPlatformProtocol[] = {
  {
    0,
    FALSE,
    SAS0BusAddr,
    SAS0ResetAddr
  },
  {
    1,
    TRUE,
    SAS1BusAddr,
    SAS1ResetAddr
  },
  {
    2,
    FALSE,
    SAS2BusAddr,
    SAS2ResetAddr
  }
};
#define SAS_CONTROLLER_NUMBER    sizeof (mSasPlatformProtocol) / sizeof (HISI_PLATFORM_SAS_PROTOCOL)

EFI_STATUS
EFIAPI
SasPlatformInitialize (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  UINTN                    Loop;
  SAS_PLATFORM_INSTANCE    *PrivateData;
  EFI_STATUS               Status;

  for (Loop = 0; Loop < SAS_CONTROLLER_NUMBER; Loop++) {
    if (mSasPlatformProtocol[Loop].Enable != TRUE) {
      continue;
    }
    PrivateData = AllocateZeroPool (sizeof(SAS_PLATFORM_INSTANCE));
    if (PrivateData == NULL) {
      return EFI_OUT_OF_RESOURCES;
    }

    PrivateData->SasPlatformProtocol = mSasPlatformProtocol[Loop];

    Status = gBS->InstallMultipleProtocolInterfaces (
                  &PrivateData->Handle,
                  &gHisiPlatformSasProtocolGuid,
                  &PrivateData->SasPlatformProtocol,
                  NULL
                  );
    if (EFI_ERROR (Status)) {
      FreePool (PrivateData);
      DEBUG ((DEBUG_ERROR, "[%a]:[%dL] InstallProtocolInterface fail. %r\n", __FUNCTION__, __LINE__, Status));
      return Status;
    }
  }

  DEBUG ((DEBUG_INFO, "sas platform init dirver Ok!!!\n"));
  return EFI_SUCCESS;
}

