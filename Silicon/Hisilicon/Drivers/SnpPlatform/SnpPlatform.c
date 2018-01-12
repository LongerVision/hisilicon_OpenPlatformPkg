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


#include "SnpPlatform.h"

 HISI_PLATFORM_SNP_PROTOCOL mSnpPlatformProtocol[] = {
  {
    4,
    1
  },
  {
    5,
    1
  },
  {
    2,
    0
  },
  {
    3,
    0
  },
  {
    0,
    1
  },
 {
    1,
    1
  },
  {
    6,
    0
  },
  {
    7,
    0
  }
};

#define SNP_CONTROLLER_NUMBER             sizeof (mSnpPlatformProtocol) / sizeof (HISI_PLATFORM_SNP_PROTOCOL)

EFI_STATUS
EFIAPI
SnpPlatformInitialize (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  UINTN                    Loop;
  SNP_PLATFORM_INSTANCE    *PrivateData;
  EFI_STATUS               Status;

  for (Loop = 0; Loop < SNP_CONTROLLER_NUMBER; Loop++) {
    if(mSnpPlatformProtocol[Loop].Enable != 1) {
      continue;
    }
    PrivateData = AllocateZeroPool (sizeof(SNP_PLATFORM_INSTANCE));
    if (PrivateData == NULL) {
      DEBUG ((DEBUG_INFO,"SnpPlatformInitialize  error 1\n"));
      return EFI_OUT_OF_RESOURCES;
    }


    PrivateData->SnpPlatformProtocol = mSnpPlatformProtocol[Loop];

    //
    // Install the snp protocol, device path protocol
    //
    Status = gBS->InstallMultipleProtocolInterfaces (
                  &PrivateData->Handle,
                  &gHisiSnpPlatformProtocolGuid,
                  &PrivateData->SnpPlatformProtocol,
                  NULL
                  );
    if (EFI_ERROR (Status)) {
      FreePool (PrivateData);
      DEBUG ((DEBUG_ERROR, "[%a]:[%dL] InstallProtocolInterface fail. %r\n", __FUNCTION__, __LINE__, Status));
      return Status;
    }
  }

  DEBUG ((DEBUG_INFO,"SnpPlatformInitialize succes!\n"));

  return EFI_SUCCESS;
}
