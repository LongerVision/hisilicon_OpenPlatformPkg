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

#include <Library/IoLib.h>
#include <Library/ArmLib.h>
#include <Library/BaseLib.h>
#include <Library/TimerLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/PcdLib.h>
#include <PcieInitLib.h>

static RC_LTSSM  g_RC_LTSSM[MAX_PORTS];
extern PCIE_CTRL g_PCIE[MAX_CHIPS];

// Flag for whether Ecam is Inited.
UINT8 Ecam_Inited[4] = {0, 0, 0, 0};

RC_LTSSM ltssm_rc_cfg_def[4] = {
  // Config 0
  {
    CFG_WX16,
    GEN1,
    GEN1,
    {
      GBL_WX16,
      0,
      0,
    },
    GEN1,
    CFG_WX16,
  },

  // Config 1
  {
    CFG_WX8,
    GEN1,
    GEN1,
    {
      GBL_WX8,
      0,
      0,
    },
    GEN1,
    CFG_WX8,
  },

  // Config 2
  {
    CFG_WX1,
    GEN2,
    GEN2,
    {
      GBL_WX1,
      0,
      0,
    },
    GEN2,
    CFG_WX1,
  },

  // Config3
  {
    CFG_WX8,
    GEN1,
    GEN1,
    {
      GBL_WX8,
      0,
      0,
    },
    GEN1,
    CFG_WX8,
  }
};

static PARAM_TABLE LtssmConfigTable[] = {
  {PCIE_X16_GEN4_LINKUP, &ltssm_rc_cfg_def[0]},
  {PCIE_X8_GEN4_LINKUP,  &ltssm_rc_cfg_def[1]},
  {PCIE_X1_GEN2_LINKUP,  &ltssm_rc_cfg_def[2]},
  {PCIE_X8_GEN1_LINKUP,  &ltssm_rc_cfg_def[3]},   /*  Only for FPGA GEN1 test */
  { -1, NULL}
};

//Allocate Max_Port resource for total ltssm.
RC_LTSSM* GetRcLtssm (
  UINT32 PortId
  )
{
  if (PortId >= MAX_PORTS) {
    return NULL;
  }

  return &g_RC_LTSSM[PortId];
}

PCIE_CTRL* Get_Pcie_By_Chipid (
  UINT32 Chip_id
  )
{
  if (Chip_id >= MAX_CHIPS) {
    return NULL;
  }

  return &g_PCIE[Chip_id];
}

PCIE_CTRL* Get_Pcie_By_Portid (
  UINT32 Port_id
  )
{
  UINT32 Chip_id = PORTID_2_CHIPID (Port_id);
  return  &g_PCIE[Chip_id];
}

UINT32 Pcie_Apb_Read (UINT32 Chip, UINT32 Offset)
{
  UINT32 Value = 0;
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip);

  if (Chip > MAX_CHIPS) {
    return 0xffffffff;
  }

  Value = MmioRead32 (Pcie->apb_base + Offset);
  return Value;
}

VOID
Pcie_Apb_Write (
  UINT32 Chip,
  UINT32 Offset,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip);

  if (Chip > MAX_CHIPS) {
    return;
  }

  MmioWrite32 (Pcie->apb_base + Offset, Value);
  return;
}

EFI_STATUS
Hisi_Pcie_Ap_Iob_Reg_Read (
  UINT32 Chip_id,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip_id);
  UINTN Address=0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->apb_base;
  *Value = MmioRead32 (Address + Reg);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Ap_Iob_Reg_Write (
  UINT32 Chip_id,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip_id);
  UINTN Address=0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->apb_base;
  MmioWrite32 (Address + Reg, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Ap_Iob_Rx_Am_Reg_Read (
  UINT32 Chip_id,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip_id);
  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  *Value = MmioRead32 (Pcie->ap_iob_rx_am + Reg);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Ap_Iob_Rx_Am_Reg_Write (
  UINT32 Chip_id,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip_id);
  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  MmioWrite32 ((Pcie->ap_iob_rx_am + Reg), Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Ap_Iob_Rx_Odr_Reg_Write (
  UINT32 Chip_id,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip_id);
  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  MmioWrite32 ((Pcie->ap_iob_rx_odr + Reg), Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Ap_Iob_Rx_Odr_Reg_Read (
  UINT32 Chip_id,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Chipid (Chip_id);
  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  *Value = MmioRead32 (Pcie->ap_iob_rx_odr + Reg);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Cfg_Read (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINTN Address=0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->core_port[PORTID_ONECHIP (Port_id)];
  *Value = MmioRead32 (Address + CFG_REG_OFFSET + Reg);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Cfg_Write (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINTN Address=0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->core_port[PORTID_ONECHIP (Port_id)];
  MmioWrite32 (Address + CFG_REG_OFFSET + Reg, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Core_Port_Reg_Read (
  UINT32 Port_id,
  UINT32 Offset,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINTN Address = 0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->core_port[PORTID_ONECHIP (Port_id)];
  *Value = MmioRead32 (Address + Offset + Reg);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Core_Port_Reg_Write (
  UINT32 Port_id,
  UINT32 Offset,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINTN Address = 0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->core_port[PORTID_ONECHIP (Port_id)];
  MmioWrite32 (Address + Offset + Reg, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Core_Global_Reg_Read (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINT32 CoreNum = PORTID_2_CORENUM (Port_id);
  UINTN Address=0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->core_global[CoreNum];
  *Value = MmioRead32 (Address + Reg);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Core_Global_Reg_Write (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINT32 CoreNum = PORTID_2_CORENUM (Port_id);

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  MmioWrite32 ((Pcie->core_global[CoreNum] + Reg), Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Pcs_Reg_Read (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINTN Address=0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->pcs[PORTID_2_CORENUM (Port_id)];
  *Value = MmioRead32 (Address + Reg);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Pcs_Reg_Write (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  UINTN Address=0;

  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  Address = Pcie->pcs[PORTID_2_CORENUM (Port_id)];
  MmioWrite32 (Address + Reg, Value);

  return EFI_SUCCESS;
}

UINT32
Pcie_Pcs_Reg_Read (
  UINT32 Port_id,
  UINT32 Offset
  )
{
  UINT32 Ret;
  UINT32 Value = 0;

  Ret = Hisi_Pcie_Pcs_Reg_Read (Port_id, Offset, &Value);
  if (Ret) {
    return 0xffffffff;
  }

  return Value;
}

VOID
Pcie_Pcs_Reg_Write (
  UINT32 Port_id,
  UINT32 Offset,
  UINT32 Value
  )
{
  UINT32 Ret;

  Ret = Hisi_Pcie_Pcs_Reg_Write (Port_id, Offset, Value);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: write pcs Reg %x fail\n", __FUNCTION__, __LINE__, Offset));
  }

  return;
}

EFI_STATUS
Hisi_Pcie_Subctrl_Reg_Read (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 *Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  *Value = MmioRead32 (Pcie->subctrl_base + Reg);
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Subctrl_Reg_Write (
  UINT32 Port_id,
  UINT32 Reg,
  UINT32 Value
  )
{
  PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);
  if (Pcie == NULL) {
    return EFI_UNSUPPORTED;
  }

  MmioWrite32 ((Pcie->subctrl_base + Reg), Value);
  return EFI_SUCCESS;
}

//
// PCIE iATU Config Start.
//
//extsize  Offset 0x08[11:0] is for external Region size.
EFI_STATUS
Hisi_Pcie_Set_Iob_Txatu_Ext_Region_Size (
  UINT32 Atu_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_IOB_TXATU_CONTROL_2 Reg_Val;

  Ret = Hisi_Pcie_Ap_Iob_Reg_Read (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.iob_txatu_ext_region_size = Value;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_2_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

//size Lsb [31:0]
EFI_STATUS
Hisi_Pcie_Set_Iob_Txatu_Region_Size (
  UINT32 Atu_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  UINT32 Reg_Val = Value;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_REGION_SIZE_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), Reg_Val);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

//src_h
EFI_STATUS
Hisi_Pcie_Set_Iob_Txatu_Base_Addr_High (
  UINT32 Atu_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  UINT32 Reg_Val = Value;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_H_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), Reg_Val);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

//src_l
EFI_STATUS
Hisi_Pcie_Set_Iob_Txatu_Base_Addr_Low (
  UINT32 Atu_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_BASE_ADDR_L_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), Value);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

//dst_h
EFI_STATUS
Hisi_Pcie_Set_Iob_Txatu_Tar_Addr_High (
  UINT32 Atu_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  UINT32 Reg_Val = Value;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_H_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), Reg_Val);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

//dst_l
EFI_STATUS
Hisi_Pcie_Set_Iob_Txatu_Tar_Addr_Low (
  UINT32 Atu_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_TAR_ADDR_L_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), Value);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Iob_Txatu_En (
  UINT32 Atu_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_IOB_TXATU_CONTROL_0 Reg_Val;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Read (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  if ((Atu_id == 0x3) || (Atu_id == 0x9) ) {
    DEBUG((DEBUG_INFO, "Tx atu config for IO\n"));
    Reg_Val.bits.iob_txatu_type_trans_mode = 1;
  }

  Reg_Val.bits.iob_txatu_en = Value;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (TXATUID_2_CHIPID (Atu_id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_TXATU_CONTROL_0_0_REG
                                + (TXATUID_ONECHIP (Atu_id) << ATU_SIZE_SHIFT), Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
IatuInit (
  UINT32 Atu_id
  )
{
  UINT32  Ret;
  UINT64  Tx_Region_Size = 0;
  UINT64  Tx_Src_Base = 0;
  UINT64  Tx_Dst_Base = 0;

  if ((Atu_id == 01)||(Atu_id == 0x4)||(Atu_id == 0x5)||
      (Atu_id == 07)||(Atu_id == 0x0A)||(Atu_id == 0x0B)) {
    return EFI_SUCCESS;
  }

  if (Atu_id < 0x06) {
    // Chip0 Atu setting.
    if (Atu_id == 0x00) {               // 64-prefetch
      Tx_Region_Size = 0x4000000000;    // 256G
      Tx_Src_Base = 0x80000000000;      // 8T
      Tx_Dst_Base = 0x80000000000;      //
    }

    if (Atu_id == 0x02) {               // 32-NonPrefetch
      Tx_Region_Size = 0x7FF0000;       // 128M - 64K
      Tx_Src_Base = 0xE0000000;         // 3.5G
      Tx_Dst_Base = 0xE0000000;         // 3.5G
    }

    if (Atu_id == 0x03) {               // IO
      Tx_Region_Size = 0x10000;         // 64K
      Tx_Src_Base = 0xE7FF0000;         // 3.5G + 128M - 64K
      Tx_Dst_Base = 0x0;
    }
  } else {
    // Chip1 Atu setting.
    if (Atu_id == 0x06) {               // 64-prefetch
      Tx_Region_Size = 0x4000000000;    // 256G
      Tx_Src_Base = 0x480000000000;
      Tx_Dst_Base = 0x480000000000;
    }

    if (Atu_id == 0x08) {               // 32-NonPrefetch
      Tx_Region_Size = 0x7FF0000;       // 128M -64K
      Tx_Src_Base = 0xE8000000;         // 3.5G + 128M
      Tx_Dst_Base = 0xE8000000;         // 3.5G + 128M
    }

    if (Atu_id == 0x09) {               // IO
      Tx_Region_Size = 0x10000;         // 64K
      Tx_Src_Base = 0xEFFF0000;         // 3.5G + 256M - 64K
      Tx_Dst_Base = 0x0;                // 0
    }
  }

  Ret = Hisi_Pcie_Set_Iob_Txatu_Ext_Region_Size (Atu_id, (UINT32)(Tx_Region_Size >> 32));
  if (Ret) {
    goto out;
  }

  Ret = Hisi_Pcie_Set_Iob_Txatu_Region_Size (Atu_id, (UINT32)Tx_Region_Size);
  if (Ret) {
    goto out;
  }

  Ret = Hisi_Pcie_Set_Iob_Txatu_Base_Addr_High (Atu_id, (UINT32)(Tx_Src_Base >> 32));
  if (Ret) {
    goto out;
  }

  Ret = Hisi_Pcie_Set_Iob_Txatu_Base_Addr_Low (Atu_id, (UINT32)Tx_Src_Base);
  if (Ret) {
    goto out;
  }

  Ret = Hisi_Pcie_Set_Iob_Txatu_Tar_Addr_High (Atu_id, (UINT32)(Tx_Dst_Base >> 32));
  if (Ret) {
    goto out;
  }

  Ret = Hisi_Pcie_Set_Iob_Txatu_Tar_Addr_Low (Atu_id, (UINT32)Tx_Dst_Base);
  if (Ret) {
    goto out;
  }

  Ret = Hisi_Pcie_Set_Iob_Txatu_En (Atu_id, 1);
  if (Ret) {
    goto out;
  }

out:
  return Ret;
}

EFI_STATUS
Hisi_Pcie_Get_Port_Sft_Rst (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PORT_RESET Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_REG, &Reg_Val.u32);

  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.port_sft_rst;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port_Sft_Rst (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT_RESET Reg_Val;
  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port_sft_rst = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Port_Ctrl_Sft_Rst (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PORT_RESET Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.port_ctrl_sft_rst;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port_Ctrl_Sft_Rst (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT_RESET Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port_ctrl_sft_rst = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Pcs_Sft_Rst (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PCS_SOFT_REST Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PCS_SOFT_REST_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.pcs_sft_rst = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PCS_SOFT_REST_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Pcs_Lane_Sft_Rst (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PCS_SOFT_REST Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PCS_SOFT_REST_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.pcs_lane_sft_rst;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Pcs_Lane_Sft_Rst (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PCS_SOFT_REST Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PCS_SOFT_REST_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.pcs_lane_sft_rst = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PCS_SOFT_REST_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Port_Sticky_Sft_Rst (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PHY_RESET Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PHY_RESET_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.port_sticky_sft_rst;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port_Sticky_Sft_Rst (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PHY_RESET Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PHY_RESET_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port_sticky_sft_rst = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PHY_RESET_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

UINT32
Transe_Gbl_Lane_Num_To_Cfg_Width (
  UINT32 Gbl_Lanes
  )
{
  switch (Gbl_Lanes) {
    case GBL_WX1:
      return CFG_WX1;
      break;

    case GBL_WX2:
      return CFG_WX2;
      break;

    case GBL_WX4:
      return CFG_WX4;
      break;

    case GBL_WX8:
      return CFG_WX8;
      break;

    default:
    case GBL_WX16:
      return CFG_WX16;
      break;
  }
}

EFI_STATUS
Hisi_Pcie_Get_Port_En (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PORT_EN Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_EN_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.port_en;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT_EN Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_EN_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port_en = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_EN_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Port_En_Enable (
  UINT32 Port_id,
  UINT32 Enable
  )
{
  UINT32 Ret;
  UINT32 Value;

  Ret = Hisi_Pcie_Get_Port_En (Port_id, &Value);
  if (Ret) {
    return Ret;
  }

  if (Enable) {
    DEBUG((DEBUG_INFO, "[%a]:[%dL]: port %d is enabled\n", __FUNCTION__, __LINE__, Port_id));
    Value |= 0x1 << (PORTID_2_PORTNUM (Port_id));
  } else {
    DEBUG((DEBUG_INFO, "[%a]:[%dL]: port %d disable\n", __FUNCTION__, __LINE__, Port_id));
    Value &= ~((UINT32)0x1 << (PORTID_2_PORTNUM (Port_id)));
  }

  Ret = Hisi_Pcie_Set_Port_En (Port_id, Value);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Port_Logic_Reset (
  UINT32 Port_id
  )
{
  UINT32 Value = 0;

  Hisi_Pcie_Get_Port_Sft_Rst (Port_id, &Value);
  Value |= 0x1 << PORTID_2_PORTNUM (Port_id);
  Hisi_Pcie_Set_Port_Sft_Rst (Port_id, Value);
  MicroSecondDelay (1); // 1ms

  Hisi_Pcie_Get_Port_Ctrl_Sft_Rst (Port_id, &Value);
  Value |= (0x1 << PORTID_2_PORTNUM (Port_id));
  Hisi_Pcie_Set_Port_Ctrl_Sft_Rst (Port_id, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Port_Logic_Dereset (
  UINT32 Port_id
  )
{
  UINT32 Value = 0;

  Hisi_Pcie_Get_Port_Sft_Rst (Port_id, &Value);
  Value &= ~(0x1 << PORTID_2_PORTNUM (Port_id));

  Hisi_Pcie_Set_Port_Sft_Rst (Port_id, Value);
  MicroSecondDelay(1);

  Hisi_Pcie_Get_Port_Ctrl_Sft_Rst (Port_id, &Value);
  Value &= ~(0x1 << PORTID_2_PORTNUM (Port_id));

  Hisi_Pcie_Set_Port_Ctrl_Sft_Rst (Port_id, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Port_Sticky_Reset (
  UINT32 Port_id
  )
{
  UINT32 Value = 0;
  UINT32 Port_Bit = 0;

  Hisi_Pcie_Get_Port_Sticky_Sft_Rst (Port_id, &Value);
  Port_Bit = PORTID_2_PORTNUM (Port_id);

  SetBit (Value, Port_Bit);
  Hisi_Pcie_Set_Port_Sticky_Sft_Rst (Port_id, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Port_Sticky_Dereset (
  UINT32 Port_id
  )
{
  UINT32 Value = 0;
  UINT32 Port_Bit = 0;

  Hisi_Pcie_Get_Port_Sticky_Sft_Rst (Port_id, &Value);
  Port_Bit = PORTID_2_PORTNUM (Port_id);
  ClearBit (Value, Port_Bit);
  Hisi_Pcie_Set_Port_Sticky_Sft_Rst (Port_id, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Pcs_Lane_Reset (
  UINT32 Port_id,
  UINT32 Lanes
  )
{
  UINT8 Index = 0;
  UINT32 Value = 0;

  Hisi_Pcie_Get_Pcs_Lane_Sft_Rst (Port_id, &Value);
  for (Index = 0; Index < Lanes; Index++) {
    Value |= (UINT32)(0x1 << (PORTID_2_PORTNUM (Port_id) + Index));
  }
  Hisi_Pcie_Set_Pcs_Lane_Sft_Rst (Port_id, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Pcs_Eios_Enable (
  UINT32 Port_id,
  UINT32 Lanes
  )
{
  UINT32 Reg_Offset = 0x5c;
  UINT32 Value;
  UINT32 Index;

  Value = Pcie_Pcs_Reg_Read (Port_id, Reg_Offset);
  for (Index = 0; Index < Lanes; Index++) {
    Value |= (0x1 << Index);
  }
  Pcie_Pcs_Reg_Write (Port_id, Reg_Offset, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Pcs_Lane_Dereset (
  UINT32 Port_id,
  UINT32 Lanes
  )
{
  UINT8 Index = 0;
  UINT32 Value = 0;

  Hisi_Pcie_Get_Pcs_Lane_Sft_Rst (Port_id, &Value);
  for (Index = 0; Index < Lanes; Index++) {
    Value &= ~((UINT32)0x1 << (PORTID_2_PORTNUM (Port_id) + Index));
  }
  Hisi_Pcie_Set_Pcs_Lane_Sft_Rst (Port_id, Value);

  /* Eliminate unexpected bad TLP */
  Pcie_Pcs_Eios_Enable (Port_id, Lanes);

  return EFI_SUCCESS;
}

/*
*core0 port0对应bit4
*core1 port0对应bit0  *core1 port1对应bit1
*core2 port0对应bit2  *core2 port1对应bit3
*/
EFI_STATUS
Pcie_Serdes_Lane_Reset (
  UINT32 Port_id
  )
{
  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Serdes_Lane_Dereset (
  UINT32 Port_id
  )
{
  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Pcs_Apb_Dereset (
  UINT32 Port_id
  )
{
  Hisi_Pcie_Set_Pcs_Sft_Rst (Port_id, 0);
  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Check_Reset (
  UINT32 Port_id
  )
{
  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Check_Dereset (
  UINT32 Port_id
  )
{
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Pciec_Mode_Sel (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_GLB_PCIEC_MODE_SEL Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_GLB_PCIEC_MODE_SEL_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.pciec_mode_sel;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Pciec_Mode_Sel (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_GLB_PCIEC_MODE_SEL Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_GLB_PCIEC_MODE_SEL_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.pciec_mode_sel = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_GLB_PCIEC_MODE_SEL_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port0_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT07_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port0_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port2_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT07_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port2_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port4_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT07_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port4_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port6_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT07_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port6_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT07_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port8_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT815_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port8_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port10_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT815_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port10_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port12_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT815_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port12_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Port14_Link_Mode (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT815_LINK_MODE Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.port14_link_mode = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT815_LINK_MODE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Auto_Speed_Change_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_ENTER_LPBK_DISABLE Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.auto_speed_change_en = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_First_Auto_Speed_Change_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_ENTER_LPBK_DISABLE Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.first_auto_speed_change_en = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Disable_Enter_Compliance (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_ENTER_LPBK_DISABLE Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.disable_enter_compliance = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Disable_Enter_Hotreset (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_ENTER_LPBK_DISABLE Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.disable_enter_hotreset = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Disable_Enter_Disable (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_ENTER_LPBK_DISABLE Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.disable_enter_disable = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Disable_Enter_Loopback (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_ENTER_LPBK_DISABLE Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.disable_enter_loopback = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Sel_Trace_Rx_Data_Mode (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_LTSSM_TRACER_CFG0 Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_LTSSM_TRACER_CFG0_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.sel_trace_rx_data_mode;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Reg_Ltssm_Tracer_Recap (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LTSSM_TRACER_INPUT Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_INPUT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.reg_ltssm_tracer_recap = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_INPUT_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}
EFI_STATUS
Hisi_Pcie_Get_Linkdown_Clr_Port_En (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PHY_RESET Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PHY_RESET_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.linkdown_clr_port_en;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Linkdown_Clr_Port_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PHY_RESET Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PHY_RESET_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.linkdown_clr_port_en = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PHY_RESET_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Linkdown_Rst_En (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PORT_RESET_CFG Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_CFG_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.linkdown_rst_en;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Linkdown_Rst_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT_RESET_CFG Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_CFG_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.linkdown_rst_en = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_CFG_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Mac_Link_Up (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LINK_INFO Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LINK_INFO_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.mac_link_up;

   // Here we need some delay by read it again,
   // otherwise Too fast to get link up status.
   {
      UINT32 Tempdata;
      UINTN  Address = 0;
      PCIE_CTRL *Pcie = Get_Pcie_By_Portid (Port_id);

      Address = Pcie->core_port[PORTID_ONECHIP (Port_id)];
      Tempdata= MmioRead32 (Address + MAC_REG_OFFSET + PCIe_HIPCIEC_MAC_REG_MAC_REG_LINK_INFO_REG);
      DEBUG((DEBUG_INFO, "[%a]:[%dL]: mac_link_up = 0x%x \r\n", __FUNCTION__, __LINE__, (UINT8)(Tempdata >> 16)));
   }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Mac_Cur_Link_Speed (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LINK_INFO Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LINK_INFO_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.mac_cur_link_speed;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Mac_Cur_Link_Width (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LINK_INFO Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LINK_INFO_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.mac_cur_link_width;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Mac_Ltssm_Info (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LINK_INFO Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LINK_INFO_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.mac_ltssm_st;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Mac_Reg_Ltssm_Tracer_Output_1 (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LTSSM_TRACER_OUTPUT_1 Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_OUTPUT_1_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.u32;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Mac_Reg_Ltssm_Tracer_Output_2 (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LTSSM_TRACER_OUTPUT_2 Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_OUTPUT_2_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.u32;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Ltssm_Tracer_Last_Waddr (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LTSSM_TRACER_LAST_ADDR Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_LAST_ADDR_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.ltssm_tracer_last_waddr;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Ltssm_Tracer_Addr_Rollback (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LTSSM_TRACER_LAST_ADDR Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_LAST_ADDR_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.ltssm_tracer_addr_rollback;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Get_Ltssm_Tracer_Data_Ok (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LTSSM_TRACER_OUTPUT_OK Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_OUTPUT_OK_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.ltssm_tracer_data_ok;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Reg_Ltssm_Tracer_Raddr (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_MAC_REG_LTSSM_TRACERADDR Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACERADDR_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.reg_ltssm_tracer_raddr = Value;
  Ret = Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACERADDR_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Get_Base_Class_Code (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PCIHDR_CLSREV Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.base_class_code;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Get_Sub_Class_Code (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PCIHDR_CLSREV Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.sub_class_code;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Get_Program_Inf (
  UINT32 Port_id,
  UINT32* Value
  )
{
  UINT32 Ret;
  U_PCIHDR_CLSREV Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  *Value = Reg_Val.bits.program_inf;
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Max_Link_Speed (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_LINK_CAPBILITY Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_LINK_CAPBILITY_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.max_link_speed = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_LINK_CAPBILITY_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Max_Link_Width (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_LINK_CAPBILITY Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_LINK_CAPBILITY_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.max_link_width = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_LINK_CAPBILITY_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Target_Link_Speed (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_LINK_CTRL_STATUS2 Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_LINK_CTRL_STATUS2_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.target_link_speed = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_LINK_CTRL_STATUS2_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Base_Class_Code (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PCIHDR_CLSREV Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.base_class_code = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Sub_Class_Code (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PCIHDR_CLSREV Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.sub_class_code = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Program_Inf (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PCIHDR_CLSREV Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.program_inf = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_PCIHDR_CLSREV_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Feature_Exchange_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT8 Ret;
  U_DL_FEATURE_CAP_REG04 Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_DL_FEATURE_CAP_REG04_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.feature_exchange_en = Value;
  (VOID)Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_DL_FEATURE_CAP_REG04_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Aer_Int_Num (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_ROOT_ERROR_STATUS Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_ROOT_ERROR_STATUS_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.aer_int_number = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_ROOT_ERROR_STATUS_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Dpc_Int_Msg_Num (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_DPC_CAP_0X04 Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X04_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.dcp_int_msg_num = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_DPC_CAP_0X04_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Acs_Src_Vld_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_ACS_CAP_0X04 Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_ACS_CAP_0X04_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.acs_src_vld_en = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_ACS_CAP_0X04_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Rp_Set_Crs_Sw_Visibility (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_ROOT_CTRL_STATUS Reg_Val;

  Ret = Hisi_Pcie_Rp_Cfg_Read (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_ROOT_CTRL_STATUS_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.crs_sw_visibility = Value;
  Ret = Hisi_Pcie_Rp_Cfg_Write (Port_id, PCIe_HIPCIEC_RP_CFGSPACE_ROOT_CTRL_STATUS_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

//
//mode: 0: ep, 1: rp
//
EFI_STATUS
Pcie_Global_Set_Port_Mode (
  UINT32 Port_id,
  UINT32 mode
  )
{
  UINT32 Ret = 0;
  UINT32 Value = 0;

  Ret = Hisi_Pcie_Get_Pciec_Mode_Sel (Port_id, &Value);
  if (Ret) {
    return Ret;
  }

  if (mode == PORT_RP) {
    Value |= 0x1 << (PORTID_2_PORTNUM (Port_id));
  } else {
    Value &= ~((UINT32)0x1 << (PORTID_2_PORTNUM (Port_id)));
  }

  Ret = Hisi_Pcie_Set_Pciec_Mode_Sel (Port_id, Value);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Global_Set_Port_LaneNum (
  UINT32 Port_id,
  UINT32 lane_num
  )
{
  DEBUG((DEBUG_INFO, "[%a]:[%dL] set_port_num selection = %d \n", __FUNCTION__, __LINE__, PORTID_2_PORTNUM (Port_id)));
  DEBUG((DEBUG_INFO, "[%a]:[%dL] Port_id = %d \n", __FUNCTION__, __LINE__, Port_id));
  DEBUG((DEBUG_INFO, "[%a]:[%dL] lane_num = %d \n", __FUNCTION__, __LINE__, lane_num));

  switch (PORTID_2_PORTNUM (Port_id)) {
    case 0:
      Hisi_Pcie_Set_Port0_Link_Mode (Port_id, lane_num);
      break;

    case 2:
      Hisi_Pcie_Set_Port2_Link_Mode (Port_id, lane_num);
      break;

    case 4:
      Hisi_Pcie_Set_Port4_Link_Mode (Port_id, lane_num);
      break;

    case 6:
      Hisi_Pcie_Set_Port6_Link_Mode (Port_id, lane_num);
      break;

    case 8:
      Hisi_Pcie_Set_Port8_Link_Mode (Port_id, lane_num);
      break;

    case 10:
      Hisi_Pcie_Set_Port10_Link_Mode (Port_id, lane_num);
      break;

    case 12:
      Hisi_Pcie_Set_Port12_Link_Mode (Port_id, lane_num);
      break;

    case 14:
      Hisi_Pcie_Set_Port14_Link_Mode (Port_id, lane_num);
      break;

    default:
      break;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Global_Set_Port_Linkdown_Rst_Num (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT_RESET_CFG Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_CFG_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.linkdown_rst_num = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RESET_CFG_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Global_Set_Port_Dly_Cnt (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_PORT_RST_DLY_CNT Reg_Val;

  Ret = Hisi_Pcie_Core_Global_Reg_Read (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RST_DLY_CNT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.cfg_rst_dly_cnt = Value;
  Ret = Hisi_Pcie_Core_Global_Reg_Write (Port_id, PCIe_HIPCIEC_GLOBAL_REG_PORT_RST_DLY_CNT_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Reg_Framing_Err_Retrain_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT8 Ret;
  U_MAC_FRAMING_ERR_CTRL Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_FRAMING_ERR_CTRL_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.reg_framing_err_retrain_en = Value;
  (VOID)Hisi_Pcie_Core_Port_Reg_Write (Port_id, MAC_REG_OFFSET, PCIe_HIPCIEC_MAC_REG_MAC_FRAMING_ERR_CTRL_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

// Offset 0xB1C
EFI_STATUS
Hisi_Pcie_Set_Tl_Ph_Vc0_Cdt (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_POSTED_CREDIT Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_ph_vc0_cdt = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Pd_Vc0_Cdt (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_POSTED_CREDIT Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_pd_vc0_cdt = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

// Offset 0xB20
EFI_STATUS
Hisi_Pcie_Set_Tl_Nph_Vc0_Cdt (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_NON_POSTED_CREDIT Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_nph_vc0_cdt = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Npd_Vc0_Cdt (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_NON_POSTED_CREDIT Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_npd_vc0_cdt = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

// Offset 0xB24
EFI_STATUS
Hisi_Pcie_Set_Tl_Cplh_Vc0_Cdt (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_CPL_CREDIT Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cplh_vc0_cdt = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Cpld_Vc0_Cdt (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_CPL_CREDIT Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cpld_vc0_cdt = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Ph_Vc0_Scale (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_ph_vc0_scale = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Pd_Vc0_Scale (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_pd_vc0_scale = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Nph_Vc0_Scale (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_NON_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_nph_vc0_scale = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Npd_Vc0_Scale (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_NON_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_npd_vc0_scale = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Cplh_Vc0_Scale (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT8 Ret;
  U_TL_RX_CPL_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cplh_vc0_scale = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, Reg_Val.u32);
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Cpld_Vc0_Scale (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT8 Ret;
  U_TL_RX_CPL_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cpld_vc0_scale = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, Reg_Val.u32);
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Ph_Vc0_Cdt_Df (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_ph_vc0_cdt_df = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Pd_Vc0_Cdt_Df (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_pd_vc0_cdt_df = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Nph_Vc0_Cdt_Df (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_NON_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_nph_vc0_cdt_df = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Npd_Vc0_Cdt_Df (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_NON_POSTED_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_npd_vc0_cdt_df = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_NON_POSTED_CREDIT_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Cplh_Vc0_Cdt_Df (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT8 Ret;
  U_TL_RX_CPL_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cplh_vc0_cdt_df = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, Reg_Val.u32);
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Cpld_Vc0_Cdt_Df (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT8 Ret;
  U_TL_RX_CPL_CREDIT_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cpld_vc0_cdt_df = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CPL_CREDIT_DF_REG, Reg_Val.u32);
  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Cpl_Cdt_Infi_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_CDT_INI_UP_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cpl_cdt_infi_en = Value;
  (VOID)Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Hisi_Pcie_Set_Tl_Cdt_Ini_Up_Df (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_CDT_INI_UP_DF Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_DF_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cdt_ini_up_df = Value;
  (VOID)Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_DF_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

// Offset 0xB28
EFI_STATUS
Hisi_Pcie_Set_Tl_Cdt_Ini_Up (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  U_TL_RX_CDT_INI_UP Reg_Val;

  Ret = Hisi_Pcie_Core_Port_Reg_Read (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.tl_cdt_ini_up = Value;
  Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_RX_CDT_INI_UP_REG, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Nonpost_Cdt_Df (
  UINT32 Port_id,
  UINT32 scale,
  UINT32 vc,
  UINT32 nph_cdt,
  UINT32 npd_cdt
  )
{
  //UINT32 Ret = 0;

  if (vc == 0) {
    Hisi_Pcie_Set_Tl_Nph_Vc0_Scale (Port_id, scale);
    Hisi_Pcie_Set_Tl_Npd_Vc0_Scale (Port_id, scale);
    Hisi_Pcie_Set_Tl_Nph_Vc0_Cdt_Df (Port_id, nph_cdt);
    Hisi_Pcie_Set_Tl_Npd_Vc0_Cdt_Df (Port_id, npd_cdt);
  } else {
    /*vc1 todo */
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Post_Cdt_Df (
  UINT32 Port_id,
  UINT32 scale,
  UINT32 vc,
  UINT32 ph_cdt,
  UINT32 pd_cdt
  )
{
  //UINT32 Ret = 0;

  if (vc == 0) {
    Hisi_Pcie_Set_Tl_Ph_Vc0_Scale (Port_id, scale);
    Hisi_Pcie_Set_Tl_Pd_Vc0_Scale (Port_id, scale);
    Hisi_Pcie_Set_Tl_Ph_Vc0_Cdt_Df (Port_id, ph_cdt);
    Hisi_Pcie_Set_Tl_Pd_Vc0_Cdt_Df (Port_id, pd_cdt);
  } else {
    /*vc1 todo */
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Cdt_Initup (
  UINT32 Port_id
  )
{
  return Hisi_Pcie_Set_Tl_Cdt_Ini_Up (Port_id, 1);
}

EFI_STATUS Pcie_Set_Cdt_Initup_Df (UINT32 Port_id)
{
  Hisi_Pcie_Set_Tl_Cdt_Ini_Up_Df (Port_id, 1);
  Hisi_Pcie_Set_Tl_Cpl_Cdt_Infi_En (Port_id, 1);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Post_Cdt (
  UINT32 Port_id,
  UINT32 vc,
  UINT32 ph_cdt,
  UINT32 pd_cdt
  )
{
  UINT32 Ret = 0;

  if (vc == 0) {
    Ret = Hisi_Pcie_Set_Tl_Ph_Vc0_Cdt (Port_id, ph_cdt);
    if (Ret) {
      return Ret;
    }

    Ret = Hisi_Pcie_Set_Tl_Pd_Vc0_Cdt (Port_id, pd_cdt);
    if (Ret) {
      return Ret;
    }
  } else {
    /*vc1 todo */
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Nonpost_Cdt (
  UINT32 Port_id,
  UINT32 vc,
  UINT32 nph_cdt,
  UINT32 npd_cdt
  )
{
  UINT32 Ret = 0;

  if (vc == 0) {
    Hisi_Pcie_Set_Tl_Nph_Vc0_Cdt (Port_id, nph_cdt);
    Hisi_Pcie_Set_Tl_Npd_Vc0_Cdt (Port_id, npd_cdt);
  } else {
    /*vc1 todo */
  }

  return Ret;
}

EFI_STATUS
Pcie_Set_Cpl_Cdt (
  UINT32 Port_id,
  UINT32 vc,
  UINT32 h_cdt,
  UINT32 d_cdt
  )
{
  UINT32 Ret = 0;

  if (vc == 0) {
    Hisi_Pcie_Set_Tl_Cplh_Vc0_Cdt (Port_id, h_cdt);
    Hisi_Pcie_Set_Tl_Cpld_Vc0_Cdt (Port_id, d_cdt);
  } else {
    /*vc1 todo */
  }

  return Ret;
}

EFI_STATUS
Pcie_Set_Cpl_Cdt_Df (
  UINT32 Port_id,
  UINT32 scale,
  UINT32 vc,
  UINT32 h_cdt,
  UINT32 d_cdt
  )
{
  //UINT32 Ret = 0;

  if (vc == 0) {
    Hisi_Pcie_Set_Tl_Cplh_Vc0_Scale (Port_id, scale);
    Hisi_Pcie_Set_Tl_Cpld_Vc0_Scale (Port_id, scale);
    Hisi_Pcie_Set_Tl_Cplh_Vc0_Cdt_Df (Port_id, h_cdt);
    Hisi_Pcie_Set_Tl_Cpld_Vc0_Cdt_Df (Port_id, d_cdt);
  } else {
    /*vc1 todo */
  }

  return EFI_SUCCESS;
}

UINT32
Get_Port_Width (
  UINT32 Port_id
  )
{
  UINT32 Width;

  if (PORTID_2_CORENUM (Port_id) == 0 || PORTID_2_CORENUM (Port_id) == 1) {
    switch (PORTID_2_PORTNUM (Port_id)) {
      case 0:
        Width = 16;
        break;

      case 8:
        Width = 8;
        break;

      case 4:
      case 12:
        Width = 4;
        break;

      default:
      case 2:
      case 6:
      case 10:
      case 14:
        Width = 2;
        break;
    }
  } else {
    switch (PORTID_2_PORTNUM (Port_id)) {
      case 0:
        Width = 8;
        break;

      case 4:
        Width = 4;
        break;

      default:
      case 2:
      case 6:
        Width = 2;
        break;
    }
  }

  return Width;
}

EFI_STATUS
Pcie_Set_Ap_Its_Addr (
  UINT32 Chip_id,
  UINT32 Msi_Ctrl_Idx,
  UINT64 Its_Addr,
  UINT32 Enable,
  UINT32 Protect_En
  )
{
  if (Chip_id >= MAX_CHIPS) {
    return EFI_INVALID_PARAMETER;
  }

  Pcie_Apb_Write (Chip_id, 0x5504 + Msi_Ctrl_Idx * 0x10, (UINT32)(Its_Addr >> 32) & 0xffffffff);
  Pcie_Apb_Write (Chip_id, 0x5508 + Msi_Ctrl_Idx * 0x10, (UINT32)Its_Addr & 0xffffffff);

  if (Enable) {
    Pcie_Apb_Write (Chip_id, 0x5500 + Msi_Ctrl_Idx * 0x10, 1);
  } else {
    Pcie_Apb_Write (Chip_id, 0x5500 + Msi_Ctrl_Idx * 0x10, 0);
  }

  if (Protect_En) {
    Pcie_Apb_Write (Chip_id, 0x5600, 1);
  } else {
    Pcie_Apb_Write (Chip_id, 0x5600, 0);
  }

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Ap_Ctrl_Lat_Stat_Rd_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  UINT32 Mst_Idx = 0;
  U_AXIM_GLOBAL_CTRL Reg_Val;

  switch (PORTID_2_CORENUM (Port_id)) {
    default:
    case 0:
      Mst_Idx = 0;
      break;

    case 1:
      Mst_Idx = 1;
      break;

    case 2:
      Mst_Idx = 2;
      break;
  }

  Ret = Hisi_Pcie_Ap_Iob_Rx_Am_Reg_Read (PORTID_2_CHIPID (Port_id), (PCIe_HIPCIEC_AP_IOB_RX_AM_REG_AXIM_GLOBAL_CTRL_0_REG) + Mst_Idx * 0x100, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.ctrl_lat_stat_rd_en = Value;
  Hisi_Pcie_Ap_Iob_Rx_Am_Reg_Write (PORTID_2_CHIPID (Port_id), (PCIe_HIPCIEC_AP_IOB_RX_AM_REG_AXIM_GLOBAL_CTRL_0_REG) + Mst_Idx * 0x100, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Set_Ap_Ctrl_Lat_Stat_Wr_En (
  UINT32 Port_id,
  UINT32 Value
  )
{
  UINT32 Ret;
  UINT32 Mst_Idx = 0;
  U_AXIM_GLOBAL_CTRL Reg_Val;

  switch (PORTID_2_CORENUM (Port_id)) {
    default:
    case 0:
      Mst_Idx = 0;
      break;

    case 1:
      Mst_Idx = 1;
      break;

    case 2:
      Mst_Idx = 2;
      break;
  }

  Ret = Hisi_Pcie_Ap_Iob_Rx_Am_Reg_Read (PORTID_2_CHIPID (Port_id), (PCIe_HIPCIEC_AP_IOB_RX_AM_REG_AXIM_GLOBAL_CTRL_0_REG) + Mst_Idx * 0x100, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.ctrl_lat_stat_wr_en = Value;
  Hisi_Pcie_Ap_Iob_Rx_Am_Reg_Write (PORTID_2_CHIPID (Port_id), (PCIe_HIPCIEC_AP_IOB_RX_AM_REG_AXIM_GLOBAL_CTRL_0_REG) + Mst_Idx * 0x100, Reg_Val.u32);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Port_Linkdown_Rst_En (
  UINT32 Port_id,
  PORT_GLOBAL_CFG* Glb_Cfg
  )
{
  UINT32 Ret = 0;
  UINT32 Value = 0;
  PORT_GLOBAL_CFG* pGlobalCfg = Glb_Cfg;

  if (pGlobalCfg == NULL) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d param fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_EPARAM;
  }

  Ret = Hisi_Pcie_Get_Linkdown_Rst_En (Port_id, &Value);
  if (Ret) {
    return Ret;
  }

  if (pGlobalCfg->linkdown_rst_en) {
    Value |= 0x1 << (PORTID_2_PORTNUM (Port_id));
  } else {
    Value &= ~((UINT32)0x1 << (PORTID_2_PORTNUM (Port_id)));
  }

  Hisi_Pcie_Set_Linkdown_Rst_En (Port_id, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Port_Linkdown_Clr_Port_En (
  UINT32 Port_id,
  PORT_GLOBAL_CFG* Glb_Cfg
  )
{
  UINT32 Ret = 0;
  UINT32 Value = 0;
  PORT_GLOBAL_CFG* pGlobalCfg = Glb_Cfg;

  if (pGlobalCfg == NULL) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d param fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_EPARAM;
  }

  Ret = Hisi_Pcie_Get_Linkdown_Clr_Port_En (Port_id, &Value);
  if (Ret) {
    return Ret;
  }

  if (pGlobalCfg->linkdown_clr_port_en) {
    Value |= 0x1 << (PORTID_2_PORTNUM (Port_id));
  } else {
    Value &= ~((UINT32)0x1 << (PORTID_2_PORTNUM (Port_id)));
  }

  Hisi_Pcie_Set_Linkdown_Clr_Port_En (Port_id, Value);

  return EFI_SUCCESS;
}

EFI_STATUS
Pcie_Get_Ltssm_Trace (
  UINT32 Port_id,
  UINT64* Ltssm_Status,
  UINT32* Ltssm_Num
  )
{
  UINT32 Ret;
  UINT32 Index = 0;
  UINT32 Temp_Val;
  UINT32 Trace_Addr = 0x0;
  UINT32 Addr_Index = 0x0;

  if (Ltssm_Status == NULL || Ltssm_Num == NULL) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d get ltssm trace data fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_EPARAM;
  }

  /*ltssm_status first element to save tracer mode*/
  Ret = Hisi_Pcie_Get_Sel_Trace_Rx_Data_Mode (Port_id, &Temp_Val);
  if (Ret) {
    return Ret;
  }

  *Ltssm_Status = Temp_Val & 0x8;
  Index++;

  Ret = Hisi_Pcie_Get_Ltssm_Tracer_Last_Waddr (Port_id, &Trace_Addr);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Get_Ltssm_Tracer_Addr_Rollback (Port_id, &Temp_Val);
  if (Ret) {
    return Ret;
  }

  if (Temp_Val == 1) {
    Addr_Index = Trace_Addr;

    do {
      Ret = Hisi_Pcie_Set_Reg_Ltssm_Tracer_Raddr (Port_id, Addr_Index);
      if (Ret) {
        return Ret;
      }

      do {
        // Whether add timeout protect?  ---qiuzhenfa
        Ret = Hisi_Pcie_Get_Ltssm_Tracer_Data_Ok (Port_id, &Temp_Val);
        if (Ret) {
          return Ret;
        }
      } while (!Temp_Val);

      Ret = Hisi_Pcie_Get_Mac_Reg_Ltssm_Tracer_Output_2 (Port_id, &Temp_Val);
      if (Ret) {
        return Ret;
      }

      *(Ltssm_Status + Index) = Temp_Val;
      Ret = Hisi_Pcie_Get_Mac_Reg_Ltssm_Tracer_Output_1 (Port_id, &Temp_Val);
      if (Ret) {
        return Ret;
      }

      *(Ltssm_Status + Index) = (*(Ltssm_Status + Index) << 32) | Temp_Val;
      Index++;

      if (Addr_Index == 63) {
        Addr_Index = 0;
      } else {
        Addr_Index++;
      }
    }while (Addr_Index != Trace_Addr);
  } else {

    while (Addr_Index < Trace_Addr) {
      Ret = Hisi_Pcie_Set_Reg_Ltssm_Tracer_Raddr (Port_id, Addr_Index);
      if (Ret) {
        return Ret;
      }

      do {
        // Whether add timeout protect? ---qiuzhenfa
        Ret = Hisi_Pcie_Get_Ltssm_Tracer_Data_Ok (Port_id, &Temp_Val);
        if (Ret) {
          return Ret;
        }
      }
      while (!Temp_Val);

      Ret = Hisi_Pcie_Get_Mac_Reg_Ltssm_Tracer_Output_2 (Port_id, &Temp_Val);
      if (Ret) {
        return Ret;
      }

      *(Ltssm_Status + Index) = Temp_Val;
      Ret = Hisi_Pcie_Get_Mac_Reg_Ltssm_Tracer_Output_1 (Port_id, &Temp_Val);
      if (Ret) {
        return Ret;
      }

      *(Ltssm_Status + Index) = (*(Ltssm_Status + Index) << 32) | Temp_Val;
      Index++;

      Addr_Index++;
    }
  }

  *Ltssm_Num = Index;
  Ret = Hisi_Pcie_Set_Reg_Ltssm_Tracer_Recap (Port_id, 0x1);
  if (Ret) {
    return Ret;
  }

  return EFI_SUCCESS;
}

VOID
Pcie_Print_Ltssm_Trace (
  UINT64* Ltssm_Input,
  UINT32 Ltssm_Num
  )
{
  UINT32 Index;

  DEBUG((DEBUG_INFO, "ltssm tracer: \n"));
  DEBUG((DEBUG_INFO, "	trace mode: %d\n", (UINT8)*Ltssm_Input));
  DEBUG((DEBUG_INFO, "	ltssm[ii]:  63:48 47:32 31 30 29 28 27 26 25 24 23 22 21:20 19:12 11:10 9:6 5:0\n"));

  for (Index = 1; Index < Ltssm_Num; Index++) {
    DEBUG((DEBUG_INFO, "	ltssm[%02u]: 0x%04x %04x   %x  %x  %x  %x  %x  %x  %x  %x  %x  %x  %x     %02x    %x     %x   %02x\n",
           Index, ( UINT8)(*(Ltssm_Input + Index) >> 48) & 0xffff,
           ( UINT8)(*(Ltssm_Input + Index) >> 32) & 0xffff,
           ( UINT8)(*(Ltssm_Input + Index) >> 31) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 30) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 29) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 28) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 27) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 26) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 25) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 24) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 23) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 22) & 0x1,
           ( UINT8)(*(Ltssm_Input + Index) >> 20) & 0x3,
           ( UINT8)(*(Ltssm_Input + Index) >> 12) & 0x7f,
           ( UINT8)(*(Ltssm_Input + Index) >> 10) & 0x3,
           ( UINT8)(*(Ltssm_Input + Index) >> 6) & 0xf,
           ( UINT8)(*(Ltssm_Input + Index)) & 0x3f
          ));
  }
}

/*return:
 * 		0: ok
 * 		4: number fail
 * 		5: ltssm fail
 **/
EFI_STATUS
PcieCheckLtssm (
  UINT32 Ltssm_Type,
  UINT64* Ltssm_Input,
  UINT32 Ltssm_Num
  )
{
  UINT32 Ltssm_Ref[TRACER_DEPTH] = {0};
  UINT32 Ltssm_Ref_Num = TRACER_DEPTH;
  UINT32 Index;
  UINT64* Ltssm_In;

  switch (Ltssm_Type) {
      /* GEN1 linkup */
    case LTSSM_TYPE_1:
      Ltssm_Ref_Num = 16;
      Ltssm_Ref[0] = 0x1;
      Ltssm_Ref[1] = 0x2;
      Ltssm_Ref[2] = 0x3;
      Ltssm_Ref[3] = 0x4;
      Ltssm_Ref[4] = 0x5;
      Ltssm_Ref[5] = 0x6;
      Ltssm_Ref[6] = 0x7;
      Ltssm_Ref[7] = 0x9;
      Ltssm_Ref[8] = 0xa;
      Ltssm_Ref[9] = 0xb;
      Ltssm_Ref[10] = 0xc;
      Ltssm_Ref[11] = 0xd;
      Ltssm_Ref[12] = 0xf;
      Ltssm_Ref[13] = 0x10;
      break;

    case LTSSM_TYPE_NO:
    default:
      return EFI_SUCCESS;
  }

  if ((Ltssm_Num - 1) != Ltssm_Ref_Num) {
    DEBUG((DEBUG_ERROR, "Ltssm_Num is not true\n"));
    DEBUG((DEBUG_ERROR, "we need %d, but out is %d\n", Ltssm_Ref_Num, Ltssm_Num));

    return 4;
  }

  if (*Ltssm_Input != 0) {
    return EFI_SUCCESS;
  }

  Ltssm_In = Ltssm_Input + 1;
  for (Index = 0; Index < Ltssm_Ref_Num; Index++) {
    if ((*(Ltssm_In + Index) & 0x3f) != Ltssm_Ref[Index]) {
      DEBUG((DEBUG_ERROR, "Ltssm_Num is the same, but status isn't the same\n"));
      return 5;
    }
  }

  return EFI_SUCCESS;
}

EFI_STATUS
RcApInit (
  UINT32 Port_id
  )
{
  UINT32 Value;
  UINT32 Ret = 0;
  UINT32 Chip_id = PORTID_2_CHIPID (Port_id);

  /*set port valid*/
  Value = Pcie_Apb_Read (PORTID_2_CHIPID (Port_id), 0x20048);
  Value |= 0x1 << PORTID_ONECHIP (Port_id);
  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x20048, Value);

  /*stash disable*/
  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x5f08, 0x200);

  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x5f00, 1);
  Value = Pcie_Apb_Read (PORTID_2_CHIPID (Port_id), 0x5f10);
  Value &= ~(0x1 << 12);
  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x5f10, Value);
  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x5f00, 0);

  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x5f04, 1);
  Value = Pcie_Apb_Read (PORTID_2_CHIPID (Port_id), 0x5f0c);
  Value &= ~(0x1 << 12);
  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x5f0c, Value);
  Pcie_Apb_Write (PORTID_2_CHIPID (Port_id), 0x5f04, 0);

  /*set the max_payload_size_support of the port
   * which just support X2 to 256byte*/
  if ((PORTID_2_PORTNUM (Port_id) == 2) || \
      (PORTID_2_PORTNUM (Port_id) == 6) || \
      (PORTID_2_PORTNUM (Port_id) == 10) || \
      (PORTID_2_PORTNUM (Port_id) == 14)) {
    Hisi_Pcie_Rp_Cfg_Read (Port_id, 0x44, &Value);
    Value &= (~0x7);
    Value |= 0x1;
    Hisi_Pcie_Rp_Cfg_Write (Port_id, 0x44, Value);
  }

  /*axim latency Enable*/
  Pcie_Set_Ap_Ctrl_Lat_Stat_Wr_En (Port_id, 1);
  Pcie_Set_Ap_Ctrl_Lat_Stat_Rd_En (Port_id, 1);

  /*msi Address config*/
  /*TB ITS*/
  Pcie_Set_Ap_Its_Addr (PORTID_2_CHIPID (Port_id), 0, 0xa8110040 + Chip_id * 0x400000000000, 1, 1);
  /*For Windows TB ITS*/
  Pcie_Set_Ap_Its_Addr (PORTID_2_CHIPID (Port_id), 1, 0xAA000040 + Chip_id * 0x400000000000, 1, 1);

  /*NIMBUS ITS*/
  Pcie_Set_Ap_Its_Addr (PORTID_2_CHIPID (Port_id), 2, 0x202110040 + Chip_id * 0x400000000000, 1, 1);

  /*FS 1.7.18.5: odr sbm pfull threshold*/
  Ret = Hisi_Pcie_Ap_Iob_Rx_Odr_Reg_Read (PORTID_2_CHIPID (Port_id), 0x5c + 0x400 * PORTID_2_CORENUM (Port_id), &Value);
  if (Ret) {
    return Ret;
  } else {
    Value &= ~0xffff;
    Value |= 0x2020;
    Hisi_Pcie_Ap_Iob_Rx_Odr_Reg_Write (PORTID_2_CHIPID (Port_id), 0x5c + 0x400 * PORTID_2_CORENUM (Port_id), Value);
  }

  return EFI_SUCCESS;
}

VOID HisiPcieRpRemoveSerialNumberCap (UINT32 Port_id)
{
  U_VC_CAP_REG VcCap0;
  U_SECONDARY_PCIE_EXT_CAP_HEADER_REG SecPcieExtCap;

  if ((Port_id % PCIE_PORT_EACH_CHIP) == 0) {
    Hisi_Pcie_Rp_Cfg_Read (Port_id, VC_CAP_REG, &VcCap0.u32);
    VcCap0.bits.vc_next_cap_offset = ACS_CAP_REG;
    Hisi_Pcie_Rp_Cfg_Write (Port_id, VC_CAP_REG, VcCap0.u32);
  } else {
    Hisi_Pcie_Rp_Cfg_Read (Port_id, SECONDARY_PCIE_EXT_CAP_HEADER, &SecPcieExtCap.u32);
    SecPcieExtCap.bits.sec_pcie_next_cap_offset = ACS_CAP_REG;
    Hisi_Pcie_Rp_Cfg_Write (Port_id, SECONDARY_PCIE_EXT_CAP_HEADER, SecPcieExtCap.u32);
  }
  Hisi_Pcie_Rp_Cfg_Write (Port_id, DEVICE_SERIAL_NUMBER_CAP_HEADER, 0x00);
  Hisi_Pcie_Rp_Cfg_Write (Port_id, SERIAL_LNUM, 0x00);
  Hisi_Pcie_Rp_Cfg_Write (Port_id, SERIAL_HNUM, 0x00);
}

EFI_STATUS
RcTlInit (
  UINT32 Port_id
  )
{
  UINT32 Width;
  PORT_TL_CFG Tl_Cfg;

  Width = Get_Port_Width (Port_id);
    switch (Width) {
      case 16:
        Tl_Cfg.ph_vc0_cdt = 0x7f;
        Tl_Cfg.pd_vc0_cdt = 0x412;
        Tl_Cfg.nph_vc0_cdt = 0x7f;
        Tl_Cfg.npd_vc0_cdt = 0x20;
        Tl_Cfg.cplh_vc0_cdt = 0x7f;
        Tl_Cfg.cpld_vc0_cdt = 0x400;

        Tl_Cfg.ph_vc0_cdt_df = 0xd0;
        Tl_Cfg.pd_vc0_cdt_df = 0x412;
        Tl_Cfg.nph_vc0_cdt_df = 0xd0;
        Tl_Cfg.npd_vc0_cdt_df = 0x20;
        Tl_Cfg.cplh_vc0_cdt_df = 0x80;
        Tl_Cfg.cpld_vc0_cdt_df = 0x400;
        break;

      case 8:
        Tl_Cfg.ph_vc0_cdt = 0x68;
        Tl_Cfg.pd_vc0_cdt = 0x20a;
        Tl_Cfg.nph_vc0_cdt = 0x68;
        Tl_Cfg.npd_vc0_cdt = 0x10;
        Tl_Cfg.cplh_vc0_cdt = 0x40;
        Tl_Cfg.cpld_vc0_cdt = 0x200;

        Tl_Cfg.ph_vc0_cdt_df = 0x68;
        Tl_Cfg.pd_vc0_cdt_df = 0x20a;
        Tl_Cfg.nph_vc0_cdt_df = 0x68;
        Tl_Cfg.npd_vc0_cdt_df = 0x10;
        Tl_Cfg.cplh_vc0_cdt_df = 0x40;
        Tl_Cfg.cpld_vc0_cdt_df = 0x200;
        break;

      case 4:
        Tl_Cfg.ph_vc0_cdt = 0x28;
        Tl_Cfg.pd_vc0_cdt = 0xc8;
        Tl_Cfg.nph_vc0_cdt = 0x28;
        Tl_Cfg.npd_vc0_cdt = 0x4;
        Tl_Cfg.cplh_vc0_cdt = 0x8;
        Tl_Cfg.cpld_vc0_cdt = 0x20;

        Tl_Cfg.ph_vc0_cdt_df = 0x28;
        Tl_Cfg.pd_vc0_cdt_df = 0xc8;
        Tl_Cfg.nph_vc0_cdt_df = 0x28;
        Tl_Cfg.npd_vc0_cdt_df = 0x4;
        Tl_Cfg.cplh_vc0_cdt_df = 0x8;
        Tl_Cfg.cpld_vc0_cdt_df = 0x20;
        break;

      case 2:
        Tl_Cfg.ph_vc0_cdt = 0x10;
        Tl_Cfg.pd_vc0_cdt = 0x50;
        Tl_Cfg.nph_vc0_cdt = 0x10;
        Tl_Cfg.npd_vc0_cdt = 0x2;
        Tl_Cfg.cplh_vc0_cdt = 0x4;
        Tl_Cfg.cpld_vc0_cdt = 0x10;

        Tl_Cfg.ph_vc0_cdt_df = 0x10;
        Tl_Cfg.pd_vc0_cdt_df = 0x50;
        Tl_Cfg.nph_vc0_cdt_df = 0x10;
        Tl_Cfg.npd_vc0_cdt_df = 0x2;
        Tl_Cfg.cplh_vc0_cdt_df = 0x4;
        Tl_Cfg.cpld_vc0_cdt_df = 0x10;
        break;

      default : //(X8)
        Tl_Cfg.ph_vc0_cdt = 0x68;
        Tl_Cfg.pd_vc0_cdt = 0x20a;
        Tl_Cfg.nph_vc0_cdt = 0x68;
        Tl_Cfg.npd_vc0_cdt = 0x10;
        Tl_Cfg.cplh_vc0_cdt = 0x40;
        Tl_Cfg.cpld_vc0_cdt = 0x200;

        Tl_Cfg.ph_vc0_cdt_df = 0x68;
        Tl_Cfg.pd_vc0_cdt_df = 0x20a;
        Tl_Cfg.nph_vc0_cdt_df = 0x68;
        Tl_Cfg.npd_vc0_cdt_df = 0x10;
        Tl_Cfg.cplh_vc0_cdt_df = 0x40;
        Tl_Cfg.cpld_vc0_cdt_df = 0x200;
        break;
    }

  Tl_Cfg.ph_vc0_scale = 3;
  Tl_Cfg.pd_vc0_scale = 3;
  Tl_Cfg.nph_vc0_scale = 3;
  Tl_Cfg.npd_vc0_scale = 3;
  Tl_Cfg.cplh_vc0_scale = 3;
  Tl_Cfg.cpld_vc0_scale = 3;

  DEBUG((DEBUG_INFO, "RP TL init\n"));

  Pcie_Set_Post_Cdt_Df (Port_id, 3, 0, Tl_Cfg.ph_vc0_cdt, Tl_Cfg.pd_vc0_cdt);
  Pcie_Set_Nonpost_Cdt_Df (Port_id, 3, 0, Tl_Cfg.nph_vc0_cdt, Tl_Cfg.npd_vc0_cdt);
  Pcie_Set_Cpl_Cdt_Df (Port_id, 3, 0, Tl_Cfg.cplh_vc0_cdt, Tl_Cfg.cpld_vc0_cdt);
  Pcie_Set_Cdt_Initup_Df (Port_id);

  Pcie_Set_Post_Cdt (Port_id, 0, Tl_Cfg.ph_vc0_cdt, Tl_Cfg.pd_vc0_cdt);
  Pcie_Set_Nonpost_Cdt (Port_id, 0, Tl_Cfg.nph_vc0_cdt, Tl_Cfg.npd_vc0_cdt);
  Pcie_Set_Cpl_Cdt (Port_id, 0, Tl_Cfg.cplh_vc0_cdt, Tl_Cfg.cpld_vc0_cdt);
  Pcie_Set_Cdt_Initup (Port_id);

  /* 1620 PCIE FS: chapter 1.8.2.6:
     For 1620 mode, all four ports of port0,port2,port4 and port6 in Core2, Field
     tl_tx_th of TL_TX_TH need to be set 0xA by local CPU at initialization.
  */
  if (PORTID_2_CORENUM (Port_id) == 0x02) {
    Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_TX_TH_REG, 0x0A);
  } else {
    Hisi_Pcie_Core_Port_Reg_Write (Port_id, TL_REG_OFFSET, PCIe_HIPCIEC_TL_REG_TL_TX_TH_REG, 0x08);
  }

  /* 1620 PCIE FS: chapter PCIe TL initialization flow
      2.  PCIe port is RP mode
      7)  Remove device serial number capability:
  */
  HisiPcieRpRemoveSerialNumberCap (Port_id);

  return EFI_SUCCESS;
}

/*
 * port mac layer configuration
 * */
EFI_STATUS
PciePortMacConfig (
  UINT32 Port_id
  )
{
  UINT32 Ret = 0;

  Ret = Hisi_Pcie_Set_Auto_Speed_Change_En (Port_id, AUTO_SPD_CHANGE_EN);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Set_First_Auto_Speed_Change_En (Port_id, FIRST_AUTO_SPD_CHG_EN);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Set_Disable_Enter_Compliance (Port_id, ENTER_COMPLIANCE_DIS);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Set_Disable_Enter_Hotreset (Port_id, ENTER_HOTRST_DIS);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Set_Disable_Enter_Disable (Port_id, ENTER_DISABLE_DIS);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Set_Disable_Enter_Loopback (Port_id, ENTER_LOOPBAK_DIS);
  if (Ret) {
    return Ret;
  }

  /*set framing err retrain Enable*/
  (VOID)Hisi_Pcie_Set_Reg_Framing_Err_Retrain_En (Port_id, 0);

  return EFI_SUCCESS;
}

EFI_STATUS
RcCfgDefConfig (
  UINT32 Port_id
  )
{
  UINT32 Ret = 0;
  UINT32 Type = 0, Sub = 0, Pgm_Inf = 0;

  RC_LTSSM* pCfg = GetRcLtssm (Port_id);
  if (!pCfg) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d get ltssm fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_EPARAM;
  }

  DEBUG((DEBUG_INFO, "[%a]:[%dL]: Expected Max Link Speed = 0x%x \n", __FUNCTION__, __LINE__, pCfg->max_lk_spd));
  DEBUG((DEBUG_INFO, "[%a]:[%dL]: Expected Max Width = 0x%x \n", __FUNCTION__, __LINE__, pCfg->max_sup_width));
  DEBUG((DEBUG_INFO, "[%a]:[%dL]: Expected Target Link Speed = 0x%x \n", __FUNCTION__, __LINE__, pCfg->target_speed));

  Ret = Hisi_Pcie_Rp_Set_Max_Link_Speed (Port_id, pCfg->max_lk_spd);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Rp_Set_Max_Link_Width (Port_id, pCfg->max_sup_width);
  if (Ret) {
    return Ret;
  }

  Ret = Hisi_Pcie_Rp_Set_Target_Link_Speed (Port_id, pCfg->target_speed);
  if (Ret) {
    return Ret;
  }

  /*class code check and init*/
  Hisi_Pcie_Rp_Get_Base_Class_Code (Port_id, &Type);
  Hisi_Pcie_Rp_Get_Sub_Class_Code (Port_id, &Sub);
  Hisi_Pcie_Rp_Get_Program_Inf (Port_id, &Pgm_Inf);
  DEBUG((DEBUG_INFO, "[%a]:[%dL]: port %d class code 0x%x\n", __FUNCTION__, __LINE__, Port_id, (Type << 24) | (Sub << 16) | (Pgm_Inf << 8)));

  if (Type != 0x6) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d base class code Error 0x%x != 0x6\n", __FUNCTION__, __LINE__, Port_id, Type));
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: init class code\n", __FUNCTION__, __LINE__));
    Hisi_Pcie_Rp_Set_Base_Class_Code (Port_id, 6);
    Hisi_Pcie_Rp_Set_Sub_Class_Code (Port_id, 4);
    Hisi_Pcie_Rp_Set_Program_Inf (Port_id, 0);
  }

  /* Set msi vector Number for AER + DPC */
  Hisi_Pcie_Rp_Set_Aer_Int_Num (Port_id, 1);
  Hisi_Pcie_Rp_Set_Dpc_Int_Msg_Num (Port_id, 2);

  /*close dl feature*/
  Hisi_Pcie_Rp_Set_Feature_Exchange_En (Port_id, 0);

  // Enable ACS Source Validation function
  Hisi_Pcie_Rp_Set_Acs_Src_Vld_En (Port_id, 1);

  // Set Crs_Sw_Visibility for ES sample.
  Hisi_Pcie_Rp_Set_Crs_Sw_Visibility (Port_id, 1);

  return EFI_SUCCESS;
}

EFI_STATUS
PciePortGlobalConfig (
  UINT32 Port_id,
  PORT_GLOBAL_CFG* Glb_Cfg
  )
{
  UINT32 Ret = 0;
  PORT_GLOBAL_CFG* pGlobalCfg = Glb_Cfg;

  if (pGlobalCfg == NULL) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d param fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_EPARAM;
  }

  DEBUG((DEBUG_INFO, "[%a]:[%dL] Set Port Enable\n", __FUNCTION__, __LINE__));
  Ret = Pcie_Global_Set_Port_Mode (Port_id, PORT_RP);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d set port mode fail\n", __FUNCTION__, __LINE__, Port_id));
    return Ret;
  }

  DEBUG((DEBUG_INFO, "[%a]:[%dL] Set port Lane number\n", __FUNCTION__, __LINE__));
  Ret = Pcie_Global_Set_Port_LaneNum (Port_id, pGlobalCfg->lane_num);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d set port number fail\n", __FUNCTION__, __LINE__, Port_id));
    return Ret;
  }

  // This register Value is large than 0x3E.
  // And is double than the Value of cfg_rst_dly_cnt register.
  DEBUG((DEBUG_INFO, "[%a]:[%dL] Set Linkdown reset Number\n", __FUNCTION__, __LINE__));
  Ret = Pcie_Global_Set_Port_Linkdown_Rst_Num (Port_id, LKD_RST_NUM);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d set port number fail\n", __FUNCTION__, __LINE__, Port_id));
    return Ret;
  }

  DEBUG((DEBUG_INFO, "[%a]:[%dL] Set port reset delay Count\n", __FUNCTION__, __LINE__));
  Ret = Pcie_Global_Set_Port_Dly_Cnt (Port_id, RST_DLY_CNT);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d reset delay Count fail\n", __FUNCTION__, __LINE__, Port_id));
    return Ret;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
PciePortDereset (
  UINT32 Port_id,
  UINT32 Lanes
  )
{
  UINT32 Ret = 0;
  UINT32 Count = 0;

  DEBUG((DEBUG_INFO, "Start port Dereset\n"));
  Ret = Pcie_Serdes_Lane_Dereset (Port_id);

  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d serdes lane dereset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  DEBUG((DEBUG_INFO, "Pcie_Pcs_Apb_Dereset\n"));
  Ret = Pcie_Pcs_Apb_Dereset (Port_id);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d pcs apb dereset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  DEBUG((DEBUG_INFO, "Pcie_Pcs_Lane_Dereset\n"));
  Ret = Pcie_Pcs_Lane_Dereset (Port_id, Transe_Gbl_Lane_Num_To_Cfg_Width (Lanes));
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d pcs lane dereset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  DEBUG((DEBUG_INFO, "Pcie_Port_Logic_Dereset\n"));
  Ret = Pcie_Port_Logic_Dereset (Port_id);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d logic dereset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  Ret = Pcie_Port_Sticky_Dereset (Port_id);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d sticky dereset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  //must check port dereset status
  while (Count < 10) {
    if (!Pcie_Check_Dereset (Port_id)) {
      break;
    }

    MicroSecondDelay (10);
    Count++;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
PciePortReset (
  UINT32 Port_id,
  UINT32 Lanes
  )
{
  UINT32       Ret;
  UINT32       Count = 0;

  DEBUG((DEBUG_INFO, "Start port reset\n"));
  Ret = Pcie_Set_Port_En_Enable (Port_id, 0);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d disable fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  DEBUG((DEBUG_INFO, "Pcie_Port_Logic_Reset\n"));
  Ret = Pcie_Port_Logic_Reset (Port_id);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d logic reset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  DEBUG((DEBUG_INFO, "Pcie_Port_Sticky_Reset\n"));
  Ret = Pcie_Port_Sticky_Reset (Port_id);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d sticky reset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  DEBUG((DEBUG_INFO, "Pcie_Pcs_Lane_Reset\n"));
  Ret = Pcie_Pcs_Lane_Reset (Port_id, Transe_Gbl_Lane_Num_To_Cfg_Width(Lanes));
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d pcs lane reset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  Ret = Pcie_Serdes_Lane_Reset (Port_id);
  if (Ret) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d serdes lane reset fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_ERST;
  }

  //must check port reset status
  while (Count < 10) {
    if (!Pcie_Check_Reset (Port_id)) {
      break;
    }

    MicroSecondDelay (10);
    Count++;
  }

  return EFI_SUCCESS;
}

EFI_STATUS
PcieEstablishLink (
  RC_LTSSM* Cfg,
  UINT32 Port_id
  )
{
  UINT32      Ret;
  RC_LTSSM*   pCfg = Cfg;

  if (pCfg == NULL) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d param fail\n", __FUNCTION__, __LINE__, Port_id));
    return PCIE_EPARAM;
  }

  DEBUG((DEBUG_INFO, "Start port reset\n"));
  Ret = PciePortReset (Port_id, pCfg->glb_cfg.lane_num);
  if (Ret) {
    return PCIE_ELINK;
  }

  DEBUG((DEBUG_INFO, "Start port Dereset\n"));
  Ret = PciePortDereset (Port_id, pCfg->glb_cfg.lane_num);
  if (Ret) {
    return PCIE_ELINK;
  }

  /*  Later Need Add Check Total Lane Num. Max support is 40 Lanes in 1 Chip  */
#ifdef DEBUG
  DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d config:\n", __FUNCTION__, __LINE__, Port_id));
  DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port lane num: %d\n", __FUNCTION__, __LINE__, pCfg->glb_cfg.lane_num));
#endif

  // Config port working mode，lane Number.
  Ret = PciePortGlobalConfig (Port_id, &(pCfg->glb_cfg));
  if (Ret) {
    return PCIE_ELINK;
  }

  // Config default Configuration space.
  DEBUG((DEBUG_INFO, "\r Start RcCfgDefConfig\n"));
  Ret = RcCfgDefConfig (Port_id);
  if (Ret) {
    return Ret;
  }

  // Config equalization setting.
  // To do.

  // config MAC setting.
  DEBUG((DEBUG_INFO, "Start PciePortMacConfig\n"));
  Ret = PciePortMacConfig (Port_id);
  if (Ret) {
    return Ret;
  }

  //Config TL_REG for each port.
  Ret = RcTlInit (Port_id);
  if (Ret) {
    return Ret;
  }

  //Config RC_AP for each port.
  Ret = RcApInit (Port_id);
  if (Ret) {
    return Ret;
  }

  //clear port-en or not when linkdown occured
  DEBUG((DEBUG_INFO, "Start Pcie_Port_Linkdown_Clr_Port_En\n"));
  Ret = Pcie_Port_Linkdown_Clr_Port_En (Port_id, &(pCfg->glb_cfg));
  if (Ret) {
    return Ret;
  }

  //reset the port or not when linkdown occured
  DEBUG((DEBUG_INFO, "Start Pcie_Port_Linkdown_Rst_En\n"));
  Ret = Pcie_Port_Linkdown_Rst_En (Port_id, &(pCfg->glb_cfg));
  if (Ret) {
    return Ret;
  }

  MicroSecondDelay (1);

  //port Enable
  DEBUG((DEBUG_INFO, "Start pcie_set_port_en\n"));
  Pcie_Set_Port_En_Enable (Port_id, PORT_EN);

  return EFI_SUCCESS;
}

/* After link up, check if link status match the request.
 * return:
 * 	  < 0: read Reg fail
 * 	    0: ok
 * 	    1: speed fail
 * 	    2: Width fail
 * 	    3: ltssm fail
 **/
UINT8
PcieCheckLinkStat (
  UINT32 Port_id,
  UINT32 tgt_spd,
  UINT32 tgt_w,
  UINT32 Ltssm_Type
  )
{
  UINT32 Ret = 0;
  UINT32 Value = 0;
  UINT8  Error = 0;
  UINT32 Ltssm_Num;
  UINT64 Ltssm_St_Save[TRACER_DEPTH];

  Ret = Hisi_Pcie_Get_Mac_Cur_Link_Speed (Port_id, &Value);
  if (Ret) {
    return Ret;
  }

  if (Value != tgt_spd) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d link speed check fail, %d != %d\n", __FUNCTION__, __LINE__, Port_id, Value, tgt_spd));
    Error = 1;
  }

  Ret = Hisi_Pcie_Get_Mac_Cur_Link_Width (Port_id, &Value);
  if (Ret) {
    return Ret;
  }

  if (Value != tgt_w) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d link Width check fail, %d != %d\n", __FUNCTION__, __LINE__, Port_id, Value, tgt_w));
    if (!Error) {
	  Error = 2;
	}
  }

  /* will print ltssm check fail, 4/1 confirm that it's known issue.
     some status is not sure, will fix it later by Linux Owner,
     then BIOS should sync the code. */
  Ret = Pcie_Get_Ltssm_Trace (Port_id, Ltssm_St_Save, &Ltssm_Num);
  if (Ret) {
    if (!Error) {
	  Error = 4;
	}
  }

  Pcie_Print_Ltssm_Trace (Ltssm_St_Save, Ltssm_Num);

  return Error;
}

EFI_STATUS
PcieGetLinkStatus (
  UINT32 Port_id
  )
{
  UINT32 Ret = 0;
  UINT32 Value = 0;
  UINT32 Count = 0;

  UINT32 Spd = 0;
  UINT32 Ltssm_Status = 0;
  UINT32 Width = 0;

  while (Count < 100) {
    Ret = Hisi_Pcie_Get_Mac_Link_Up (Port_id, &Value);
    if (Ret) {
      return PCIE_ERD;
    }

    if (Value) {
      break;
    }

    Count++;
    MicroSecondDelay (10);
  }

  Hisi_Pcie_Get_Mac_Cur_Link_Speed (Port_id, &Spd);
  Hisi_Pcie_Get_Mac_Cur_Link_Width (Port_id, &Width);
  Hisi_Pcie_Get_Mac_Ltssm_Info (Port_id, &Ltssm_Status);

  DEBUG((DEBUG_INFO, "[%a]:[%dL]: port %d: \n", __FUNCTION__, __LINE__, Port_id));
  DEBUG((DEBUG_INFO, "[%a]:[%dL]:        ltssm st: %x\n", __FUNCTION__, __LINE__, Ltssm_Status));
  DEBUG((DEBUG_INFO, "[%a]:[%dL]:        speed: %d\n", __FUNCTION__, __LINE__, Spd));
  DEBUG((DEBUG_INFO, "[%a]:[%dL]:        Width: %d\n", __FUNCTION__, __LINE__, Width));

  if (Value) {
    return EFI_SUCCESS;
  }

  return PCIE_ELINK;
}

EFI_STATUS
PcieRcEstablishLink (
  UINT32 Port_id
  )
{
  RC_LTSSM* pCfg = GetRcLtssm (Port_id);

  DEBUG((DEBUG_INFO, "Start establish link\n"));

  if (pCfg == NULL) {
    return PCIE_EPARAM;
  }

  return PcieEstablishLink (pCfg, Port_id);
}

EFI_STATUS
PcieEcamInit (
  UINT32 Port_Id,
  UINT32 Addr_Low,
  UINT32 Addr_High,
  UINT32 Start_Bus
  )
{
  UINT32 Ret;
  UINT8  Chip_id;
  U_IOB_ECAM_CONTROL Reg_Val;

  Chip_id = PORTID_2_CHIPID (Port_Id);

  if (Ecam_Inited[Chip_id] == 0xAA) {
    DEBUG((DEBUG_INFO, "Already init done...\n"));
    return EFI_SUCCESS;
  }

  if (Chip_id == 0) {
    Start_Bus = 0x00;
  }
  else if (Chip_id == 1) {
    Start_Bus = 0x80;
  }
  else if (Chip_id == 2) {
    Start_Bus = 0xC0;
  }
  else if (Chip_id == 3) {
    Start_Bus = 0xE0;
  }

  // LSB 32-bit Addr
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (PORTID_2_CHIPID (Port_Id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_ECAM_BASE_ADDR_L_REG, Addr_Low);
  if (Ret) {
    return Ret;
  }

  // MSB 32-bit Addr
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (PORTID_2_CHIPID (Port_Id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_ECAM_BASE_ADDR_H_REG, Addr_High);
  if (Ret) {
    return Ret;
  }

  // Satrt Bus Init
  Ret = Hisi_Pcie_Ap_Iob_Reg_Read (PORTID_2_CHIPID (Port_Id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_ECAM_CONTROL_REG, &Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  Reg_Val.bits.iob_ecam_start_bus = Start_Bus;
  Ret = Hisi_Pcie_Ap_Iob_Reg_Write (PORTID_2_CHIPID (Port_Id), PCIe_HIPCIEC_AP_IOB_TX_REG_IOB_ECAM_CONTROL_REG, Reg_Val.u32);
  if (Ret) {
    return Ret;
  }

  //Set flag
  Ecam_Inited[Chip_id] = 0xAA;

  return EFI_SUCCESS;
}

VOID
GetLtssmDefConfig (
  UINT32    PortId,
  UINT32    ConfigIdx,
  RC_LTSSM  *pCfg
  )
{
  UINT32     Index = 0;
  RC_LTSSM   *pConfigIdx;

  while (LtssmConfigTable[Index].Config >= 0) {
    if (LtssmConfigTable[Index].Config != ConfigIdx) {
      DEBUG ((DEBUG_INFO, "[%s][%d]Table-Config= %u\n", __FUNCTION__, __LINE__, LtssmConfigTable[Index].Config));
      Index++;
      continue;
    }

    pConfigIdx = (RC_LTSSM*)LtssmConfigTable[Index].Data;

    //copy default configuration
    pCfg->max_sup_width   = pConfigIdx->max_sup_width;
    pCfg->max_lk_spd      = pConfigIdx->max_lk_spd;
    pCfg->target_speed    = pConfigIdx->target_speed;
    pCfg->tgt_lk_spd      = pConfigIdx->tgt_lk_spd;
    pCfg->tgt_lk_width    = pConfigIdx->tgt_lk_width;

    //global configuration
    pCfg->glb_cfg.lane_num        = pConfigIdx->glb_cfg.lane_num;
    pCfg->glb_cfg.linkdown_rst_en = pConfigIdx->glb_cfg.linkdown_rst_en;
    pCfg->glb_cfg.linkdown_clr_port_en = pConfigIdx->glb_cfg.linkdown_clr_port_en;

    break;
  }

  return;
}

EFI_STATUS
PciePortInit (
  UINT32  PortId,
  UINT32  ParamIdx
  )
{
  RC_LTSSM      *pLtssmCfg;
  UINT32        EcamBaseAddr = 0;
  EFI_STATUS    Status = EFI_SUCCESS;

  if (PortId > MAX_PORTS) {
    return EFI_INVALID_PARAMETER;
  }

  pLtssmCfg = GetRcLtssm (PortId);
  if (!pLtssmCfg){
    DEBUG((DEBUG_ERROR, "[%a]:[%dL] Allocate ltssm Address failed!\n", __FUNCTION__, __LINE__));
    return RETURN_BAD_BUFFER_SIZE;
  }

  // Get the default config parameter for each port.
  (VOID)GetLtssmDefConfig (PortId, ParamIdx, pLtssmCfg);

  EcamBaseAddr = PcdGet64 (PcdPciExpressBaseAddress);
  (VOID)PcieEcamInit (PortId, EcamBaseAddr, 0, 0);

  (VOID)PcieRcEstablishLink (PortId);

  Status = PcieGetLinkStatus (PortId);
  if (Status == EFI_SUCCESS) {
    DEBUG ((DEBUG_INFO, "[%a]:[%dL]: port %d link up\n", __FUNCTION__, __LINE__, PortId));
  } else {
    DEBUG ((DEBUG_ERROR, "[%a]:[%dL]: port %d link fail, Status = %x\n",__FUNCTION__, __LINE__, PortId, Status));
  }

  Status = PcieCheckLinkStat (PortId, pLtssmCfg->tgt_lk_spd, pLtssmCfg->tgt_lk_width, pLtssmCfg->tgt_lk_spd);
  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "[%a]:[%dL]: port %d check stat fail, Status = %x\n",__FUNCTION__, __LINE__, PortId, Status));
    return Status;
  }

  return EFI_SUCCESS;
}
