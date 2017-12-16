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

#ifndef __PCIE_INIT_LIB_H__
#define __PCIE_INIT_LIB_H__

#include <Library/IoLib.h>
#include <PcieApIobTxReg.h>
#include <PcieApIobRxComReg.h>
#include <PcieApIobRxAmReg.h>
#include <PcieGlobalReg.h>
#include <PcieMacReg.h>
#include <PcieRpCfgSpaceReg.h>
#include <PcieTlReg.h>
#include <PcieTxAtuReg.h>
#include <Uefi.h>

#define MAX_CHIPS               (2)
#define PCIE_MAX_CORE_NUM       (3)
#define PCIE_PORT_EACH_CHIP     (20)

// Port Number.
#define MAX_PORTS               (PCIE_PORT_EACH_CHIP * MAX_CHIPS)
#define PORTID_ONECHIP(p)       ((p) % PCIE_PORT_EACH_CHIP)             /* 0 ~ 19 */
#define PORTID_2_CHIPID(p)      ((p) / PCIE_PORT_EACH_CHIP)             /* 0 ->Chip0, 1 ->Chip1.      */
#define PORTID_2_CORENUM(p)     (PORTID_ONECHIP(p)>>3)                  /* Pcie Core -> 0, 1, 2       */
#define PORTID_2_PORTNUM(p)     ((PORTID_ONECHIP(p) % 8) << 1)             /* Port 0 ~ 7, 8 ~ 15, 16 ~ 19,
                                                                          translate to FS define Port
                                                                          2/4/6/8/10/12/14            */
#define TRACER_DEPTH        65
#define LTSSM_TYPE_1        GEN1
#define LTSSM_TYPE_2        GEN2
#define LTSSM_TYPE_3        GEN3
#define LTSSM_TYPE_4        GEN4
#define LTSSM_TYPE_5        0x10    // recovery ltssm
#define LTSSM_TYPE_6        0x11    // disable ltssm
#define LTSSM_TYPE_NO       0x100   // do not check ltssm

#define AP_IOB_TX           0x0
#define AP_IOB_RX_COM       0x4000
#define AP_IOB_RX_AM        0x6000
#define AP_IOB_RX_ODR       0x6400
#define AP_MG               0x8000
#define AP_DMA              0xc000
#define AP_INT              0x10000
#define PCIE_GLOBAL         0x20000

#define TL_REG_OFFSET       0x0
#define CFG_REG_OFFSET      0x1000
#define DL_REG_OFFSET       0x2000
#define MAC_REG_OFFSET      0x3000

#define SECONDARY_PCIE_EXT_CAP_HEADER      0x0310
#define VC_CAP_REG                         0x0400
#define DEVICE_SERIAL_NUMBER_CAP_HEADER    0x04e0
#define SERIAL_LNUM                        0x04e4
#define SERIAL_HNUM                        0x04e8
#define ACS_CAP_REG                        0x0630
// All Base Address
#define APB_BASE_ADDR       0x148200000
#define SUBCTRL_BASE_ADDR   0x148070000
#define PCIE_PCS_OFFSET     0x1c0000

// Port attrbution define.
#define PORT_EP         (0)
#define PORT_RP         (1)

#define PORT_EN         (1)

#define AUTO_SPD_CHANGE_EN     (1)
#define ENTER_COMPLIANCE_DIS   (1)
#define ENTER_DISABLE_DIS      (0)
#define ENTER_HOTRST_DIS       (0)
#define ENTER_LOOPBAK_DIS      (0)
#define FIRST_AUTO_SPD_CHG_EN  (0)

#define GEN1            (0x1)
#define GEN2            (0x2)
#define GEN3            (0x3)
#define GEN4            (0x4)

#define GBL_WX1         (0x0)
#define GBL_WX2         (0x1)
#define GBL_WX4         (0x2)
#define GBL_WX8	        (0x3)
#define GBL_WX16        (0x4)

#define CFG_WX1         (0x1)
#define CFG_WX2         (0x2)
#define CFG_WX4         (0x4)
#define CFG_WX8	        (0x8)
#define CFG_WX16        (0x10)

#define LKD_RST_NUM     (0x3F)
#define RST_DLY_CNT     (0x1F)

//Error definition.
#define PCIE_ERR        (0x10000000)
#define PCIE_ERST       (PCIE_ERR + 0x1)
#define PCIE_EPARAM     (PCIE_ERR + 0x2)
#define PCIE_ELINK      (PCIE_ERR + 0x3)
#define PCIE_ERD        (PCIE_ERR + 0x4)
#define PCIE_EWR        (PCIE_ERR + 0x5)
#define PCIE_ENOMEM     (PCIE_ERR + 0x6)

// Bit shift define
#define SetBit(dat, i)   ((dat) |= ((UINT32)1 << (i)))
#define ClearBit(dat, i) ((dat) &= (~((UINT32)0x01 << (i))))

typedef struct {
  UINT32      lane_num;
  UINT32      linkdown_clr_port_en;
  UINT32      linkdown_rst_en;
} PORT_GLOBAL_CFG;

typedef struct {
  UINT32      ph_vc0_cdt;
  UINT32      pd_vc0_cdt;
  UINT32      nph_vc0_cdt;
  UINT32      npd_vc0_cdt;
  UINT32      cplh_vc0_cdt;
  UINT32      cpld_vc0_cdt;

  UINT32      ph_vc0_scale;
  UINT32      pd_vc0_scale;
  UINT32      nph_vc0_scale;
  UINT32      npd_vc0_scale;
  UINT32      cplh_vc0_scale;
  UINT32      cpld_vc0_scale;
  UINT32      ph_vc0_cdt_df;
  UINT32      pd_vc0_cdt_df;
  UINT32      nph_vc0_cdt_df;
  UINT32      npd_vc0_cdt_df;
  UINT32      cplh_vc0_cdt_df;
  UINT32      cpld_vc0_cdt_df;
}PORT_TL_CFG;

typedef struct {
  UINT32              max_sup_width;
  UINT32              max_lk_spd;
  UINT32              target_speed;
  PORT_GLOBAL_CFG     glb_cfg;
  UINT32              tgt_lk_spd;
  UINT32              tgt_lk_width;
} RC_LTSSM;

// For Config type define
typedef enum {
  PCIE_X16_GEN4_LINKUP = 0,
  PCIE_X8_GEN4_LINKUP,
  PCIE_X1_GEN2_LINKUP,
  PCIE_X8_GEN1_LINKUP,
} PCIE_LTSSM_PARAM;

typedef struct {
  UINT8 Config;
  VOID  *Data;
} PARAM_TABLE;

typedef union {
  struct
  {
    UINT32    port_sft_rst          : 16  ; /* [15..0]   */
    UINT32    port_ctrl_sft_rst     : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_PORT_RESET;

typedef union
{
  struct
  {
    UINT32    port_sticky_sft_rst   : 16  ; /* [15..0]   */
    UINT32    linkdown_clr_port_en  : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_PHY_RESET;

typedef union
{
  struct
  {
    UINT32    pciec_mode_sel        : 16  ; /* [15..0]   */
    UINT32    reserved_0            : 16  ; /* [31..16]  */
  } bits;

  UINT32        u32;
} U_GLB_PCIEC_MODE_SEL;

typedef union
{
  struct
  {
     UINT32    port0_link_mode       : 3   ; /* [2..0]   */
     UINT32    reserved_0            : 1   ; /* [3]      */
     UINT32    port1_link_mode       : 3   ; /* [6..4]   */
     UINT32    reserved_1            : 1   ; /* [7]      */
     UINT32    port2_link_mode       : 3   ; /* [10..8]  */
     UINT32    reserved_2            : 1   ; /* [11]     */
     UINT32    port3_link_mode       : 3   ; /* [14..12] */
     UINT32    reserved_3            : 1   ; /* [15]     */
     UINT32    port4_link_mode       : 3   ; /* [18..16] */
     UINT32    reserved_4            : 1   ; /* [19]     */
     UINT32    port5_link_mode       : 3   ; /* [22..20] */
     UINT32    reserved_5            : 1   ; /* [23]     */
     UINT32    port6_link_mode       : 3   ; /* [26..24] */
     UINT32    reserved_6            : 1   ; /* [27]     */
     UINT32    port7_link_mode       : 3   ; /* [30..28] */
     UINT32    reserved_7            : 1   ; /* [31]     */
  } bits;

  UINT32    u32;
} U_PORT07_LINK_MODE;

typedef union
{
  struct
  {
    UINT32    port8_link_mode       : 3   ; /* [2..0]   */
    UINT32    reserved_0            : 1   ; /* [3]      */
    UINT32    port9_link_mode       : 3   ; /* [6..4]   */
    UINT32    reserved_1            : 1   ; /* [7]      */
    UINT32    port10_link_mode      : 3   ; /* [10..8]  */
    UINT32    reserved_2            : 1   ; /* [11]     */
    UINT32    port11_link_mode      : 3   ; /* [14..12] */
    UINT32    reserved_3            : 1   ; /* [15]     */
    UINT32    port12_link_mode      : 3   ; /* [18..16] */
    UINT32    reserved_4            : 1   ; /* [19]     */
    UINT32    port13_link_mode      : 3   ; /* [22..20] */
    UINT32    reserved_5            : 1   ; /* [23]     */
    UINT32    port14_link_mode      : 3   ; /* [26..24] */
    UINT32    reserved_6            : 1   ; /* [27]     */
    UINT32    port15_link_mode      : 3   ; /* [30..28] */
    UINT32    reserved_7            : 1   ; /* [31]     */
  } bits;

  UINT32    u32;
} U_PORT815_LINK_MODE;

typedef union
{
  struct
  {
    UINT32    disable_enter_loopback        : 3   ; /* [2..0]   */
    UINT32    disable_enter_disable         : 3   ; /* [5..3]   */
    UINT32    disable_enter_hotreset        : 1   ; /* [6]      */
    UINT32    auto_speed_disable_mask       : 1   ; /* [7]      */
    UINT32    first_auto_speed_change_en    : 1   ; /* [8]      */
    UINT32    auto_speed_change_en          : 1   ; /* [9]      */
    UINT32    disable_enter_compliance      : 1   ; /* [10]     */
    UINT32    gen3_low_latency_mode         : 1   ; /* [11]     */
    UINT32    reg_disable_ctrl_skp          : 1   ; /* [12]     */
    UINT32    reg_new_gen4_eieos_en         : 1   ; /* [13]     */
    UINT32    disable_scramber_disable      : 1   ; /* [14]     */
    UINT32    reserved_0                    : 17  ; /* [31..15] */
  } bits;

  UINT32    u32;
} U_MAC_ENTER_LPBK_DISABLE;

typedef union
{
  struct
  {
    UINT32    ltssm_trace_signal_mask       : 6   ; /* [5..0]   */
    UINT32    reserved_0                    : 3   ; /* [8..6]   */
    UINT32    ltssm_trace_timer_clk_sel     : 1   ; /* [9]      */
    UINT32    reserved_1                    : 6   ; /* [15..10] */
    UINT32    ltssm_trace_lane_num          : 4   ; /* [19..16] */
    UINT32    reserved_2                    : 4   ; /* [23..20] */
    UINT32    sel_trace_rx_data_mode        : 8   ; /* [31..24] */
  } bits;

  UINT32    u32;
} U_MAC_LTSSM_TRACER_CFG0;

typedef union
{
  struct
  {
    UINT32    ltssm_trace_trigger_timer   : 11  ; /* [10..0]   */
    UINT32    reserved_0                  : 5   ; /* [15..11]  */
    UINT32    ltssm_trace_state           : 6   ; /* [21..16]  */
    UINT32    reserved_1                  : 2   ; /* [23..22]  */
    UINT32    clr_ltssm_trace_timer       : 1   ; /* [24]      */
    UINT32    reserved_2                  : 7   ; /* [31..25]  */
  } bits;

  UINT32    u32;
} U_MAC_LTSSM_TRACER_CFG1;

typedef union
{
  struct
  {
    UINT32    reg_ltssm_tracer_recap        : 1   ; /* [0]  */
    UINT32    reg_ltssm_tracer_cap_mode     : 1   ; /* [1]  */
    UINT32    reserved_0                    : 30  ; /* [31..2]  */
  } bits;

  UINT32    u32;
} U_MAC_REG_LTSSM_TRACER_INPUT;

typedef union
{
  struct
  {
    UINT32    linkdown_rst_num      : 16  ; /* [15..0]  */
    UINT32    linkdown_rst_en       : 16  ; /* [31..16] */
  } bits;

  UINT32    u32;
} U_PORT_RESET_CFG;

typedef union
{
  struct
  {
    UINT32    cfg_rst_dly_cnt       : 16  ; /* [15..0]  */
    UINT32    reserved_0            : 16  ; /* [31..16] */
  } bits;

  UINT32    u32;
} U_PORT_RST_DLY_CNT;

typedef union
{
  struct
  {
    UINT32    port_en               : 16  ; /* [15..0]  */
    UINT32    reserved_0            : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_PORT_EN;

typedef union
{
  struct
  {
    UINT32    mac_cur_link_width        : 6   ; /* [5..0]  */
    UINT32    reserved_0                : 2   ; /* [7..6]  */
    UINT32    mac_cur_link_speed        : 4   ; /* [11..8]  */
    UINT32    rxl0s_st                  : 2   ; /* [13..12]  */
    UINT32    rx_eval_st                : 2   ; /* [15..14]  */
    UINT32    mac_link_up               : 1   ; /* [16]  */
    UINT32    is_upstream_port_ltssm    : 1   ; /* [17]  */
    UINT32    mac_descramble_disable    : 1   ; /* [18]  */
    UINT32    lane_reverse              : 1   ; /* [19]  */
    UINT32    req_ending_txdata_en      : 1   ; /* [20]  */
    UINT32    reserved_1                : 3   ; /* [23..21]  */
    UINT32    mac_ltssm_st              : 6   ; /* [29..24]  */
    UINT32    rx_deskew_st              : 2   ; /* [31..30]  */
  } bits;

  UINT32    u32;
}U_MAC_REG_LINK_INFO;

typedef union
{
  struct
  {
    UINT32    ltssm_tracer_last_waddr       : 6   ; /* [5..0]  */
    UINT32    ltssm_tracer_addr_rollback    : 1   ; /* [6]  */
    UINT32    reserved_0                    : 25  ; /* [31..7]  */
  } bits;

  UINT32    u32;
} U_MAC_REG_LTSSM_TRACER_LAST_ADDR;

typedef union
{
  struct
  {
    UINT32    reg_ltssm_tracer_raddr : 6   ; /* [5..0]  */
    UINT32    reserved_0             : 26  ; /* [31..6]  */
  } bits;

  UINT32    u32;
} U_MAC_REG_LTSSM_TRACERADDR;

typedef union
{
  struct
  {
    UINT32    ltssm_tracer_data_ok  : 1   ; /* [0]  */
    UINT32    reserved_0            : 31  ; /* [31..1]  */
  } bits;

  UINT32    u32;
} U_MAC_REG_LTSSM_TRACER_OUTPUT_OK;

typedef union
{
  struct
  {
    UINT32    train_bit_map         : 16  ; /* [15..0]  */
    UINT32    txdetrx               : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_MAC_REG_LTSSM_TRACER_OUTPUT_2;

typedef union
{
  struct
  {
    UINT32    max_link_speed        : 4   ; /* [3..0]  */
    UINT32    max_link_width        : 6   ; /* [9..4]  */
    UINT32    aspm_sup              : 2   ; /* [11..10]  */
    UINT32    l0_exit_lat           : 3   ; /* [14..12]  */
    UINT32    l1_exit_lat           : 3   ; /* [17..15]  */
    UINT32    clock_pm              : 1   ; /* [18]  */
    UINT32    surprise_dn_err_rpt_cap : 1   ; /* [19]  */
    UINT32    dl_link_act_rpt_cap   : 1   ; /* [20]  */
    UINT32    link_band_notice_cap  : 1   ; /* [21]  */
    UINT32    aspm_opt_compliance   : 1   ; /* [22]  */
    UINT32    reserved_0            : 1   ; /* [23]  */
    UINT32    port_num              : 8   ; /* [31..24]  */
  } bits;

  UINT32    u32;
} U_LINK_CAPBILITY;

typedef union
{
  struct
  {
    UINT32    ltssm_st              : 6   ; /* [5..0]  */
    UINT32    duration_counter      : 4   ; /* [9..6]  */
    UINT32    mac_cur_link_speed    : 2   ; /* [11..10]  */
    UINT32    train_bit_map         : 8   ; /* [19..12]  */
    UINT32    rxl0s_st              : 2   ; /* [21..20]  */
    UINT32    any_change_pipe_req   : 1   ; /* [22]  */
    UINT32    rcv_eios              : 1   ; /* [23]  */
    UINT32    dl_retrain            : 1   ; /* [24]  */
    UINT32    all_phy_rxeleidle_or_rx_skp_interval_timeout : 1   ; /* [25]  */
    UINT32    directed_speed_change : 1   ; /* [26]  */
    UINT32    any_det_eieos_ts      : 1   ; /* [27]  */
    UINT32    rxl0s_to_recovery     : 1   ; /* [28]  */
    UINT32    any_lane_rcv_speed_change : 1   ; /* [29]  */
    UINT32    changed_speed_recovery : 1   ; /* [30]  */
    UINT32    suceessful_speed_negotiation : 1   ; /* [31]  */
  } bits;

  UINT32    u32;
} U_MAC_REG_LTSSM_TRACER_OUTPUT_1;

typedef union
{
  struct
  {
    UINT32    pcs_lane_sft_rst      : 16  ; /* [15..0]  */
    UINT32    pcs_sft_rst           : 1   ; /* [16]  */
    UINT32    reserved_0            : 15  ; /* [31..17]  */
  } bits;

  UINT32    u32;
} U_PCS_SOFT_REST;

typedef union
{
  struct
  {
    UINT32    target_link_speed     : 4   ; /* [3..0]  */
    UINT32    enter_compliance      : 1   ; /* [4]  */
    UINT32    hw_auto_speed_dis     : 1   ; /* [5]  */
    UINT32    selectable_de_emphasis : 1   ; /* [6]  */
    UINT32    transmit_margin       : 3   ; /* [9..7]  */
    UINT32    enter_mod_compliance  : 1   ; /* [10]  */
    UINT32    compliance_sos        : 1   ; /* [11]  */
    UINT32    compliance_preset_deemp : 4   ; /* [15..12]  */
    UINT32    cur_deemp_level       : 1   ; /* [16]  */
    UINT32    eq_8g_complete        : 1   ; /* [17]  */
    UINT32    eq_8g_phase1_success  : 1   ; /* [18]  */
    UINT32    eq_8g_phase2_success  : 1   ; /* [19]  */
    UINT32    eq_8g_phase3_success  : 1   ; /* [20]  */
    UINT32    link_8g_eq_req        : 1   ; /* [21]  */
    UINT32    retimer_presence_detect : 1   ; /* [22]  */
    UINT32    retimer2_presence_detect : 1   ; /* [23]  */
    UINT32    crosslink_resolution  : 2   ; /* [25..24]  */
    UINT32    reserved_0            : 2   ; /* [27..26]  */
    UINT32    downstream_component_presence   : 3   ; /* [30..28]  */
    UINT32    drs_msg_recved        : 1   ; /* [31]  */
  } bits;

  UINT32    u32;
} U_LINK_CTRL_STATUS2;

typedef union
{
  struct
  {
    UINT32    revision_id           : 8   ; /* [7..0]  */
    UINT32    program_inf           : 8   ; /* [15..8]  */
    UINT32    sub_class_code        : 8   ; /* [23..16]  */
    UINT32    base_class_code       : 8   ; /* [31..24]  */
  } bits;

  UINT32    u32;
} U_PCIHDR_CLSREV;

/* Define the union U_ROOT_ERROR_STATUS */
typedef union
{
  struct
  {
    UINT32    core_err_rcv          : 1   ; /* [0]  */
    UINT32    multi_cor_err_rcv     : 1   ; /* [1]  */
    UINT32    uncor_err_rcv         : 1   ; /* [2]  */
    UINT32    multi_uncor_err_rcv   : 1   ; /* [3]  */
    UINT32    first_uncor_err       : 1   ; /* [4]  */
    UINT32    non_fatal_msg_rcv     : 1   ; /* [5]  */
    UINT32    fatal_msg_rcv         : 1   ; /* [6]  */
    UINT32    reserved_0            : 20  ; /* [26..7]  */
    UINT32    aer_int_number        : 5   ; /* [31..27]  */
  } bits;

  UINT32    u32;
} U_ROOT_ERROR_STATUS;


/* Define the union U_DPC_CAP_0X04 */
typedef union
{
  struct
  {
    UINT32     dcp_int_msg_num       : 5   ; /* [4..0]  */
    UINT32     ext_for_dpc           : 1   ; /* [5]  */
    UINT32     egress_block_ep_tlp_sup : 1   ; /* [6]  */
    UINT32     soft_trig_sup         : 1   ; /* [7]  */
    UINT32     pio_log_size          : 4   ; /* [11..8]  */
    UINT32     dl_active_signal_sup  : 1   ; /* [12]  */
    UINT32     reserved_0            : 3   ; /* [15..13]  */
    UINT32     dp_trig_en            : 2   ; /* [17..16]  */
    UINT32     dpc_cpl_ctrl          : 1   ; /* [18]  */
    UINT32     dpc_int_en            : 1   ; /* [19]  */
    UINT32     dpc_err_cor_en        : 1   ; /* [20]  */
    UINT32     ep_egress_blk_en      : 1   ; /* [21]  */
    UINT32     dpc_soft_trig         : 1   ; /* [22]  */
    UINT32     dl_active_err_cor_en  : 1   ; /* [23]  */
    UINT32     reserved_1            : 8   ; /* [31..24]  */
  } bits;

  UINT32     u32;
} U_DPC_CAP_0X04;

/* Define the union U_ACS_CAP_0X04 */
typedef union
{
  struct
  {
    UINT32    acs_src_vld             : 1   ; /* [0]  */
    UINT32    acs_tx_block            : 1   ; /* [1]  */
    UINT32    acs_p2p_req_redirect    : 1   ; /* [2]  */
    UINT32    acs_p2p_cpl_redirect    : 1   ; /* [3]  */
    UINT32    acs_up_forward          : 1   ; /* [4]  */
    UINT32    acs_p2p_egress_ctrl     : 1   ; /* [5]  */
    UINT32    acs_direct_tx_p2p       : 1   ; /* [6]  */
    UINT32    reserved_0              : 1   ; /* [7]  */
    UINT32    acs_ctrl_vec_size       : 8   ; /* [15..8]  */
    UINT32    acs_src_vld_en          : 1   ; /* [16]  */
    UINT32    acs_tx_block_en         : 1   ; /* [17]  */
    UINT32    acs_p2p_req_redirect_en : 1   ; /* [18]  */
    UINT32    acs_p2p_cpl_redirect_en : 1   ; /* [19]  */
    UINT32    acs_up_forward_en       : 1   ; /* [20]  */
    UINT32    acs_p2p_egress_ctrl_en  : 1   ; /* [21]  */
    UINT32    acs_direct_tx_p2p_en    : 1   ; /* [22]  */
    UINT32    reserved_1              : 9   ; /* [31..23]  */
  } bits;

  UINT32    u32;
} U_ACS_CAP_0X04;

/* Define the union U_ROOT_CTRL_STATUS */
typedef union
{
  struct
  {
    UINT32    sys_err_on_cor_err_en : 1   ; /* [0]  */
    UINT32    sys_err_on_non_fat_en : 1   ; /* [1]  */
    UINT32    sys_err_on_fat_err_en : 1   ; /* [2]  */
    UINT32    pme_int_en            : 1   ; /* [3]  */
    UINT32    crs_sw_visibility_en  : 1   ; /* [4]  */
    UINT32    reserved_0            : 11  ; /* [15..5]  */
    UINT32    crs_sw_visibility     : 1   ; /* [16]  */
    UINT32    reserved_1            : 15  ; /* [31..17]  */
  } bits;

  UINT32    u32;
} U_ROOT_CTRL_STATUS;

typedef union
{
  struct
  {
    UINT32    iob_ecam_start_bus    : 8   ; /* [7..0]  */
    UINT32    iob_ecam_tc           : 3   ; /* [10..8]  */
    UINT32    iob_ecam_at           : 2   ; /* [12..11]  */
    UINT32    iob_ecam_attr         : 3   ; /* [15..13]  */
    UINT32    iob_ecam_td           : 1   ; /* [16]  */
    UINT32    iob_ecam_th           : 1   ; /* [17]  */
    UINT32    iob_ecam_ph           : 2   ; /* [19..18]  */
    UINT32    reserved_0            : 12  ; /* [31..20]  */
  } bits;

  UINT32    u32;
} U_IOB_ECAM_CONTROL;

typedef union
{
  struct
  {
    UINT32    msi_msix_enable     : 1   ; /* [0]  */
    UINT32    reserved_0          : 3   ; /* [3..1]  */
    UINT32    msi_msix_axicache   : 4   ; /* [7..4]  */
    UINT32    msi_msix_snpattr    : 1   ; /* [8]  */
    UINT32    reserved_1          : 23  ; /* [31..9]  */
  } bits;

  UINT32    u32;
} U_AM_MSI_MSIX_CTRL;

typedef union
{
  struct
  {
    UINT32    tl_ph_vc0_cdt         : 12  ; /* [11..0]  */
    UINT32    reserved_0            : 4   ; /* [15..12]  */
    UINT32    tl_pd_vc0_cdt         : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_TL_RX_POSTED_CREDIT;

typedef union
{
  struct
  {
    UINT32    tl_nph_vc0_cdt        : 12  ; /* [11..0]  */
    UINT32    reserved_0            : 4   ; /* [15..12]  */
    UINT32    tl_npd_vc0_cdt        : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_TL_RX_NON_POSTED_CREDIT;

typedef union
{
  struct
  {
    UINT32    tl_cplh_vc0_cdt       : 12  ; /* [11..0]  */
    UINT32    reserved_0            : 4   ; /* [15..12]  */
    UINT32    tl_cpld_vc0_cdt       : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_TL_RX_CPL_CREDIT;

typedef union
{
  struct
  {
    UINT32    tl_cdt_ini_up         : 1   ; /* [0]  */
    UINT32    reserved_0            : 31  ; /* [31..1]  */
  } bits;

  UINT32    u32;

} U_TL_RX_CDT_INI_UP;

typedef union
{
  struct
  {
    UINT32    tl_ph_vc0_cdt_df      : 12  ; /* [11..0]  */
    UINT32    tl_pd_vc0_scale       : 2   ; /* [13..12]  */
    UINT32    tl_ph_vc0_scale       : 2   ; /* [15..14]  */
    UINT32    tl_pd_vc0_cdt_df      : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_TL_RX_POSTED_CREDIT_DF;

typedef union
{
  struct
  {
    UINT32    tl_nph_vc0_cdt_df     : 12  ; /* [11..0]  */
    UINT32    tl_npd_vc0_scale      : 2   ; /* [13..12]  */
    UINT32    tl_nph_vc0_scale      : 2   ; /* [15..14]  */
    UINT32    tl_npd_vc0_cdt_df     : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_TL_RX_NON_POSTED_CREDIT_DF;

typedef union
{
  struct
  {
    UINT32    tl_cplh_vc0_cdt_df    : 12  ; /* [11..0]  */
    UINT32    tl_cpld_vc0_scale     : 2   ; /* [13..12]  */
    UINT32    tl_cplh_vc0_scale     : 2   ; /* [15..14]  */
    UINT32    tl_cpld_vc0_cdt_df    : 16  ; /* [31..16]  */
  } bits;

    UINT32    u32;
} U_TL_RX_CPL_CREDIT_DF;

typedef union
{
  struct
  {
    UINT32    tl_cdt_ini_up_df      : 1   ; /* [0]  */
    UINT32    reserved_0            : 7   ; /* [7..1]  */
    UINT32    tl_cpl_cdt_infi_en    : 1   ; /* [8]  */
    UINT32    reserved_1            : 23  ; /* [31..9]  */
  } bits;

  UINT32    u32;
} U_TL_RX_CDT_INI_UP_DF;

/* Define the union U_AXIM_GLOBAL_CTRL */
typedef union
{
  struct
  {
    UINT32    ctrl_shutdown_req     : 1   ; /* [0]  */
    UINT32    ctrl_en_rd_256byte    : 1   ; /* [1]  */
    UINT32    ctrl_en_wr_256byte    : 1   ; /* [2]  */
    UINT32    ctrl_partial_write_64byte : 1   ; /* [3]  */
    UINT32    ctrl_lat_stat_rd_en   : 1   ; /* [4]  */
    UINT32    ctrl_lat_stat_wr_en   : 1   ; /* [5]  */
    UINT32    reserved_0            : 2   ; /* [7..6]  */
    UINT32    ctrl_axuser_update_en : 1   ; /* [8]  */
    UINT32    reserved_1            : 23  ; /* [31..9]  */
  } bits;

  UINT32    u32;
} U_AXIM_GLOBAL_CTRL;

/* Define the union U_DL_FEATURE_CAP_REG04 */
typedef union
{
  struct
  {
    UINT32    local_scale_fc_support       : 1   ; /* [0]  */
    UINT32    local_future_feature_support : 22  ; /* [22..1]  */
    UINT32    reserved_0                   : 8   ; /* [30..23]  */
    UINT32    feature_exchange_en          : 1   ; /* [31]  */
  } bits;

  UINT32    u32;
} U_DL_FEATURE_CAP_REG04;

/* Define the union U_MAC_FRAMING_ERR_CTRL */
typedef union
{
  struct
  {
    UINT32    reg_framing_err_retrain_en : 1   ; /* [0]  */
    UINT32    reg_framing_err_rpt_en : 1   ; /* [1]  */
    UINT32    reserved_0            : 6   ; /* [7..2]  */
    UINT32    reg_framing_mask      : 8   ; /* [15..8]  */
    UINT32    resvered              : 16  ; /* [31..16]  */
  } bits;

  UINT32    u32;
} U_MAC_FRAMING_ERR_CTRL;

typedef union
{
  struct
  {
    UINT32    vc_cap_id                 : 16  ; /* [15..0]   */
    UINT32    vc_cap_version            : 4  ; /* [19..16]  */
    UINT32    vc_next_cap_offset        : 12  ; /* [31..20]  */
  } bits;

  UINT32        u32;
} U_VC_CAP_REG;

typedef union
{
  struct
  {
    UINT32    sec_pcie_ext_cap_id            : 16  ; /* [15..0]   */
    UINT32    sec_pcie_cap_version           : 4  ; /* [19..16]  */
    UINT32    sec_pcie_next_cap_offset       : 12  ; /* [31..20]  */
  } bits;

  UINT32        u32;
} U_SECONDARY_PCIE_EXT_CAP_HEADER_REG;

typedef struct {
  UINTN   apb_base;
  UINTN   ap_iob_tx;
  UINTN   ap_iob_rx_com;
  UINTN   ap_iob_rx_am;
  UINTN   ap_iob_rx_odr;
  UINTN   ap_mg;
  UINTN   ap_dma;
  UINTN   ap_int;
  UINTN   pcie_global;
  UINTN   subctrl_base;
  UINTN   core_global[PCIE_MAX_CORE_NUM];
  UINTN   pcs[PCIE_MAX_CORE_NUM];
  UINTN   core_port[PCIE_PORT_EACH_CHIP];
}PCIE_CTRL;

// Declare routine
EFI_STATUS
EFIAPI
PciePortInit(
  UINT32  port_id,
  UINT32  param_idx
  );

EFI_STATUS
EFIAPI
IatuInit(
  UINT32 atu_id
  );

#endif
