/**
 * Copyright (c) 2012 NVIDIA Corporation.  All rights reserved.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/**
 * Defines the SDRAM parameter structure.
 *
 * Note that PLLM is used by EMC.
 */

#ifndef INCLUDED_NVBOOT_SDRAM_PARAM_H
#define INCLUDED_NVBOOT_SDRAM_PARAM_H

#define NVBOOT_BCT_SDRAM_ARB_CONFIG_WORDS 27

typedef enum {
	/* Specifies the memory type to be undefined */
	nvboot_memory_type_none = 0,

	/* Specifies the memory type to be DDR SDRAM */
	nvboot_memory_type_ddr,

	/* Specifies the memory type to be LPDDR SDRAM */
	nvboot_memory_type_lpddr,

	/* Specifies the memory type to be DDR2 SDRAM */
	nvboot_memory_type_ddr2,

	/* Specifies the memory type to be LPDDR2 SDRAM */
	nvboot_memory_type_lpddr2,

	/* Specifies the memory type to be DDR3 SDRAM */
	nvboot_memory_type_ddr3,

	nvboot_memory_type_num,
	nvboot_memory_type_force32 = 0x7FFFFFF
} nvboot_memory_type;

/**
 * Defines the SDRAM parameter structure
 */
typedef struct nvboot_sdram_params_rec {
	/* sdram data structure generated by tool warmboot_code_gen */

	/* Specifies the type of memory device */
	nvboot_memory_type memory_type;

	/* MC/EMC clock source configuration */

	/* Specifies the CPCON value for PllM */
	u_int32_t pllm_charge_pump_setup_ctrl;
	/* Specifies the LPCON value for PllM */
	u_int32_t pllm_loop_filter_setup_ctrl;
	/* Specifies the M value for PllM */
	u_int32_t pllm_input_divider;
	/* Specifies the N value for PllM */
	u_int32_t pllm_feedback_divider;
	/* Specifies the P value for PllM */
	u_int32_t pllm_post_divider;
	/* Specifies the time to wait for PLLM to lock (in microseconds) */
	u_int32_t pllm_stable_time;

	/* Specifies the divider for the EMC Clock Source */
	u_int32_t emc_clock_divider;
	/* Specifies the PLL source for the EMC Clock Source */
	u_int32_t emc_clock_source;
	/*
	 * Specifies the enable for using low jitter clock for
	 * the EMC Clock Source
	 */
	u_int32_t emc_clock_use_pll_mud;

	/* Auto-calibration of EMC pads */

	/* Specifies the value for EMC_AUTO_CAL_INTERVAL */
	u_int32_t emc_auto_cal_interval;
	/*
	 * Specifies the value for EMC_AUTO_CAL_CONFIG
	 * Note: Trigger bits are set by the SDRAM code.
	 */
	u_int32_t emc_auto_cal_config;
	/*
	 * Specifies the time for the calibration
	 * to stabilize (in microseconds)
	 */
	u_int32_t emc_auto_cal_wait;

	/*
	 * DRAM size information
	 * Specifies the value for EMC_ADR_CFG
	 */
	u_int32_t emc_adr_cfg;

	/*
	 * Specifies the time to wait after asserting pin
	 * CKE (in microseconds)
	 */
	u_int32_t emc_pin_program_wait;
	/* Specifies the extra delay before/after pin RESET/CKE command */
	u_int32_t emc_pin_extra_wait;
	/*
	 * Specifies the extra delay after the first writing
	 * of EMC_TIMING_CONTROL
	 */
	u_int32_t emc_timing_control_wait;

	/* Timing parameters required for the SDRAM */

	/* Specifies the value for EMC_RC */
	u_int32_t emc_rc;
	/* Specifies the value for EMC_RFC */
	u_int32_t emc_rfc;
	/* Specifies the value for EMC_RAS */
	u_int32_t emc_ras;
	/* Specifies the value for EMC_RP */
	u_int32_t emc_rp;
	/* Specifies the value for EMC_R2W */
	u_int32_t emc_r2w;
	/* Specifies the value for EMC_R2W */
	u_int32_t emc_w2r;
	/* Specifies the value for EMC_R2P */
	u_int32_t emc_r2p;
	/* Specifies the value for EMC_W2P */
	u_int32_t emc_w2p;
	/* Specifies the value for EMC_RD_RCD */
	u_int32_t emc_rd_rcd;
	/* Specifies the value for EMC_WR_RCD */
	u_int32_t emc_wr_rcd;
	/* Specifies the value for EMC_RRD */
	u_int32_t emc_rrd;
	/* Specifies the value for EMC_REXT */
	u_int32_t emc_rext;
	/* Specifies the value for EMC_WEXT */
	u_int32_t emc_wext;
	/* Specifies the value for EMC_WDV */
	u_int32_t emc_wdv;
	/* Specifies the value for EMC_QUSE */
	u_int32_t emc_quse;
	/* Specifies the value for EMC_QRST */
	u_int32_t emc_qrst;
	/* Specifies the value for EMC_QSAFE */
	u_int32_t emc_qsafe;
	/* Specifies the value for EMC_RDV */
	u_int32_t emc_rdv;
	/* Specifies the value for EMC_CTT */
	u_int32_t emc_ctt;
	/* Specifies the value for EMC_CTT_DURATION */
	u_int32_t emc_ctt_duration;
	/* Specifies the value for EMC_REFRESH */
	u_int32_t emc_refresh;
	/* Specifies the value for EMC_BURST_REFRESH_NUM */
	u_int32_t emc_burst_refresh_num;
	/* Specifies the value for EMC_PRE_REFRESH_REQ_CNT */
	u_int32_t emc_prerefresh_req_cnt;
	/* Specifies the value for EMC_PDEX2WR */
	u_int32_t emc_pdex2wr;
	/* Specifies the value for EMC_PDEX2RD */
	u_int32_t emc_pdex2rd;
	/* Specifies the value for EMC_PCHG2PDEN */
	u_int32_t emc_pchg2pden;
	/* Specifies the value for EMC_ACT2PDEN */
	u_int32_t emc_act2pden;
	/* Specifies the value for EMC_AR2PDEN */
	u_int32_t emc_ar2pden;
	/* Specifies the value for EMC_RW2PDEN */
	u_int32_t emc_rw2pden;
	/* Specifies the value for EMC_TXSR */
	u_int32_t emc_txsr;
	/* Specifies the value for EMC_TXSRDLL */
	u_int32_t emc_txsr_dll;
	/* Specifies the value for EMC_TCKE */
	u_int32_t emc_tcke;
	/* Specifies the value for EMC_TFAW */
	u_int32_t emc_tfaw;
	/* Specifies the value for EMC_TRPAB */
	u_int32_t emc_trpab;
	/* Specifies the value for EMC_TCLKSTABLE */
	u_int32_t emc_tclkstable;
	/* Specifies the value for EMC_TCLKSTOP */
	u_int32_t emc_tclkstop;
	/* Specifies the value for EMC_TREFBW */
	u_int32_t emc_trefbw;
	/* Specifies the value for EMC_QUSE_EXTRA */
	u_int32_t emc_quse_extra;

	/* FBIO configuration values */

	/* Specifies the value for EMC_FBIO_CFG5 */
	u_int32_t emc_fbio_cfg5;
	/* Specifies the value for EMC_FBIO_CFG6 */
	u_int32_t emc_fbio_cfg6;
	/* Specifies the value for EMC_FBIO_SPARE */
	u_int32_t emc_fbio_spare;

	/* Specifies the value for EMC_CFG_RSV */
	u_int32_t emc_cfg_rsv;

	/* MRS command values */

	/* Specifies the value for EMC_MRS */
	u_int32_t emc_mrs;
	/* Specifies the value for EMC_EMRS */
	u_int32_t emc_emrs;
	/* Specifies the programming to LPDDR2 Mode Register 1 at cold boot */
	u_int32_t emc_mrw1;
	/* Specifies the programming to LPDDR2 Mode Register 2 at cold boot */
	u_int32_t emc_mrw2;
	/* Specifies the programming to LPDDR2 Mode Register 3 at cold boot */
	u_int32_t emc_mrw3;
	/*
	 * Specifies the programming to extra LPDDR2 Mode Register
	 * at cold boot
	 */
	u_int32_t emc_mrw_extra;
	/* Specifies the programming to LPDDR2 Mode Register 1 at warm boot */
	u_int32_t emc_warm_boot_mrw1;
	/* Specifies the programming to LPDDR2 Mode Register 2 at warm boot */
	u_int32_t emc_warm_boot_mrw2;
	/* Specifies the programming to LPDDR2 Mode Register 3 at warm boot */
	u_int32_t emc_warm_boot_mrw3;
	/*
	 * Specifies the programming to extra LPDDR2 Mode Register
	 * at warm boot
	 */
	u_int32_t emc_warm_boot_mrw_extra;
	/*
	 * Specify the enable of extra Mode Register programming at
	 * warm boot
	 */
	u_int32_t emc_warm_boot_extramode_reg_write_enable;
	/*
	 * Specify the enable of extra Mode Register programming at
	 * cold boot
	 */
	u_int32_t emc_extramode_reg_write_enable;

	/* Specifies the EMC_MRW reset command value */
	u_int32_t emc_mrw_reset_command;
	/* Specifies the EMC Reset wait time (in microseconds) */
	u_int32_t emc_mrw_reset_ninit_wait;
	/* Specifies the value for EMC_MRS_WAIT_CNT */
	u_int32_t emc_mrs_wait_cnt;

	/* EMC miscellaneous configurations */

	/* Specifies the value for EMC_CFG */
	u_int32_t emc_cfg;
	/* Specifies the value for EMC_CFG_2 */
	u_int32_t emc_cfg2;
	/* Specifies the value for EMC_DBG */
	u_int32_t emc_dbg;
	/* Specifies the value for EMC_CMDQ */
	u_int32_t emc_cmd_q;
	/* Specifies the value for EMC_MC2EMCQ */
	u_int32_t emc_mc2emc_q;
	/* Specifies the value for EMC_DYN_SELF_REF_CONTROL */
	u_int32_t emc_dyn_self_ref_control;

	/* Specifies the value for MEM_INIT_DONE */
	u_int32_t ahb_arbitration_xbar_ctrl_meminit_done;

	/* Specifies the value for EMC_CFG_DIG_DLL */
	u_int32_t emc_cfg_dig_dll;
	/* Specifies the value for EMC_CFG_DIG_DLL_PERIOD */
	u_int32_t emc_cfg_dig_dll_period;
	/* Specifies the vlaue of *DEV_SELECTN of various EMC registers */
	u_int32_t emc_dev_select;

	/* Specifies the value for EMC_SEL_DPD_CTRL */
	u_int32_t emc_sel_dpd_ctrl;

	/* Pads trimmer delays */

	/* Specifies the value for EMC_DLL_XFORM_DQS0 */
	u_int32_t emc_dll_xform_dqs0;
	/* Specifies the value for EMC_DLL_XFORM_DQS1 */
	u_int32_t emc_dll_xform_dqs1;
	/* Specifies the value for EMC_DLL_XFORM_DQS2 */
	u_int32_t emc_dll_xform_dqs2;
	/* Specifies the value for EMC_DLL_XFORM_DQS3 */
	u_int32_t emc_dll_xform_dqs3;
	/* Specifies the value for EMC_DLL_XFORM_DQS4 */
	u_int32_t emc_dll_xform_dqs4;
	/* Specifies the value for EMC_DLL_XFORM_DQS5 */
	u_int32_t emc_dll_xform_dqs5;
	/* Specifies the value for EMC_DLL_XFORM_DQS6 */
	u_int32_t emc_dll_xform_dqs6;
	/* Specifies the value for EMC_DLL_XFORM_DQS7 */
	u_int32_t emc_dll_xform_dqs7;
	/* Specifies the value for EMC_DLL_XFORM_QUSE0 */
	u_int32_t emc_dll_xform_quse0;
	/* Specifies the value for EMC_DLL_XFORM_QUSE1 */
	u_int32_t emc_dll_xform_quse1;
	/* Specifies the value for EMC_DLL_XFORM_QUSE2 */
	u_int32_t emc_dll_xform_quse2;
	/* Specifies the value for EMC_DLL_XFORM_QUSE3 */
	u_int32_t emc_dll_xform_quse3;
	/* Specifies the value for EMC_DLL_XFORM_QUSE4 */
	u_int32_t emc_dll_xform_quse4;
	/* Specifies the value for EMC_DLL_XFORM_QUSE5 */
	u_int32_t emc_dll_xform_quse5;
	/* Specifies the value for EMC_DLL_XFORM_QUSE6 */
	u_int32_t emc_dll_xform_quse6;
	/* Specifies the value for EMC_DLL_XFORM_QUSE7 */
	u_int32_t emc_dll_xform_quse7;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS0 */
	u_int32_t emc_dli_trim_tx_dqs0;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS1 */
	u_int32_t emc_dli_trim_tx_dqs1;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS2 */
	u_int32_t emc_dli_trim_tx_dqs2;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS3 */
	u_int32_t emc_dli_trim_tx_dqs3;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS4 */
	u_int32_t emc_dli_trim_tx_dqs4;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS5 */
	u_int32_t emc_dli_trim_tx_dqs5;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS6 */
	u_int32_t emc_dli_trim_tx_dqs6;
	/* Specifies the value for EMC_DLI_TRIM_TXDQS7 */
	u_int32_t emc_dli_trim_tx_dqs7;
	/* Specifies the value for EMC_DLL_XFORM_DQ0 */
	u_int32_t emc_dll_xform_dq0;
	/* Specifies the value for EMC_DLL_XFORM_DQ1 */
	u_int32_t emc_dll_xform_dq1;
	/* Specifies the value for EMC_DLL_XFORM_DQ2 */
	u_int32_t emc_dll_xform_dq2;
	/* Specifies the value for EMC_DLL_XFORM_DQ3 */
	u_int32_t emc_dll_xform_dq3;

	/*
	 * Specifies the delay after asserting CKE pin during a WarmBoot0
	 * sequence (in microseconds)
	 */
	u_int32_t warm_boot_wait;

	/* Specifies the value for EMC_CTT_TERM_CTRL */
	u_int32_t emc_ctt_term_ctrl;

	/* Specifies the value for EMC_ODT_WRITE */
	u_int32_t emc_odt_write;
	/* Specifies the value for EMC_ODT_WRITE */
	u_int32_t emc_odt_read;

	/* Periodic ZQ calibration */

	/*
	 * Specifies the value for EMC_ZCAL_INTERVAL
	 * Value 0 disables ZQ calibration
	 */
	u_int32_t emc_zcal_interval;
	/* Specifies the value for EMC_ZCAL_WAIT_CNT */
	u_int32_t emc_zcal_wait_cnt;
	/* Specifies the value for EMC_ZCAL_MRW_CMD */
	u_int32_t emc_zcal_mrw_cmd;

	/* DRAM initialization sequence flow control */

	/* Specifies the MRS command value for resetting DLL */
	u_int32_t emc_mrs_reset_dll;
	/* Specifies the command for ZQ initialization of device 0 */
	u_int32_t emc_zcal_init_dev0;
	/* Specifies the command for ZQ initialization of device 1 */
	u_int32_t emc_zcal_init_dev1;
	/*
	 * Specifies the wait time after programming a ZQ initialization
	 * command (in microseconds)
	 */
	u_int32_t emc_zcal_init_wait;
	/* Specifies the enable for ZQ calibration at cold boot */
	u_int32_t emc_zcal_cold_boot_enable;
	/* Specifies the enable for ZQ calibration at warm boot */
	u_int32_t emc_zcal_warm_boot_enable;

	/*
	 * Specifies the MRW command to LPDDR2 for ZQ calibration
	 *on warmboot
	 */
	/* Is issued to both devices separately */
	u_int32_t emc_mrw_lpddr2zcal_warm_boot;
	/*
	 * Specifies the ZQ command to DDR3 for ZQ calibration on warmboot
	 * Is issued to both devices separately
	 */
	u_int32_t emc_zqcal_ddr3_warm_boot;
	/*
	 * Specifies the wait time for ZQ calibration on warmboot
	 * (in microseconds)
	 */
	u_int32_t emc_zcal_warm_boot_wait;
	/*
	 * Specifies the enable for DRAM Mode Register programming
	 * at warm boot
	 */
	u_int32_t emc_mrs_warm_boot_enable;
	/*
	 * Specifies the wait time after sending an MRS DLL reset command
	 * in microseconds)
	 */
	u_int32_t emc_mrs_reset_dll_wait;
	/*
	 * Specifies the first of two EMRS commands to initialize mode
	 * registers
	 */
	u_int32_t emc_emrs_emr2;
	/*
	 * Specifies the second of two EMRS commands to initialize mode
	 * registers
	 */
	u_int32_t emc_emrs_emr3;
	/* Specifies the extra MRS command to initialize mode registers */
	u_int32_t emc_mrs_extra;
	/* Specifies the programming to DDR3 Mode Register 0 at warm boot */
	u_int32_t emc_warm_boot_mrs;
	/* Specifies the programming to DDR3 Mode Register 1 at warm boot */
	u_int32_t emc_warm_boot_emrs;
	/* Specifies the programming to DDR3 Mode Register 2 at warm boot */
	u_int32_t emc_warm_boot_emr2;
	/* Specifies the programming to DDR3 Mode Register 3 at warm boot */
	u_int32_t emc_warm_boot_emr3;
	/* Specifies the extra MRS command at warm boot */
	u_int32_t emc_warm_boot_mrs_extra;
	/* Specifies the EMRS command to enable the DDR2 DLL */
	u_int32_t emc_emrs_ddr2_dll_enable;
	/* Specifies the MRS command to reset the DDR2 DLL */
	u_int32_t emc_mrs_ddr2_dll_reset;
	/* Specifies the EMRS command to set OCD calibration */
	u_int32_t emc_emrs_ddr2_ocd_calib;
	/*
	 * Specifies the wait between initializing DDR and setting OCD
	 * calibration (in microseconds)
	 */
	u_int32_t emc_ddr2_wait;
	/* Specifies the value for EMC_CLKEN_OVERRIDE */
	u_int32_t emc_clken_override;
	/*
	 * Specifies LOG2 of the extra refresh numbers after booting
	 * Program 0 to disable
	 */
	u_int32_t emc_extra_refresh_num;
	/* Specifies the master override for all EMC clocks */
	u_int32_t emc_clken_override_allwarm_boot;
	/* Specifies the master override for all MC clocks */
	u_int32_t mc_clken_override_allwarm_boot;
	/* Specifies digital dll period, choosing between 4 to 64 ms */
	u_int32_t emc_cfg_dig_dll_period_warm_boot;

	/* Pad controls */

	/* Specifies the value for PMC_VDDP_SEL */
	u_int32_t pmc_vddp_sel;
	/* Specifies the value for PMC_DDR_PWR */
	u_int32_t pmc_ddr_pwr;
	/* Specifies the value for PMC_DDR_CFG */
	u_int32_t pmc_ddr_cfg;
	/* Specifies the value for PMC_IO_DPD_REQ */
	u_int32_t pmc_io_dpd_req;
	/* Specifies the value for PMC_E_NO_VTTGEN */
	u_int32_t pmc_eno_vtt_gen;
	/* Specifies the value for PMC_NO_IOPOWER */
	u_int32_t pmc_no_io_power;
	/* Specifies the value for EMC_XM2CMDPADCTRL */
	u_int32_t emc_xm2cmd_pad_ctrl;
	/* Specifies the value for EMC_XM2CMDPADCTRL2 */
	u_int32_t emc_xm2cmd_pad_ctrl2;
	/* Specifies the value for EMC_XM2DQSPADCTRL */
	u_int32_t emc_xm2dqs_pad_ctrl;
	/* Specifies the value for EMC_XM2DQSPADCTRL2 */
	u_int32_t emc_xm2dqs_pad_ctrl2;
	/* Specifies the value for EMC_XM2DQSPADCTRL3 */
	u_int32_t emc_xm2dqs_pad_ctrl3;
	/* Specifies the value for EMC_XM2DQPADCTRL */
	u_int32_t emc_xm2dq_pad_ctrl;
	/* Specifies the value for EMC_XM2DQPADCTRL2 */
	u_int32_t emc_xm2dq_pad_ctrl2;
	/* Specifies the value for EMC_XM2CLKPADCTRL */
	u_int32_t emc_xm2clk_pad_ctrl;
	/* Specifies the value for EMC_XM2COMPPADCTRL */
	u_int32_t emc_xm2comp_pad_ctrl;
	/* Specifies the value for EMC_XM2VTTGENPADCTRL */
	u_int32_t emc_xm2vttgen_pad_ctrl;
	/* Specifies the value for EMC_XM2VTTGENPADCTRL2 */
	u_int32_t emc_xm2vttgen_pad_ctrl2;
	/* Specifies the value for EMC_XM2QUSEPADCTRL */
	u_int32_t emc_xm2quse_pad_ctrl;

	/* DRAM size information */

	/* Specifies the value for MC_EMEM_ADR_CFG */
	u_int32_t mc_emem_adr_cfg;
	/* Specifies the value for MC_EMEM_ADR_CFG_DEV0 */
	u_int32_t mc_emem_adr_cfg_dev0;
	/* Specifies the value for MC_EMEM_ADR_CFG_DEV1 */
	u_int32_t mc_emem_adr_cfg_dev1;

	/*
	 * Specifies the value for MC_EMEM_CFG which holds the external memory
	 * size (in KBytes)
	 */
	u_int32_t mc_emem_cfg;

	/* MC arbitration configuration */

	/* Specifies the value for MC_EMEM_ARB_CFG */
	u_int32_t mc_emem_arb_cfg;
	/* Specifies the value for MC_EMEM_ARB_OUTSTANDING_REQ */
	u_int32_t mc_emem_arb_outstanding_req;
	/* Specifies the value for MC_EMEM_ARB_TIMING_RCD */
	u_int32_t mc_emem_arb_timing_rcd;
	/* Specifies the value for MC_EMEM_ARB_TIMING_RP */
	u_int32_t mc_emem_arb_timing_rp;
	/* Specifies the value for MC_EMEM_ARB_TIMING_RC */
	u_int32_t mc_emem_arb_timing_rc;
	/* Specifies the value for MC_EMEM_ARB_TIMING_RAS */
	u_int32_t mc_emem_arb_timing_ras;
	/* Specifies the value for MC_EMEM_ARB_TIMING_FAW */
	u_int32_t mc_emem_arb_timing_faw;
	/* Specifies the value for MC_EMEM_ARB_TIMING_RRD */
	u_int32_t mc_emem_arb_timing_rrd;
	/* Specifies the value for MC_EMEM_ARB_TIMING_RAP2PRE */
	u_int32_t mc_emem_arb_timing_rap2pre;
	/* Specifies the value for MC_EMEM_ARB_TIMING_WAP2PRE */
	u_int32_t mc_emem_arb_timing_wap2pre;
	/* Specifies the value for MC_EMEM_ARB_TIMING_R2R */
	u_int32_t mc_emem_arb_timing_r2r;
	/* Specifies the value for MC_EMEM_ARB_TIMING_W2W */
	u_int32_t mc_emem_arb_timing_w2w;
	/* Specifies the value for MC_EMEM_ARB_TIMING_R2W */
	u_int32_t mc_emem_arb_timing_r2w;
	/* Specifies the value for MC_EMEM_ARB_TIMING_W2R */
	u_int32_t mc_emem_arb_timing_w2r;
	/* Specifies the value for MC_EMEM_ARB_DA_TURNS */
	u_int32_t mc_emem_arb_da_turns;
	/* Specifies the value for MC_EMEM_ARB_DA_COVERS */
	u_int32_t mc_emem_arb_da_covers;
	/* Specifies the value for MC_EMEM_ARB_MISC0 */
	u_int32_t mc_emem_arb_misc0;
	/* Specifies the value for MC_EMEM_ARB_MISC1 */
	u_int32_t mc_emem_arb_misc1;
	/* Specifies the value for MC_EMEM_ARB_RING1_THROTTLE */
	u_int32_t mc_emem_arb_ring1_throttle;
	/* Specifies the value for MC_EMEM_ARB_OVERRIDE */
	u_int32_t mc_emem_arb_override;
	/* Specifies the value for MC_EMEM_ARB_RSV */
	u_int32_t mc_emem_arb_rsv;

	/* Specifies the value for MC_CLKEN_OVERRIDE */
	u_int32_t mc_clken_override;

	/* End of generated code by warmboot_code_gen */
} nvboot_sdram_params;
#endif /* #ifndef INCLUDED_NVBOOT_SDRAM_PARAM_H */

