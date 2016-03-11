/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2005
 *
 *  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 *  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
 *  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 *  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 *  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 *  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
 *  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
 *  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
 *  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 *  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
 *  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
 *  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
 *  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
 *  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
 *  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
 *
 *****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * timeattdb.c
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file is for MTK Bluetooth Time profile
 *
 * Author:
 * -------
 * Jacob Lee
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision: #1 $
 * $Modtime: $
 * $Log: $
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __BT_TIMES_PROFILE__
#include "attdb.h"
#include "attdef.h"
#include "attdbmain.h"

extern U8 time_att_db_cttime_callback(U8 type, BtRemoteDevice *link, U16 *len, U8 **raw);
extern U8 time_att_db_cttime_config_callback(U8 type, BtRemoteDevice *link, U16 *len, U8 **raw);
extern U8 time_att_db_local_time_info_callback(U8 type, BtRemoteDevice *link, U16 *len, U8 **raw);
extern U8 time_att_db_ref_time_info_callback(U8 type, BtRemoteDevice *link, U16 *len, U8 **raw);
extern U8 time_att_db_time_with_dst_callback(U8 type, BtRemoteDevice *link, U16 *len, U8 **raw);
extern U8 time_att_db_update_ctrl_point_callback(U8 type, BtRemoteDevice *link, U16 *len, U8 **raw);
extern U8 time_att_db_update_state_callback(U8 type, BtRemoteDevice *link, U16 *len, U8 **raw);

/* Current Time service */
const U8 attCurrTimeRecord[] = 
{
	ATT_HANDLE16(ATT_HANDLE_PRIMARY_SERVICE_CURRENT_TIME,
				BT_UUID_GATT_TYPE_PRIMARY_SERVICE,
				BT_ATT_CONST_VARIABLE, 0x02),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETUUID16(BT_UUID_GATT_SERVICE_TIME),

	/* CT Time characteristic */
	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_CT_TIME,
			BT_UUID_GATT_TYPE_CHARACTERISTIC,
			BT_ATT_CONST_VARIABLE, 0x05),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETCHARACTERISTIC(GATT_CHAR_PROP_READ | GATT_CHAR_PROP_NOTIFY,
			ATT_HANDLE_CHARACTERISTIC_CT_TIME_VALUE,
			BT_UUID_CT_TIME),

	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_CT_TIME_VALUE,
			BT_UUID_CT_TIME,
			BT_ATT_FIX_VARIABLE_IN_UPPER_AP, 0x0A),
	ATT_PERMINSIONS(ATT_PERMISSIONS_GATT_DEFINED),

	ATT_HANDLE16(ATT_HANDLE_CLIENT_CHARACTERISTIC_CONFIG_CT_TIME_VALUE,
			BT_UUID_GATT_CHAR_DESC_CLIENT_CHAR_CONFIG,
			BT_ATT_FIX_VARIABLE_IN_UPPER_AP, 0x02),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_WRITE),

	/* Local Time Information characteristic */
	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_LOCAL_TIME_INFO,
			BT_UUID_GATT_TYPE_CHARACTERISTIC,
			BT_ATT_CONST_VARIABLE, 0x05),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETCHARACTERISTIC(GATT_CHAR_PROP_READ,
			ATT_HANDLE_CHARACTERISTIC_LOCAL_TIME_INFO_VALUE,
			BT_UUID_LOCAL_TIME_INFO),

	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_LOCAL_TIME_INFO_VALUE,
			BT_UUID_LOCAL_TIME_INFO,
			BT_ATT_FIX_VARIABLE_IN_UPPER_AP, 0x02),
	ATT_PERMINSIONS(ATT_PERMISSIONS_GATT_DEFINED),

	/* Reference Time Information characteristic */
	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_REF_TIME_INFO,
			BT_UUID_GATT_TYPE_CHARACTERISTIC,
			BT_ATT_CONST_VARIABLE, 0x05),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETCHARACTERISTIC(GATT_CHAR_PROP_READ,
			ATT_HANDLE_CHARACTERISTIC_REF_TIME_INFO_VALUE,
			BT_UUID_REF_TIME_INFO),

	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_REF_TIME_INFO_VALUE,
			BT_UUID_REF_TIME_INFO,
			BT_ATT_FIX_VARIABLE_IN_UPPER_AP, 0x04),
	ATT_PERMINSIONS(ATT_PERMISSIONS_GATT_DEFINED),
};

/* Next DST Change service */
const U8 attNextDstRecord[] =
{
	ATT_HANDLE16(ATT_HANDLE_PRIMARY_SERVICE_NEXT_DST_CHANGE,
			BT_UUID_GATT_TYPE_PRIMARY_SERVICE,
			BT_ATT_CONST_VARIABLE, 0x02),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETUUID16(BT_UUID_GATT_SERVICE_DST),

	/* Time with DST characteristic */
	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_TIME_WITH_DST,
			BT_UUID_GATT_TYPE_CHARACTERISTIC,
			BT_ATT_CONST_VARIABLE, 0x05),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETCHARACTERISTIC(GATT_CHAR_PROP_READ,
			ATT_HANDLE_CHARACTERISTIC_TIME_WITH_DST_VALUE,
			BT_UUID_TIME_WITH_DST),

	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_TIME_WITH_DST_VALUE,
			BT_UUID_TIME_WITH_DST,
			BT_ATT_FIX_VARIABLE_IN_UPPER_AP, 0x08),
	ATT_PERMINSIONS(ATT_PERMISSIONS_GATT_DEFINED),
};

/* Reference Time Update service */
const U8 attRefTimeUpdateRecord[] =
{
	ATT_HANDLE16(ATT_HANDLE_PRIMARY_SERVICE_REFERENCE_TIME_UPDATE,
			BT_UUID_GATT_TYPE_PRIMARY_SERVICE,
			BT_ATT_CONST_VARIABLE, 0x02),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETUUID16(BT_UUID_GATT_SERVICE_TIMEUPDATE),

	/* Time Update Control Point characteristic */
	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_CONTROL_POINT,
			BT_UUID_GATT_TYPE_CHARACTERISTIC,
			BT_ATT_CONST_VARIABLE, 0x05),
	ATT_PERMINSIONS(ATT_PERMISSIONS_WRITE_ONLY),
	ATT_SETCHARACTERISTIC(GATT_CHAR_PROP_WRITE_WO_RESPONSE,
			ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_CONTROL_POINT_VALUE,
			BT_UUID_TIME_UPDATE_CONTROL_POINT),

	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_CONTROL_POINT_VALUE,
			BT_UUID_TIME_UPDATE_CONTROL_POINT,
			BT_ATT_FIX_VARIABLE_IN_UPPER_AP, 0x01),
	ATT_PERMINSIONS(ATT_PERMISSIONS_GATT_DEFINED),

	/* Time Update State characteristic */
	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_STATE,
			BT_UUID_GATT_TYPE_CHARACTERISTIC,
			BT_ATT_CONST_VARIABLE, 0x05),
	ATT_PERMINSIONS(ATT_PERMISSIONS_READ_ONLY),
	ATT_SETCHARACTERISTIC(GATT_CHAR_PROP_READ,
			ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_STATE_VALUE,
			BT_UUID_TIME_UPDATE_STATE),

	ATT_HANDLE16(ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_STATE_VALUE,
			BT_UUID_TIME_UPDATE_STATE,
			BT_ATT_FIX_VARIABLE_IN_UPPER_AP, 0x01),
	ATT_PERMINSIONS(ATT_PERMISSIONS_GATT_DEFINED),
};

U8 TimeAttDB_AddRecord(void) {
	BtStatus status;

	status = ATTDB_AddRecord(attCurrTimeRecord, sizeof(attCurrTimeRecord));
	ATTDB_AddRecordCB(ATT_HANDLE_CHARACTERISTIC_CT_TIME_VALUE, time_att_db_cttime_callback);
	ATTDB_AddRecordCB(ATT_HANDLE_CLIENT_CHARACTERISTIC_CONFIG_CT_TIME_VALUE, time_att_db_cttime_config_callback);
	ATTDB_AddRecordCB(ATT_HANDLE_CHARACTERISTIC_LOCAL_TIME_INFO_VALUE, time_att_db_local_time_info_callback);
	ATTDB_AddRecordCB(ATT_HANDLE_CHARACTERISTIC_REF_TIME_INFO_VALUE, time_att_db_ref_time_info_callback);
	ATTDB_AddGroupRecord(ATT_HANDLE_PRIMARY_SERVICE_CURRENT_TIME, 
			ATT_HANDLE_PRIMARY_SERVICE_CURRENT_TIME_END, 
			BT_UUID_GATT_TYPE_PRIMARY_SERVICE);

	status = ATTDB_AddRecord(attNextDstRecord, sizeof(attNextDstRecord));
	ATTDB_AddRecordCB(ATT_HANDLE_CHARACTERISTIC_TIME_WITH_DST_VALUE, time_att_db_time_with_dst_callback);
	ATTDB_AddGroupRecord(ATT_HANDLE_PRIMARY_SERVICE_NEXT_DST_CHANGE, 
			ATT_HANDLE_PRIMARY_SERVICE_NEXT_DST_CHANGE_END, 
			BT_UUID_GATT_TYPE_PRIMARY_SERVICE);

	status = ATTDB_AddRecord(attRefTimeUpdateRecord, sizeof(attRefTimeUpdateRecord));
	ATTDB_AddRecordCB(ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_CONTROL_POINT_VALUE, time_att_db_time_with_dst_callback);
	ATTDB_AddRecordCB(ATT_HANDLE_CHARACTERISTIC_TIME_UPDATE_STATE_VALUE, time_att_db_time_with_dst_callback);
	ATTDB_AddGroupRecord(ATT_HANDLE_PRIMARY_SERVICE_REFERENCE_TIME_UPDATE, 
			ATT_HANDLE_PRIMARY_SERVICE_REFERENCE_TIME_UPDATE_END, 
			BT_UUID_GATT_TYPE_PRIMARY_SERVICE);

	return (U8) status;
}

U8 TimeAttDB_RemoveRecord(void) {
	ATTDB_RemoveRecord(ATT_HANDLE_PRIMARY_SERVICE_CURRENT_TIME,
			ATT_HANDLE_PRIMARY_SERVICE_REFERENCE_TIME_UPDATE_END);

	ATTDB_RemoveGroupRecord(ATT_HANDLE_PRIMARY_SERVICE_CURRENT_TIME, 
			ATT_HANDLE_PRIMARY_SERVICE_CURRENT_TIME_END);
	ATTDB_RemoveGroupRecord(ATT_HANDLE_PRIMARY_SERVICE_NEXT_DST_CHANGE, 
			ATT_HANDLE_PRIMARY_SERVICE_NEXT_DST_CHANGE_END);
	ATTDB_RemoveGroupRecord(ATT_HANDLE_PRIMARY_SERVICE_REFERENCE_TIME_UPDATE, 
			ATT_HANDLE_PRIMARY_SERVICE_REFERENCE_TIME_UPDATE_END);

	return (U8) BT_STATUS_SUCCESS;
}
#endif
