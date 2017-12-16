/** @file
  Differentiated System Description Table Fields (DSDT)

  Copyright (c) 2014, ARM Ltd. All rights reserved.<BR>
  Copyright (c) 2017, Hisilicon Limited. All rights reserved.<BR>
  Copyright (c) 2017, Linaro Limited. All rights reserved.<BR>
    This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

  Based on the files under ArmPlatformPkg/ArmJunoPkg/AcpiTables/

**/

#include "Hi1620Platform.h"

DefinitionBlock("DsdtTable.aml", "DSDT", 2, "HISI  ", "HIP08   ", EFI_ACPI_ARM_OEM_REVISION) {
     include ("Hi1620Com.asl")
     include ("Hi1620CPU.asl")
     include ("Hi1620Pci.asl")
     include ("Hi1620Hns.asl")
     include ("Hi1620Sas.asl")
     include ("Hi1620Apei.asl")
}
