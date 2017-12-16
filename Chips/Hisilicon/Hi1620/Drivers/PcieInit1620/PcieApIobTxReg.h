// ******************************************************************************
// Copyright     :  Copyright (C) 2017, Hisilicon Technologies Co. Ltd.
// File name     :  hipciec_ap_iob_tx_reg_reg_offset.h
// Project line  :  Platform And Key Technologies Development
// Department    :  CAD Development Department
// Author        :  xxx
// Version       :  1.0
// Date          :  2016/3/10
// Description   :  The description of xxx project
// Others        :  Generated automatically by nManager V4.1
// History       :  xxx 2017/05/20 11:23:39 Create file
// ******************************************************************************

#ifndef __HIPCIEC_AP_IOB_TX_REG_REG_OFFSET_H__
#define __HIPCIEC_AP_IOB_TX_REG_REG_OFFSET_H__

/* HIPCIEC_AP_IOB_TX_REG Base address of Module's Register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_BASE                       (0x0)

/******************************************************************************/
/*                      PCIe HIPCIEC_AP_IOB_TX_REG Registers' Definitions                            */
/******************************************************************************/

#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_0_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x0)    /* IOB TX address transition unit control register0.Common information. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_1_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x20)   /* IOB TX address transition unit control register0.Common information. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_2_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x40)   /* IOB TX address transition unit control register0.Common information. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_3_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x60)   /* IOB TX address transition unit control register0.Common information. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_4_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x80)   /* IOB TX address transition unit control register0.Common information. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_5_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA0)   /* IOB TX address transition unit control register0.Common information. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_0_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x8)    /* IOB TX address transition unit control information register2.Extend the IOB_TXATU_REGION_SIZE. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_1_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x28)   /* IOB TX address transition unit control information register2.Extend the IOB_TXATU_REGION_SIZE. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_2_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x48)   /* IOB TX address transition unit control information register2.Extend the IOB_TXATU_REGION_SIZE. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_3_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x68)   /* IOB TX address transition unit control information register2.Extend the IOB_TXATU_REGION_SIZE. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_4_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x88)   /* IOB TX address transition unit control information register2.Extend the IOB_TXATU_REGION_SIZE. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_5_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA8)   /* IOB TX address transition unit control information register2.Extend the IOB_TXATU_REGION_SIZE. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_REGION_SIZE_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xC)    /* IOB TX address transition unit region size low 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_REGION_SIZE_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2C)   /* IOB TX address transition unit region size low 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_REGION_SIZE_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x4C)   /* IOB TX address transition unit region size low 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_REGION_SIZE_3_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x6C)   /* IOB TX address transition unit region size low 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_REGION_SIZE_4_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x8C)   /* IOB TX address transition unit region size low 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_REGION_SIZE_5_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAC)   /* IOB TX address transition unit region size low 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_L_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x10)   /* IOB TX address transition unit base address low 32bit.the address is align to 4KByte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_L_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30)   /* IOB TX address transition unit base address low 32bit.the address is align to 4KByte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_L_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x50)   /* IOB TX address transition unit base address low 32bit.the address is align to 4KByte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_L_3_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x70)   /* IOB TX address transition unit base address low 32bit.the address is align to 4KByte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_L_4_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x90)   /* IOB TX address transition unit base address low 32bit.the address is align to 4KByte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_L_5_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xB0)   /* IOB TX address transition unit base address low 32bit.the address is align to 4KByte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_H_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x14)   /* IOB TX address transition unit base address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_H_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x34)   /* IOB TX address transition unit base address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_H_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x54)   /* IOB TX address transition unit base address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_H_3_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x74)   /* IOB TX address transition unit base address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_H_4_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x94)   /* IOB TX address transition unit base address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_H_5_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xB4)   /* IOB TX address transition unit base address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_L_0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x18)   /* IOB TX address transition unit target address low 32bit.the address is align to 4Byte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_L_1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x38)   /* IOB TX address transition unit target address low 32bit.the address is align to 4Byte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_L_2_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x58)   /* IOB TX address transition unit target address low 32bit.the address is align to 4Byte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_L_3_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x78)   /* IOB TX address transition unit target address low 32bit.the address is align to 4Byte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_L_4_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x98)   /* IOB TX address transition unit target address low 32bit.the address is align to 4Byte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_L_5_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xB8)   /* IOB TX address transition unit target address low 32bit.the address is align to 4Byte. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_H_0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1C)   /* IOB TX address transition unit target address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_H_1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3C)   /* IOB TX address transition unit target address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_H_2_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x5C)   /* IOB TX address transition unit target address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_H_3_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x7C)   /* IOB TX address transition unit target address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_H_4_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x9C)   /* IOB TX address transition unit target address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_H_5_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xBC)   /* IOB TX address transition unit target address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT0_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x300)  /* IOB TX maximum tag of port0 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT1_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x304)  /* IOB TX maximum tag of port1 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT2_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x308)  /* IOB TX maximum tag of port2 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT3_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30C)  /* IOB TX maximum tag of port3 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT4_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x310)  /* IOB TX maximum tag of port4 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT5_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x314)  /* IOB TX maximum tag of port5 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT6_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x318)  /* IOB TX maximum tag of port6 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT7_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x31C)  /* IOB TX maximum tag of port7 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT8_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x320)  /* IOB TX maximum tag of port8 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT9_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x324)  /* IOB TX maximum tag of port9 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT10_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x328)  /* IOB TX maximum tag of port10 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT11_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x32C)  /* IOB TX maximum tag of port11 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT12_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x330)  /* IOB TX maximum tag of port12 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT13_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x334)  /* IOB TX maximum tag of port13 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT14_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x338)  /* IOB TX maximum tag of port14 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT15_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x33C)  /* IOB TX maximum tag of port15 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT16_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x340)  /* IOB TX maximum tag of port16 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT17_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x344)  /* IOB TX maximum tag of port17 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT18_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x348)  /* IOB TX maximum tag of port18 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_TAG_NUM_PORT19_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x34C)  /* IOB TX maximum tag of port19 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x400)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x404)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_2_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x408)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_3_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x40C)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_4_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x410)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_5_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x414)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_6_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x418)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_7_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x41C)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_8_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x420)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_9_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x424)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_10_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x428)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_11_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x42C)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_12_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x430)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_13_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x434)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_14_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x438)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_15_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x43C)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_16_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x440)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_17_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x444)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_18_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x448)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_REQ_TIMER_CFG_19_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x44C)  /* IOB transmit request timeout timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_TIMER_CFG0_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x500)  /* IOB completion timeout registers of default value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_TIMER_CFG1_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x504)  /* IOB completion timeout register of Range A first timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_TIMER_CFG2_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x508)  /* IOB completion timeout register of Range A second timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_TIMER_CFG3_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x50C)  /* IOB completion timeout register of Range B first timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_TIMER_CFG4_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x510)  /* IOB completion timeout register of Range B second timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_TIMER_CFG5_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x514)  /* IOB completion timeout register of Range C first timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_TIMER_CFG6_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x518)  /* IOB completion timeout register of Range C second timeout value. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_0_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x600)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_1_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x604)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_2_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x608)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_3_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x60C)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_4_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x610)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_5_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x614)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_6_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x618)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_7_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x61C)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_8_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x620)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_9_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x624)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_10_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x628)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_11_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x62C)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_12_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x630)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_13_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x634)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_14_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x638)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_15_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x63C)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_16_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x640)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_17_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x644)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_18_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x648)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_CRS_RETRY_COUNTER_CFG_19_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x64C)  /* IOB CRS retry time counter register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_0_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x700)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_1_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x704)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_2_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x708)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_3_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x70C)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_4_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x710)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_5_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x714)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_6_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x718)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_7_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x71C)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_8_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x720)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_9_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x724)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_10_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x728)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_11_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x72C)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_12_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x730)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_13_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x734)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_14_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x738)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_15_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x73C)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_16_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x740)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_17_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x744)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_18_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x748)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_WEIGHT_19_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x74C)  /* IOB TX port arbiter weight */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_SET1_REG                 (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x800)  /* IOB TX interrupt set register1 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_SET2_REG                 (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x804)  /* IOB TX interrupt set register2 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_SET3_REG                 (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x808)  /* IOB TX interrupt set register3 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_MASK1_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x810)  /* IOB TX interrupt mask register1 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_MASK2_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x814)  /* IOB TX interrupt mask register2 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_MASK3_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x818)  /* IOB TX interrupt mask register3 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_STATUS1_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x820)  /* IOB TX interrupt status register1 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_STATUS2_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x824)  /* IOB TX interrupt status register2 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_INT_STATUS3_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x828)  /* IOB TX interrupt status register3 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_UNMATCH_ADDR_L_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x840)  /* IOB TX unmatched address low 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_UNMATCH_ADDR_H_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x844)  /* IOB TX unmatched address high 32bit. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_RESET_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x900)  /* IOB TX port reset register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CFG_RESET_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x904)  /* IOB TX cfg reset register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_AP_WAIT_IDLE_TIMER_CFG_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x908)  /* AP wait idle timer configuration register. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_ENTRY_WL_0_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x910)  /* IOB TX post entry waterline */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_ENTRY_WL_1_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x914)  /* IOB TX post entry waterline */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_ENTRY_WL_2_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x918)  /* IOB TX post entry waterline */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRY_WL_0_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x920)  /* IOB TX non_post entry waterline */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRY_WL_1_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x924)  /* IOB TX non_post entry waterline */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRY_WL_2_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x928)  /* IOB TX non_post entry waterline */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA00)  /* Post block waterline of Port0 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA04)  /* Post block waterline of Port1 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT2_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA08)  /* Post block waterline of Port2 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT3_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA0C)  /* Post block waterline of Port3 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT4_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA10)  /* Post block waterline of Port4 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT5_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA14)  /* Post block waterline of Port5 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT6_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA18)  /* Post block waterline of Port6 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT7_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA1C)  /* Post block waterline of Port7 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT8_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA20)  /* Post block waterline of Port8 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT9_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA24)  /* Post block waterline of Port9 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT10_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA28)  /* Post block waterline of Port10 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT11_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA2C)  /* Post block waterline of Port11 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT12_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA30)  /* Post block waterline of Port12 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT13_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA34)  /* Post block waterline of Port13 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT14_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA38)  /* Post block waterline of Port14 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT15_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA3C)  /* Post block waterline of Port15 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT16_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA40)  /* Post block waterline of Port16 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT17_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA44)  /* Post block waterline of Port17 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT18_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA48)  /* Post block waterline of Port18 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_BLK_CNT_PORT19_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA4C)  /* Post block waterline of Port19 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA80)  /* Non-Post block waterline of Port0 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA84)  /* Non-Post block waterline of Port1 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA88)  /* Non-Post block waterline of Port2 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT3_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA8C)  /* Non-Post block waterline of Port3 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT4_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA90)  /* Non-Post block waterline of Port4 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT5_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA94)  /* Non-Post block waterline of Port5 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT6_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA98)  /* Non-Post block waterline of Port6 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT7_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xA9C)  /* Non-Post block waterline of Port7 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT8_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAA0)  /* Non-Post block waterline of Port8 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT9_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAA4)  /* Non-Post block waterline of Port9 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT10_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAA8)  /* Non-Post block waterline of Port10 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT11_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAAC)  /* Non-Post block waterline of Port11 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT12_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAB0)  /* Non-Post block waterline of Port12 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT13_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAB4)  /* Non-Post block waterline of Port13 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT14_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAB8)  /* Non-Post block waterline of Port14 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT15_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xABC)  /* Non-Post block waterline of Port15 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT16_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAC0)  /* Non-Post block waterline of Port16 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT17_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAC4)  /* Non-Post block waterline of Port17 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT18_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xAC8)  /* Non-Post block waterline of Port18 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_BLK_CNT_PORT19_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0xACC)  /* Non-Post block waterline of Port19 */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_ECAM_CONTROL_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1264) /* IOB ECAM control register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_ECAM_BASE_ADDR_L_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1268) /* IOB ECAM base address low 32bit */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_ECAM_BASE_ADDR_H_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x126C) /* IOB ECAM base address high 32bit */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_POISON_CTRL_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1800) /* IOB TX poison control bit register. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_ERR_EN_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1804) /* IOB TX Completion error enable control register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_ERR_RPLC_DATA_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1808) /* IOB TX replace data when the cpl is err */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_DELAY_CTRL_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1810) /* IOB TX post send out delay control of each core. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_DELAY_PORT_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1814) /* IOB TX post send out delay port enable signal */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_DELAY_CTRL_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1818) /* IOB TX non post send out delay control of each core. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_DELAY_PORT_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x181C) /* IOB TX non post send out delay port enable signal */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_DELAY_CTRL_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1820) /* IOB TX completion send out delay control of each core. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_DELAY_PORT_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x1824) /* IOB TX completion send out delay port enable signal */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_CFG_ORDERING_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2000) /* Control the outbound ordering */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_CFG_RETRY_REG            (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2004) /* Controll the parameters that are used in the CHI retry */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_CFG_RESOURCE_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2008) /* Configure the common resource */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_CFG_MISC_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x200C) /* IOB_TX_CHI_CFG_MISC register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_0_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2100) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_1_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2104) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_2_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2108) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_3_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x210C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_4_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2110) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_5_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2114) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_6_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2118) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_7_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x211C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_8_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2120) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_9_REG                (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2124) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_10_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2128) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_11_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x212C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_12_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2130) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_13_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2134) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_14_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2138) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_15_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x213C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_16_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2140) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_17_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2144) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_18_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2148) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_19_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x214C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_20_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2150) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_21_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2154) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_22_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2158) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_23_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x215C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_24_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2160) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_25_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2164) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_26_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2168) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_27_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x216C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_28_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2170) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_29_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2174) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_30_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2178) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_31_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x217C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_32_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2180) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_33_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2184) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_34_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2188) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_35_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x218C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_36_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2190) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_37_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2194) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_38_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2198) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_DFX_39_REG               (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x219C) /* IOB chi2pcie dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_STATUS_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2200) /* IOB TX port status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_PORT_P_STATUS_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2204) /* IOB TX CHI port post status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CHI_PORT_NP_STATUS_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2208) /* IOB TX CHI port non_post status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_SLV_PORT_STATUS_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x220C) /* IOB TX Slave port status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_SLV_PORT_P_STATUS_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2210) /* IOB TX Slave port post queue status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_SLV_PORT_NP_STATUS_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2214) /* IOB TX Slave port non post queue status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_FIFO_DFX0_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2220) /* IOB TX post channel fifo status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_FIFO_DFX1_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2224) /* IOB TX post channel fifo status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_FIFO_DFX2_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2228) /* IOB TX post channel fifo status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_FIFO_DFX0_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2230) /* IOB TX nonpost channel fifo status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_FIFO_DFX1_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2234) /* IOB TX nonpost channel fifo status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_FIFO_DFX2_REG             (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2238) /* IOB TX nonpost channel fifo status register */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_IN_CNT_DFX_0_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2300) /* IOB TX input req and return cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_IN_CNT_DFX_1_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2310) /* IOB TX input req and return cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_IN_CNT_DFX_2_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2320) /* IOB TX input req and return cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_OUT_CNT_DFX_0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2304) /* IOB TX output post req and dump post req counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_OUT_CNT_DFX_1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2314) /* IOB TX output post req and dump post req counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_OUT_CNT_DFX_2_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2324) /* IOB TX output post req and dump post req counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_ENTRY_ST0_DFX_0_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2308) /* IOB TX Post Entry Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_ENTRY_ST0_DFX_1_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2318) /* IOB TX Post Entry Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_P_ENTRY_ST0_DFX_2_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2328) /* IOB TX Post Entry Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2340) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2344) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2348) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_3_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x234C) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_4_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2350) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_5_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2354) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_6_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2358) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_7_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x235C) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_8_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2360) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_9_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2364) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_10_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2368) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_11_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x236C) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_12_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2370) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_13_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2374) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_14_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2378) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_15_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x237C) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_16_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2380) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_17_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2384) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_18_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2388) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_CNT_DFX_19_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x238C) /* IOB TX post req counter dfx */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_IN_CNT_DFX_0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2400) /* IOB TX input req and return cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_IN_CNT_DFX_1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2440) /* IOB TX input req and return cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_IN_CNT_DFX_2_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2480) /* IOB TX input req and return cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_OUT_CNT_DFX_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2404) /* IOB TX output np req and dump np req counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_OUT_CNT_DFX_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2444) /* IOB TX output np req and dump np req counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_OUT_CNT_DFX_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2484) /* IOB TX output np req and dump np req counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_IN_CNT_DFX_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2408) /* IOB TX input cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_IN_CNT_DFX_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2448) /* IOB TX input cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_CPL_IN_CNT_DFX_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2488) /* IOB TX input cpl counter. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST0_DFX_0_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2410) /* IOB TX NonPost Entry Low32bit Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST0_DFX_1_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2450) /* IOB TX NonPost Entry Low32bit Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST0_DFX_2_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2490) /* IOB TX NonPost Entry Low32bit Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST0_DFX_0_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2514) /* IOB TX NonPost Entry High32bit Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST0_DFX_1_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2554) /* IOB TX NonPost Entry High32bit Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST0_DFX_2_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2594) /* IOB TX NonPost Entry High32bit Status0(Req Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST1_DFX_0_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2518) /* IOB TX NonPost Entry Low32bit Status1(Wait CPL) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST1_DFX_1_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2558) /* IOB TX NonPost Entry Low32bit Status1(Wait CPL) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST1_DFX_2_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2598) /* IOB TX NonPost Entry Low32bit Status1(Wait CPL) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST1_DFX_0_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x251C) /* IOB TX NonPost Entry High32bit Status1(Wait CPL) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST1_DFX_1_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x255C) /* IOB TX NonPost Entry High32bit Status1(Wait CPL) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST1_DFX_2_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x259C) /* IOB TX NonPost Entry High32bit Status1(Wait CPL) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST2_DFX_0_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2520) /* IOB TX NonPost Entry Low32bit Status2(CPL Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST2_DFX_1_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2560) /* IOB TX NonPost Entry Low32bit Status2(CPL Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYL_ST2_DFX_2_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x25A0) /* IOB TX NonPost Entry Low32bit Status2(CPL Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST2_DFX_0_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2524) /* IOB TX NonPost Entry High32bit Status2(CPL Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST2_DFX_1_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2564) /* IOB TX NonPost Entry High32bit Status2(CPL Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_NP_ENTRYH_ST2_DFX_2_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x25A4) /* IOB TX NonPost Entry High32bit Status2(CPL Pending) DFX */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_0_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2600) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_1_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2610) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_2_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2620) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_3_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2630) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_4_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2640) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_5_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2650) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_6_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2660) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_7_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2670) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_8_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2680) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_9_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2690) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_10_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26A0) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_11_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26B0) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_12_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26C0) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_13_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26D0) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_14_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26E0) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_15_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26F0) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_16_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2700) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_17_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2710) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_18_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2720) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_CNT_DFX_19_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2730) /* IOB TX Non post send out counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2604) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2614) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_2_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2624) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_3_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2634) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_4_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2644) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_5_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2654) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_6_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2664) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_7_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2674) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_8_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2684) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_9_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2694) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_10_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26A4) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_11_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26B4) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_12_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26C4) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_13_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26D4) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_14_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26E4) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_15_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26F4) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_16_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2704) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_17_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2714) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_18_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2724) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_CNT_DFX_19_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2734) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2608) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2618) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_2_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2628) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_3_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2638) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_4_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2648) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_5_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2658) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_6_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2668) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_7_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2678) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_8_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2688) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_9_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2698) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_10_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26A8) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_11_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26B8) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_12_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26C8) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_13_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26D8) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_14_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26E8) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_15_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x26F8) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_16_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2708) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_17_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2718) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_18_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2728) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_ERR_CNT_DFX_19_REG      (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2738) /* IOB TX Non completion in counter of each port. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_LANTENCY_CTRL_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2780) /* IOB TX lantency control of each port register. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW_CTRL_REG           (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2784) /* IOB TX post bandwidth control of each port register. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW_CTRL_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2788) /* IOB TX non post bandwidth control of each port register. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW_CTRL_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x278C) /* IOB TX cpl bandwidth control of each port register. */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW0_DFX_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2800) /* IOB TX p bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW0_DFX_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2810) /* IOB TX p bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW0_DFX_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2820) /* IOB TX p bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW1_DFX_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2804) /* IOB TX p bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW1_DFX_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2814) /* IOB TX p bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW1_DFX_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2824) /* IOB TX p bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW2_DFX_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2808) /* IOB TX p bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW2_DFX_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2818) /* IOB TX p bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_P_BW2_DFX_2_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2828) /* IOB TX p bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW0_DFX_0_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2840) /* IOB TX np bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW0_DFX_1_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2850) /* IOB TX np bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW0_DFX_2_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2860) /* IOB TX np bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW1_DFX_0_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2844) /* IOB TX np bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW1_DFX_1_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2854) /* IOB TX np bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW1_DFX_2_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2864) /* IOB TX np bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW2_DFX_0_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2848) /* IOB TX np bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW2_DFX_1_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2858) /* IOB TX np bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_BW2_DFX_2_REG        (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2868) /* IOB TX np bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW0_DFX_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2880) /* IOB TX cpl bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW0_DFX_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2890) /* IOB TX cpl bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW0_DFX_2_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x28A0) /* IOB TX cpl bandwidth of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW1_DFX_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2884) /* IOB TX cpl bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW1_DFX_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2894) /* IOB TX cpl bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW1_DFX_2_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x28A4) /* IOB TX cpl bandwidth of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW2_DFX_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2888) /* IOB TX cpl bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW2_DFX_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2898) /* IOB TX cpl bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_CPL_BW2_DFX_2_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x28A8) /* IOB TX cpl bandwidth of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY0_DFX_0_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2900) /* IOB TX np lantency of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY0_DFX_1_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2910) /* IOB TX np lantency of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY0_DFX_2_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2920) /* IOB TX np lantency of each port.(minimum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY1_DFX_0_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2904) /* IOB TX np lantency of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY1_DFX_1_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2914) /* IOB TX np lantency of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY1_DFX_2_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2924) /* IOB TX np lantency of each port.(maximum) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY2_DFX_0_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2908) /* IOB TX np  lantency of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY2_DFX_1_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2918) /* IOB TX np  lantency of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TX_PORT_NP_LATENCY2_DFX_2_REG   (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x2928) /* IOB TX np  lantency of each port.(average) */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_NAT_RX_DISABLE_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3000) /* Disable send data to APP */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_INF_DFX_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3004) /* ib bar disp inf signals */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_ODR_NUM_DFX_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3008) /* core1 oder RX P and NP TLP number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_NAT_NUM_DFX_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x300C) /* native RX P and NP TLP number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_SDI_NUM_DFX_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3010) /* sdi RX P and NP TLP number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_ODR_RESP_NUM_DFX_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3014) /* oder P resp number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_SDI_NAT_RESP_NUM_DFX_REG (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3018) /* sdi and native P resp number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_ODR_NO_ACK_DFX_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x301C) /* core1 oder RX P and NP waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_NAT_NO_ACK_DFX_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3020) /* native RX P and NP waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_IB_BAR_SDI_NO_ACK_DFX_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3024) /* sdi RX P and NP waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_INF_DFX0_0_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3040) /* dwc tx np and rx cpl inf signals */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_INF_DFX0_1_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3080) /* dwc tx np and rx cpl inf signals */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_INF_DFX1_0_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3044) /* dwc rx req and tx cpl inf signals */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_INF_DFX1_1_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3084) /* dwc rx req and tx cpl inf signals */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_INF_DFX2_0_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3048) /* dwc rx req p resp and tx p inf signals */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_INF_DFX2_1_REG              (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3088) /* dwc rx req p resp and tx p inf signals */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_NUM_DFX_0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x304C) /* TX TLP P and P resp number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_NUM_DFX_1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x308C) /* TX TLP P and P resp number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_NP_CPL_NUM_DFX_0_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3050) /* TX TLP NP and RX TLP CPL number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_NP_CPL_NUM_DFX_1_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3090) /* TX TLP NP and RX TLP CPL number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_P_NUM_DFX_0_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3054) /* RX TLP P and P resp number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_P_NUM_DFX_1_REG          (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3094) /* RX TLP P and P resp number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_NP_CPL_NUM_DFX_0_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3058) /* RX TLP NP and TX TLP CPL number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_NP_CPL_NUM_DFX_1_REG     (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3098) /* RX TLP NP and TX TLP CPL number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_NO_ACK_DFX_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x305C) /* TX P and P resp waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_NO_ACK_DFX_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x309C) /* TX P and P resp waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_NP_CPL_NO_ACK_DFX_0_REG  (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3060) /* TX NP and RX CPL waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_NP_CPL_NO_ACK_DFX_1_REG  (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30A0) /* TX NP and RX CPL waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_REQ_CPL_NO_ACK_DFX_0_REG (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3064) /* RX REQ and TX CPL waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_REQ_CPL_NO_ACK_DFX_1_REG (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30A4) /* RX REQ and TX CPL waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_P_BRESP_NO_ACK_DFX_0_REG (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3068) /* RX P resp waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_RX_P_BRESP_NO_ACK_DFX_1_REG (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30A8) /* RX P resp waiting ready time */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_NP_CPL_ERR_NUM_DFX_0_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x306C) /* TX and RX NP, CPL err TLP number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_NP_CPL_ERR_NUM_DFX_1_REG    (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30AC) /* TX and RX NP, CPL err TLP number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_P_ERR_NUM_DFX_0_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3070) /* TX and RX P error TLP number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_P_ERR_NUM_DFX_1_REG         (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30B0) /* TX and RX P error TLP number */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_ID_ST_DFX0_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3074) /* TX P ID state low 32bits */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_ID_ST_DFX0_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30B4) /* TX P ID state low 32bits */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_ID_ST_DFX1_0_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x3078) /* TX P ID state [63:32] bits */
#define PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_DWC_TX_P_ID_ST_DFX1_1_REG       (PCIe_HIPCIEC_AP_IOB_TX_REG_BASE + 0x30B8) /* TX P ID state [63:32] bits */

#endif // __HIPCIEC_AP_IOB_TX_REG_REG_OFFSET_H__
