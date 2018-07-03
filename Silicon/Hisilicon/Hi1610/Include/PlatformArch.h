/** @file
*
*  Copyright (c) 2015 - 2018, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2015 - 2018, Linaro Limited. All rights reserved.
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



#ifndef _PLATFORM_ARCH_H_
#define _PLATFORM_ARCH_H_

#define MAX_SOCKET      2
#define MAX_DIE         4
#define MAX_DDRC        2
#define MAX_NODE        (MAX_SOCKET * MAX_DIE)
#define MAX_CHANNEL     4
#define MAX_DIMM        3
#define MAX_RANK_CH     12
#define MAX_RANK_DIMM   4
#define MAX_DIMM_SIZE   32  // In GB
// Max NUMA node number for each node type
#define MAX_NUM_PER_TYPE 8

#define S1_BASE               0x40000000000

#define RASC_BASE                (0x5000)
/* configuration register for Rank statistical information */
#define RASC_CFG_INFOIDX_REG     (RASC_BASE + 0x5C)
/* configuration register for Sparing level */
#define RASC_CFG_SPLVL_REG       (RASC_BASE + 0xB8)

//
// ACPI table information used to initialize tables.
//
#define EFI_ACPI_ARM_OEM_ID           'H','I','S','I',' ',' '   // OEMID 6 bytes long
#define EFI_ACPI_ARM_OEM_TABLE_ID     SIGNATURE_64 ('H','I','P','0','6',' ',' ',' ') // OEM table id 8 bytes long
#define EFI_ACPI_ARM_OEM_REVISION     0x00000000
#define EFI_ACPI_ARM_CREATOR_ID       SIGNATURE_32 ('I','N','T','L')
#define EFI_ACPI_ARM_CREATOR_REVISION 0x20151124

// A macro to initialise the common header part of EFI ACPI tables as defined by
// EFI_ACPI_DESCRIPTION_HEADER structure.
#define ARM_ACPI_HEADER(Signature, Type, Revision) {            \
  Signature,                      /* UINT32  Signature */       \
  sizeof (Type),                  /* UINT32  Length */          \
  Revision,                       /* UINT8   Revision */        \
  0,                              /* UINT8   Checksum */        \
  { EFI_ACPI_ARM_OEM_ID },        /* UINT8   OemId[6] */        \
  EFI_ACPI_ARM_OEM_TABLE_ID,      /* UINT64  OemTableId */      \
  EFI_ACPI_ARM_OEM_REVISION,      /* UINT32  OemRevision */     \
  EFI_ACPI_ARM_CREATOR_ID,        /* UINT32  CreatorId */       \
  EFI_ACPI_ARM_CREATOR_REVISION   /* UINT32  CreatorRevision */ \
  }

#endif

