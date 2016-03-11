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

#ifndef __OSAPI_H
#define __OSAPI_H

/****************************************************************************
 *
 * File:
 *     $Workfile:osapi.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     Defines the APIs used by the stack to access system services.
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
/*****************************************************************************
* Include
*****************************************************************************/
/* basic system service headers */
#include "bt_common.h"

/*---------------------------------------------------------------------------
 * Operating System API layer
 *
 *     The OS API is a set of functions used by the stack to access
 *     system services. If you are porting to a new operating system,
 *     you must provide the functions described here.
 *
 *     The functions in this API are intended for exclusive use by the
 *     stack. Applications should use the native operating system interface
 *     and avoid making OS_ calls themselves.
 */

/****************************************************************************
 *
 * Types
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * TimeT type
 *
 *     Indicates an amount of time in system ticks or milliseconds. This must
 *     be a 32-bit value because some timeouts may exceed 5 minutes.
 */
typedef U32 TimeT;

/* End of TimeT type */

/* typedef unsigned long DWORD; */


typedef void (*OsTimerNotify) (void);


/****************************************************************************
 *
 * Function Reference
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * OS_Init()
 *
 *     Initializes the stack and operating system layer. This function is
 *     not called by the stack, but must be called by your operating system
 *     or application to set up the stack and its operating system services.
 *
 *     The OS_Init function must perform the following tasks in this order:
 *
 *     1) Seed the random number generator with a random value such as
 *     the current system time.
 *
 *     2) Any other operating-system specific functions, such as timer
 *     initialization or the creation of semaphores.
 *
 *     3) Call EVM_Init to initialize the Event Manager. This also
 *     initializes all stack layers. Note that this function may
 *     return FALSE if stack initialization failed for some reason.
 *
 *     4) Create and start the stack task. This task calls EVM_Process
 *     at least once for every call to OS_NotifyEvm. See OS_NotifyEvm
 *     for more details.
 *
 * Returns:
 *     TRUE - Success.
 *
 *     FALSE - Initialization failed for some reason.
 */
BOOL OS_Init(void);

/*---------------------------------------------------------------------------
 * OS_Deinit()
 *
 *     Deinitializes the stack and operating system layer. This function
 *     is not called by the stack, but may be called by your operating
 *     system or application to shut down the stack and free its resources.
 */
void OS_Deinit(void);

/*---------------------------------------------------------------------------
 * OS_GetSystemTime()
 *
 *     Called by the stack to get the current system time in ticks.
 *
 *     The system time provided by this function can start at any value;
 *     it does not to start at 0. However, the time must "roll over" only
 *     when reaching the maximum value allowed by TimeT. For instance, a
 *     16-bit TimeT must roll over at 0xFFFF. A 32-bit TimeT must roll
 *     over at 0xFFFFFFFF.
 *
 *     System ticks may or may not be equivalent to milliseconds. See the
 *     MS_TO_TICKS macro in config.h (General Configuration Constants)
 *     for more information.
 *
 * Returns:
 *     The current time in ticks.
 */
TimeT OS_GetSystemTime(void);

/*---------------------------------------------------------------------------
 * OS_Rand()
 *
 *     Called by the stack to generate a random number between
 *     0x0000 and 0xFFFF.
 *
 * Returns:
 *     A 16-bit random number.
 */
U16 OS_Rand(void);

/*---------------------------------------------------------------------------
 * OS_Rand32()
 *
 *     Called by the stack to generate a random number between 0x0000 and 0xFFFFFFFF.
 *
 * Returns:
 *     A 32-bit random number.
 */
S32 OS_Rand32(void);

/*---------------------------------------------------------------------------
 * OS_MemCopy()
 *
 *     Called by the stack to copy memory from one buffer to another.
 *
 *     This function's implementation could use the ANSI memcpy function.
 *
 * Parameters:
 *     dest - Destination buffer for data.
 *
 *     source - Source buffer for data. "dest" and "source" must not
 *         overlap.
 *
 *     numBytes - Number of bytes to copy from "source" to "dest".
 */
void OS_MemCopy(U8 *dest, const U8 *source, U32 numBytes);

/*---------------------------------------------------------------------------
 * OS_MemCmp()
 *
 *     Called by the stack to compare the bytes in two different buffers.
 *     If the buffers lengths or contents differ, this function returns FALSE.
 *
 *     This function's implementation could use the ANSI memcmp
 *     routine as shown:
 *
 *     return (len1 != len2) ? FALSE : (0 == memcmp(buffer1, buffer2, len2));
 *
 *
 * Parameters:
 *     buffer1 - First buffer to compare.
 *
 *     len1 - Length of first buffer to compare.
 *
 *     buffer2 - Second buffer to compare.
 *
 *     len2 - Length of second buffer to compare.
 *
 * Returns:
 *     TRUE - The lengths and contents of both buffers match exactly.
 *
 *     FALSE - Either the lengths or the contents of the buffers do not
 *         match.
 */
BOOL OS_MemCmp(const U8 *buffer1, U16 len1, const U8 *buffer2, U16 len2);

/*---------------------------------------------------------------------------
 * OS_MemSet()
 *
 *     Fills the destination buffer with the specified byte.
 *
 *     This function's implementation could use the ANSI memset
 *     function.
 *
 * Parameters:
 *     dest - Buffer to fill.
 *
 *     byte - Byte to fill with.
 *
 *     len - Length of the destination buffer.
 */
void OS_MemSet(U8 *dest, U8 byte, U32 len);

/*---------------------------------------------------------------------------
 * OS_StartTimer()
 *
 *     Called by the stack to start the event timer. When the time
 *     expires, it is the system's responsibility to call the notify
 *     function provided. The notify function may be called in either
 *     interrupt or task modes as required by the operating system.
 *
 *     If the timer is already active, OS_StartTimer automatically
 *     cancels the previous timer as if OS_CancelTimer was called.
 *
 *     In non-multitasking systems (where XA_MULTITASKING is disabled), this
 *     function is not used. EVM_Process will call OS_GetSystemTime
 *     frequently to determine if its internal timers have elapsed.
 *
 * Requires:
 *     XA_MULTITASKING enabled.
 *
 * Parameters:
 *     time - number of ticks until the timer fires
 *
 *     func - The function to call when the timer expires.
 *
 */
void OS_StartTimer(TimeT time, OsTimerNotify func);

/*---------------------------------------------------------------------------
 * OS_CancelTimer()
 *
 *     Called by the stack to stops the event timer. This must prevent
 *     the operating system from calling the timer notification
 *     function provided by OS_StartTimer.
 *
 *     If function is called when the event timer is not running, do
 *     nothing.
 *
 *     In non-multitasking systems (where XA_MULTITASKING is disabled), this
 *     function is not used.
 *
 * Requires:
 *     XA_MULTITASKING enabled.
 */
void OS_CancelTimer(void);
void OS_ResetTimerId(void);
void OS_ResetInd(void);

/*---------------------------------------------------------------------------
 * OS_NotifyEvm()
 *
 *     Called by the stack to indicate that EVM_Process should be called.
 *     Depending on your operating system, this call may be made in
 *     interrupt mode or task mode.
 *
 *     In multitasking systems, the stack task alternately calls EVM_Process
 *     and blocks to save CPU time. The block may be implemented by an
 *     event semaphore or similar object. OS_NotifyEvm should post the
 *     semaphore, or otherwise cause the stack task to unblock and
 *     call EVM_Process.
 *
 *     In non-multitasking systems (where XA_MULTITASKING is disabled),
 *     tasks are usually simulated using a round-robin execution scheme. In
 *     this case, EVM_Process is called continuously, and no task ever
 *     blocks. Therefore, this function is not used.
 *
 *     If OS_NotifyEvm is called during EVM_Process execution,
 *     EVM_Process must be executed again before the stack task blocks.
 *
 * Requires:
 *     XA_MULTITASKING enabled.
 */
void OS_NotifyEvm(void);

#define OS_LockStack()   (void)0
#define OS_UnlockStack() (void)0
#define OS_StopHardware() (void)0
#define OS_ResumeHardware() (void)0



/*---------------------------------------------------------------------------
 * OS_StrCmp()
 *
 *     Compares two strings for equality.
 *
 * Parameters:
 *     Str1 - String to compare.
 *     Str2 - String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
U8 OS_StrCmp(const char *Str1, const char *Str2);

U8 OS_StriCmp(const char *str1, const char *str2);

U8 OS_StrnCmp(const char *Str1, const char *Str2, U32 size);

U8 OS_StrniCmp(const char *str1, const char *str2, U32 size);

/*---------------------------------------------------------------------------
 * OS_StrLen()
 *
 *     Calculate the length of the string.
 *
 * Parameters:
 *     Str - String to count length.
 *
 * Returns:
 *     Returns length of string.
 */
U16 OS_StrLen(const char *Str);

/*---------------------------------------------------------------------------
 * OS_StrCpy()
 *
 *     Copy the string.
 *
 * Parameters:
 *     source - String to copy from
 *     dest - String buffer to copy to
 *
 * Returns:
 *     Returns dest string.
 */
char* OS_StrCpy(char *dest, const char *source);

/*---------------------------------------------------------------------------
 * OS_StrnCpy()
 *
 *     Copy the string with specified size
 *
 * Parameters:
 *     source - String to copy from
 *     dest - String buffer to copy to
 *     numBytes - size to copy to
 *
 * Returns:
 *     Returns dest string.
 */
char *OS_StrnCpy(char *dest, const char *source, U32 numBytes);

/*---------------------------------------------------------------------------
 * OS_StrCat()
 *
 *     Concatenate the string.
 *
 * Parameters:
 *     source - String to copy from
 *     dest - String buffer to copy to
 *
 * Returns:
 *     Returns dest string.
 */
char* OS_StrCat(char *dest, const char *source);

void MTK_BT_Assert(void);

#ifndef __BT_SHRINK_SIZE__



#if defined(DEBUG_KAL)
#define Assert(exp)  (((exp) != 0) ? (void)0 : kal_assert_fail(#exp, __FILE__, __LINE__, KAL_FALSE, 0, 0, 0, NULL))
#elif defined (BTMTK_ON_WIN32) || defined(BTMTK_ON_WISESDK) /*|| defined(BTMTK_ON_LINUX)*/
#define Assert(exp)  (((exp) != 0) ? (void)0 : (void)bt_assert(#exp, __FILE__, __LINE__))
#else
#define Assert(exp)  (((exp) != 0) ? (void)0 : (void)bt_assert_reset(#exp, __FILE__, __LINE__))
#endif
#define AssertEval(exp) Assert(exp)

#else /* __BT_SHRINK_SIZE__ */

#define Assert(exp) (((exp) != 0) ? (void)0 : (void)MTK_BT_Assert())
#define AssertEval(exp) Assert(exp)

#endif /* __BT_SHRINK_SIZE__ */

/*---------------------------------------------------------------------------
 * OS_Report()
 *
 *     Called by the stack to report debugging information.
 *
 * Requires:
 *     XA_DEBUG_PRINT enabled.
 *
 * Parameters:
 *     format - A string containing the failed expression.
 *
 *     ... - printf style arguments.
 */
void OS_Report(const char *format, ...);

#define DebugPrint(s) OS_Report s
#define Report(s) OS_Report s

#define CAM_COLOR_END    "\033[m"
#define CAM_RED          "\033[0;32;31m"
#define CAM_LIGHT_RED    "\033[1;31m" 
#define CAM_GREEN        "\033[0;32;32m"
#define CAM_LIGHT_GREEN  "\033[1;32m"
#define CAM_BLUE         "\033[0;32;34m"
#define CAM_LIGHT_BLUE   "\033[1;34m"
#define CAM_DARY_GRAY    "\033[1;30m"
#define CAM_CYAN         "\033[0;36m"
#define CAM_LIGHT_CYAN   "\033[1;36m"
#define CAM_PURPLE       "\033[0;35m"
#define CAM_LIGHT_PURPLE "\033[1;35m"
#define CAM_BROWN        "\033[0;33m"
#define CAM_YELLOW       "\033[1;33m"
#define CAM_LIGHT_GRAY   "\033[0;37m"
#define CAM_WHITE        "\033[1;37m"

#define CLOGV(fmt, args...)   OS_Report("\n=+=+=3 " CAM_YELLOW fmt CAM_COLOR_END, ##args)        // verbose log
#define CLOGI(fmt, args...)   OS_Report("\n=+=+=2 " CAM_LIGHT_GREEN fmt CAM_COLOR_END, ##args)   // information log
#define CLOGD(fmt, args...)   OS_Report("\n=+=+=1 " CAM_LIGHT_CYAN fmt CAM_COLOR_END, ##args)    // debug log
#define CLOGE(fmt, args...)   OS_Report("\n=+=+=0 " CAM_LIGHT_RED fmt CAM_COLOR_END, ##args)     // error log


#endif /* __OSAPI_H */

