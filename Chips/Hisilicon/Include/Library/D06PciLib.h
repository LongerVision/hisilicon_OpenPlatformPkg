/** @file
*
*  Copyright (c) 2016, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2016, Linaro Limited. All rights reserved.
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

#ifndef _PLATFORM_PCI_LIB_H_
#define _PLATFORM_PCI_LIB_H_

#define PCIE_MAX_HOSTBRIDGE      2
#define PCIE_MAX_ROOTBRIDGE      1

//Chip 0 Config
#define PCI_TOTAL_ECAM           FixedPcdGet64(PciTotalEcam)
#define PCI_HB0_MEM32BASE        FixedPcdGet64(PciHb0Mem32Base)
#define PCI_HB0_MEM32LIMIT       FixedPcdGet64(PciHb0Mem32Size)
#define PCI_HB0_IOBASE           FixedPcdGet64(PciHb0IoBase)
#define PCI_HB0_IOLIMIT          FixedPcdGet64(PciHb0IoSize)
#define PCI_HB0_MEM64BASE        FixedPcdGet64(PciHb0Mem64Base)
#define PCI_HB0_MEM64LIMIT       FixedPcdGet64(PciHb0Mem64Size)

//Chip 1 Config
#define PCI_HB1_MEM32BASE        FixedPcdGet64(PciHb1Mem32Base)
#define PCI_HB1_MEM32LIMIT       FixedPcdGet64(PciHb1Mem32Size)
#define PCI_HB1_IOBASE           FixedPcdGet64(PciHb1IoBase)
#define PCI_HB1_IOLIMIT          FixedPcdGet64(PciHb1IoSize)
#define PCI_HB1_MEM64BASE        FixedPcdGet64(PciHb1Mem64Base)
#define PCI_HB1_MEM64LIMIT       FixedPcdGet64(PciHb1Mem64Size)

typedef struct {
  UINT64          Ecam;
  UINT64          BusBase;
  UINT64          BusLimit;
  UINT32          Mem32Base;
  UINT32          Mem32Limit;
  UINT64          IoBase;
  UINT64          IoLimit;
  UINT64          Mem64Base;
  UINT64          Mem64Limit;
} PCI_ROOT_BRIDGE_RESOURCE_APPETURE;

extern PCI_ROOT_BRIDGE_RESOURCE_APPETURE  mResAppeture[PCIE_MAX_HOSTBRIDGE][PCIE_MAX_ROOTBRIDGE];
#endif

