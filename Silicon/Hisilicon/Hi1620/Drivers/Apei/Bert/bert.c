/** @file
*
*  Copyright (c) 2018, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2018, Linaro Limited. All rights reserved.
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

#include "bert.h"
#include "ErrorSource/Ghes.h"
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include "PlatformArch.h"

VOID
BertSetAcpiTable (
  IN BERT_CONTEXT *Context
)
{
  UINTN          AcpiTableHandle;
  EFI_STATUS     Status;
  if (Context == NULL) {
    return;
  }
  EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_HEADER* Bert = Context->BertHeader;
  Bert->Header.Checksum = CalculateCheckSum8 ((UINT8*)(Bert), Bert->Header.Length);
  AcpiTableHandle = 0;
  Status = mAcpiTableProtocol->InstallAcpiTable (
                                 mAcpiTableProtocol,
                                 Bert,
                                 Bert->Header.Length,
                                 &AcpiTableHandle);
  ASSERT_EFI_ERROR (Status);
  return;
}

BOOLEAN
BertAddGenericErrorData (
  IN EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_HEADER *Bert,
  IN EFI_CPER_SECTION_TYPE                       TypeOfErrorData,
  IN VOID                                        *GenericErrorData,
  IN UINT32                                      SizeOfGenericErrorData,
  IN ERROR_SEVERITY                              ErrorSeverity,
  IN BOOLEAN                                     Correctable
)
{
  DEBUG ((DEBUG_ERROR, "[%a]:[%dL]: \n", __FUNCTION__, __LINE__));
  BOOLEAN Status = ErrorBlockAddErrorData (
                     (VOID*)Bert->BootErrorRegion,
                     Bert->BootErrorRegionLength,
                     TypeOfErrorData,
                     GenericErrorData,
                     SizeOfGenericErrorData,
                     ErrorSeverity,
                     Correctable);
  return Status;
}

EFI_STATUS
BertHeaderCreator (
  IN BERT_CONTEXT  *Context,
  IN UINT32        ErrorBlockSize
)
{
  if (Context == NULL) {
    return EFI_INVALID_PARAMETER;
  }
  Context->BertHeader = AllocateZeroPool (sizeof (EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_HEADER));
  Context->Block = AllocateReservedZeroPool (ErrorBlockSize);
  Context->BlockSize = ErrorBlockSize;
  *Context->BertHeader = (EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_HEADER) {
    ARM_ACPI_HEADER (
      EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_SIGNATURE,
      EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_HEADER,
      EFI_ACPI_6_0_BOOT_ERROR_RECORD_TABLE_REVISION
      ),
    Context->BlockSize,
    (UINT64)Context->Block
  };
  return EFI_SUCCESS;
}


