/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.48 $ of : mfd-top.m2c,v $
 *
 * $Id: //WIFI_SOC/MP/SDK_4_3_0_0/RT288x_SDK/source/user/net-snmp-5.5.pre2/agent/mibgroup/ip-mib/ipv6InterfaceTable/ipv6InterfaceTable.h#1 $
 */
#ifndef IPV6INTERFACETABLE_H
#define IPV6INTERFACETABLE_H

#ifdef __cplusplus
extern          "C" {
#endif


/** @addtogroup misc misc: Miscellaneous routines
 *
 * @{
 */
#include <net-snmp/library/asn1.h>
#include <net-snmp/data_access/interface.h>

#include "if-mib/ifTable/ifTable.h"

    /*
     * other required module components 
     */
    /* *INDENT-OFF*  */
config_require(if-mib/ifTable/ifTable)
config_require(ip-mib/ipv6InterfaceTable/ipv6InterfaceTable_interface)
config_require(ip-mib/ipv6InterfaceTable/ipv6InterfaceTable_data_access)
    /* *INDENT-ON*  */

    /*
     * OID, column number and enum definions for ipv6InterfaceTable 
     */
#include "ipv6InterfaceTable_constants.h"

    /*
     *********************************************************************
     * function declarations
     */
    void            init_ipv6InterfaceTable(void);
    void            shutdown_ipv6InterfaceTable(void);

    /*
     *********************************************************************
     * Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipv6InterfaceTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IP-MIB::ipv6InterfaceTable is subid 30 of ip.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.4.30, length: 8
     *
     * we share data structures (data too, in fact) with ifTable
     */
    typedef ifTable_registration ipv6InterfaceTable_registration;
    typedef ifTable_data ipv6InterfaceTable_data;
    typedef ifTable_undo_data ipv6InterfaceTable_undo_data;
    typedef ifTable_mib_index ipv6InterfaceTable_mib_index;
    typedef ifTable_rowreq_ctx ipv6InterfaceTable_rowreq_ctx;

    /*
     * ipv6InterfaceReasmMaxSize(2)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/R/d/h
     */
#define ipv6InterfaceReasmMaxSize ifentry->reasm_max_v6

    /*
     * ipv6InterfaceIdentifier(3)/Ipv6AddressIfIdentifierTC/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/H
     */

#define ipv6InterfaceIdentifier ifentry->v6_if_id
#define ipv6InterfaceIdentifier_len ifentry->v6_if_id_len

    /*
     * ipv6InterfaceEnableStatus(5)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
     */
#define ipv6InterfaceEnableStatus ifentry->admin_status

    /*
     * ipv6InterfaceReachableTime(6)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h
     */
#define ipv6InterfaceReachableTime ifentry->reachable_time

    /*
     * ipv6InterfaceRetransmitTime(7)/UNSIGNED32/ASN_UNSIGNED/u_long(u_long)//l/A/w/e/r/d/h
     */
#define ipv6InterfaceRetransmitTime ifentry->retransmit_v6

    /*
     * ipv6InterfaceForwarding(8)/INTEGER/ASN_INTEGER/long(u_long)//l/A/W/E/r/d/h
     */
#define ipv6InterfaceForwarding ifentry->forwarding_v6


    /*
     *********************************************************************
     * function prototypes
     */
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_pre_request(ipv6InterfaceTable_registration *
                                       user_context);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_post_request(ipv6InterfaceTable_registration *
                                        user_context, int rc);

    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_rowreq_ctx_init(ipv6InterfaceTable_rowreq_ctx *
                                           rowreq_ctx,
                                           void *user_init_ctx);
    void
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_rowreq_ctx_cleanup(ipv6InterfaceTable_rowreq_ctx
                                              * rowreq_ctx);

    int             ipv6InterfaceTable_commit(ipv6InterfaceTable_rowreq_ctx
                                              * rowreq_ctx);

         
         
         
         
         
         
        ipv6InterfaceTable_rowreq_ctx
        * ipv6InterfaceTable_row_find_by_mib_index
        (ipv6InterfaceTable_mib_index * mib_idx);

    extern const oid      ipv6InterfaceTable_oid[];
    extern const int      ipv6InterfaceTable_oid_size;


#include "ipv6InterfaceTable_interface.h"
#include "ipv6InterfaceTable_data_access.h"
    /*
     *********************************************************************
     * GET function declarations
     */

    /*
     *********************************************************************
     * GET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipv6InterfaceTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IP-MIB::ipv6InterfaceTable is subid 30 of ip.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.4.30, length: 8
     */
    /*
     * indexes
     */

    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReasmMaxSize_get(ipv6InterfaceTable_rowreq_ctx *
                                      rowreq_ctx,
                                      u_long *
                                      ipv6InterfaceReasmMaxSize_val_ptr);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceIdentifier_get(ipv6InterfaceTable_rowreq_ctx *
                                    rowreq_ctx, char
                                    **ipv6InterfaceIdentifier_val_ptr_ptr,
                                    size_t
                                    *
                                    ipv6InterfaceIdentifier_val_ptr_len_ptr);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceEnableStatus_get(ipv6InterfaceTable_rowreq_ctx *
                                      rowreq_ctx,
                                      u_long *
                                      ipv6InterfaceEnableStatus_val_ptr);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReachableTime_get(ipv6InterfaceTable_rowreq_ctx *
                                       rowreq_ctx,
                                       u_long *
                                       ipv6InterfaceReachableTime_val_ptr);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceRetransmitTime_get(ipv6InterfaceTable_rowreq_ctx *
                                        rowreq_ctx,
                                        u_long *
                                        ipv6InterfaceRetransmitTime_val_ptr);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceForwarding_get(ipv6InterfaceTable_rowreq_ctx *
                                    rowreq_ctx,
                                    u_long *
                                    ipv6InterfaceForwarding_val_ptr);


    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_indexes_set_tbl_idx(ipv6InterfaceTable_mib_index
                                               * tbl_idx, long
                                               ipv6InterfaceIfIndex_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_indexes_set(ipv6InterfaceTable_rowreq_ctx *
                                       rowreq_ctx,
                                       long ipv6InterfaceIfIndex_val);



    /*
     *********************************************************************
     * SET function declarations
     */

    /*
     *********************************************************************
     * SET Table declarations
     */
/**********************************************************************
 **********************************************************************
 ***
 *** Table ipv6InterfaceTable
 ***
 **********************************************************************
 **********************************************************************/
    /*
     * IP-MIB::ipv6InterfaceTable is subid 30 of ip.
     * Its status is Current.
     * OID: .1.3.6.1.2.1.4.30, length: 8
     */


    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_undo_setup(ipv6InterfaceTable_rowreq_ctx *
                                      rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_undo_cleanup(ipv6InterfaceTable_rowreq_ctx *
                                        rowreq_ctx);
    int             ipv6InterfaceTable_undo(ipv6InterfaceTable_rowreq_ctx *
                                            rowreq_ctx);
    int             ipv6InterfaceTable_commit(ipv6InterfaceTable_rowreq_ctx
                                              * rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_undo_commit(ipv6InterfaceTable_rowreq_ctx *
                                       rowreq_ctx);


    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReasmMaxSize_check_value(ipv6InterfaceTable_rowreq_ctx
                                              * rowreq_ctx,
                                              u_long
                                              ipv6InterfaceReasmMaxSize_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReasmMaxSize_undo_setup(ipv6InterfaceTable_rowreq_ctx
                                             * rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReasmMaxSize_set(ipv6InterfaceTable_rowreq_ctx *
                                      rowreq_ctx,
                                      u_long
                                      ipv6InterfaceReasmMaxSize_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReasmMaxSize_undo(ipv6InterfaceTable_rowreq_ctx *
                                       rowreq_ctx);

    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceIdentifier_check_value(ipv6InterfaceTable_rowreq_ctx *
                                            rowreq_ctx, char
                                            *ipv6InterfaceIdentifier_val_ptr,
                                            size_t
                                            ipv6InterfaceIdentifier_val_ptr_len);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceIdentifier_undo_setup(ipv6InterfaceTable_rowreq_ctx *
                                           rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceIdentifier_set(ipv6InterfaceTable_rowreq_ctx *
                                    rowreq_ctx,
                                    char *ipv6InterfaceIdentifier_val_ptr,
                                    size_t
                                    ipv6InterfaceIdentifier_val_ptr_len);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceIdentifier_undo(ipv6InterfaceTable_rowreq_ctx *
                                     rowreq_ctx);

    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceEnableStatus_check_value(ipv6InterfaceTable_rowreq_ctx
                                              * rowreq_ctx,
                                              u_long
                                              ipv6InterfaceEnableStatus_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceEnableStatus_undo_setup(ipv6InterfaceTable_rowreq_ctx
                                             * rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceEnableStatus_set(ipv6InterfaceTable_rowreq_ctx *
                                      rowreq_ctx,
                                      u_long
                                      ipv6InterfaceEnableStatus_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceEnableStatus_undo(ipv6InterfaceTable_rowreq_ctx *
                                       rowreq_ctx);

    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReachableTime_check_value
        (ipv6InterfaceTable_rowreq_ctx * rowreq_ctx,
         u_long ipv6InterfaceReachableTime_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReachableTime_undo_setup(ipv6InterfaceTable_rowreq_ctx
                                              * rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReachableTime_set(ipv6InterfaceTable_rowreq_ctx *
                                       rowreq_ctx,
                                       u_long
                                       ipv6InterfaceReachableTime_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceReachableTime_undo(ipv6InterfaceTable_rowreq_ctx *
                                        rowreq_ctx);

    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceRetransmitTime_check_value
        (ipv6InterfaceTable_rowreq_ctx * rowreq_ctx,
         u_long ipv6InterfaceRetransmitTime_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceRetransmitTime_undo_setup
        (ipv6InterfaceTable_rowreq_ctx * rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceRetransmitTime_set(ipv6InterfaceTable_rowreq_ctx *
                                        rowreq_ctx,
                                        u_long
                                        ipv6InterfaceRetransmitTime_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceRetransmitTime_undo(ipv6InterfaceTable_rowreq_ctx *
                                         rowreq_ctx);

    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceForwarding_check_value(ipv6InterfaceTable_rowreq_ctx *
                                            rowreq_ctx,
                                            u_long
                                            ipv6InterfaceForwarding_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceForwarding_undo_setup(ipv6InterfaceTable_rowreq_ctx *
                                           rowreq_ctx);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceForwarding_set(ipv6InterfaceTable_rowreq_ctx *
                                    rowreq_ctx,
                                    u_long ipv6InterfaceForwarding_val);
    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceForwarding_undo(ipv6InterfaceTable_rowreq_ctx *
                                     rowreq_ctx);


    int
     
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        ipv6InterfaceTable_check_dependencies(ipv6InterfaceTable_rowreq_ctx
                                              * ctx);


    /*
     * DUMMY markers, ignore
     *
     * TODO:099:x: *************************************************************
     * TODO:199:x: *************************************************************
     * TODO:299:x: *************************************************************
     * TODO:399:x: *************************************************************
     * TODO:499:x: *************************************************************
     */

#ifdef __cplusplus
}
#endif
#endif                          /* IPV6INTERFACETABLE_H */
/** @} */

