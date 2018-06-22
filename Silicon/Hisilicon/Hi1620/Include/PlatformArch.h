/** @file
*
*  Copyright (c) 2015, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2015, Linaro Limited. All rights reserved.
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
#define MAX_DDRC        4
#define MAX_NODE        (MAX_SOCKET * MAX_DIE)
#define MAX_CHANNEL     8
#define MAX_DIMM        2
#define MAX_RANK_CH     8
#define MAX_RANK_DIMM   4
// Max NUMA node number for each node type
#define MAX_NUM_PER_TYPE 8


// for acpi
#define NODE_IN_SOCKET                                  2
#define CORE_NUM_PER_SOCKET                             48
#define EFI_ACPI_MEMORY_AFFINITY_STRUCTURE_COUNT        16
#define EFI_ACPI_6_2_ITS_AFFINITY_STRUCTURE_COUNT       1

#endif

