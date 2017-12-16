/** @file

  Copyright (c) 2017, Hisilicon Limited. All rights reserved.<BR>
  Copyright (c) 2017, Linaro Limited. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <Library/PcdLib.h>
#include <Library/D06PciLib.h>

PCI_ROOT_BRIDGE_RESOURCE_APPETURE  mResAppeture[PCIE_MAX_HOSTBRIDGE][PCIE_MAX_ROOTBRIDGE] = {
 {// HostBridge 0
      {
        (PCI_TOTAL_ECAM),                                          // Ecam
        (0x00),                                                    // BusBase
        (0x3F),                                                    // BusLimit
        (PCI_HB0_MEM32BASE),                                       // Mem32base
        (PCI_HB0_MEM32BASE + PCI_HB0_MEM32LIMIT - 1),              // Memlimit
        (PCI_HB0_IOBASE),                                          // IoBase
        (PCI_HB0_IOBASE + PCI_HB0_IOLIMIT - 1),                    // IoLimit
        (PCI_HB0_MEM64BASE),                                       // Mem64Base
        (PCI_HB0_MEM64BASE + PCI_HB0_MEM64LIMIT - 1),              // Mem64limit
     }
 },
 // HostBridge 1
 {
    {
      (PCI_TOTAL_ECAM),                                          // Ecam
      (0x80),                                                    // BusBase
      (0x9F),                                                    // BusLimit
      (PCI_HB1_MEM32BASE),                                       // Mem32base
      (PCI_HB1_MEM32BASE + PCI_HB1_MEM32LIMIT - 1),              // Memlimit
      (PCI_HB1_IOBASE),                                          // IoBase
      (PCI_HB1_IOBASE + PCI_HB1_IOLIMIT - 1),                    // IoLimit
      (PCI_HB1_MEM64BASE),                                       // Mem64Base
      (PCI_HB1_MEM64BASE + PCI_HB1_MEM64LIMIT - 1),              // Mem64limit
   }
 }
};

