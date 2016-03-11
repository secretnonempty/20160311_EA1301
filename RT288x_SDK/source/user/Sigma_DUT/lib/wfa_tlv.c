 
/****************************************************************************
 *  (c) Copyright 2007 Wi-Fi Alliance.  All Rights Reserved
 *
 *
 *  LICENSE
 *
 *  License is granted only to Wi-Fi Alliance members and designated
 *  contractors ($B!H(BAuthorized Licensees$B!I(B)..AN  Authorized Licensees are granted
 *  the non-exclusive, worldwide, limited right to use, copy, import, export
 *  and distribute this software:
 *  (i) solely for noncommercial applications and solely for testing Wi-Fi
 *  equipment; and
 *  (ii) solely for the purpose of embedding the software into Authorized
 *  Licensee$B!G(Bs proprietary equipment and software products for distribution to
 *  its customers under a license with at least the same restrictions as
 *  contained in this License, including, without limitation, the disclaimer of
 *  warranty and limitation of liability, below..AN  The distribution rights
 *  granted in clause
 *  (ii), above, include distribution to third party companies who will
 *  redistribute the Authorized Licensee$B!G(Bs product to their customers with or
 *  without such third party$B!G(Bs private label. Other than expressly granted
 *  herein, this License is not transferable or sublicensable, and it does not
 *  extend to and may not be used with non-Wi-Fi applications..AN  Wi-Fi Alliance
 *  reserves all rights not expressly granted herein..AN 
 *.AN 
 *  Except as specifically set forth above, commercial derivative works of
 *  this software or applications that use the Wi-Fi scripts generated by this
 *  software are NOT AUTHORIZED without specific prior written permission from
 *  Wi-Fi Alliance.
 *.AN 
 *  Non-Commercial derivative works of this software for internal use are
 *  authorized and are limited by the same restrictions; provided, however,
 *  that the Authorized Licensee shall provide Wi-Fi Alliance with a copy of
 *  such derivative works under a perpetual, payment-free license to use,
 *  modify, and distribute such derivative works for purposes of testing Wi-Fi
 *  equipment.
 *.AN 
 *  Neither the name of the author nor "Wi-Fi Alliance" may be used to endorse
 *  or promote products that are derived from or that use this software without
 *  specific prior written permission from Wi-Fi Alliance.
 *
 *  THIS SOFTWARE IS PROVIDED BY WI-FI ALLIANCE "AS IS" AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 *  OF MERCHANTABILITY, NON-INFRINGEMENT AND FITNESS FOR A.AN PARTICULAR PURPOSE,
 *  ARE DISCLAIMED. IN NO EVENT SHALL WI-FI ALLIANCE BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, THE COST OF PROCUREMENT OF SUBSTITUTE
 *  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE) ARISING IN ANY WAY OUT OF
 *  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ******************************************************************************
 */

/*
 * file: wfa_tlv.c
 * The file contains all TLV process functions, including Encode, Decode, etc
 * TLV stands for Tag, Length, Value.
 *
 *   Revision History:
 *      2006/03/10 -- initially created by qhu
 *      2006/06/01 -- BETA release by qhu
 *      2006/06/13 -- 00.02 release by qhu
 *      2006/06/30 -- 00.10 Release by qhu
 *      2006/07/10 -- 01.00 Release by qhu
 *      2006/09/01 -- 01.05 Release by qhu
 *      2007/02/15  -- WMM Extension Beta released by qhu, mkaroshi
 *      2007/03/30 -- 01.40 WPA2 and Official WMM Beta Release by qhu
 *      2007/04/20 -- 02.00 WPA2 and Official WMM Release by qhu
 *      2007/08/15 --  02.10 WMM-Power Save release by qhu
 *      2007/10/10 --  02.20 Voice SOHO beta -- qhu
 *      2007/11/07 -- 02.30 Voice HSO -- qhu
 *          -- make sure the the data len must be less than buffer size, 
 *             a potential bug reported by rmaeder and ydror
 *
 */
#include "wfa_portall.h"
#include "wfa_stdincs.h"
#include "wfa_main.h"
#include "wfa_debug.h"
#include "wfa_types.h"
#include "wfa_tlv.h"

extern unsigned short wfa_defined_debug;

/*
 * wfaEncodeTLV(): Encoding a packet to TLV format 
 * input: the_tag - packet type
 *        the_len - the value length
 *        the_value - the value buffer
 *
 * output: tlv_data - encoded TLV packet buffer. Caller must allocate the buffer
 */
BOOL wfaEncodeTLV(WORD the_tag, WORD the_len, BYTE *the_value, BYTE *tlv_data)
{
   void *data = tlv_data;

   ((wfaTLV *)data)->tag = the_tag;
   ((wfaTLV *)data)->len = the_len;
   if(the_value != NULL && the_len != 0)
      wMEMCPY((data+4), (BYTE *)the_value, the_len);

   return WFA_SUCCESS;
}

/*
 * wfaDecodeTLV(); Decoding a TLV format into actually values
 * input:  tlv_data - the TLV format packet buffer
 *         tlv_len  - the total length of the TLV
 * output: ptag - the TLV type
 *         pval_len - the value length
 *         pvalue - value buffer, caller must allocate the buffer
 */

BOOL wfaDecodeTLV(BYTE *tlv_data, int tlv_len, WORD *ptag, int *pval_len, BYTE *pvalue)
{ 
   wfaTLV *data = (wfaTLV *)tlv_data;
 
   if(pvalue == NULL)
   {
       DPRINT_ERR(WFA_ERR, "Parm buf invalid\n");
       return WFA_FAILURE;
   }
   *ptag = data->tag; 
   *pval_len = data->len;

   if(tlv_len < *pval_len)
       return WFA_FAILURE;

   if(*pval_len != 0 && *pval_len < MAX_PARMS_BUFF)
   {
      wMEMCPY(pvalue, tlv_data+4, *pval_len);
   }

   return WFA_SUCCESS;
}

/*
 * wfaGetTLVTag(): the individual function to retrieve a TLV type.
 * input: tlv_data - TLV buffer
 * return: the TLV type.
 */

WORD wfaGetTLVTag(BYTE *tlv_data)
{
   wfaTLV *ptlv = (wfaTLV *)tlv_data;

   if(ptlv != NULL)
      return ptlv->tag;
   
   return WFA_SUCCESS;
}

/*
 * wfaSetTLVTag(): the individual function to set TLV type.
 * input: new_tag - the new TLV type.
 * Output: tlv_data - a TLV buffer, caller must allocate this buffer.
 */

BOOL wfaSetTLVTag(WORD new_tag, BYTE *tlv_data)
{
   wfaTLV *ptlv = (wfaTLV *)tlv_data;

   if(tlv_data == NULL)
      return WFA_FAILURE;

   ptlv->tag = new_tag;

   return WFA_SUCCESS;
}

/*
 * wfaGetTLVLen(): retrieve a TLV value length
 * input: tlv_data - a TLV buffer
 * return: the value length.
 */

WORD wfaGetTLVLen(BYTE *tlv_data)
{
   wfaTLV *ptlv = (wfaTLV *)tlv_data;

   if(tlv_data == NULL)
     return WFA_FAILURE;

   return ptlv->len;
}

/*
 * wfaGetTLVValue(): retrieve a TLV value
 * input: value_len - TLV value length
 *        tlv_data - a TLV data buffer
 * output: pvalue - the value buffer, caller must allocate it.
 */

BOOL wfaGetTLVvalue(int value_len, BYTE *tlv_data, BYTE *pvalue)
{
    if(tlv_data == NULL)
      return WFA_FAILURE;

    wMEMCPY(pvalue, tlv_data+WFA_TLV_HEAD_LEN, value_len);

    return WFA_SUCCESS;
}
