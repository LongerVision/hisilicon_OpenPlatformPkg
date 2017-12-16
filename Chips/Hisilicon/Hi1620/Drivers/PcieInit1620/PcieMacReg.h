// ******************************************************************************
// Copyright     :  Copyright (C) 2017, Hisilicon Technologies Co. Ltd.
// File name     :  hipciec_mac_reg_reg_offset.h
// Project line  :  Platform And Key Technologies Development
// Department    :  CAD Development Department
// Author        :  xxx
// Version       :  1.0
// Date          :  2016/3/10
// Description   :  The description of xxx project
// Others        :  Generated automatically by nManager V4.1
// History       :  xxx 2017/05/20 11:23:39 Create file
// ******************************************************************************

#ifndef __HIPCIEC_MAC_REG_REG_OFFSET_H__
#define __HIPCIEC_MAC_REG_REG_OFFSET_H__

/* HIPCIEC_MAC_REG Base address of Module's Register */
#define PCIe_HIPCIEC_MAC_REG_BASE                       (0x000)

/******************************************************************************/
/*                      PCIe HIPCIEC_MAC_REG Registers' Definitions           */
/******************************************************************************/

#define PCIe_HIPCIEC_MAC_REG_MAC_REQ_EIOS_TO_ELEIDLE_DELAY_REG             (PCIe_HIPCIEC_MAC_REG_BASE + 0x0)   /* Receive EIOS to phy_eleidle delay */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_ENTER_LOOPBACK_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x4)   /* LTSSM enter loopback mode enable */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_RETRAIN_LINK_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x8)   /* retrain link enable */
#define PCIe_HIPCIEC_MAC_REG_MAC_REQ_TX_LINK_NUM_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0xC)   /* setting TX Link number advertising to Link parter when being as DS port. */
#define PCIe_HIPCIEC_MAC_REG_MAC_REQ_SCRAMBLE_DISABLE_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x10)  /* scramble disable */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_SKP_INTVAL_SRIS_REG                   (PCIe_HIPCIEC_MAC_REG_BASE + 0x14)  /* SKP interval in SRIS mode */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DC_BALANCE_DISABLE_REG                (PCIe_HIPCIEC_MAC_REG_BASE + 0x18)  /* DC balance funciton disanle */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_EQ_DISABLE_REG                        (PCIe_HIPCIEC_MAC_REG_BASE + 0x1C)  /* TX EQ function disable */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_SUPPORTED_TX_PRESET_BM_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x20)  /* TX EQ supported tx preset bit map */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PHY_EQ_FB_SEL_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x24)  /* PHY TX EQ feedback mode sel */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN3_TX_COEFF_MAP_MODE_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x28)  /* TX coeff mapping mode */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_EQ_PHASE23_CONV_STEP_ADDR_REG         (PCIe_HIPCIEC_MAC_REG_BASE + 0x2C)  /* TX EQ convergence steps reqired when in TX_EQ2 (US port) or TX_EQ3 (DS port) */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_EQ_PHASE23_TIMEOUT_VAL_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x30)  /* TX EQ timeout value for TX_EQ phase2 and phase3, unit (ms) */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_SKP_INTVAL_SRNS_REG                   (PCIe_HIPCIEC_MAC_REG_BASE + 0x34)  /* SKP interval in SRNS mode */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_N_FTS_REG                             (PCIe_HIPCIEC_MAC_REG_BASE + 0x38)  /* number of FTS need to be transmit during L0s back to L0 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PHYSTATUS_DET_TIMEOUT_VAL_REG         (PCIe_HIPCIEC_MAC_REG_BASE + 0x3C)  /* phystatus detection timeout value */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_RDN_CROSS_TIMEOUT_VAL_REG             (PCIe_HIPCIEC_MAC_REG_BASE + 0x40)  /* Random cross timeout value */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_SEL_DEEMPH_US_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x44)  /* sel_deemph for Upstream port */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_TX_COMP_RCV_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x48)  /* transmit complaince receive */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_TXSWING_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x4C)  /* Tx swing selection */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_INPUT_REG                (PCIe_HIPCIEC_MAC_REG_BASE + 0x50)  /* LTSSM tracer input */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_MAC_INT_STATUS_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x54)  /* Interrupt status */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_MAC_INT_MASK_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x58)  /* interrupt mask */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_TEST_COUNTER_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x5C)  /* test counter set */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LINK_INFO_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x60)  /* mac link information */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE1_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x64)  /* debug PIPE signal set1 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE2_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x68)  /* debug PIPE signal set2 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE3_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x6C)  /* debug PIPE signal set3 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE4_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x70)  /* debug PIPE signal set4 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_RXDLI_1_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x74)  /* debug RXDLI signal */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LINK_NUM_1_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x78)  /* debug_link_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LANE_NUM_1_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x7C)  /* debug_lane_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_TXDLI_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x80)  /* debug TXDLI */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_OUTPUT_1_REG             (PCIe_HIPCIEC_MAC_REG_BASE + 0x84)  /* LTSSM tracer output */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_LAST_ADDR_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x88)  /* LTSSM tracer last write address */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_SYMBOL_UNLOCL_COUNTER_REG             (PCIe_HIPCIEC_MAC_REG_BASE + 0x8C)  /* symbol_unlock_counter */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_MAC_INT_RO_REG                        (PCIe_HIPCIEC_MAC_REG_BASE + 0x90)  /* Interrupt status RO */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_MAC_INT_SET_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x94)  /* interrupt sets */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_ENTER_L1L2_TIMEOUT_VAL_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x98)  /* enter L1L2 state timeout */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_EQ_FIX_LP_TX_PRESET_REG               (PCIe_HIPCIEC_MAC_REG_BASE + 0x9C)  /* Tx EQ pahse fix link partner preset */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_ADJ_HILINK_MODE_EN_REG                (PCIe_HIPCIEC_MAC_REG_BASE + 0xA0)  /* adjust hilink SERDES function mode enable */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LP_GEN3_TX_PRESET_P1_1_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0xA4)  /* tx preset value latched in GEN3 P1 state */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_EQ_OPT_TX_PRESET_1_REG                (PCIe_HIPCIEC_MAC_REG_BASE + 0xA8)  /* TX EQ opimal TX PRESET result */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LOOPBACK_PRESET_TIMEOUT_VAL_ADDR_REG  (PCIe_HIPCIEC_MAC_REG_BASE + 0xAC)  /* P2 or P3 wait for tx preset loopback timeout value */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_COMP_OPTION_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0xB0)  /* Compliance option */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PHY_RXDATA_TS_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0xB4)  /* PIPE RX data */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_ECO_RSV0_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0xB8)  /* ECO reserve register 0 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_ECO_RSV1_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0xBC)  /* ECO reserve register 1 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REGEQ_TRACE_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0xC0)  /* mac_eq_trace_reg */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_EQ_TIMEOUT_SET_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0xC4)  /* mac_eq_timeout_reg */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_EQ_INIT_COEFF_CFG_REG                 (PCIe_HIPCIEC_MAC_REG_BASE + 0xC8)  /* eq_init_coeff_cfg */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_WAIT_LINK_NUM_TIMER_REG               (PCIe_HIPCIEC_MAC_REG_BASE + 0xCC)  /* mac_wait_link_num_timer */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_0_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x100) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_1_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x104) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_2_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x108) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_3_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x10C) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_4_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x110) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_5_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x114) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_6_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x118) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_1_7_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x11C) /* Lane0¡«lane7 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET0_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x200) /* Preset0 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET1_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x204) /* Preset1 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET2_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x208) /* Preset2 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET3_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x20C) /* Preset3 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET4_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x210) /* Preset4 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET5_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x214) /* Preset5 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET6_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x218) /* Preset6 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET7_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x21C) /* Preset7 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET8_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x220) /* Preset8 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET9_REG                           (PCIe_HIPCIEC_MAC_REG_BASE + 0x224) /* Preset9 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET10_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0x228) /* Preset10 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET11_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0x22C) /* Preset11 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET12_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0x230) /* Preset12 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET13_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0x234) /* Preset13 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET14_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0x238) /* Preset14 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PRESET15_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0x23C) /* Preset15 coeff for Lane */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE5_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x240) /* debug PIPE signal set5 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE6_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x244) /* debug PIPE signal set6 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE7_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x248) /* debug PIPE signal set7 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE8_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x24C) /* debug PIPE signal set8 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE9_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x250) /* debug PIPE signal set9 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE10_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x254) /* debug PIPE signal set10 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_PIPE11_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x258) /* debug PIPE signal set11 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_RXDLI_2_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x25C) /* debug RXDLI signal */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LINK_NUM_2_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x260) /* debug_link_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LINK_NUM_3_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x264) /* debug_link_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LINK_NUM_4_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x268) /* debug_link_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LANE_NUM_2_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x26C) /* debug_lane_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LANE_NUM_3_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x270) /* debug_lane_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_DEBUG_LANE_NUM_4_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x274) /* debug_lane_num */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LP_GEN3_TX_PRESET_P1_2_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x278) /* tx preset value latched in GEN3 P1 state */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN3_EQ_OPT_TX_PRESET_2_REG           (PCIe_HIPCIEC_MAC_REG_BASE + 0x27C) /* TX EQ opimal TX PRESET result */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_0_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x280) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_1_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x284) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_2_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x288) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_3_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x28C) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_4_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x290) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_5_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x294) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_6_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x298) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LANE_COEFF_2_7_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x29C) /* Lane 8 ¡« lane 15 Transmitter equalizer coeff */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_OUTPUT_2_REG             (PCIe_HIPCIEC_MAC_REG_BASE + 0x2A0) /* LTSSM tracer output */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_OUTPUT_OK_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x2A4) /* LTSSM tracer output */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_SRAM_ECC_INSERT_REG      (PCIe_HIPCIEC_MAC_REG_BASE + 0x2A8) /* LTSSM tracer output */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACER_ECC_ERR_ADDR_REG         (PCIe_HIPCIEC_MAC_REG_BASE + 0x2AC) /* LTSSM tracer output */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_COEFF_SEARCH_TRACER_OUTPUT_REG        (PCIe_HIPCIEC_MAC_REG_BASE + 0x2B0) /* COEFF_SEARCH tracer output */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_REMOTE_FS_LF_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x2B4) /* REMOTE_PHY_FS_LF */
#define PCIe_HIPCIEC_MAC_REG_MAC_LOOP_LINK_DATA_ERR_COUNT_REG              (PCIe_HIPCIEC_MAC_REG_BASE + 0x2B8) /* loopback_link_data_err_count */
#define PCIe_HIPCIEC_MAC_REG_MAC_PCS_RX_ERR_CNT_REG                        (PCIe_HIPCIEC_MAC_REG_BASE + 0x2BC) /* pcs_rx_err_cnt */
#define PCIe_HIPCIEC_MAC_REG_MAC_UP_MAX_AUTO_REDO_NUM_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x2C0) /* up_max_auto_redo_number */
#define PCIe_HIPCIEC_MAC_REG_MAC_WAIT_LANE_NUM_TIMER_REG                   (PCIe_HIPCIEC_MAC_REG_BASE + 0x2C4) /* mac_wait_lane_num_timer */
#define PCIe_HIPCIEC_MAC_REG_MAC_LANE_NUM_WAIT_TIMER_REG                   (PCIe_HIPCIEC_MAC_REG_BASE + 0x2C8) /* mac_lane_num_wait_timer */
#define PCIe_HIPCIEC_MAC_REG_MAC_LANE_NUM_ACC_TIMER_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x2CC) /* mac_lane_num_acc_timer */
#define PCIe_HIPCIEC_MAC_REG_MAC_LNW_TO_LNA_1MS_TIMER_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x2D0) /* mac_lnw_to_lna_1ms_timer */
#define PCIe_HIPCIEC_MAC_REG_MAC_EQ_LTSMM_HOLD_TIMER_REG                   (PCIe_HIPCIEC_MAC_REG_BASE + 0x2D4) /* mac_eq_ltssm_hold_timer */
#define PCIe_HIPCIEC_MAC_REG_MAC_LTSSM_CRTL_INFER_ELECIDLE_REG             (PCIe_HIPCIEC_MAC_REG_BASE + 0x2D8) /* mac_ltssm_ctrl_infer_elecidle */
#define PCIe_HIPCIEC_MAC_REG_MAC_LTSSM_TRACER_CFG0_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x2DC) /* mac_ltssm_tracer_cfg0 */
#define PCIe_HIPCIEC_MAC_REG_MAC_LTSSM_TRACER_CFG1_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x2E0) /* mac_ltssm_tracer_cfg1 */
#define PCIe_HIPCIEC_MAC_REG_MAC_CMP_LOOP_SENT_EQTS1_REG                   (PCIe_HIPCIEC_MAC_REG_BASE + 0x2E8) /* mac_cmp_loop_sent_eq_ts */
#define PCIe_HIPCIEC_MAC_REG_MAC_ENTER_LPBK_DISABLE_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x2EC) /* mac_enter_lpbk_disable */
#define PCIe_HIPCIEC_MAC_REG_MAC_PRESET_TABLE0_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x2F0) /* mac_preset_table0 */
#define PCIe_HIPCIEC_MAC_REG_MAC_PRESET_TABLE1_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x2F4) /* mac_preset_table1 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LTSSM_TRACERADDR_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x2F8) /* LTSSM tracer addr */
#define PCIe_HIPCIEC_MAC_REG_MAC_CFG_COMPLETE_TIMER_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x2FC) /* maccfg_complete_timer */
#define PCIe_HIPCIEC_MAC_REG_MAC_CFG_COMP_ERRATA_DISABLE_REG               (PCIe_HIPCIEC_MAC_REG_BASE + 0x300) /* comp_errata_disable */
#define PCIe_HIPCIEC_MAC_REG_MAC_RX_ERR_CHECK_EN_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x304) /* mac_rx_error_check_en */
#define PCIe_HIPCIEC_MAC_REG_MAC_TRACE_2BIT_ECC_CNT_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x308) /* mac_ecc_2bit_er_cnt */
#define PCIe_HIPCIEC_MAC_REG_MAC_TRACE_1BIT_ECC_CNT_REG                    (PCIe_HIPCIEC_MAC_REG_BASE + 0x30C) /* mac_ecc_1bit_er_cnt */
#define PCIe_HIPCIEC_MAC_REG_MAC_CFG_RCV_HOLD_EN_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x310) /* mac_rcv_hold_en */
#define PCIe_HIPCIEC_MAC_REG_MAC_CFG_RCV_LOCK_HOLD_TIME_REG                (PCIe_HIPCIEC_MAC_REG_BASE + 0x314) /* mac_rcv_lock_hold_time */
#define PCIe_HIPCIEC_MAC_REG_MAC_CFG_RCV_CFG_HOLD_TIME_REG                 (PCIe_HIPCIEC_MAC_REG_BASE + 0x318) /* mac_rcv_cfg_hold_time */
#define PCIe_HIPCIEC_MAC_REG_MAC_CFG_RCV_IDLE_HOLD_TIME_REG                (PCIe_HIPCIEC_MAC_REG_BASE + 0x31C) /* mac_rcv_idle_hold_time */
#define PCIe_HIPCIEC_MAC_REG_MAC_LTSSM_INT_STATUS_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x320) /* mac_ltssm_int_match_state */
#define PCIe_HIPCIEC_MAC_REG_MAC_DESKEW_SYMBOL_UNLOCK_RCV_MASK_REG         (PCIe_HIPCIEC_MAC_REG_BASE + 0x324) /* mac_deskew_symbol_unlock_recovery_mask */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN4_EQ_OPT_TX_PRESET_1_REG           (PCIe_HIPCIEC_MAC_REG_BASE + 0x328) /* TX GNE4 EQ opimal TX PRESET result */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN4_EQ_OPT_TX_PRESET_2_REG           (PCIe_HIPCIEC_MAC_REG_BASE + 0x32C) /* TX GEN4 EQ opimal TX PRESET result */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LP_GEN4_TX_PRESET_P1_1_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x330) /* tx preset value latched in GEN4 P1 state */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_LP_GEN4_TX_PRESET_P1_2_REG            (PCIe_HIPCIEC_MAC_REG_BASE + 0x334) /* tx preset value latched in GEN4 P1 state */
#define PCIe_HIPCIEC_MAC_REG_MAC_LPBK_DATA_REG                             (PCIe_HIPCIEC_MAC_REG_BASE + 0x338) /* Tx data in loopback state */
#define PCIe_HIPCIEC_MAC_REG_MAC_RX_MARGIN_SELF_CTRL_REG                   (PCIe_HIPCIEC_MAC_REG_BASE + 0x33C) /* mac_reg_margn_sel_ctrl */
#define PCIe_HIPCIEC_MAC_REG_MAC_RX_MARGIN_CFG_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x340) /* mac_rx_margin_cfg */
#define PCIe_HIPCIEC_MAC_REG_GEN4_RX_MARGIN_CPA0_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x344) /* gen4_rx_margin_cap0 */
#define PCIe_HIPCIEC_MAC_REG_GEN4_RX_MARGIN_CPA1_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x348) /* gen4_rx_margin_cap1 */
#define PCIe_HIPCIEC_MAC_REG_GEN4_RX_MARGIN_RSV_REG                        (PCIe_HIPCIEC_MAC_REG_BASE + 0x34C) /* resvered for rx margin */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN3_EQ_FIX_TX_PRESET_1_REG           (PCIe_HIPCIEC_MAC_REG_BASE + 0x350) /* TX GNE3 EQ fix TX PRESET value1 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN3_EQ_FIX_TX_PRESET_2_REG           (PCIe_HIPCIEC_MAC_REG_BASE + 0x354) /* TX GNE3 EQ fix TX PRESETvalue2 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN4_EQ_FIX_TX_PRESET_1_REG           (PCIe_HIPCIEC_MAC_REG_BASE + 0x358) /* TX GNE4 EQ fix TX PRESET value1 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_GEN4_EQ_FIX_TX_PRESET_2_REG           (PCIe_HIPCIEC_MAC_REG_BASE + 0x35C) /* TX GNE4 EQ fix TX PRESETvalue2 */
#define PCIe_HIPCIEC_MAC_REG_MAC_REG_PHASE01_COARSETUNE_START_TM_VALUE_REG (PCIe_HIPCIEC_MAC_REG_BASE + 0x360) /* MAC_REG_PHASE01_COARSETUNE_START_TM_VALUE */
#define PCIe_HIPCIEC_MAC_REG_MAC_LTSSM_TIMEOUT_ENABLE_REG                  (PCIe_HIPCIEC_MAC_REG_BASE + 0x364) /* LTSSM_TIMEOUT_ENABLE */
#define PCIe_HIPCIEC_MAC_REG_MAC_LOOPBACK_EC_VALUE_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x368) /* MAC_LOOPBACK_EC_VALUE */
#define PCIe_HIPCIEC_MAC_REG_MAC_LANE_REVERSE_CFG_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x36C) /* MAC_LANE_REVERSE_CFG */
#define PCIe_HIPCIEC_MAC_REG_MAC_PIPE_SRIS_EN_REG                          (PCIe_HIPCIEC_MAC_REG_BASE + 0x370) /* MAC_PIPE_SRIS_EN_CFG */
#define PCIe_HIPCIEC_MAC_REG_MAC_PIPE_EBUF_MODE_REG                        (PCIe_HIPCIEC_MAC_REG_BASE + 0x374) /* MAC_PIPE_EBUF_MODE_CFG */
#define PCIe_HIPCIEC_MAC_REG_MAC_PIPE_SRIS_EN0_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x378) /* MAC_EBUF_DEPTH_CFG0 */
#define PCIe_HIPCIEC_MAC_REG_MAC_PIPE_SRIS_EN1_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x37C) /* MAC_EBUF_DEPTH_CFG1 */
#define PCIe_HIPCIEC_MAC_REG_MAC_PIPE_SRIS_EN2_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x380) /* MAC_EBUF_DEPTH_CFG2 */
#define PCIe_HIPCIEC_MAC_REG_MAC_PIPE_SRIS_EN3_REG                         (PCIe_HIPCIEC_MAC_REG_BASE + 0x384) /* MAC_EBUF_DEPTH_CFG3 */
#define PCIe_HIPCIEC_MAC_REG_MAC_FRAMING_ERR_CNT_REG                       (PCIe_HIPCIEC_MAC_REG_BASE + 0x39C) /* MAC_FRAMING_ERR_CNT */
#define PCIe_HIPCIEC_MAC_REG_MAC_FRAMING_ERR_CTRL_REG                      (PCIe_HIPCIEC_MAC_REG_BASE + 0x3A0) /* MAC_FRAMING_ERR_CTRL */
#define PCIe_HIPCIEC_MAC_REG_MAC_LINKDOWN_REQ_MASK_REG                     (PCIe_HIPCIEC_MAC_REG_BASE + 0x3A4) /* MAC_LINKDOWN_REQ_MASK */

#endif // __HIPCIEC_MAC_REG_REG_OFFSET_H__
