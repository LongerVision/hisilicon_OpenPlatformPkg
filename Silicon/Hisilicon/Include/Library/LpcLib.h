/** @file
*
*  Copyright (c) 2016-2018, Hisilicon Limited. All rights reserved.
*  Copyright (c) 2016-2018, Linaro Limited. All rights reserved.
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

#ifndef _LPC_LIB_H_
#define _LPC_LIB_H_

#include <Uefi.h>

#define PCIE_SUBSYS_IOMUX       0x201100000
#define PCIE_SUBSYS_IOMG019     (PCIE_SUBSYS_IOMUX + 0x48)
#define PCIE_SUBSYS_IOMG020     (PCIE_SUBSYS_IOMUX + 0x4C)
#define PCIE_SUBSYS_IOMG021     (PCIE_SUBSYS_IOMUX + 0x50)
#define PCIE_SUBSYS_IOMG022     (PCIE_SUBSYS_IOMUX + 0x54)
#define PCIE_SUBSYS_IOMG023     (PCIE_SUBSYS_IOMUX + 0x58)
#define PCIE_SUBSYS_IOMG024     (PCIE_SUBSYS_IOMUX + 0x5C)
#define PCIE_SUBSYS_IOMG025     (PCIE_SUBSYS_IOMUX + 0x60)
#define PCIE_SUBSYS_IOMG028     (PCIE_SUBSYS_IOMUX + 0x6C)

#define IO_MGMT_SUBCTRL_BASE    0x201070000
#define SC_LPC_RESET_REQ_REG    (IO_MGMT_SUBCTRL_BASE + 0x0a58)
#define SC_LPC_RESET_DREQ_REG   (IO_MGMT_SUBCTRL_BASE + 0x0a5c)
#define SC_LPC_SEL              (IO_MGMT_SUBCTRL_BASE + 0x2400)


#define LPCD06_BASE             0x201190000
#define LPC_FIRM_SPACE0_CFG     (LPCD06_BASE + 0x100)
#define LPC_FIRM_SPACE1_CFG     (LPCD06_BASE + 0x104)
#define LPC_FIRM_SPACE2_CFG     (LPCD06_BASE + 0x108)
#define LPC_FIRM_SPACE3_CFG     (LPCD06_BASE + 0x10C)
#define LPC_FIRM_SPACE4_CFG     (LPCD06_BASE + 0x110)
#define LPC_FIRM_SPACE5_CFG     (LPCD06_BASE + 0x114)
#define LPC_FIRM_SPACE6_CFG     (LPCD06_BASE + 0x118)
#define LPC_FIRM_SPACE7_CFG     (LPCD06_BASE + 0x11C)
#define LPC_MEM_SPACE0_CFG      (LPCD06_BASE + 0x120)
#define LPC_MEM_SPACE1_CFG      (LPCD06_BASE + 0x124)
#define LPC_MEM_SPACE2_CFG      (LPCD06_BASE + 0x128)
#define LPC_MEM_SPACE3_CFG      (LPCD06_BASE + 0x12C)
#define LPC_MEM_SPACE4_CFG      (LPCD06_BASE + 0x130)
#define LPC_MEM_SPACE5_CFG      (LPCD06_BASE + 0x134)
#define LPC_MEM_SPACE6_CFG      (LPCD06_BASE + 0x138)

#define LPCD06_START_REG        (LPCD06_BASE + 0x00)
#define LPCD06_OP_STATUS_REG    (LPCD06_BASE + 0x04)
#define LPCD06_IRQ_ST_REG       (LPCD06_BASE + 0x08)
#define LPCD06_OP_LEN_REG       (LPCD06_BASE + 0x10)
#define LPCD06_CMD_REG          (LPCD06_BASE + 0x14)
#define LPCD06_ADDR_REG         (LPCD06_BASE + 0x20)
#define LPCD06_WDATA_REG        (LPCD06_BASE + 0x24)
#define LPCD06_RDATA_REG        (LPCD06_BASE + 0x28)

#define LPC_SIRQ_CTR0           (LPCD06_BASE + 0x80)
#define LPC_SIRQ_CTR1           (LPCD06_BASE + 0x84)
#define LPC_SIRQ_INT_MASK       (LPCD06_BASE + 0x94)


#define PCIE_SUBSYS_IO_MUX      0xA0170000
#define PCIE_SUBSYS_IOMG033     (PCIE_SUBSYS_IO_MUX + 0x84)
#define PCIE_SUBSYS_IOMG035     (PCIE_SUBSYS_IO_MUX + 0x8C)
#define PCIE_SUBSYS_IOMG036     (PCIE_SUBSYS_IO_MUX + 0x90)
#define PCIE_SUBSYS_IOMG045     (PCIE_SUBSYS_IO_MUX + 0xB4)
#define PCIE_SUBSYS_IOMG046     (PCIE_SUBSYS_IO_MUX + 0xB8)
#define PCIE_SUBSYS_IOMG047     (PCIE_SUBSYS_IO_MUX + 0xBC)
#define PCIE_SUBSYS_IOMG048     (PCIE_SUBSYS_IO_MUX + 0xC0)
#define PCIE_SUBSYS_IOMG049     (PCIE_SUBSYS_IO_MUX + 0xC4)
#define PCIE_SUBSYS_IOMG050     (PCIE_SUBSYS_IO_MUX + 0xC8)

#define IO_WRAP_CTRL_BASE       0xA0100000
#define SC_LPC_CLK_EN_REG       (IO_WRAP_CTRL_BASE + 0x03a0)
#define SC_LPC_CLK_DIS_REG      (IO_WRAP_CTRL_BASE + 0x03a4)
#define SC_LPC_BUS_CLK_EN_REG   (IO_WRAP_CTRL_BASE + 0x03a8)
#define SC_LPC_BUS_CLK_DIS_REG  (IO_WRAP_CTRL_BASE + 0x03ac)
#define SC_LPC_RESET_REQ        (IO_WRAP_CTRL_BASE + 0x0ad8)
#define SC_LPC_RESET_DREQ       (IO_WRAP_CTRL_BASE + 0x0adc)
#define SC_LPC_BUS_RESET_REQ    (IO_WRAP_CTRL_BASE + 0x0ae0)
#define SC_LPC_BUS_RESET_DREQ   (IO_WRAP_CTRL_BASE + 0x0ae4)
#define SC_LPC_CTRL_REG         (IO_WRAP_CTRL_BASE + 0x2028)


#define LPC_BASE                0xA01B0000
#define LPC_START_REG           (LPC_BASE + 0x00)
#define LPC_OP_STATUS_REG       (LPC_BASE + 0x04)
#define LPC_IRQ_ST_REG          (LPC_BASE + 0x08)
#define LPC_OP_LEN_REG          (LPC_BASE + 0x10)
#define LPC_CMD_REG             (LPC_BASE + 0x14)
#define LPC_FWH_ID_MSIZE_REG    (LPC_BASE + 0x18)
#define LPC_ADDR_REG            (LPC_BASE + 0x20)
#define LPC_WDATA_REG           (LPC_BASE + 0x24)
#define LPC_RDATA_REG           (LPC_BASE + 0x28)
#define LPC_LONG_CNT_REG        (LPC_BASE + 0x30)
#define LPC_TX_FIFO_ST_REG      (LPC_BASE + 0x50)
#define LPC_RX_FIFO_ST_REG      (LPC_BASE + 0x54)
#define LPC_TIME_OUT_REG        (LPC_BASE + 0x58)
#define LPC_SIRQ_CTRL0_REG      (LPC_BASE + 0x80)
#define LPC_SIRQ_CTRL1_REG      (LPC_BASE + 0x84)
#define LPC_SIRQ_INT_REG        (LPC_BASE + 0x90)
#define LPC_SIRQ_INT_MASK_REG   (LPC_BASE + 0x94)
#define LPC_SIRQ_STAT_REG       (LPC_BASE + 0xA0)

#define LPC_FIFO_LEN            (16)

typedef enum{
    LPC_ADDR_MODE_INCREASE,
    LPC_ADDR_MODE_SINGLE
}LPC_ADDR_MODE;

typedef enum{
    LPC_TYPE_IO,
    LPC_TYPE_MEM,
    LPC_TYPE_FWH
}LPC_TYPE;


typedef union {
    struct{
        UINT32  lpc_wr:1;
        UINT32  lpc_type:2;
        UINT32  same_addr:1;
        UINT32  resv:28;
    }bits;
    UINT32  u32;
}LPC_CMD_STRUCT;

typedef union {
    struct{
        UINT32  op_len:5;
        UINT32  resv:27;
    }bits;
    UINT32  u32;
}LPC_OP_LEN_STRUCT;


VOID LpcInit(VOID);
BOOLEAN LpcIdle(VOID);
EFI_STATUS LpcByteWrite(
    IN  UINT32              Addr,
    IN  UINT8               Data);
EFI_STATUS LpcByteRead(
    IN  UINT32              Addr,
    IN OUT  UINT8          *Data);

EFI_STATUS LpcWrite(
    IN  UINT32              Addr,
    IN  UINT8              *Data,
    IN  UINT8               Len);

#endif


