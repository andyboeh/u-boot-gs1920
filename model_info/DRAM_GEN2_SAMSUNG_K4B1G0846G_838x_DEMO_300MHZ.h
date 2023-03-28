.mcr = 0x00000000,
.dcr = 0x20320000,
.d23oscr = 0x00000000,
.daccr = 0x80000010,
.dacspcr = 0x0000007f,
.dacspar = 0x00000000,
.auto_calibration = 0x00,
#ifndef CONFIG_USE_CUSTOM_PARAMETERS
.dtr0 = 0x54433830,
.dtr1 = 0x0404030f,
.dtr2 = 0x0630d000,
.mpmr0 = 0x0f3ff3ff,
.mpmr1 = 0xff000000,
.dider = 0x80000000,
.DDR1_mr = 0x00000000,
.DDR1_emr = 0x00000000,
.DDR2_mr = 0x00000000,
.DDR2_emr1 = 0x00000000,
.DDR2_emr2 = 0x00000000,
.DDR2_emr3 = 0x00000000,
.DDR3_mr0 = 0x00101220,
.DDR3_mr1 = 0x00110040, //0x00110042:RZQ/7;  0x00110040:RZQ/6;  ->OCD large, driving small
.DDR3_mr2 = 0x00120400,
.DDR3_mr3 = 0x00130000,
.static_cal_data_0 = 0x0a1e0f00,
.static_cal_data_1 = 0x0a1e0f00,
.static_cal_data_2 = 0x0a1e0f00,
.static_cal_data_3 = 0x0a1e0f00,
.static_cal_data_4 = 0x0a1e0f00,
.static_cal_data_5 = 0x0a1e0f00,
.static_cal_data_6 = 0x0a1e0f00,
.static_cal_data_7 = 0x0a1e0f00,
.static_cal_data_8 = 0x001e0f00,
.static_cal_data_9 = 0x001e0f00,
.static_cal_data_10 = 0x001e0f00,
.static_cal_data_11 = 0x001e0f00,
.static_cal_data_12 = 0x001e0f00,
.static_cal_data_13 = 0x001e0f00,
.static_cal_data_14 = 0x001e0f00,
.static_cal_data_15 = 0x001e0f00,
.static_cal_data_16 = 0x001e0f00,
.static_cal_data_17 = 0x001e0f00,
.static_cal_data_18 = 0x001e0f00,
.static_cal_data_19 = 0x001e0f00,
.static_cal_data_20 = 0x001e0f00,
.static_cal_data_21 = 0x001e0f00,
.static_cal_data_22 = 0x001e0f00,
.static_cal_data_23 = 0x001e0f00,
.static_cal_data_24 = 0x001e0f00,
.static_cal_data_25 = 0x001e0f00,
.static_cal_data_26 = 0x001e0f00,
.static_cal_data_27 = 0x001e0f00,
.static_cal_data_28 = 0x001e0f00,
.static_cal_data_29 = 0x001e0f00,
.static_cal_data_30 = 0x001e0f00,
.static_cal_data_31 = 0x001e0f00,
.static_cal_data_32 = 0x08000000,
.zq_setting = 0x0000107c,
.calibration_type = 0x01,
.tx_clk_phs_delay = 17,
.clkm_delay = 13,
.clkm90_delay = 10,
.drv_strength = 0x00,
#endif
