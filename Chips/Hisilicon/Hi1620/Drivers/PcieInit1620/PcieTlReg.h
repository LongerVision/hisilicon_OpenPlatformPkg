// ******************************************************************************
// Copyright     :  Copyright (C) 2017, Hisilicon Technologies Co. Ltd.
// File name     :  hipciec_tl_reg_reg_offset.h
// Project line  :  Platform And Key Technologies Development
// Department    :  CAD Development Department
// Author        :  xxx
// Version       :  1.0
// Date          :  2016/3/10
// Description   :  The description of xxx project
// Others        :  Generated automatically by nManager V4.1
// History       :  xxx 2017/05/20 11:23:39 Create file
// ******************************************************************************

#ifndef __HIPCIEC_TL_REG_REG_OFFSET_H__
#define __HIPCIEC_TL_REG_REG_OFFSET_H__

/* HIPCIEC_TL_REG Base address of Module's Register */
#define PCIe_HIPCIEC_TL_REG_BASE                       (0x000)

/******************************************************************************/
/*                      PCIe HIPCIEC_TL_REG Registers' Definitions            */
/******************************************************************************/

#define PCIe_HIPCIEC_TL_REG_TL_TX_CTRL_REG                    (PCIe_HIPCIEC_TL_REG_BASE + 0x0)   /* Transaction Layer source arbiter control */
#define PCIe_HIPCIEC_TL_REG_TL_ENGIEN_STATUS_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x4)   /* tl tx status registers */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CHECK_EN_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x8)   /* Error detct optional checker enable */
#define PCIe_HIPCIEC_TL_REG_TL_BASE_LIMT_CHECK__EN_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0xC)   /* Control the base/limit check register */
#define PCIe_HIPCIEC_TL_REG_TL_NAT_BAR_ADDRESS_CONTROL_REG    (PCIe_HIPCIEC_TL_REG_BASE + 0x10)  /* TL bar address for native */
#define PCIe_HIPCIEC_TL_REG_TL_ASPM_IDLE_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x100) /* ASPM self-launch control register */
#define PCIe_HIPCIEC_TL_REG_TL_ASPM_IDLE_EN_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x104) /* ASPM self-launch control register */
#define PCIe_HIPCIEC_TL_REG_TL_PM_DC_CTRL_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0x108) /* Power management DC control */
#define PCIe_HIPCIEC_TL_REG_TL_PM_STATE_REG                   (PCIe_HIPCIEC_TL_REG_BASE + 0x10C) /* Power management state */
#define PCIe_HIPCIEC_TL_REG_TL_PM_UC_CTRL_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0x114) /* Power management RX control */
#define PCIe_HIPCIEC_TL_REG_TL_ENTER_L0_CTRL_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x118) /* Power management wake up control */
#define PCIe_HIPCIEC_TL_REG_TL_PM_TIMEOUT_CTRL_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0x11C) /* Power management timeout control */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR0_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x300) /* Physical function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR0_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x304) /* Physical function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR0_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x308) /* Physical function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR0_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x30C) /* Physical function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR1_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x320) /* Physical function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR1_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x324) /* Physical function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR1_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x328) /* Physical function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR1_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x32C) /* Physical function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR2_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x340) /* Physical function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR2_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x344) /* Physical function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR2_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x348) /* Physical function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR2_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x34C) /* Physical function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR3_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x360) /* Physical function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR3_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x364) /* Physical function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR3_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x368) /* Physical function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR3_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x36C) /* Physical function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR4_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x380) /* Physical function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR4_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x384) /* Physical function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR4_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x388) /* Physical function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR4_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x38C) /* Physical function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR5_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3A0) /* Physical function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR5_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3A4) /* Physical function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR5_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3A8) /* Physical function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BAR5_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3AC) /* Physical function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR0_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3C0) /* Virtual function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR0_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3C4) /* Virtual function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR0_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3C8) /* Virtual function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR0_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3CC) /* Virtual function n BAR0 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR1_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3E0) /* Virtual function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR1_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3E4) /* Virtual function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR1_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3E8) /* Virtual function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR1_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x3EC) /* Virtual function n BAR1 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR2_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x400) /* Virtual function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR2_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x404) /* Virtual function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR2_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x408) /* Virtual function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR2_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x40C) /* Virtual function n BAR2 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR3_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x420) /* Virtual function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR3_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x424) /* Virtual function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR3_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x428) /* Virtual function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR3_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x42C) /* Virtual function n BAR3 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR4_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x440) /* Virtual function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR4_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x444) /* Virtual function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR4_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x448) /* Virtual function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR4_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x44C) /* Virtual function n BAR4 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR5_MASK_0_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x460) /* Virtual function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR5_MASK_1_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x464) /* Virtual function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR5_MASK_2_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x468) /* Virtual function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_VFN_BAR5_MASK_3_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x46C) /* Virtual function n BAR5 mask */
#define PCIe_HIPCIEC_TL_REG_PFN_BARN_ENABLE_0_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x478) /* Physical function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_PFN_BARN_ENABLE_1_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x47C) /* Physical function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_PFN_BARN_ENABLE_2_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x480) /* Physical function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_PFN_BARN_ENABLE_3_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x484) /* Physical function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_PFN_BARN_ENABLE_4_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x488) /* Physical function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_PFN_BARN_ENABLE_5_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x48C) /* Physical function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_VFN_BARN_ENABLE_0_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x490) /* Virtual function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_VFN_BARN_ENABLE_1_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x494) /* Virtual function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_VFN_BARN_ENABLE_2_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x498) /* Virtual function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_VFN_BARN_ENABLE_3_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x49C) /* Virtual function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_VFN_BARN_ENABLE_4_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x4A0) /* Virtual function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_VFN_BARN_ENABLE_5_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x4A4) /* Virtual function n BAR enable */
#define PCIe_HIPCIEC_TL_REG_PFN_ROM_MASK_0_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x4B0) /* Physical function n extended ROM mask */
#define PCIe_HIPCIEC_TL_REG_PFN_ROM_MASK_1_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x4B4) /* Physical function n extended ROM mask */
#define PCIe_HIPCIEC_TL_REG_PFN_ROM_MASK_2_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x4B8) /* Physical function n extended ROM mask */
#define PCIe_HIPCIEC_TL_REG_PFN_ROM_MASK_3_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x4BC) /* Physical function n extended ROM mask */
#define PCIe_HIPCIEC_TL_REG_PFN_ROM_ENABLE_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x4D0) /* Physical function n extended ROM enable */
#define PCIe_HIPCIEC_TL_REG_TL_CFG_SPACE_CTRL_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x4D4) /* TL CFGSPACE control register */
#define PCIe_HIPCIEC_TL_REG_TL_CFG_SPACE_PF_CTRL_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0x4D8) /* PF SUPPORT ENABLE */
#define PCIe_HIPCIEC_TL_REG_TL_CFG_SPACE_VF_NUM_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x4DC) /* PF SUPPORT NUKMBER */
#define PCIe_HIPCIEC_TL_REG_SYSTEM_ERR_OVERRIDE_CONTROL_REG   (PCIe_HIPCIEC_TL_REG_BASE + 0x4E4) /* SYSTEM ERROR CONTROL REGISTER FOR ROOT PORT */
#define PCIe_HIPCIEC_TL_REG_TL_CFG_HCK_EN_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0x4E8) /* Control the RW/RO attributes of HCK warning register */
#define PCIe_HIPCIEC_TL_REG_TL_CFGSPACE_SEL_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x4EC) /* Select CFGSPACE Function */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_0_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x500) /* VF FLR occur interrupt mask,VF0~VF31 */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_0_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x504) /* VF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_1_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x508) /* VF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_1_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x50C) /* VF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_2_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x510) /* VF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_2_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x514) /* VF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_3_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x518) /* VF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_3_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x51C) /* VF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_4_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x520) /* VF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_4_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x524) /* FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_5_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x528) /* VF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_5_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x52C) /* VF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_6_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x530) /* VF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_6_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x534) /* VF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_MASK_7_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x538) /* VF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_FLR_INT_STATUS_7_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x53C) /* VF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_PF_FLR_INT_MASK_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x540) /* PF FLR occur interrupt mask */
#define PCIe_HIPCIEC_TL_REG_PF_FLR_INT_STATUS_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x544) /* PF FLR occur interrupt status */
#define PCIe_HIPCIEC_TL_REG_PF_FLR_EN_REG                     (PCIe_HIPCIEC_TL_REG_BASE + 0x548) /* Enable PF  level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_0_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x54C) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_1_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x550) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_2_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x554) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_3_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x558) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_4_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x55C) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_5_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x560) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_6_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x564) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_FLR_EN_7_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x568) /* Enable VF level reset as SPEC description */
#define PCIe_HIPCIEC_TL_REG_TL_INT_STATUS0_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x56C) /* TL TX interrupt status */
#define PCIe_HIPCIEC_TL_REG_TL_INT_STATUS1_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x570) /* TL TX interrupt status */
#define PCIe_HIPCIEC_TL_REG_TL_INT_MASK0_REG                  (PCIe_HIPCIEC_TL_REG_BASE + 0x574) /* transaction layer tx interrupt mask */
#define PCIe_HIPCIEC_TL_REG_TL_INT_SET0_REG                   (PCIe_HIPCIEC_TL_REG_BASE + 0x578) /* transaction layer tx interrupt set register */
#define PCIe_HIPCIEC_TL_REG_TL_INT_RO0_REG                    (PCIe_HIPCIEC_TL_REG_BASE + 0x57C) /* transaction layer tx interrupt indicater status */
#define PCIe_HIPCIEC_TL_REG_TL_INT_MASK1_REG                  (PCIe_HIPCIEC_TL_REG_BASE + 0x580) /* transaction layer tx interrupt mask */
#define PCIe_HIPCIEC_TL_REG_TL_INT_SET1_REG                   (PCIe_HIPCIEC_TL_REG_BASE + 0x584) /* transaction layer tx interrupt set register */
#define PCIe_HIPCIEC_TL_REG_TL_INT_RO1_REG                    (PCIe_HIPCIEC_TL_REG_BASE + 0x588) /* transaction layer tx interrupt indicater status */
#define PCIe_HIPCIEC_TL_REG_TL_FLR_INT_SEL_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x58C) /* Where the FLR interrupt is report. To IEP or CORE interrupt line */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ATOMIC_BLK_CNT_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0x900) /* TL TX atomic block error counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_PFX_BLK_CNT_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x904) /* TL TX prefix block error counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_MEM_RD_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x908) /* TL TX memory read  counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_MEM_WR_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x90C) /* TL TX memory write counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CFG_RD_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x910) /* TL TX CFG read counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CFG_WR_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x914) /* TL TX CFG write counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_IO_RD_CNT_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x918) /* TL TX IO read counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_IO_WR_CNT_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x91C) /* TL TX IO write counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_POISON_BLK_CNT_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0x920) /* TL TX poison block error counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_MSG_CNT_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0x924) /* TL TX  message counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_UR_CNT_REG                  (PCIe_HIPCIEC_TL_REG_BASE + 0x928) /* TL TX UR error counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_GEN_CPL_CNT_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x92C) /* TL TX native gen CPL counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ERR_CNT_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0x930) /* TL TX CPL counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CCIX_CNT_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x934) /* TL TX CCIX counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ATOMIC_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x938) /* TL TX atomic counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_P2P_CNT_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0x93C) /* TL TX peer2peer TLP counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_FUN_TLP_TLP_CNT_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0x940) /* TL TX function TLP number counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_FUN_PAYLOAD_CNT_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0x944) /* TL TX function TLP payload counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_FUN_ALL_DW_CNT_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0x948) /* TL TX function TLP ALL DW counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_0_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x94C) /* TL TX capture or insert field in TLP, The DW0 field of header */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_1_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x950) /* TL TX capture or insert field in TLP, The DW1 field of header */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_2_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x954) /* TL TX capture or insert field in TLP, The DW2 field of header */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_3_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x958) /* TL TX capture or insert field in TLP, The DW3 field of header */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_MAP_0_REG       (PCIe_HIPCIEC_TL_REG_BASE + 0x95C) /* TL TX capture or insert field in TLP, The DW0 field mask of header */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_MAP_1_REG       (PCIe_HIPCIEC_TL_REG_BASE + 0x960) /* TL TX capture or insert field in TLP, The DW1 field mask of header */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_MAP_2_REG       (PCIe_HIPCIEC_TL_REG_BASE + 0x964) /* TL TX capture or insert field in TLP, The DW2 field mask of header */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_FIELD_MAP_3_REG       (PCIe_HIPCIEC_TL_REG_BASE + 0x968) /* TL TX capture or insert field in TLP, The DW3 field mask of header */
#define PCIe_HIPCIEC_TL_REG_TL_CNT_CTRL_REG                   (PCIe_HIPCIEC_TL_REG_BASE + 0x96C) /* Traffic monitor control */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CNT_ST_REG                  (PCIe_HIPCIEC_TL_REG_BASE + 0x970) /* Traffic monitor status */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_HED_0_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x974) /* TL TX have capture header DW0 */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_HED_1_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x978) /* TL TX have capture header DW1 */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_HED_2_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x97C) /* TL TX have capture header DW2 */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CAPTU_HED_3_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0x980) /* TL TX have capture header DW3 */
#define PCIe_HIPCIEC_TL_REG_TL_TX_DL_BP_CNT_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0x990) /* TL TX and DL, backpressure clock cycle */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_CTRL_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0x994) /* Software postTLP generater */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_HEADER0_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0x998) /* tlp header DW0 */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_HEADER1_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0x99C) /* tlp header DW1 */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_HEADER2_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0x9A0) /* tlp header DW2 */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_HEADER3_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0x9A4) /* tlp header DW3 */
#define PCIe_HIPCIEC_TL_REG_TL_TLP_FUN_SEL_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x9A8) /* message function selection */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_DATA0_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x9AC) /* Payload DW 0 */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_DATA1_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x9B0) /* Payload DW 1 */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_DATA2_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x9B4) /* Payload DW 2 */
#define PCIe_HIPCIEC_TL_REG_TL_INSERT_TLP_DATA3_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x9B8) /* Payload DW 3 */
#define PCIe_HIPCIEC_TL_REG_TL_TX_TH_REG                      (PCIe_HIPCIEC_TL_REG_BASE + 0x9BC) /* tl tx and ap depth */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ECC_CFG_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0x9C0) /* TL TX SRAM ECC configure */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ECC_1BIT_ERR_ADDR_REG       (PCIe_HIPCIEC_TL_REG_BASE + 0x9C4) /* TL TX SRAM ECC 1bit error, the SRAM address */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ECC_2BIT_ERR_ADDR_REG       (PCIe_HIPCIEC_TL_REG_BASE + 0x9C8) /* TL TX SRAM ECC 2bit error, the SRAM address */
#define PCIe_HIPCIEC_TL_REG_TL_TX_VC0_P_FC_LEFT_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x9CC) /* VC0 P header  and data flow credit left valud */
#define PCIe_HIPCIEC_TL_REG_TL_TX_VC0_NP_FC_LEFT_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0x9D0) /* VC0 NP header  and data flow credit left valud */
#define PCIe_HIPCIEC_TL_REG_TL_TX_VC0_CPL_FC_LEFT_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0x9D4) /* VC0 CPL header  and data flow credit left valud */
#define PCIe_HIPCIEC_TL_REG_TL_TX_VC1_P_FC_LEFT_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0x9D8) /* CCIX VC P header  and data flow credit left valud */
#define PCIe_HIPCIEC_TL_REG_TL_TX_TC_MAPERR_TC_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0x9DC) /* when TC map VC is error, remembor the error TLP's TC. */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ERR_ERROR_STATUS_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0x9E0) /* TL TX ERR ERROR STATUS */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ECC_1BIT_ERR_CNT_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0x9E4) /* TL TX 1bit ECC Error counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_ECC_2BIT_ERR_CNT_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0x9E8) /* TL TX 2bit ECC Error counter */
#define PCIe_HIPCIEC_TL_REG_TL_TX_CCIX_SP_EN_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0x9EC) /* TL TX CCIX have higher priority. */
#define PCIe_HIPCIEC_TL_REG_TL_TX_FIFO_STS_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0x9F0) /* TL TX FIFO empty and full */
#define PCIe_HIPCIEC_TL_REG_TL_RX_VC0_POST_CREDIT_LEFT_REG    (PCIe_HIPCIEC_TL_REG_BASE + 0xB00) /* VC0_POST_CREDIT */
#define PCIe_HIPCIEC_TL_REG_TL_RX_VC0_NONPOST_CREDIT_LEFT_REG (PCIe_HIPCIEC_TL_REG_BASE + 0xB04) /* VC0_NONPOST_CREDIT */
#define PCIe_HIPCIEC_TL_REG_TL_RX_VC0_CPL_CREDIT_LEFT_REG     (PCIe_HIPCIEC_TL_REG_BASE + 0xB08) /* VC0_CPL_CREDIT */
#define PCIe_HIPCIEC_TL_REG_TL_RX_VC1_POST_CREDIT_LEFT_REG    (PCIe_HIPCIEC_TL_REG_BASE + 0xB0C) /* VC1_POST_CREDIT */
#define PCIe_HIPCIEC_TL_REG_RX_RX_BUFFER_STATUS_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0xB18) /* RX BUFFER FIFO STATUS */
#define PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0xB1C) /* TL RX CREDIT POSTED TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_REG       (PCIe_HIPCIEC_TL_REG_BASE + 0xB20) /* TL RX CREDIT NON_POSTED TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xB24) /* TL RX CREDIT CPL TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xB28) /* TL RX CREDIT reconfigure enable */
#define PCIe_HIPCIEC_TL_REG_TL_RX_ERR_CNT_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0xB2C) /* RX Error counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_NULL_CNT_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0xB30) /* RX null/dl Error counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_UR_CPL_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xB34) /* RX generate UR CPL Error counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_TOTAL_CNT_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0xB38) /* RX received total tlp counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_TOTAL_TR_CNT_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0xB3C) /* RX total sending tlps counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_DROP_CNT_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0xB40) /* RX drop tlps counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_POST_CNT_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0xB44) /* RX post tlp counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_NONPOST_CNT_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0xB48) /* RX non-post tlp counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CNT_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0xB4C) /* RX completion tlp counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_ERRCPL_CNT_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xB50) /* RX completion tlp status is CRS/UR/CA counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CCIX_CNT_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0xB54) /* RX completion tlp status is CRS counter */
#define PCIe_HIPCIEC_TL_REG_RX_PAYLOAD_CNT_CTRL_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0xB58) /* rx tlp payload count control */
#define PCIe_HIPCIEC_TL_REG_RX_MWR_PAYLOAD_COUNTER_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0xB5C) /* rx memory write tlp payload counter */
#define PCIe_HIPCIEC_TL_REG_RX_CPL_PAYLOAD_COUNTER_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0xB60) /* rx completion tlp payload counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CMP_EN_REG                  (PCIe_HIPCIEC_TL_REG_BASE + 0xB64) /* trace spcify info enable,and inbound or outbound select */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CMP_HED_DW0_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0xB68) /* trace header bit 0 to 31 */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CMP_HED_DW1_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0xB6C) /* trace header bit 32 to 63 */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CMP_HED_DW2_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0xB70) /* trace header bit 64 to 95 */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CMP_HED_DW3_REG             (PCIe_HIPCIEC_TL_REG_BASE + 0xB74) /* trace header bit 96 to 127 */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CAPTURED_HEADR_0DW_REG      (PCIe_HIPCIEC_TL_REG_BASE + 0xB78) /* Captured the  first header 0 DW data */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CAPTURED_HEADR_1DW_REG      (PCIe_HIPCIEC_TL_REG_BASE + 0xB7C) /* Captured the  first header 1 DW data */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CAPTURED_HEADR_2DW_REG      (PCIe_HIPCIEC_TL_REG_BASE + 0xB80) /* Captured the  first header 2 DW data */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CAPTURED_HEADR_3DW_REG      (PCIe_HIPCIEC_TL_REG_BASE + 0xB84) /* Captured the  first header 3 DW data */
#define PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0xB88) /* TL RX CREDIT POSTED TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG    (PCIe_HIPCIEC_TL_REG_BASE + 0xB8C) /* TL RX CREDIT NON_POSTED TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0xB90) /* TL RX CREDIT CPL TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_DF_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0xB94) /* TL RX CREDIT reconfigure enable */
#define PCIe_HIPCIEC_TL_REG_RX_ASYN_STONE_FIFO_STATUS_REG     (PCIe_HIPCIEC_TL_REG_BASE + 0xB98) /* The asyn and stone fifo of tl rx */
#define PCIe_HIPCIEC_TL_REG_TL_RX_ERR_STATUS_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xB9C) /* TL RX ERROR STATUS */
#define PCIe_HIPCIEC_TL_REG_TL_RX_ECC_ERROR_STATUS_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0xBA0) /* tl rx ecc error status */
#define PCIe_HIPCIEC_TL_REG_TL_RX_BP_CTRL_REG                 (PCIe_HIPCIEC_TL_REG_BASE + 0xBA4) /* tl rx back preture signal */
#define PCIe_HIPCIEC_TL_REG_TL_RX_ECC_1BIT_ERR_CNT_REG        (PCIe_HIPCIEC_TL_REG_BASE + 0xBA8) /* TL RX 1bit ECC Error counter */
#define PCIe_HIPCIEC_TL_REG_TL_RX_ECC_1BIT_ERR_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0xBAC) /* TL ecc 1bit error report */
#define PCIe_HIPCIEC_TL_REG_TL_ECC_2BIT_ERR_CNT_REG           (PCIe_HIPCIEC_TL_REG_BASE + 0xBB0) /* RX buffer 2bit ECC Error counter */
#define PCIe_HIPCIEC_TL_REG_TL_ECC_2BIT_ERR_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0xBB4) /* tl rx buffer ecc 2bit error report */
#define PCIe_HIPCIEC_TL_REG_TL_RX_INSERT_ECC_ERR_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0xBB8) /* tl rx insert ECC error */
#define PCIe_HIPCIEC_TL_REG_MSIX_CONTROL_REG_0_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0xE00) /* MSIX CONTROL REGISTER */
#define PCIe_HIPCIEC_TL_REG_MSIX_CONTROL_REG_1_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0xE04) /* MSIX CONTROL REGISTER */
#define PCIe_HIPCIEC_TL_REG_MSIX_CONTROL_REG_2_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0xE08) /* MSIX CONTROL REGISTER */
#define PCIe_HIPCIEC_TL_REG_MSIX_CONTROL_REG_3_REG            (PCIe_HIPCIEC_TL_REG_BASE + 0xE0C) /* MSIX CONTROL REGISTER */
#define PCIe_HIPCIEC_TL_REG_MSIX_OFFSET_BIR_REG_0_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0xE10) /* MSIX OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_MSIX_OFFSET_BIR_REG_1_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0xE14) /* MSIX OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_MSIX_OFFSET_BIR_REG_2_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0xE18) /* MSIX OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_MSIX_OFFSET_BIR_REG_3_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0xE1C) /* MSIX OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_PBA_OFFSET_BIR_REG_0_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0xE20) /* PBA OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_PBA_OFFSET_BIR_REG_1_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0xE24) /* PBA OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_PBA_OFFSET_BIR_REG_2_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0xE28) /* PBA OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_PBA_OFFSET_BIR_REG_3_REG          (PCIe_HIPCIEC_TL_REG_BASE + 0xE2C) /* PBA OFFSET AND BIR REGISTER */
#define PCIe_HIPCIEC_TL_REG_TL_CFGSPACE_BDF_REG               (PCIe_HIPCIEC_TL_REG_BASE + 0xE30) /* TL CFGSPACE BUS NUMBER AND DEVICE NUMBER */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_RX_POSTED_CREDIT_DF_REG   (PCIe_HIPCIEC_TL_REG_BASE + 0xF00) /* TL CCIX RX CREDIT POSTED TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_RX_CDT_INI_UP_DF_REG      (PCIe_HIPCIEC_TL_REG_BASE + 0xF04) /* TL CCIX RX CREDIT POSTED TLP INITIAL CONTROL */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_VDR_ID_REG                (PCIe_HIPCIEC_TL_REG_BASE + 0xF08) /* ccix vendor ID */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_VC_POST_CREDIT_LEFT_REG   (PCIe_HIPCIEC_TL_REG_BASE + 0xF0C) /* CCIX VC_POST_CREDIT */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_RX_POSTED_CREDIT_REG      (PCIe_HIPCIEC_TL_REG_BASE + 0xF10) /* TL CCIX RX CREDIT POSTED TLP INITIAL SIZE */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_RX_CDT_INI_UP_REG         (PCIe_HIPCIEC_TL_REG_BASE + 0xF14) /* TL CCIX RX CREDIT POSTED TLP INITIAL CONTROL */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_HEAD_DW0_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xF18) /* TL CCIX ERROR HEADER LOG DW0 */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_HEAD_DW1_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xF1C) /* TL CCIX ERROR HEADER LOG DW1 */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_HEAD_DW2_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xF20) /* TL CCIX ERROR HEADER LOG DW2 */
#define PCIe_HIPCIEC_TL_REG_TL_CCIX_HEAD_DW3_REG              (PCIe_HIPCIEC_TL_REG_BASE + 0xF24) /* TL CCIX ERROR HEADER LOG DW3 */
#define PCIe_HIPCIEC_TL_REG_ECO_TL_REG                        (PCIe_HIPCIEC_TL_REG_BASE + 0xFFF) /* Add some registers for eco. */

#endif // __HIPCIEC_TL_REG_REG_OFFSET_H__
