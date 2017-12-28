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
*  Based on the files under ArmPlatformPkg/ArmJunoPkg/AcpiTables/
*
**/

#ifndef _PPTT_H_
#define _PPTT_H_

#include <IndustryStandard/Acpi.h>
#include <Library/ArmLib/ArmLibPrivate.h>
#include <Library/BaseMemoryLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Protocol/AcpiSystemDescriptionTable.h>
#include <Protocol/AcpiTable.h>
#include "../D05AcpiTables/Hi1616Platform.h"

///
/// "PPTT"  Processor Properties Topology Table
///
#define EFI_ACPI_6_2_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_SIGNATURE  SIGNATURE_32('P', 'P', 'T', 'T')
#define EFI_ACPI_6_2_PROCESSOR_PROPERTIES_TOPOLOGY_TABLE_REVISION   0x01
#define EFI_ACPI_MAX_NUM_TABLES                                     20

#define PPTT_TABLE_MAX_LEN         0x6000
#define PPTT_SOCKET_NO             0x2
#define PPTT_DIE_NO                0x2
#define PPTT_CULSTER_NO            0x4
#define PPTT_CORE_NO               0x4
#define PPTT_SOCKET_COMPONENT_NO   0x1
#define PPTT_CACHE_NO              0x4

#define PPTT_TYPE0_PHYSICAL_PKG        BIT0
#define PPTT_TYPE0_PROCESSORID_VALID   BIT1
#define PPTT_TYPE0_SOCKET_FLAG         PPTT_TYPE0_PHYSICAL_PKG
#define PPTT_TYPE0_DIE_FLAG            PPTT_TYPE0_PHYSICAL_PKG
#define PPTT_TYPE0_CLUSTER_FLAG        0
#define PPTT_TYPE0_CORE_FLAG           PPTT_TYPE0_PROCESSORID_VALID

#define PPTT_TYPE1_SIZE_VALID             BIT0
#define PPTT_TYPE1_NUMBER_OF_SETS_VALID   BIT1
#define PPTT_TYPE1_ASSOCIATIVITY_VALID    BIT2
#define PPTT_TYPE1_ALLOCATION_TYPE_VALID  BIT3
#define PPTT_TYPE1_CACHE_TYPE_VALID       BIT4
#define PPTT_TYPE1_WRITE_POLICY_VALID     BIT5
#define PPTT_TYPE1_LINE_SIZE_VALID        BIT6

typedef union {
  struct {
    UINT32    InD           :1;
    UINT32    Level         :3;
    UINT32    Reserved      :28;
  } Bits;
  UINT32 Data;
}CSSELR_DATA;

typedef union {
  struct {
    UINT32    LineSize           :3;
    UINT32    Associativity      :10;
    UINT32    NumSets            :15;
    UINT32    Wa                 :1;
    UINT32    Ra                 :1;
    UINT32    Wb                 :1;
    UINT32    Wt                 :1;
  } Bits;
  UINT32 Data;
}CCSIDR_DATA;

//
// Processor Hierarchy Node Structure
//
typedef struct {
  UINT8                   Type;
  UINT8                   Length;
  UINT16                  Reserved;
  UINT32                  Flags;
  UINT32                  Parent;
  UINT32                  AcpiProcessorId;
  UINT32                  PrivateResourceNo;
} EFI_ACPI_6_2_PPTT_TYPE0;

//
// Cache Configuration
//
typedef union {
  struct {
    UINT8    AllocateType   :2;
    UINT8    CacheType      :2;
    UINT8    WritePolicy    :1;
    UINT8    Reserved       :3;
  } Bits;
  UINT8 Data;
}PPTT_TYPE1_ATTRIBUTES;

//
// Cache Type Structure
//
typedef struct {
  UINT8                   Type;
  UINT8                   Length;
  UINT16                  Reserved;
  UINT32                  Flags;
  UINT32                  NextLevelOfCache;
  UINT32                  Size;
  UINT32                  NumberOfSets;
  UINT8                   Associativity;
  UINT8                   Attributes;
  UINT16                  LineSize;
} EFI_ACPI_6_2_PPTT_TYPE1;

//
// ID Structure
//
typedef struct {
  UINT8                   Type;
  UINT8                   Length;
  UINT16                  Reserved;
  UINT32                  VendorId;
  UINT64                  Level1Id;
  UINT64                  Level2Id;
  UINT16                  MajorRev;
  UINT16                  MinorRev;
  UINT16                  SpinRev;
} EFI_ACPI_6_2_PPTT_TYPE2;

#endif    // _PPTT_H_

