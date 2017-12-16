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
**/

#ifndef __PCIE_INIT_IATU_H__
#define __PCIE_INIT_IATU_H__

#define TX_ATU_EACH_CHIP    (0x6)
#define ATU_SIZE_SHIFT      (0x5)                   //对应0x20,表示每个atu单元对应的寄存器

#define TXATUID_ONECHIP(p)  (p%TX_ATU_EACH_CHIP)    // Atu 0 1 2 3 4 5;
#define TXATUID_2_CHIPID(p) (p/TX_ATU_EACH_CHIP)    // Chip 0, Chip 1, Chip2, Chip3

/* Define the union U_IOB_TXATU_CONTROL_0 */
typedef union
{
  struct
  {
    UINT32    iob_txatu_en                  : 1   ; /* [0]  */
    UINT32    iob_txatu_work_mode           : 1   ; /* [1]  */
    UINT32    iob_txatu_type_trans_mode     : 1   ; /* [2]  */
    UINT32    reserved_0                    : 1   ; /* [3]  */
    UINT32    iob_txatu_ep_num              : 1   ; /* [4]  */
    UINT32    iob_txatu_pf_num              : 3   ; /* [7..5]  */
    UINT32    reserved_1                    : 24  ; /* [31..8]  */
  } bits;

  UINT32    u32;
} U_IOB_TXATU_CONTROL_0;

/* Define the union U_IOB_TXATU_CONTROL_2 */
typedef union
{
  struct
  {
    UINT32    iob_txatu_ext_region_size : 20  ; /* [19..0]  */
    UINT32    reserved_0                : 12  ; /* [31..20] */
  } bits;

  UINT32    u32;
} U_IOB_TXATU_CONTROL_2;

#endif

