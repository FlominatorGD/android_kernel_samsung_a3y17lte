#ifndef __S6E8AA0X1_A6LTE_PARAM_H__
#define __S6E8AA0X1_A6LTE_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>
#include "dynamic_aid_s6e8aa5x01_a6lte.h"

#define EXTEND_BRIGHTNESS		355
#define UI_MAX_BRIGHTNESS		255
#define UI_DEFAULT_BRIGHTNESS		128
#define NORMAL_TEMPERATURE		25	/* 25 degrees Celsius */

#define GAMMA_CMD_CNT			((u16)ARRAY_SIZE(SEQ_GAMMA_CONDITION_SET))
#define ACL_CMD_CNT			((u16)ARRAY_SIZE(SEQ_ACL_OFF))
#define OPR_CMD_CNT			((u16)ARRAY_SIZE(SEQ_ACL_OPR_OFF))
#define ELVSS_CMD_CNT			((u16)ARRAY_SIZE(SEQ_ELVSS_SET))
#define AID_CMD_CNT			((u16)ARRAY_SIZE(SEQ_AID_SETTING))
#define TSET_CMD_CNT			((u16)ARRAY_SIZE(SEQ_TSET))

#define LDI_REG_ELVSS			0xB6
#define LDI_REG_COORDINATE		0xA1
#define LDI_REG_ID			0x04
#define LDI_REG_CHIP_ID			0xD6
#define LDI_REG_MTP			0xC8
#define LDI_REG_DATE			LDI_REG_MTP
#define LDI_REG_HBM			0xB4
#define LDI_REG_MANUFACTURE_INFO	0xC9

/* len is read length */
#define LDI_LEN_ELVSS			(ELVSS_CMD_CNT - 1)
#define LDI_LEN_COORDINATE		4
#define LDI_LEN_DATE			7
#define LDI_LEN_ID			3
#define LDI_LEN_CHIP_ID			5
#define LDI_LEN_MTP			33

#define LDI_LEN_HBM			30
#define LDI_LEN_MANUFACTURE_INFO	21

/* offset is position including addr, not only para */
#define LDI_OFFSET_AOR_1	1
#define LDI_OFFSET_AOR_2	2

#define LDI_OFFSET_ELVSS_1	1	/* B6h 1st Para: MPS_CON */
#define LDI_OFFSET_ELVSS_2	2	/* B6h 2nd Para: ELVSS_Dim_offset */
#define LDI_OFFSET_ELVSS_3	22	/* B6h 22th Para: ELVSS Temp Compensation */

#define LDI_OFFSET_OPR_1	1	/* B5h 1st Para: Frame Avg. */
#define LDI_OFFSET_OPR_2	2	/* B5h 2nd Para: Start Point */
#define LDI_OFFSET_OPR_3	4	/* B5h 22nd Para: ACL Percent */

#define LDI_OFFSET_ACL		1
#define LDI_OFFSET_TSET		8

#define LDI_GPARA_DATE		40	/* C8h 41th Para: Manufacture Year, Month */
#define LDI_GPARA_HBM_ELVSS	22	/* B6h 23th Para: ELVSS_Cal_Offset for HBM */
#define LDI_GPARA_HBM_GAMMA	1	/* B4h 2nd Para: V255 RED Gamma */

#define	LDI_REG_RDDPM		0x0A	/* Read Display Power Mode */
#define	LDI_LEN_RDDPM		1

#define	LDI_REG_RDDSM		0x0E	/* Read Display Signal Mode */
#define	LDI_LEN_RDDSM		1

#ifdef CONFIG_DISPLAY_USE_INFO
#define LDI_REG_RDNUMED		0x05		/* DPUI_KEY_PNDSIE: Read Number of the Errors on DSI */
#define LDI_LEN_RDNUMED		1
#define LDI_PNDSIE_MASK		(GENMASK(6, 0))

/*
* ESD_ERROR[6] = VLIN1 error is occurred by ESD = 0x40
* ESD_ERROR[5] = Internal HSYNC error is occurred by ESD
* ESD_ERROR[4] = CHECK_SUM error is occurred by ESD
* ESD_ERROR[3] = ELVDD error is occurred by ESD = 0x08
* ESD_ERROR[2] = VLIN3 error is occurred by ESD = 0x04
* ESD_ERROR[1] = HS CLK lane error is occurred by ESD
* ESD_ERROR[0] = MIPI DSI error is occurred by ESD
*/
#define LDI_REG_ESDERR		0xEE		/* DPUI_KEY_PNELVDE, DPUI_KEY_PNVLI1E, DPUI_KEY_PNVLO3E, DPUI_KEY_PNESDE */
#define LDI_LEN_ESDERR		1
#define LDI_PNELVDE_MASK	(BIT(3))	/* ELVDD error */
#define LDI_PNVLI1E_MASK	(BIT(6))	/* VLIN1 error */
#define LDI_PNVLO3E_MASK	(BIT(2))	/* VLIN3 error */
#define LDI_PNESDE_MASK		(BIT(2) | BIT(3) | BIT(6))

#define LDI_REG_RDDSDR		0x0F		/* DPUI_KEY_PNSDRE: Read Display Self-Diagnostic Result */
#define LDI_LEN_RDDSDR		1
#define LDI_PNSDRE_MASK		(BIT(7))	/* D7: REG_DET: Register Loading Detection */

static unsigned char SEQ_ESD_MONITOR_ON[] = {
	0xED,
	0x4C,
};
#endif

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_SLEEP_OUT[] = {
	0x11
};

static unsigned char SEQ_SLEEP_IN[] = {
	0x10
};

static unsigned char SEQ_DISPLAY_ON[] = {
	0x29
};

static unsigned char SEQ_DISPLAY_OFF[] = {
	0x28
};

static unsigned char SEQ_TEST_KEY_ON_F0[] = {
	0xF0,
	0x5A, 0x5A
};

static unsigned char SEQ_TEST_KEY_OFF_F0[] = {
	0xF0,
	0xA5, 0xA5
};

static unsigned char SEQ_PENTILE_SETTING[] = {
	0xC0,
	0xD8, 0xD8, 0x00,
};

static unsigned char SEQ_PCD_SET_DET_LOW[] = {
	0xCC,
	0x5C
};

static unsigned char SEC_ERR_FLAG_SETTING[] = {
	0xE7,
	0xED, 0xC7, 0x23, 0x67
};

static unsigned char SEQ_DISPLAY_SETTING[] = {
	0xF2,
	0x0C, 0x0C, 0xB9, 0x01
};

static unsigned char SEQ_LTPS_TIMING[] = {
	0xCB,
	0x00, 0x45, 0x10, 0x10, 0x08, 0x32, 0x54, 0x00,
	0x00, 0x00, 0x00, 0x07, 0x06, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x48, 0x5E, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0x00, 0xAD, 0x00, 0x00,
	0x08, 0x05, 0x2A, 0x54, 0x03, 0xCC, 0x00, 0xFF,
	0xFB, 0x03, 0x0D, 0x00, 0x11, 0x0F, 0x02, 0x03,
	0x0B, 0x0C, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
	0x13, 0x13, 0x13, 0x13, 0x00, 0x02, 0x03, 0x0B,
	0x0C, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,
	0x13, 0x13
};

static unsigned char SEQ_GAMMA_CONDITION_SET[] = {
	0xCA,
	0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
	0x00, 0x00, 0x00
};

static unsigned char SEQ_AID_SETTING[] = {
	0xB2,
	0x00, 0x10, 0x00, 0x10
};

static unsigned char SEQ_ELVSS_SET[] = {
	0xB6,
	0xBC,	/* MPS_CON */
	0x04,	/* ELVSS_Dim_offset */
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xC0, 0x00, 0x0A, 0xAA, 0x22, 0x12, 0x03, 0x33, 0x21,
	0x10,
	0x00,	/* DUMMY: B6h 22 Para: ELVSS_Cal_Offset */
	0x00,	/* DUMMY: B6h 23 Para: OTP for B6h 22 Para in HBM Interpolation */
};

static unsigned char SEQ_GAMMA_UPDATE[] = {
	0xF7,
	0x03,
};

static unsigned char SEQ_ACL_OPR_OFF[] = {
	0xB5,
	0x40,	/* 16 Frame Avg. at ACL Off */
	0x7F,	/* Start Point 50% */
	0x14,
	0x14	/* ACL 15% */
};

static unsigned char SEQ_ACL_OPR_08P[] = {
	0xB5,
	0x50,	/* 32 Frame Avg. at ACL On */
	0x99,	/* Start Point 60% */
	0x14,
	0x0A	/* ACL 8% */
};

static unsigned char SEQ_ACL_OPR_15P[] = {
	0xB5,
	0x50,	/* 32 Frame Avg. at ACL On */
	0x7F,	/* Start Point 50% */
	0x14,
	0x14	/* ACL 15% */
};

static unsigned char SEQ_ACL_OFF[] = {
	0x55,
	0x00
};

static unsigned char SEQ_ACL_ON[] = {
	0x55,
	0x02
};

static unsigned char SEQ_TSET[] = {
	0xB8,
	0x38, 0x00, 0x00, 0x40, 0x44, 0x00, 0x38,
	0x19	/* (ex) 25 degree : 0x19 */
};

/***********************************************/

enum {
	ACL_STATUS_OFF,
	ACL_STATUS_ON,
	ACL_STATUS_MAX
};

enum {
	OPR_STATUS_OFF,
	OPR_STATUS_08P,
	OPR_STATUS_15P,
	OPR_STATUS_MAX
};

enum {
	TEMP_ABOVE_MINUS_00_DEGREE,	/* T > 0 */
	TEMP_ABOVE_MINUS_15_DEGREE,	/* -15 < T <= 0 */
	TEMP_BELOW_MINUS_15_DEGREE,	/* T <= -15 */
	TEMP_MAX
};

static unsigned char *ACL_TABLE[ACL_STATUS_MAX] = {SEQ_ACL_OFF, SEQ_ACL_ON};
static unsigned char *OPR_TABLE[OPR_STATUS_MAX] = {SEQ_ACL_OPR_OFF, SEQ_ACL_OPR_08P, SEQ_ACL_OPR_15P};

static unsigned char elvss_mpscon_data[IBRIGHTNESS_HBM_MAX] = {
	[IBRIGHTNESS_005NIT ... IBRIGHTNESS_039NIT] = 0xAC,
	[IBRIGHTNESS_041NIT ... IBRIGHTNESS_500NIT] = 0xBC,
};

static unsigned char elvss_offset_data[IBRIGHTNESS_HBM_MAX][TEMP_MAX] = {
	[IBRIGHTNESS_005NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_006NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_007NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_008NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_009NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_010NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_011NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_012NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_013NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_014NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_015NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_016NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_017NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_019NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_020NIT] = {0x04, 0x08, 0x0F},
	[IBRIGHTNESS_021NIT] = {0x06, 0X08, 0x0F},
	[IBRIGHTNESS_022NIT] = {0x08, 0x08, 0x0F},
	[IBRIGHTNESS_024NIT] = {0x0A, 0x0A, 0x0F},
	[IBRIGHTNESS_025NIT] = {0x0C, 0x0C, 0x0F},
	[IBRIGHTNESS_027NIT] = {0x0E, 0x0E, 0x0F},
	[IBRIGHTNESS_029NIT] = {0x10, 0x10, 0x10},
	[IBRIGHTNESS_030NIT] = {0x12, 0x12, 0x12},
	[IBRIGHTNESS_032NIT] = {0x14, 0x14, 0x14},
	[IBRIGHTNESS_034NIT] = {0x16, 0x16, 0x16},
	[IBRIGHTNESS_037NIT] = {0x16, 0x16, 0x16},
	[IBRIGHTNESS_039NIT] = {0x16, 0x16, 0x16},
	[IBRIGHTNESS_041NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_044NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_047NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_050NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_053NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_056NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_060NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_064NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_068NIT] = {0x18, 0x18, 0x18},
	[IBRIGHTNESS_072NIT] = {0x17, 0x17, 0x17},
	[IBRIGHTNESS_077NIT] = {0x17, 0x17, 0x17},
	[IBRIGHTNESS_082NIT] = {0x16, 0x16, 0x16},
	[IBRIGHTNESS_087NIT] = {0x16, 0x16, 0x16},
	[IBRIGHTNESS_093NIT] = {0x16, 0x16, 0x16},
	[IBRIGHTNESS_098NIT] = {0x16, 0x16, 0x16},
	[IBRIGHTNESS_105NIT] = {0x15, 0x15, 0x15},
	[IBRIGHTNESS_111NIT] = {0x15, 0x15, 0x15},
	[IBRIGHTNESS_119NIT] = {0x14, 0x14, 0x14},
	[IBRIGHTNESS_126NIT] = {0x14, 0x14, 0x14},
	[IBRIGHTNESS_134NIT] = {0x14, 0x14, 0x14},
	[IBRIGHTNESS_143NIT] = {0x14, 0x14, 0x14},
	[IBRIGHTNESS_152NIT] = {0x13, 0x13, 0x13},
	[IBRIGHTNESS_162NIT] = {0x12, 0x12, 0x12},
	[IBRIGHTNESS_172NIT] = {0x11, 0x11, 0x11},
	[IBRIGHTNESS_183NIT] = {0x11, 0x11, 0x11},
	[IBRIGHTNESS_195NIT] = {0x10, 0x10, 0x10},
	[IBRIGHTNESS_207NIT] = {0x0F, 0x0F, 0x0F},
	[IBRIGHTNESS_220NIT] = {0x0E, 0x0E, 0x0E},
	[IBRIGHTNESS_234NIT] = {0x0D, 0x0D, 0x0D},
	[IBRIGHTNESS_249NIT] = {0x0C, 0x0C, 0x0C},
	[IBRIGHTNESS_265NIT] = {0x0B, 0x0B, 0x0B},
	[IBRIGHTNESS_282NIT] = {0x0A, 0x0A, 0x0A},
	[IBRIGHTNESS_300NIT] = {0x08, 0x08, 0x08},
	[IBRIGHTNESS_316NIT] = {0x07, 0x07, 0x07},
	[IBRIGHTNESS_333NIT] = {0x06, 0x06, 0x06},
	[IBRIGHTNESS_360NIT] = {0x04, 0x04, 0x04},
	[IBRIGHTNESS_378NIT] = {0x11, 0x11, 0x11},
	[IBRIGHTNESS_395NIT] = {0x0F, 0x0F, 0x0F},
	[IBRIGHTNESS_413NIT] = {0x0D, 0x0D, 0x0D},
	[IBRIGHTNESS_430NIT] = {0x0B, 0x0B, 0x0B},
	[IBRIGHTNESS_448NIT] = {0x09, 0x09, 0x09},
	[IBRIGHTNESS_465NIT] = {0x07, 0x07, 0x07},
	[IBRIGHTNESS_483NIT] = {0x05, 0x05, 0x05},
	[IBRIGHTNESS_500NIT] = {0x04, 0x04, 0x04},
};

static unsigned char AOR_TABLE[EXTEND_BRIGHTNESS + 1][AID_CMD_CNT] = {
	{0xB2, 0x05, 0xA5},
	{0xB2, 0x05, 0xA1},
	{0xB2, 0x05, 0x9D},
	{0xB2, 0x05, 0x99},
	{0xB2, 0x05, 0x95},
	{0xB2, 0x05, 0x92},
	{0xB2, 0x05, 0x8F},
	{0xB2, 0x05, 0x8C},
	{0xB2, 0x05, 0x89},
	{0xB2, 0x05, 0x86},
	{0xB2, 0x05, 0x83},
	{0xB2, 0x05, 0x80},
	{0xB2, 0x05, 0x7E},
	{0xB2, 0x05, 0x7B},
	{0xB2, 0x05, 0x78},
	{0xB2, 0x05, 0x75},
	{0xB2, 0x05, 0x73},
	{0xB2, 0x05, 0x70},
	{0xB2, 0x05, 0x6D},
	{0xB2, 0x05, 0x6A},
	{0xB2, 0x05, 0x67},
	{0xB2, 0x05, 0x63},
	{0xB2, 0x05, 0x5F},
	{0xB2, 0x05, 0x5B},
	{0xB2, 0x05, 0x56},
	{0xB2, 0x05, 0x53},
	{0xB2, 0x05, 0x50},
	{0xB2, 0x05, 0x4D},
	{0xB2, 0x05, 0x4A},
	{0xB2, 0x05, 0x46},
	{0xB2, 0x05, 0x42},
	{0xB2, 0x05, 0x3E},
	{0xB2, 0x05, 0x3B},
	{0xB2, 0x05, 0x3A},
	{0xB2, 0x05, 0x38},
	{0xB2, 0x05, 0x36},
	{0xB2, 0x05, 0x35},
	{0xB2, 0x05, 0x31},
	{0xB2, 0x05, 0x2D},
	{0xB2, 0x05, 0x29},
	{0xB2, 0x05, 0x25},
	{0xB2, 0x05, 0x22},
	{0xB2, 0x05, 0x20},
	{0xB2, 0x05, 0x19},
	{0xB2, 0x05, 0x11},
	{0xB2, 0x05, 0x02},
	{0xB2, 0x04, 0xF2},
	{0xB2, 0x04, 0xEB},
	{0xB2, 0x04, 0xE4},
	{0xB2, 0x04, 0xDD},
	{0xB2, 0x04, 0xD5},
	{0xB2, 0x04, 0xCD},
	{0xB2, 0x04, 0xC5},
	{0xB2, 0x04, 0xB6},
	{0xB2, 0x04, 0xA7},
	{0xB2, 0x04, 0x9E},
	{0xB2, 0x04, 0x95},
	{0xB2, 0x04, 0x85},
	{0xB2, 0x04, 0x76},
	{0xB2, 0x04, 0x65},
	{0xB2, 0x04, 0x54},
	{0xB2, 0x04, 0x4C},
	{0xB2, 0x04, 0x44},
	{0xB2, 0x04, 0x32},
	{0xB2, 0x04, 0x1F},
	{0xB2, 0x04, 0x0F},
	{0xB2, 0x03, 0xFF},
	{0xB2, 0x03, 0xE9},
	{0xB2, 0x03, 0xD3},
	{0xB2, 0x03, 0xC3},
	{0xB2, 0x03, 0xB3},
	{0xB2, 0x03, 0xA3},
	{0xB2, 0x03, 0x93},
	{0xB2, 0x03, 0x7C},
	{0xB2, 0x03, 0x66},
	{0xB2, 0x03, 0x53},
	{0xB2, 0x03, 0x40},
	{0xB2, 0x03, 0x27},
	{0xB2, 0x03, 0x0E},
	{0xB2, 0x02, 0xF8},
	{0xB2, 0x02, 0xE2},
	{0xB2, 0x02, 0xCB},
	{0xB2, 0x02, 0xB5},
	{0xB2, 0x02, 0x96},
	{0xB2, 0x02, 0x77},
	{0xB2, 0x02, 0x56},
	{0xB2, 0x02, 0x36},
	{0xB2, 0x02, 0x32},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x30},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x35},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x33},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x31},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x34},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x2E},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x35},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x2F},
	{0xB2, 0x02, 0x15},
	{0xB2, 0x02, 0x35},
	{0xB2, 0x02, 0x14},
	{0xB2, 0x01, 0xF9},
	{0xB2, 0x01, 0xDE},
	{0xB2, 0x01, 0xC5},
	{0xB2, 0x01, 0xAD},
	{0xB2, 0x01, 0x94},
	{0xB2, 0x01, 0x7A},
	{0xB2, 0x01, 0x60},
	{0xB2, 0x01, 0x46},
	{0xB2, 0x01, 0x2D},
	{0xB2, 0x01, 0x13},
	{0xB2, 0x00, 0xFA},
	{0xB2, 0x00, 0xE0},
	{0xB2, 0x00, 0xC6},
	{0xB2, 0x00, 0xAC},
	{0xB2, 0x00, 0x97},
	{0xB2, 0x00, 0x81},
	{0xB2, 0x00, 0x6C},
	{0xB2, 0x00, 0x57},
	{0xB2, 0x00, 0x53},
	{0xB2, 0x00, 0x3D},
	{0xB2, 0x00, 0x26},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x63},
	{0xB2, 0x00, 0x5B},
	{0xB2, 0x00, 0x53},
	{0xB2, 0x00, 0x4A},
	{0xB2, 0x00, 0x42},
	{0xB2, 0x00, 0x3A},
	{0xB2, 0x00, 0x31},
	{0xB2, 0x00, 0x29},
	{0xB2, 0x00, 0x21},
	{0xB2, 0x00, 0x18},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x5E},
	{0xB2, 0x00, 0x57},
	{0xB2, 0x00, 0x4F},
	{0xB2, 0x00, 0x47},
	{0xB2, 0x00, 0x3F},
	{0xB2, 0x00, 0x37},
	{0xB2, 0x00, 0x2F},
	{0xB2, 0x00, 0x28},
	{0xB2, 0x00, 0x20},
	{0xB2, 0x00, 0x18},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x60},
	{0xB2, 0x00, 0x58},
	{0xB2, 0x00, 0x50},
	{0xB2, 0x00, 0x48},
	{0xB2, 0x00, 0x40},
	{0xB2, 0x00, 0x38},
	{0xB2, 0x00, 0x30},
	{0xB2, 0x00, 0x28},
	{0xB2, 0x00, 0x20},
	{0xB2, 0x00, 0x18},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x61},
	{0xB2, 0x00, 0x59},
	{0xB2, 0x00, 0x51},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x41},
	{0xB2, 0x00, 0x38},
	{0xB2, 0x00, 0x30},
	{0xB2, 0x00, 0x28},
	{0xB2, 0x00, 0x20},
	{0xB2, 0x00, 0x18},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x61},
	{0xB2, 0x00, 0x59},
	{0xB2, 0x00, 0x51},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x41},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x31},
	{0xB2, 0x00, 0x28},
	{0xB2, 0x00, 0x20},
	{0xB2, 0x00, 0x18},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x62},
	{0xB2, 0x00, 0x5A},
	{0xB2, 0x00, 0x51},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x41},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x31},
	{0xB2, 0x00, 0x29},
	{0xB2, 0x00, 0x20},
	{0xB2, 0x00, 0x18},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x62},
	{0xB2, 0x00, 0x5B},
	{0xB2, 0x00, 0x53},
	{0xB2, 0x00, 0x4C},
	{0xB2, 0x00, 0x44},
	{0xB2, 0x00, 0x3D},
	{0xB2, 0x00, 0x35},
	{0xB2, 0x00, 0x2E},
	{0xB2, 0x00, 0x26},
	{0xB2, 0x00, 0x1F},
	{0xB2, 0x00, 0x17},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x62},
	{0xB2, 0x00, 0x5A},
	{0xB2, 0x00, 0x53},
	{0xB2, 0x00, 0x4C},
	{0xB2, 0x00, 0x44},
	{0xB2, 0x00, 0x3D},
	{0xB2, 0x00, 0x35},
	{0xB2, 0x00, 0x2E},
	{0xB2, 0x00, 0x26},
	{0xB2, 0x00, 0x1F},
	{0xB2, 0x00, 0x17},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x54},
	{0xB2, 0x00, 0x4E},
	{0xB2, 0x00, 0x47},
	{0xB2, 0x00, 0x40},
	{0xB2, 0x00, 0x39},
	{0xB2, 0x00, 0x32},
	{0xB2, 0x00, 0x2B},
	{0xB2, 0x00, 0x25},
	{0xB2, 0x00, 0x1E},
	{0xB2, 0x00, 0x17},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x56},
	{0xB2, 0x00, 0x4F},
	{0xB2, 0x00, 0x49},
	{0xB2, 0x00, 0x43},
	{0xB2, 0x00, 0x3C},
	{0xB2, 0x00, 0x36},
	{0xB2, 0x00, 0x30},
	{0xB2, 0x00, 0x29},
	{0xB2, 0x00, 0x23},
	{0xB2, 0x00, 0x1D},
	{0xB2, 0x00, 0x16},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x77},
	{0xB2, 0x00, 0x6E},
	{0xB2, 0x00, 0x66},
	{0xB2, 0x00, 0x5D},
	{0xB2, 0x00, 0x55},
	{0xB2, 0x00, 0x4C},
	{0xB2, 0x00, 0x44},
	{0xB2, 0x00, 0x3B},
	{0xB2, 0x00, 0x32},
	{0xB2, 0x00, 0x2A},
	{0xB2, 0x00, 0x21},
	{0xB2, 0x00, 0x19},
	{0xB2, 0x00, 0x10},
	{0xB2, 0x00, 0x10},
	[UI_MAX_BRIGHTNESS + 1 ... EXTEND_BRIGHTNESS] = {0xB2, 0x00, 0x10},
};

/* platform brightness <-> acl opr and percent */
static unsigned int brightness_opr_table[ACL_STATUS_MAX][EXTEND_BRIGHTNESS + 1] = {
	{
		[0 ... UI_MAX_BRIGHTNESS - 1]			= OPR_STATUS_15P,
		[UI_MAX_BRIGHTNESS ... EXTEND_BRIGHTNESS]	= OPR_STATUS_OFF,
	}, {
		[0 ... 267]					= OPR_STATUS_15P,
		[268 ... EXTEND_BRIGHTNESS]			= OPR_STATUS_08P
	}
};

/* platform brightness <-> gamma level */
static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	[0 ... 0] =	IBRIGHTNESS_005NIT,
	[1 ... 4] =	IBRIGHTNESS_006NIT,
	[5 ... 8] =	IBRIGHTNESS_007NIT,
	[9 ... 12] =	IBRIGHTNESS_008NIT,
	[13 ... 16] =	IBRIGHTNESS_009NIT,
	[17 ... 20] =	IBRIGHTNESS_010NIT,
	[21 ... 24] =	IBRIGHTNESS_011NIT,
	[25 ... 28] =	IBRIGHTNESS_012NIT,
	[29 ... 32] =	IBRIGHTNESS_013NIT,
	[33 ... 36] =	IBRIGHTNESS_014NIT,
	[37 ... 40] =	IBRIGHTNESS_015NIT,
	[41 ... 42] =	IBRIGHTNESS_016NIT,
	[43 ... 44] =	IBRIGHTNESS_017NIT,
	[45 ... 46] =	IBRIGHTNESS_019NIT,
	[47 ... 48] =	IBRIGHTNESS_020NIT,
	[49 ... 50] =	IBRIGHTNESS_021NIT,
	[51 ... 52] =	IBRIGHTNESS_022NIT,
	[53 ... 54] =	IBRIGHTNESS_024NIT,
	[55 ... 56] =	IBRIGHTNESS_025NIT,
	[57 ... 58] =	IBRIGHTNESS_027NIT,
	[59 ... 60] =	IBRIGHTNESS_029NIT,
	[61 ... 62] =	IBRIGHTNESS_030NIT,
	[63 ... 64] =	IBRIGHTNESS_032NIT,
	[65 ... 66] =	IBRIGHTNESS_034NIT,
	[67 ... 68] =	IBRIGHTNESS_037NIT,
	[69 ... 70] =	IBRIGHTNESS_039NIT,
	[71 ... 72] =	IBRIGHTNESS_041NIT,
	[73 ... 74] =	IBRIGHTNESS_044NIT,
	[75 ... 76] =	IBRIGHTNESS_047NIT,
	[77 ... 78] =	IBRIGHTNESS_050NIT,
	[79 ... 80] =	IBRIGHTNESS_053NIT,
	[81 ... 82] =	IBRIGHTNESS_056NIT,
	[83 ... 84] =	IBRIGHTNESS_060NIT,
	[85 ... 86] =	IBRIGHTNESS_064NIT,
	[87 ... 88] =	IBRIGHTNESS_068NIT,
	[89 ... 90] =	IBRIGHTNESS_072NIT,
	[91 ... 92] =	IBRIGHTNESS_077NIT,
	[93 ... 94] =	IBRIGHTNESS_082NIT,
	[95 ... 96] =	IBRIGHTNESS_087NIT,
	[97 ... 98] =	IBRIGHTNESS_093NIT,
	[99 ... 100] =	IBRIGHTNESS_098NIT,
	[101 ... 102] =	IBRIGHTNESS_105NIT,
	[103 ... 104] =	IBRIGHTNESS_111NIT,
	[105 ... 106] =	IBRIGHTNESS_119NIT,
	[107 ... 108] =	IBRIGHTNESS_126NIT,
	[109 ... 111] =	IBRIGHTNESS_134NIT,
	[112 ... 114] =	IBRIGHTNESS_143NIT,
	[115 ... 117] =	IBRIGHTNESS_152NIT,
	[118 ... 120] =	IBRIGHTNESS_162NIT,
	[121 ... 124] =	IBRIGHTNESS_172NIT,
	[125 ... 128] =	IBRIGHTNESS_183NIT,
	[129 ... 139] =	IBRIGHTNESS_195NIT,
	[140 ... 150] =	IBRIGHTNESS_207NIT,
	[151 ... 161] =	IBRIGHTNESS_220NIT,
	[162 ... 172] =	IBRIGHTNESS_234NIT,
	[173 ... 183] =	IBRIGHTNESS_249NIT,
	[184 ... 194] =	IBRIGHTNESS_265NIT,
	[195 ... 206] =	IBRIGHTNESS_282NIT,
	[207 ... 218] =	IBRIGHTNESS_300NIT,
	[219 ... 229] =	IBRIGHTNESS_316NIT,
	[230 ... 241] =	IBRIGHTNESS_333NIT,
	[242 ... 267] =	IBRIGHTNESS_360NIT,
	[268 ... 279] =	IBRIGHTNESS_378NIT,
	[280 ... 292] =	IBRIGHTNESS_395NIT,
	[293 ... 304] =	IBRIGHTNESS_413NIT,
	[305 ... 317] =	IBRIGHTNESS_430NIT,
	[318 ... 329] =	IBRIGHTNESS_448NIT,
	[330 ... 341] =	IBRIGHTNESS_465NIT,
	[342 ... 354] =	IBRIGHTNESS_483NIT,
	[355 ... EXTEND_BRIGHTNESS] =	 IBRIGHTNESS_500NIT,
};
#endif /* __S6E8AA0X1_A6LTE_PARAM_H__ */