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

#ifndef _HEST_H_
#define _HEST_H_

#include "Apei.h"


typedef struct _HEST_CONTEXT {
  EFI_ACPI_6_1_HARDWARE_ERROR_SOURCE_TABLE_HEADER  *HestHeader;         // pointer to hest header
  UINT32                                           OccupiedMemorySize; // allocated memory size for hest
  VOID                                             *KeyErrorSource;     // key error source, valtile
} HEST_CONTEXT;

EFI_STATUS
HestAddErrorSourceDescriptor (
  IN OUT HEST_CONTEXT  *Context,
  IN VOID              *ErrorSourceDescriptor,
  IN UINT32            SizeOfDescriptor
);
VOID
HestSetAcpiTable (
  IN HEST_CONTEXT *Context
);
EFI_STATUS
HestHeaderCreator (
  HEST_CONTEXT  *Context,
  UINT32        PreAllocatedHestSize
);

/**
* OEM Interface declaration
* 1.Interface is not realized default
* 2.OEM should implement this interface
*/
extern
VOID
OemHestInitialNotification (VOID);

extern
EFI_STATUS
OemInitHestTable(
  IN EFI_HANDLE ImageHandle
);

#endif    // _HEST_H_
