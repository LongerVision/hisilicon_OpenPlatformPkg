// ******************************************************************************
// Copyright     :  Copyright (C) 2017, Hisilicon Technologies Co. Ltd.
// File name     :  hipciec_rp_cfgspace_reg_offset.h
// Project line  :  Platform And Key Technologies Development
// Department    :  CAD Development Department
// Author        :  xxx
// Version       :  1.0
// Date          :  2016/3/10
// Description   :  The description of xxx project
// Others        :  Generated automatically by nManager V4.1
// History       :  xxx 2017/05/20 11:23:39 Create file
// ******************************************************************************

#ifndef __HIPCIEC_RP_CFGSPACE_REG_OFFSET_H__
#define __HIPCIEC_RP_CFGSPACE_REG_OFFSET_H__

/* HIPCIEC_RP_CFGSPACE Base address of Module's Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_BASE                       (0x000)

/******************************************************************************/
/*                      PCIe HIPCIEC_RP_CFGSPACE Registers' Definitions       */
/******************************************************************************/

#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_ID_REG                       (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x0)   /* This register specify the register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CMDSTS_REG                   (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x4)   /* This register specify the register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG                   (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x8)   /* This register specify the register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_MISC_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0xC)   /* This register specify the register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_BAR0_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x10)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_BAR1_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x14)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_BUS_NUM_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x18)  /* This register specify the base bus number of config space type1. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_IO_LIMIT_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x1C)  /* This register specify the IO limit or second status config space type1. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_MEM_BASE_LIMIT_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x20)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_PRE_MEM_BASE_LIMIT_REG       (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x24)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_PRE_MEM_BASE_32_UPADR_REG    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x28)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_PRE_MEM_LIMIT_32_UPADR_REG   (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x2C)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_IO_UPADR_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x30)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CAPPTR_REG                   (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x34)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_EXP_ROM_BASE_REG             (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x38)  /* This register specify expasion rom base address of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_INT_REG                      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x3C)  /* This register specify the base address register of config space. */
#define PCIe_HIPCIEC_RP_CFGSPACE_PCIE_CAP_HEADER_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x40)  /* This is the pcie capability header register */
#define PCIe_HIPCIEC_RP_CFGSPACE_DEVICE_CAPBILITY_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x44)  /* This register describe the device capability */
#define PCIe_HIPCIEC_RP_CFGSPACE_DEVICE_CTRL_STATUS_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x48)  /* device control status register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CAPBILITY_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x4C)  /* Link capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CTRL_STATUS_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x50)  /* Link control register */
#define PCIe_HIPCIEC_RP_CFGSPACE_SLOT_CAPABILITY_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x54)  /* Slot capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_SLOT_CTRL_STATUS_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x58)  /* Slot control and status register */
#define PCIe_HIPCIEC_RP_CFGSPACE_ROOT_CTRL_STATUS_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x5C)  /* Root control status */
#define PCIe_HIPCIEC_RP_CFGSPACE_ROOT_STATUS_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x60)  /* Root status register */
#define PCIe_HIPCIEC_RP_CFGSPACE_DEVICE_CAPABILITY2_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x64)  /* device capability 2 register */
#define PCIe_HIPCIEC_RP_CFGSPACE_DEVICE_CTRL2_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x68)  /* Device control register 2 */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CAPABILITY2_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6C)  /* Link capability 2 */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CTRL_STATUS2_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x70)  /* Link control and status 2 */
#define PCIe_HIPCIEC_RP_CFGSPACE_SLOT_CAP_2_REG                      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x74)  /* Slot Capabilities 2 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_SLOT_CTRL_2_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x78)  /* Slot Control 2 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_MSI_CAP_HEADER_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x80)  /* MSI control and ID regisiter */
#define PCIe_HIPCIEC_RP_CFGSPACE_MSI_LADDR_REG                       (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x84)  /* MSI low address */
#define PCIe_HIPCIEC_RP_CFGSPACE_MSI_HADDR_REG                       (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x88)  /* MSI uppr address */
#define PCIe_HIPCIEC_RP_CFGSPACE_MSI_DATA_REG                        (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x8C)  /* MSI data register */
#define PCIe_HIPCIEC_RP_CFGSPACE_MSI_MASK_REG                        (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x90)  /* MSI mask register */
#define PCIe_HIPCIEC_RP_CFGSPACE_MSI_PENDING_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x94)  /* MSI pending register */
#define PCIe_HIPCIEC_RP_CFGSPACE_PME_CAP_HEADER_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0xB0)  /* PME capability header and PME control */
#define PCIe_HIPCIEC_RP_CFGSPACE_PME_STATUS_REG                      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0xB4)  /* Power management status register */
#define PCIe_HIPCIEC_RP_CFGSPACE_SID_CAP_HEADER_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0xD0)  /* subsystem id capability header */
#define PCIe_HIPCIEC_RP_CFGSPACE_SSVID_SSID_REG                      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0xD4)  /* SSVID and SSID */
#define PCIe_HIPCIEC_RP_CFGSPACE_AER_CAP_HEADER_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x100) /* Advance Error Report capability header */
#define PCIe_HIPCIEC_RP_CFGSPACE_UNCR_ERR_STATUS_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x104) /* uncorrectable error status */
#define PCIe_HIPCIEC_RP_CFGSPACE_UNCR_ERR_MASK_REG                   (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x108) /* uncorrectable error mask */
#define PCIe_HIPCIEC_RP_CFGSPACE_UNCR_ERR_SEVERITY_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x10C) /* uncorrectable error serverity */
#define PCIe_HIPCIEC_RP_CFGSPACE_COR_ERR_STATUS_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x110) /* Correctable error status */
#define PCIe_HIPCIEC_RP_CFGSPACE_COR_ERR_MASK_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x114) /* correctable error mask */
#define PCIe_HIPCIEC_RP_CFGSPACE_ADVACD_CAP_CTRL_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x118) /* advanced error capabilities and control register */
#define PCIe_HIPCIEC_RP_CFGSPACE_FIRST_HEADER_LOG_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x11C) /* First DW header log */
#define PCIe_HIPCIEC_RP_CFGSPACE_SECOND_HEADER_LOG_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x120) /* Second DW header log */
#define PCIe_HIPCIEC_RP_CFGSPACE_THIRD_HEADER_LOG_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x124) /* Third DW header log */
#define PCIe_HIPCIEC_RP_CFGSPACE_FOUR_HEADER_LOG_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x128) /* Forth DW header log */
#define PCIe_HIPCIEC_RP_CFGSPACE_ROOT_ERROR_COMMAND_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x12C) /* Root error report command */
#define PCIe_HIPCIEC_RP_CFGSPACE_ROOT_ERROR_STATUS_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x130) /* Roor Error status */
#define PCIe_HIPCIEC_RP_CFGSPACE_ERR_SOURCE_IDEN_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x134) /* Erorr soure identification register */
#define PCIe_HIPCIEC_RP_CFGSPACE_FIRST_PREFIX_LOG_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x138) /* First DW prefix log */
#define PCIe_HIPCIEC_RP_CFGSPACE_SECOND_PREFIX_LOG_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x13C) /* Second DW prefix log */
#define PCIe_HIPCIEC_RP_CFGSPACE_THIRD_PREFIX_LOG_REG                (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x140) /* Third DW prefix log */
#define PCIe_HIPCIEC_RP_CFGSPACE_FOUR_PREFIX_LOG_REG                 (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x144) /* Forth DW prefix log */
#define PCIe_HIPCIEC_RP_CFGSPACE_TPH_EXTEND_CAP_REG                  (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x2A0) /* pcie tph extended capability header */
#define PCIe_HIPCIEC_RP_CFGSPACE_TPH_REQ_CAP_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x2A4) /* tph request capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_TPH_REQ_CTRL_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x2A8) /* tph requester control register */
#define PCIe_HIPCIEC_RP_CFGSPACE_SECONDARY_PCIE_EXT_CAP_HED_REG      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x310) /* Secondary PCI Express Extended Capability Header */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER_REG          (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x314) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LANE_ERROR_STATUS_REG_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x318) /* Lane Error Status Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER01_REG        (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x31C) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER23_REG        (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x320) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER45_REG        (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x324) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER67_REG        (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x328) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER89_REG        (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x32C) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER1011_REG      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x330) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER1213_REG      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x334) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_LINK_CONTROL3_REGISTER1415_REG      (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x338) /* Link Control 3 Register */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X00_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x400) /* PCI Express Extend Capability Header of VC */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X04_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x404) /* The Port VC Capability register 1 */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X08_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x408) /* The Port VC Capability register 2 */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X0C_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x40C) /* Port VC Control and Status register */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X10_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x410) /* VC0 Resource Capability */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X14_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x414) /* VC0 Resource Control */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X18_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x418) /* VC0 Resource Status */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X1C_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x41C) /* VC1 Resource Capability */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X20_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x420) /* VC0 Resource Control */
#define PCIe_HIPCIEC_RP_CFGSPACE_VC_CAP_0X24_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x424) /* VC0 Resource Status */
#define PCIe_HIPCIEC_RP_CFGSPACE_DEVICE_SERIAL_NUMBER_CAP_HEADER_REG (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x4E0) /* device serial number extended capability header */
#define PCIe_HIPCIEC_RP_CFGSPACE_SERIAL_LNUM_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x4E4) /* serial low number register */
#define PCIe_HIPCIEC_RP_CFGSPACE_SERIAL_HNUM_REG                     (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x4E8) /* serial high number register */
#define PCIe_HIPCIEC_RP_CFGSPACE_ACS_CAP_0X00_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x630) /* ACS capability register 00 */
#define PCIe_HIPCIEC_RP_CFGSPACE_ACS_CAP_0X04_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x634) /* ACS capability register 04 */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X00_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x680) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X04_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x684) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X08_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x688) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X0C_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x68C) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X10_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x690) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X14_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x694) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X18_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x698) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X1C_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x69C) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X20_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6A0) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X24_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6A4) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X28_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6A8) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X2C_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6AC) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X30_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6B0) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X34_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6B4) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X38_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6B8) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X3C_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6BC) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X40_REG                    (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x6C0) /* Downstream Port Containment CAP */
#define PCIe_HIPCIEC_RP_CFGSPACE_DL_FEATURE_CAP_REG00_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x700) /* DL feature capability register 00 */
#define PCIe_HIPCIEC_RP_CFGSPACE_DL_FEATURE_CAP_REG04_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x704) /* DL feature capability register 04 */
#define PCIe_HIPCIEC_RP_CFGSPACE_DL_FEATURE_CAP_REG08_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x708) /* DL feature capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG00_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x70C) /* RX Margin capability register 00 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG04_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x710) /* RX Margin capability register 04 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_0_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x714) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_1_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x718) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_2_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x71C) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_3_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x720) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_4_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x724) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_5_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x728) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_6_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x72C) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_7_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x730) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_8_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x734) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_9_REG            (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x738) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_10_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x73C) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_11_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x740) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_12_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x744) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_13_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x748) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_14_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x74C) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_RXMARGIN_CAP_REG08_15_REG           (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x750) /* RX Margin capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG00_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x800) /* CCIX transport capability register 00 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG04_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x804) /* CCIX transport capability register 04 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG08_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x808) /* CCIX transport capability register 08 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG0C_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x80C) /* CCIX transport capability register 0C */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG10_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x810) /* CCIX transport capability register 10 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG14_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x814) /* CCIX transport capability register 14 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG18_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x818) /* CCIX transport capability register 18 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG1C_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x81C) /* CCIX transport capability register 1C */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG20_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x820) /* CCIX transport capability register 20 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG24_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x824) /* CCIX transport capability register 24 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG28_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x828) /* CCIX transport capability register 28 */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG2C_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x82C) /* CCIX transport capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG30_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x830) /* CCIX transport capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG34_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x834) /* CCIX transport capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG38_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x838) /* CCIX transport capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_CCIX_TS_CAP_REG3C_REG               (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x83C) /* CCIX transport capability register */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG00_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x880) /* Gen4 phy txpreset capability register 00 */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG04_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x884) /* reserved */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG08_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x888) /* reserved */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG0C_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x88C) /* gen4 equalization req and status */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG10_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x890) /* local link data parity status */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG14_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x894) /* retimer link data parity status */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG18_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x898) /* second retimer link data parity status */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG1C_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x89C) /* reserved */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG20_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x8A0) /* Gen4 tx preset */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG24_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x8A4) /* Gen4 tx preset */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG28_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x8A8) /* Gen4 tx preset */
#define PCIe_HIPCIEC_RP_CFGSPACE_GEN4_PHY_CAP_REG2C_REG              (PCIe_HIPCIEC_RP_CFGSPACE_BASE + 0x8AC) /* Gen4 tx preset */

#endif // __HIPCIEC_RP_CFGSPACE_REG_OFFSET_H__
