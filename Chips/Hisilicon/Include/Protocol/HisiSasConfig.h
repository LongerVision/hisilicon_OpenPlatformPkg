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

#ifndef _HISI_SAS_CONFIG_H_
#define _HISI_SAS_CONFIG_H_

#define HISI_SAS_CONFIG_PROTOCOL_GUID   \
    { 0x3A236669, 0x6666, 0x4d04, { 0xb2, 0x83, 0x7, 0x9f, 0x3c, 0xc4, 0x71, 0x66 } }

typedef
EFI_STATUS
(EFIAPI *HISI_SAS_GET_ADDRESS) (
  IN     UINT8 Index,
  IN OUT UINT8 *SasAddrBuffer
  );

typedef struct {
  HISI_SAS_GET_ADDRESS GetAddr;
} HISI_SAS_CONFIG_PROTOCOL;

extern EFI_GUID gHisiSasConfigProtocolGuid;


#endif
