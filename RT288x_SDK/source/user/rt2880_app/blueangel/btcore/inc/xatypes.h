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

#ifndef __XATYPES_H
#define __XATYPES_H
/***************************************************************************
 *
 * File:
 *     $Workfile:xatypes.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     This file contains declarations for iAnywhere (formerly iAnywhere)
 *     protocol stacks.
 *
 * Created:
 *     November 19, 1996
 *
 * Copyright 1999-2005 Extended Systems, Inc.
 * Portions copyright 2005 iAnywhere Solutions, Inc.
 * All rights reserved. All unpublished rights reserved.
 *
 * Unpublished Confidential Information of iAnywhere Solutions, Inc.  
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any 
 * means, or stored in a database or retrieval system, without prior written 
 * permission of iAnywhere Solutions, Inc.
 * 
 * Use of this work is governed by a license granted by iAnywhere Solutions, 
 * Inc.  This work contains confidential and proprietary information of 
 * iAnywhere Solutions, Inc. which is protected by copyright, trade secret, 
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
#include "bt_common.h"
#include "config.h"

/****************************************************************************
 *
 * Base definitions used by the stack and framer
 *
 ****************************************************************************/


#ifndef BOOL
#define BOOL unsigned char  /* IGNORESTYLE */
#endif 

#ifndef U32
#define U32 kal_uint32
#endif

#ifndef U16
#define U16 kal_uint16
#endif

#ifndef U8
#define U8 kal_uint8
#endif


#ifndef S32
#define S32 signed int
#endif

#ifndef S16
#define S16 signed short
#endif

#ifndef S8
#define S8 char
#endif




/*
 * Variable sized integers. Used to optimize processor efficiency by
 * using the most efficient data size for counters, arithmatic, etc.
 */
#ifndef I32
#define I32 unsigned long
#endif


#if XA_INTEGER_SIZE == 4
#ifndef I16
#define I16 unsigned long
#endif

#ifndef I8
#define I8 unsigned long
#endif


#elif XA_INTEGER_SIZE == 2

#ifndef I16
#define I16 unsigned short
#endif

#ifndef I8
#define I8 unsigned short
#endif


#elif XA_INTEGER_SIZE == 1
#ifndef I16
#define I16 unsigned short
#endif

#ifndef I8
#define I8 unsigned char
#endif

#else 
#error No XA_INTEGER_SIZE specified!
#endif 

typedef void (*PFV) (void);

/* Boolean Definitions */
#ifndef TRUE
#define TRUE  (1==1)
#endif 

#ifndef FALSE
#define FALSE (0==1)
#endif 


#endif /* __XATYPES_H */ 

