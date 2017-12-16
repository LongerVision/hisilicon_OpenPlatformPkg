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

#include <Library/BaseMemoryLib.h>
#include <Library/OemMiscLib.h>
#include <Library/PcdLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <PcieInit.h>

PCIE_CTRL g_PCIE[MAX_CHIPS];

/* Port setting selection */
UINT32
PCIE_PORT_CONFIG_SELECT [4] = {
  PCIE_X16_GEN4_LINKUP,
  PCIE_X8_GEN4_LINKUP,
  PCIE_X1_GEN2_LINKUP,
  PCIE_X8_GEN1_LINKUP
};

VOID RegHalInit()
{
  PCIE_CTRL   *pcie;
  UINTN       apb_base;
  UINTN       pcs_base;
  UINT8       MaxChipNum = 1;

  UINT32      k = 0;
  UINT32      chip_id = 0;

  if (!OemIsMpBoot ()) {
    MaxChipNum = 1;  // 1P
  } else {
    MaxChipNum = 2;  // 2P
  }

  /* Hi1620 Base Reg Init*/
  for (chip_id = 0; chip_id < MaxChipNum; chip_id++) {
    pcie = &g_PCIE[chip_id];

    // pcie->apb
    apb_base =  APB_BASE_ADDR + chip_id * 0x400000000000;
    if (!(UINTN *)apb_base) {
      DEBUG((DEBUG_ERROR,"NULL Apb Base Address!\n"));
      return;
    }

    // pcie->pcs
    pcs_base =  APB_BASE_ADDR + PCIE_PCS_OFFSET;
    if (!(UINTN*)pcs_base) {
      DEBUG((DEBUG_ERROR,"NULL PCS Base Address!\n"));
      return;
    }

    pcie->subctrl_base = SUBCTRL_BASE_ADDR + chip_id * 0x400000000000;
    if (!(UINTN*)pcie->subctrl_base) {
      DEBUG((DEBUG_ERROR,"NULL SubCtrl Base Address!\n"));
      return;
    }

    //pcie->event_collector
    pcie->apb_base      = apb_base;
    pcie->ap_iob_tx     = apb_base + AP_IOB_TX;
    pcie->ap_iob_rx_com = apb_base + AP_IOB_RX_COM;
    pcie->ap_iob_rx_am  = apb_base + AP_IOB_RX_AM;
    pcie->ap_iob_rx_odr = apb_base + AP_IOB_RX_ODR;
    pcie->ap_mg         = apb_base + AP_MG;
    pcie->ap_dma        = apb_base + AP_DMA;
    pcie->ap_int        = apb_base + AP_INT;
    pcie->pcie_global   = apb_base + PCIE_GLOBAL;

    for (k = 0; k < PCIE_MAX_CORE_NUM; k++) {
      pcie->core_global[k] = apb_base + ((k + 1) * 0x80000);
      pcie->pcs[k] = pcs_base + k * 0x10000;

      DEBUG((DEBUG_INFO,"core_global[%x] = 0x%p \n", k, pcie->core_global[k]));
      DEBUG((DEBUG_INFO,"pcs[%x] = 0x%p \n", k, pcie->pcs[k]));
    }

    for (k = 0; k < 20; k++) {
      pcie->core_port[k] = pcie->core_global[PORTID_2_CORENUM(k)] + (PORTID_2_PORTNUM(k) + 1) * 0x4000;
      if (k < 10) {
        DEBUG((DEBUG_INFO,"core_port[%x]  = 0x%p  \n", k, pcie->core_port[k]));
      }
    }
  }

  DEBUG((DEBUG_INFO,"pcie_probe apb_base = 0x%p\n", apb_base));
  DEBUG((DEBUG_INFO,"pcie_probe pcs_base = 0x%p\n", pcs_base));
  DEBUG((DEBUG_INFO,"pcie_probe subctrl_base = 0x%p\n", pcie->subctrl_base));
  DEBUG((DEBUG_INFO,"pcie_probe ap_iob_tx = 0x%p\n", pcie->ap_iob_tx));
  DEBUG((DEBUG_INFO,"pcie_probe ap_iob_rx_com = 0x%p\n", pcie->ap_iob_rx_com));
  DEBUG((DEBUG_INFO,"pcie_probe ap_iob_rx_am = 0x%p\n", pcie->ap_iob_rx_am));
  DEBUG((DEBUG_INFO,"pcie_probe ap_iob_rx_odr = 0x%p\n", pcie->ap_iob_rx_odr));
  DEBUG((DEBUG_INFO,"pcie_probe ap_int = 0x%p\n", pcie->ap_int));
  DEBUG((DEBUG_INFO,"pcie_probe ap_mg = 0x%p\n", pcie->ap_mg));
  DEBUG((DEBUG_INFO,"pcie_probe ap_dma = 0x%p\n", pcie->ap_dma));

  return;
}

EFI_STATUS
PcieInitEntry (
  IN EFI_HANDLE                 ImageHandle,
  IN EFI_SYSTEM_TABLE           *SystemTable
  )
{
  EFI_STATUS         Status = EFI_SUCCESS;
  UINT32             Port_id;
  UINT32             Atu_type;          //0: 64-Pre 1: 32-pre 2: 32-NonPre 3: I/O
  UINT32             Config_Select;
  UINT32             FinalSel = 0;
  UINT8              MaxPortNum = 0;
  UINT8              MaxAtuNum = 0;
  UINT32             Port_id_enable[9];
  UINT32             Port_Config_sel[9];

  (VOID) SetMem((VOID *)Port_id_enable, sizeof(Port_id_enable), 0xFF);
  (VOID) SetMem((VOID *)Port_Config_sel, sizeof(Port_Config_sel), 0xFF);

  // Init Global PCIE Base address.
  (VOID)RegHalInit();

  if (!OemIsMpBoot ()) {
    // 1P
    MaxPortNum = MAX_PORT_NUM_1P;
    MaxAtuNum  = MAX_ATU_NUM_1P;
    Port_id_enable[0] = 0;
    Port_id_enable[1] = 8;
    Port_id_enable[2] = 12;
    Port_id_enable[3] = 16;
    Port_id_enable[4] = 17;
    Port_Config_sel[0] = PCIE_PORT_CONFIG_SELECT[0];
    Port_Config_sel[1] = PCIE_PORT_CONFIG_SELECT[1];
    Port_Config_sel[2] = PCIE_PORT_CONFIG_SELECT[1];
    Port_Config_sel[3] = PCIE_PORT_CONFIG_SELECT[2];
    Port_Config_sel[4] = PCIE_PORT_CONFIG_SELECT[2];
  } else {
    // 2P.
    MaxPortNum = MAX_PORT_NUM_2P;
    MaxAtuNum  = MAX_ATU_NUM_2P;
    Port_id_enable[0] = 0;
    Port_id_enable[1] = 8;
    Port_id_enable[2] = 12;
    Port_id_enable[3] = 16;
    Port_id_enable[4] = 17;
    Port_id_enable[5] = 20;
    Port_id_enable[6] = 28;
    Port_id_enable[7] = 32;
    Port_id_enable[8] = 36;
    Port_Config_sel[0] = PCIE_PORT_CONFIG_SELECT[0];
    Port_Config_sel[1] = PCIE_PORT_CONFIG_SELECT[1];
    Port_Config_sel[2] = PCIE_PORT_CONFIG_SELECT[1];
    Port_Config_sel[3] = PCIE_PORT_CONFIG_SELECT[2];
    Port_Config_sel[4] = PCIE_PORT_CONFIG_SELECT[2];
    Port_Config_sel[5] = PCIE_PORT_CONFIG_SELECT[0];
    Port_Config_sel[6] = PCIE_PORT_CONFIG_SELECT[1];
    Port_Config_sel[7] = PCIE_PORT_CONFIG_SELECT[1];
    Port_Config_sel[8] = PCIE_PORT_CONFIG_SELECT[1];
  }

  for (Port_id = 0;  Port_id < MaxPortNum; Port_id++) {
    if (Port_id == Port_id_enable[FinalSel]) {
      Config_Select = Port_Config_sel[FinalSel];
      FinalSel++;
    } else {
      continue;
    }

    Status = PciePortInit (Port_id, Config_Select);
    if (EFI_ERROR(Status)) {
      DEBUG((DEBUG_ERROR, "Pcie Port %d Init Failed! \n", Port_id));
    }
  }

  DEBUG((DEBUG_INFO, "Pcie iATU Init Start! \n"));
  for (Atu_type = 0; Atu_type < MaxAtuNum; Atu_type++) {
    Status = IatuInit (Atu_type);
    if (EFI_ERROR(Status)) {
      DEBUG((DEBUG_ERROR, "Pcie Port %d Init Failed! \n", Atu_type));
    }
  }

  return Status;
}
