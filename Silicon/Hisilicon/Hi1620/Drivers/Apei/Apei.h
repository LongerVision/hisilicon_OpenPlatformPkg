/** @file
*
*  Copyright (c) 2017 Hisilicon Limited. All rights reserved.
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
#ifndef _APEI_H_
#define _APEI_H_

#include <Hi1620Platform.h>
#include <IndustryStandard/Acpi.h>
#include <Library/ArmSmcLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include <Protocol/AcpiTable.h>

#define EFI_ACPI_MAX_NUM_TABLES         20
#define PRIVATE_ARM_SMC_ID_APEI         0x83000100
#define PRIVATE_ARM_SMC_ID_APEI_S       0x83000101

typedef struct {
  EFI_ACPI_6_1_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE  *HestCorrectedErrorGhesV2;
  EFI_ACPI_6_1_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE  *HestFatalErrorGhesV2;
  EFI_ACPI_6_1_GENERIC_HARDWARE_ERROR_SOURCE_VERSION_2_STRUCTURE  *HestRecoverableErrorGhesV2;
  EFI_PHYSICAL_ADDRESS                                            HestTableAddress;
  EFI_PHYSICAL_ADDRESS                                            EinjTableAddress;
  EFI_PHYSICAL_ADDRESS                                            EinjDataStruct;
  VOID                                                            *ErstContext;
} APEI_TRUSTFIRMWARE_STRUCTURE;

extern EFI_ACPI_TABLE_PROTOCOL       *mAcpiTableProtocol;
extern EFI_ACPI_SDT_PROTOCOL         *mAcpiSdtProtocol;
extern APEI_TRUSTFIRMWARE_STRUCTURE  *mApeiTrustfirmwareStruc;


#endif    // _APEI_H_
