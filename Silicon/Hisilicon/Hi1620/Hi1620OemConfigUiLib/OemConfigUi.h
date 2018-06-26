/** @file

Copyright (c) 2007 - 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

Module Name:

  OemConfigUi.h

Abstract:

  NVData structure used by the OEM Config.

Revision History:


**/

#ifndef _OEM_CONFIG_UI_H_
#define _OEM_CONFIG_UI_H_

#define EFI_VARIABLE_NON_VOLATILE            0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS      0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS          0x00000004
#define OEM_CONFIG_FORM_ID                   1
#define MEMORY_CONFIG_FORM_ID                2
#define IBMC_CONFIG_FORM_ID                  3
#define PCIE_CONFIG_FORM_ID                  4
#define MISC_CONFIG_FORM_ID                  5
#define RAS_CONFIG_FORM_ID                   6

#define VFR_FORMID_PCIE_SOCKET0              0x4100
#define VFR_FORMID_PCIE_SOCKET1              0x4200
#define VFR_FORMID_PCIE_PORT0                0x4000
#define VFR_FORMID_PCIE_PORT1                0x4001
#define VFR_FORMID_PCIE_PORT2                0x4002
#define VFR_FORMID_PCIE_PORT3                0x4003
#define VFR_FORMID_PCIE_PORT4                0x4004
#define VFR_FORMID_PCIE_PORT5                0x4005
#define VFR_FORMID_PCIE_PORT6                0x4006
#define VFR_FORMID_PCIE_PORT7                0x4007
#define VFR_FORMID_PCIE_PORT8                0x4008
#define VFR_FORMID_PCIE_PORT9                0x4009
#define VFR_FORMID_PCIE_PORT10               0x4010
#define VFR_FORMID_PCIE_PORT11               0x4011
#define VFR_FORMID_PCIE_PORT12               0x4012
#define VFR_FORMID_PCIE_PORT13               0x4013
#define VFR_FORMID_PCIE_PORT14               0x4014
#define VFR_FORMID_PCIE_PORT15               0x4015

#define VFR_FORMID_MEMORY_RAS                0x6100
#define VFR_FORMID_CORRECT_ERROR             0x6101
#define VFR_FORMID_PCIE_RAS                  0x6200

#define RMT_PATTERN_LENGTH                   256


#endif
