/* Copyright (c) 2012-2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
/****************************** Revision History ******************************************
 *CH# Product           author          Description                             Date
 *-----------------------------------------------------------------------------------------
 *01  Atlantic	      nj.shetty    Intial file creation                    09-May-2014
 *      3G
 ******************************************************************************************
 */

#include <linux/batterydata-lib.h>

static struct single_row_lut fcc_temp = {
	.x		= {-20, 0, 25, 40, 60},
	.y		= {2098, 2097, 2096, 2093, 2084},
	.cols	= 5
};

static struct single_row_lut fcc_sf = {
	.x		= {0},
	.y		= {100},
	.cols	= 1
};

static struct sf_lut rbatt_sf = {
	.rows		= 30,
	.cols		= 5,
	.row_entries		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
	.sf		= {
				{1157, 239, 100, 86, 87},
				{1095, 240, 100, 88, 88},
				{1077, 244, 101, 88, 88},
				{1019, 249, 103, 89, 89},
				{972, 254, 106, 91, 90},
				{909, 257, 111, 94, 92},
				{896, 233, 116, 97, 93},
				{884, 232, 125, 101, 96},
				{888, 227, 129, 109, 101},
				{903, 224, 107, 98, 96},
				{925, 224, 100, 89, 89},
				{956, 225, 100, 89, 89},
				{990, 229, 102, 90, 92},
				{1036, 236, 103, 93, 94},
				{1092, 251, 106, 93, 94},
				{1158, 265, 109, 92, 91},
				{1249, 274, 106, 90, 90},
				{1390, 284, 105, 90, 90},
				{1618, 308, 102, 88, 89},
				{2002, 341, 103, 90, 90},
				{2175, 349, 103, 90, 92},
				{2698, 389, 105, 92, 92},
				{3579, 486, 108, 94, 94},
				{4964, 670, 112, 96, 97},
				{7516, 885, 118, 99, 99},
				{11629, 1162, 123, 99, 97},
				{17704, 1708, 121, 96, 94},
				{26440, 2631, 131, 100, 97},
				{39109, 4127, 168, 109, 106},
				{39109, 4127, 168, 109, 106},
	}
};

static struct pc_temp_ocv_lut pc_temp_ocv = {
	.rows		= 31,
	.cols		= 5,
	.temp		= {-20, 0, 25, 40, 60},
	.percent	= {100, 95, 90, 85, 80, 75, 70, 65, 60, 55, 50, 45, 40, 35, 30, 25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
	.ocv		= {
				{4382, 4382, 4382, 4382, 4382},
				{4312, 4312, 4312, 4312, 4312},
				{4283, 4283, 4283, 4283, 4283},
				{4237, 4237, 4237, 4237, 4237},
				{4167, 4167, 4167, 4167, 4167},
				{4078, 4078, 4078, 4078, 4078},
				{3916, 3958, 3983, 3988, 3987},
				{3875, 3919, 3950, 3950, 3948},
				{3843, 3883, 3912, 3914, 3912},
				{3819, 3851, 3860, 3865, 3864},
				{3799, 3825, 3828, 3829, 3829},
				{3784, 3803, 3806, 3807, 3806},
				{3770, 3786, 3790, 3789, 3789},
				{3757, 3774, 3776, 3776, 3774},
				{3743, 3764, 3767, 3763, 3760},
				{3728, 3751, 3759, 3750, 3737},
				{3709, 3728, 3739, 3730, 3716},
				{3690, 3707, 3710, 3702, 3689},
				{3672, 3694, 3683, 3675, 3666},
				{3656, 3686, 3676, 3670, 3659},
				{3648, 3682, 3674, 3668, 3657},
				{3637, 3677, 3672, 3666, 3656},
				{3624, 3673, 3669, 3664, 3654},
				{3612, 3667, 3667, 3661, 3651},
				{3594, 3659, 3662, 3656, 3646},
				{3573, 3645, 3649, 3641, 3628},
				{3545, 3614, 3613, 3603, 3587},
				{3505, 3565, 3554, 3543, 3528},
				{3443, 3490, 3473, 3462, 3449},
				{3340, 3372, 3352, 3343, 3331},
				{3000, 3000, 3000, 3000, 3000}
	}
};

struct bms_battery_data samsung_2100mAH_4400mV_data = {
	.fcc				= 2100,
	.fcc_temp_lut			= &fcc_temp,
	.fcc_sf_lut			= &fcc_sf,
	.pc_temp_ocv_lut		= &pc_temp_ocv,
	.rbatt_sf_lut			= &rbatt_sf,
	.default_rbatt_mohm	= 177
};

