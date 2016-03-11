/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/****************************************************************************
 *
 * File:
 *     $Workfile:a2alloc.h$ for XTNDAccess Blue SDK, Version 2.0
 *     $Revision: #1 $
 *
 * Description: This file contains memory allocation code for the Advanced 
 *     Audio Distribution Profile (A2DP).
 *             
 * Created:     June 8, 2004
 *
 * Copyright 2004 - 2005 Extended Systems, Inc.  ALL RIGHTS RESERVED.
 *
 * Unpublished Confidential Information of Extended Systems, Inc.  
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any means, 
 * or stored in a database or retrieval system, without prior written 
 * permission of Extended Systems, Inc.
 * 
 * Use of this work is governed by a license granted by Extended Systems, Inc. 
 * This work contains confidential and proprietary information of Extended 
 * Systems, Inc. which is protected by copyright, trade secret, trademark and 
 * other intellectual property rights.
 *
 ****************************************************************************/

#ifndef __A2ALLOC_H_
#define __A2ALLOC_H_

#include "a2dp.h"

/* The BtA2dpContext structure contains the global context of the A2DP SDK. */
typedef struct _BtA2dpContext {

    /* Device Pool */
    ListEntry           freeDeviceList;
    ListEntry           inuseDeviceList;
    U8                  devRefCount;
    A2dpDevice          device[NUM_BT_DEVICES];
    A2dpDevice         *currentDevice;
    AvdtpConfigRequest  currentCfgReq;

    /* Stream Registration state */
    U8                  srcRefCount;
    U8                  snkRefCount;
    ListEntry           streamList;

    /* Pool of StreamInfo structures used during stream discovery */
    A2dpStreamInfo      streamInfos[A2DP_MAX_STREAMINFOS];
    ListEntry           freeStreamInfoList;

#if A2DP_SOURCE == XA_ENABLED
    /* A2DP Source SDP Variables */
    SdpRecord           a2dpSrcSdpRecord;

#endif

#if A2DP_SINK == XA_ENABLED
    /* A2DP Sink SDP Variables */
    SdpRecord           a2dpSnkSdpRecord;

#endif

} BtA2dpContext;

#if XA_CONTEXT_PTR == XA_ENABLED
extern BtA2dpContext *a2dpContext;
#define A2DP(s) (a2dpContext->s)
#else /* XA_CONTEXT_PTR == XA_ENABLED */
extern BtA2dpContext a2dpContext;
#define A2DP(s) (a2dpContext.s)
#endif /* XA_CONTEXT_PTR */

/* Function prototypes */
BOOL A2dpAlloc(void);

#endif /* __A2ALLOC_H_ */


