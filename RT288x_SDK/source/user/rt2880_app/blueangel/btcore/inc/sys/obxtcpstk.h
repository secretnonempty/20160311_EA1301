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

#ifndef __OBXTCPSTK_H
#define __OBXTCPSTK_H
/****************************************************************************
 *
 * File:          obxtcpstk.h
 *
 * Description:   This file contains the definitions and typedefs used
 *                by the OBEX TCP transport module. It is not
 *                used by any other component of the OBEX protocol.
 * 
 * Created:       February 20, 2000
 *
 * Version:       MTObex 3.4
 *
 * Copyright 2000-2005 Extended Systems, Inc.  ALL RIGHTS RESERVED.
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

#include <sys/obstkif.h>
#include <sys/obprotif.h>

#if TCP_STACK == XA_ENABLED
#ifndef _WINSOCKAPI_
/*
 * This is done so that we can build OBEX without including any windows
 * header files. This is a necessary step because it allows us to test ANSI-C
 * compliance of the base OBEX code. Winsock.h violates ANSI-C rules. In
 * obxtcpstk.c winsock.h is included to pull in the remainder of the WinSock
 * API definitions.
 */
typedef unsigned int SOCKET;
#endif

/* Forward type declarations  */
typedef struct _ObTcpClientTransport ObTcpClientTransport;
typedef struct _ObTcpServerTransport ObTcpServerTransport;

/*---------------------------------------------------------------------------
 *
 * Functions exported for the Application to manage the client connection.
 */
ObStatus TCPSTACK_ClientConnect( ObexTcpTarget *Target, ObTcpClientTransport *txp,
                                 ObexTransport **Trans);
ObStatus TCPSTACK_ClientDisconnect(ObTcpClientTransport *txp);

/****************************************************************************
 *
 * Defines used internally by the OBEX TCP Transport
 *
 ****************************************************************************/
#define OBEX_TCP_PORT   650         /* Assigned by IANA */
#define TCP_MAX_TPDU    1450

/* ---------------------------------------------------------------------------
 * TCP Events generated by the AsyncEventHandler to the individual Client
 * and Server event handlers.
 */
#define TCP_EVENT_CONNECT_IND    0
#define TCP_EVENT_CONNECTED      1
#define TCP_EVENT_DATA_IND       2
#define TCP_EVENT_DISCON         3

/* ---------------------------------------------------------------------------
 * Window events handled by Callback Wnd.
 */
#define WM_SELECT       WM_USER+101

/****************************************************************************
 *
 * Prototypes for Required Transport Functions (called from obstack.c)
 *
 ****************************************************************************/

#if (OBEX_ROLE_CLIENT == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
/*
 * These functions are used by the 'obstack.c' Init and Deinit functions.
 * Note that when this stack layer is disabled, macros are defined to 
 * replace these functions. See the end of this file for the macros.
 */

/*---------------------------------------------------------------------------
 * TCPSTACK_ClientInit() type
 *
 *     Initializes an instance of the OBEX TCP client stack transport
 *     driver.  This function will be called directly by OBSTACK_ClientInit().
 *     Initialization may include opening endpoints and registering services. 
 *     If successful, the new stack transport instance will be "reserved" for 
 *     the specified application.
 *     
 * Parameters:
 *     trans - TCP client transport structure.
 *
 * Returns:
 *     OB_STATUS_SUCCESS - The specified instance was initialized.
 *
 *     OB_STATUS_xxxxxxx - The instance could not be initialized. Do
 *                          not return OB_STATUS_PENDING.
 */
ObStatus (TCPSTACK_ClientInit)(ObTcpClientTransport *txp);
/* End of TCPSTACK_ClientInit */

#if OBEX_DEINIT_FUNCS == XA_ENABLED
/*---------------------------------------------------------------------------
 * TCPSTACK_ClientDeinit() type
 *
 *     Shuts down an instance of the OBEX TCP client stack transport 
 *     driver.  This function will be called directly by 
 *     OBSTACK_ClientDeinit().
 *
 * Requires:
 *     OBEX_DEINIT_FUNCS == XA_ENABLED.
 *
 * Parameters:
 *     trans - TCP client transport structure.
 *
 * Returns:
 *     TRUE - If the specified instance was deinitialized.
 *
 *     FALSE - If the instance cannot be deinitialized at this time.
 */
BOOL (TCPSTACK_ClientDeinit)(ObTcpClientTransport *txp);
#endif /* OBEX_DEINIT_FUNCS == XA_ENABLED */
/* End of TCPSTACK_ClientDeinit */
#endif /* (OBEX_ROLE_CLIENT == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

#if (OBEX_ROLE_SERVER == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
/*---------------------------------------------------------------------------
 * TCPSTACK_ServerInit() type
 *
 *     Initializes an instance of the OBEX TCP server stack transport
 *     driver.  This function will be called directly by OBSTACK_ServerInit().
 *     Initialization may include opening endpoints and registering services. 
 *     If successful, the new stack transport instance will be "reserved" for 
 *     the specified application.
 *     
 * Parameters:
 *     trans - TCP server transport structure.
 *
 * Returns:
 *     OB_STATUS_SUCCESS - The specified instance was initialized.
 *
 *     OB_STATUS_xxxxxxx - The instance could not be initialized. Do
 *                          not return OB_STATUS_PENDING.
 */
ObStatus (TCPSTACK_ServerInit)(ObTcpServerTransport *txp);
/* End of TCPSTACK_ServerInit */

#if OBEX_DEINIT_FUNCS == XA_ENABLED
/*---------------------------------------------------------------------------
 * TCPSTACK_ServerDeinit() type
 *
 *     Shuts down an instance of the OBEX TCP server stack transport 
 *     driver.  This function will be called directly by 
 *     OBSTACK_ServerDeinit().
 *
 * Requires:
 *     OBEX_DEINIT_FUNCS == XA_ENABLED
 *
 * Parameters:
 *     trans - TCP server transport structure.
 *
 * Returns:
 *     TRUE - If the specified instance was deinitialized.
 *
 *     FALSE - If the instance cannot be deinitialized at this time.
 */
BOOL (TCPSTACK_ServerDeinit)(ObTcpServerTransport *txp);
#endif /* OBEX_DEINIT_FUNCS == XA_ENABLED */
/* End of TCPSTACK_ServerDeinit */
#endif /* (OBEX_ROLE_SERVER == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

/****************************************************************************
 *
 * OBEX Transport macros
 *
 ****************************************************************************/

#if (OBEX_ROLE_CLIENT == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
/*---------------------------------------------------------------------------
 * InitTcpClientTransport()
 *
 *     Initializes an ObTcpClientTransport structure prior to registration.
 *
 * Parameters:
 *     txp - The structure to initialize.
 *
 */
void InitTcpClientTransport(ObTcpClientTransport *txp);

#define InitTcpClientTransport(_TXP)    do {      \
            OS_MemSet((U8 *)(_TXP), 0, sizeof(ObTcpClientTransport)); \
            } while (0)
#endif /* (OBEX_ROLE_CLIENT == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

#if (OBEX_ROLE_SERVER == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
/*---------------------------------------------------------------------------
 * InitTcpServerTransport()
 *
 *     Initializes an ObTcpServerTransport structure prior to registration.
 *
 * Parameters:
 *     txp - The structure to initialize.
 *
 */
void InitTcpServerTransport(ObTcpServerTransport *txp);

#define InitTcpServerTransport(_TXP)    do {      \
            OS_MemSet((U8 *)(_TXP), 0, sizeof(ObTcpServerTransport)); \
            } while (0)
#endif /* (OBEX_ROLE_SERVER == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

 /****************************************************************************
 *
 * Structures used internally by the OBEX TCP Transport
 *
 ****************************************************************************/

/*--------------------------------------------------------------------------
 *
 * OBEX Transport - This Structure manages the common TCP transport 
 * components for the OBEX client/server roles.
 */
typedef struct _ObTcpCommonTransport {
    /* Must be the first field */
    ListEntry       node;

    /* Token passed to parser to identify transport */
    ObexTransport   transport;

    ObexConnState   state;

    /* Application context handles */
    ObexAppHandle   *app;

    /* Group: Connection endpoints */
    SOCKET          conn;

    /* Local TCP device address */
    U8              devAddr[4];
} ObTcpCommonTransport;

#if (OBEX_ROLE_CLIENT == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
/*--------------------------------------------------------------------------
 *
 * OBEX Transport - This Structure manages the TCP Stack Layer of the OBEX
 * transport component. It encapsulates all of the TCP layer information.
 */
struct _ObTcpClientTransport {

    ObTcpCommonTransport    client;
};
#endif /* (OBEX_ROLE_CLIENT == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

#if (OBEX_ROLE_SERVER == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED)
/*--------------------------------------------------------------------------
 *
 * OBEX Transport - This Structure manages the TCP Stack Layer of the OBEX
 * transport component. It encapsulates all of the TCP layer information.
 */
struct _ObTcpServerTransport {
    
    ObTcpCommonTransport    server;

    /* Connection endpoints */
    SOCKET          serverReg;
    
    /* TCP port server is listening on */
    U16             serverPort;
};
#endif /* (OBEX_ROLE_SERVER == XA_ENABLED) || (OBEX_ALLOW_SERVER_TP_CONNECT == XA_ENABLED) */

#else /* TCP_STACK == XA_ENABLED */

/*
 * Simplify Multi-Transport Init & Deinit code by providing resolution of
 * the Init & Deinit functions even when the transport is not present. In
 * debug builds, calling a missing transport's Init or Deinit function will
 * generate an assertion. In non-debug the call will return failure.
 */
#define TCPSTACK_ClientInit(_APP)      (Assert(0), OB_STATUS_FAILED)
#define TCPSTACK_ServerInit(_APP)      (Assert(0), OB_STATUS_FAILED)
#define TCPSTACK_ClientDeinit(_APP)    (TRUE)
#define TCPSTACK_ServerDeinit(_APP)    (TRUE)

#endif /* TCP_STACK == XA_ENABLED */
#endif /* __OBXTCPSTK_H */

