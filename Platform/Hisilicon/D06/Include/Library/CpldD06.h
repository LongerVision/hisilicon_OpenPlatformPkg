/** @file

  Copyright (c) 2018, Hisilicon Limited. All rights reserved.<BR>
  Copyright (c) 2018, Linaro Limited. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __CPLDD06_H__
#define __CPLDD06_H__

#define CPLD_BASE_ADDRESS                 0x80000000

#define CPLD_BIOSINDICATE_FLAG            0x09
#define CPLD_I2C_SWITCH_FLAG              0x17
#define CPU_GET_I2C_CONTROL               BIT2
#define BMC_I2C_STATUS                    BIT3

#define CPLD_LOGIC_VERSION                (0x4)
#define CPLD_LOGIC_COMPILE_YEAR          (0x1)
#define CPLD_LOGIC_COMPILE_MONTH         (0x2)
#define CPLD_LOGIC_COMPILE_DAY           (0x3)

#define CPLD_RISER_PRSNT_FLAG             0x40
#define CPU1_RISER_PRESENT                BIT6
#define CPU0_RISER_PRESENT                BIT7
#define CPLD_RISER2_BOARD_ID              0x44

#define CPLD_X8_X8_X8_BOARD_ID            0x92
#define CPLD_X16_X8_BOARD_ID              0x93

#define CPLD_CLOCK_FLAG      0xFD
#define CPLD_BOM_VER_FLAG    0x0B
#define BRD_VER_4TH          0x4

#endif /* __CPLDD06_H__ */
