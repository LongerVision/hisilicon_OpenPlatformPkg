// ******************************************************************************
// Copyright     :  Copyright (C) 2017, Hisilicon Technologies Co. Ltd.
// File name     :  hipciec_global_reg_reg_offset.h
// Project line  :  Platform And Key Technologies Development
// Department    :  CAD Development Department
// Author        :  xxx
// Version       :  1.0
// Date          :  2016/3/10
// Description   :  The description of xxx project
// Others        :  Generated automatically by nManager V4.1
// History       :  xxx 2017/05/20 11:23:39 Create file
// ******************************************************************************

#ifndef __HIPCIEC_GLOBAL_REG_REG_OFFSET_H__
#define __HIPCIEC_GLOBAL_REG_REG_OFFSET_H__

/* HIPCIEC_GLOBAL_REG Base address of Module's Register */
#define PCIe_HIPCIEC_GLOBAL_REG_BASE                       (0x0000)

/******************************************************************************/
/*                      PCIe HIPCIEC_GLOBAL_REG Registers' Definitions        */
/******************************************************************************/

#define PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_REG                 (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x0)  /* port reset */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT_EN_REG                    (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x4)  /* port enable */
#define PCIe_HIPCIEC_GLOBAL_REG_PHY_RESET_REG                  (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x8)  /* phy reset */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_CFG_REG             (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xC)  /* port reset */
#define PCIe_HIPCIEC_GLOBAL_REG_TURBO_SIM_SEL_REG              (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x10) /* turbo sim selection */
#define PCIe_HIPCIEC_GLOBAL_REG_LOCAL_LOOPBACK_MODE_REG        (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x14) /* local loopback mode selection */
#define PCIe_HIPCIEC_GLOBAL_REG_PCIE_SRAM_TIMING_CFG_REG       (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x18) /* PCIE SRAM timing config register */
#define PCIe_HIPCIEC_GLOBAL_REG_CFG_FUN_SEL_REG                (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x28) /* cfg space function sel */
#define PCIe_HIPCIEC_GLOBAL_REG_INSERT_SKP_DATA_PARITY_ERR_REG (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x7C) /* insert skp data parity error in scramble module */
#define PCIe_HIPCIEC_GLOBAL_REG_GLB_PCIEC_MODE_SEL_REG         (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x80) /* select pcie to up or dp and also can select pcie to rc or ep */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT_INT_STATUS_0_7_REG        (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x84) /* Global port interrupt status0 */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT_INT_STATUS_8_15_REG       (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x88) /* Global port interrupt status1 */
#define PCIe_HIPCIEC_GLOBAL_REG_PCIE_RELEASE_I_REG             (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x8C) /* pcie release info */
#define PCIe_HIPCIEC_GLOBAL_REG_PCIE_VERSION_I_REG             (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x90) /* pcie version info */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_SET_REG               (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x94) /* CORE interrupt set */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_MSK_REG               (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x98) /* CORE interrupt mask */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_RO_REG                (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0x9C) /* CORE interrupt status */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_STATUS_REG            (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xA0) /* CORE interrupt ind */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_CLK_FLG_REG               (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xA4) /* dfx core clk exist flag */
#define PCIe_HIPCIEC_GLOBAL_REG_APB_ECO_REG                    (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xB0) /* apb eco register */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG           (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xB4) /* port link mode */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG          (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xB8) /* port link mode */
#define PCIe_HIPCIEC_GLOBAL_REG_PCS_SOFT_REST_REG              (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xBC) /* PCS and axi soft reset */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT_RST_DLY_CNT_REG           (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xC0) /* port soft reset or linkdown reset delay count */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT_INT_STATUS_B_0_7_REG      (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xC4) /* Global port business interrupt status0 */
#define PCIe_HIPCIEC_GLOBAL_REG_PORT_INT_STATUS_B_8_15_REG     (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xC8) /* Global port business interrupt status1 */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_SET_B_REG             (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xCC) /* CORE business interrupt set */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_MSK_B_REG             (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xD0) /* CORE business interrupt mask */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_RO_B_REG              (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xD4) /* CORE  business interrupt status */
#define PCIe_HIPCIEC_GLOBAL_REG_CORE_INT_STATUS_B_REG          (PCIe_HIPCIEC_GLOBAL_REG_BASE + 0xD8) /* CORE  business interrupt ind */

#endif // __HIPCIEC_GLOBAL_REG_REG_OFFSET_H__
