/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 1.17 $ of : mfd-data-access.m2c,v $ 
 *
 * $Id: //WIFI_SOC/MP/SDK_4_3_0_0/RT288x_SDK/source/user/net-snmp-5.5.pre2/agent/mibgroup/udp-mib/udpEndpointTable/udpEndpointTable_data_access.c#1 $
 */
/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include <net-snmp/data_access/ipaddress.h>
#include <net-snmp/data_access/udp_endpoint.h>

/*
 * include our parent header 
 */
#include "udpEndpointTable.h"


#include "udpEndpointTable_data_access.h"

/** @ingroup interface 
 * @addtogroup data_access data_access: Routines to access data
 *
 * These routines are used to locate the data used to satisfy
 * requests.
 * 
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table udpEndpointTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * UDP-MIB::udpEndpointTable is subid 7 of udp.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.7.7, length: 8
 */

/**
 * initialization for udpEndpointTable data access
 *
 * This function is called during startup to allow you to
 * allocate any resources you need for the data table.
 *
 * @param udpEndpointTable_reg
 *        Pointer to udpEndpointTable_registration
 *
 * @retval MFD_SUCCESS : success.
 * @retval MFD_ERROR   : unrecoverable error.
 */
int
udpEndpointTable_init_data(udpEndpointTable_registration *
                           udpEndpointTable_reg)
{
    DEBUGMSGTL(("verbose:udpEndpointTable:udpEndpointTable_init_data",
                "called\n"));

    /*
     * TODO:303:o: Initialize udpEndpointTable data.
     */

    return MFD_SUCCESS;
}                               /* udpEndpointTable_init_data */

/**
 * container overview
 *
 */

/**
 * container initialization
 *
 * @param container_ptr_ptr A pointer to a container pointer. If you
 *        create a custom container, use this parameter to return it
 *        to the MFD helper. If set to NULL, the MFD helper will
 *        allocate a container for you.
 * @param  cache A pointer to a cache structure. You can set the timeout
 *         and other cache flags using this pointer.
 *
 *  This function is called at startup to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases. If no custom
 *  container is allocated, the MFD code will create one for your.
 *
 *  This is also the place to set up cache behavior. The default, to
 *  simply set the cache timeout, will work well with the default
 *  container. If you are using a custom container, you may want to
 *  look at the cache helper documentation to see if there are any
 *  flags you want to set.
 *
 * @remark
 *  This would also be a good place to do any initialization needed
 *  for you data source. For example, opening a connection to another
 *  process that will supply the data, opening a database, etc.
 */
void
udpEndpointTable_container_init(netsnmp_container **container_ptr_ptr,
                                netsnmp_cache * cache)
{
    DEBUGMSGTL(("verbose:udpEndpointTable:udpEndpointTable_container_init",
                "called\n"));

    if (NULL == container_ptr_ptr) {
        snmp_log(LOG_ERR,
                 "bad container param to udpEndpointTable_container_init\n");
        return;
    }

    /*
     * For advanced users, you can use a custom container. If you
     * do not create one, one will be created for you.
     */
    *container_ptr_ptr = NULL;

    if (NULL == cache) {
        snmp_log(LOG_ERR,
                 "bad cache param to udpEndpointTable_container_init\n");
        return;
    }

    /*
     * TODO:345:A: Set up udpEndpointTable cache properties.
     *
     * Also for advanced users, you can set parameters for the
     * cache. Do not change the magic pointer, as it is used
     * by the MFD helper. To completely disable caching, set
     * cache->enabled to 0.
     */
    cache->timeout = UDPENDPOINTTABLE_CACHE_TIMEOUT;    /* seconds */
}                               /* udpEndpointTable_container_init */

/**
 * container shutdown
 *
 * @param container_ptr A pointer to the container.
 *
 *  This function is called at shutdown to allow you to customize certain
 *  aspects of the access method. For the most part, it is for advanced
 *  users. The default code should suffice for most cases.
 *
 *  This function is called before udpEndpointTable_container_free().
 *
 * @remark
 *  This would also be a good place to do any cleanup needed
 *  for you data source. For example, closing a connection to another
 *  process that supplied the data, closing a database, etc.
 */
void
udpEndpointTable_container_shutdown(netsnmp_container *container_ptr)
{
    DEBUGMSGTL(("verbose:udpEndpointTable:udpEndpointTable_container_shutdown", "called\n"));

    if (NULL == container_ptr) {
        snmp_log(LOG_ERR,
                 "bad params to udpEndpointTable_container_shutdown\n");
        return;
    }

}                               /* udpEndpointTable_container_shutdown */

/**
 * load initial data
 *
 * TODO:350:M: Implement udpEndpointTable data load
 * This function will also be called by the cache helper to load
 * the container again (after the container free function has been
 * called to free the previous contents).
 *
 * @param container container to which items should be inserted
 *
 * @retval MFD_SUCCESS              : success.
 * @retval MFD_RESOURCE_UNAVAILABLE : Can't access data source
 * @retval MFD_ERROR                : other error.
 *
 *  This function is called to load the index(es) (and data, optionally)
 *  for the every row in the data set.
 *
 * @remark
 *  While loading the data, the only important thing is the indexes.
 *  If access to your data is cheap/fast (e.g. you have a pointer to a
 *  structure in memory), it would make sense to update the data here.
 *  If, however, the accessing the data invovles more work (e.g. parsing
 *  some other existing data, or peforming calculations to derive the data),
 *  then you can limit yourself to setting the indexes and saving any
 *  information you will need later. Then use the saved information in
 *  udpEndpointTable_row_prep() for populating data.
 *
 * @note
 *  If you need consistency between rows (like you want statistics
 *  for each row to be from the same time frame), you should set all
 *  data here.
 *
 */
static u_long
_address_type_from_len(int addrlen) {
	switch (addrlen) {
	case 4: 
		return INETADDRESSTYPE_IPV4;
	case 16: 
		return INETADDRESSTYPE_IPV6;
	case 0: 
		return INETADDRESSTYPE_UNKNOWN;
	default:
		/* To get same behavior as before */
		return INETADDRESSTYPE_IPV4;
	}
}

int
udpEndpointTable_container_load(netsnmp_container *container)
{
    udpEndpointTable_rowreq_ctx *rowreq_ctx;
    netsnmp_container *ep_c;
    netsnmp_iterator *ep_it;
    netsnmp_udp_endpoint_entry *ep;

    /*
     * temporary storage for index values
     */
    u_long	udpEndpointLocalAddressType;
    u_long	udpEndpointRemoteAddressType;

    DEBUGMSGTL(("verbose:udpEndpointTable:udpEndpointTable_container_load",
                "called\n"));

    /*
     * TODO:351:M: |-> Load/update data in the udpEndpointTable container.
     * loop over your udpEndpointTable data, allocate a rowreq context,
     * set the index(es) [and data, optionally] and insert into
     * the container.
     */
    ep_c = netsnmp_access_udp_endpoint_container_load(NULL, 0);
    if (NULL == ep_c)
        return MFD_RESOURCE_UNAVAILABLE;
    ep_it = CONTAINER_ITERATOR(ep_c);
    if (NULL == ep_c) {
        netsnmp_access_udp_endpoint_container_free(ep_c, 0);
        return MFD_RESOURCE_UNAVAILABLE;
    }
    for (ep = ITERATOR_FIRST(ep_it); ep; ep = ITERATOR_NEXT(ep_it)) {

        /*
         * TODO:352:M: |   |-> set indexes in new udpEndpointTable rowreq context.
         */
        rowreq_ctx = udpEndpointTable_allocate_rowreq_ctx();
        if (NULL == rowreq_ctx) {
            snmp_log(LOG_ERR, "memory allocation failed\n");
            return MFD_RESOURCE_UNAVAILABLE;
        }
        udpEndpointLocalAddressType = _address_type_from_len(ep->loc_addr_len);
	udpEndpointRemoteAddressType = _address_type_from_len(ep->rmt_addr_len);
        if (MFD_SUCCESS !=
            udpEndpointTable_indexes_set(rowreq_ctx,
                                         udpEndpointLocalAddressType,
                                         ep->loc_addr,
                                         ep->loc_addr_len,
                                         ep->loc_port,
                                         udpEndpointRemoteAddressType,
                                         ep->rmt_addr,
                                         ep->rmt_addr_len,
                                         ep->rmt_port,
                                         ep->instance,
                                         ep->pid)) {
            snmp_log(LOG_ERR,
                     "error setting index while loading "
                     "udpEndpointTable data.\n");
            udpEndpointTable_release_rowreq_ctx(rowreq_ctx);
            continue;
        }

        /*
         * TODO:352:r: |   |-> populate udpEndpointTable data context.
         * Populate data context here. (optionally, delay until row prep)
         */
        /*
         * non-TRANSIENT data: no need to copy. set pointer to data 
         */

        /*
         * insert into table container
         */
        CONTAINER_INSERT(container, rowreq_ctx);
    }

    ITERATOR_RELEASE(ep_it);

    netsnmp_access_udp_endpoint_container_free(ep_c,
                                               NETSNMP_ACCESS_UDP_ENDPOINT_FREE_DONT_CLEAR);


    DEBUGMSGT(("verbose:udpEndpointTable:udpEndpointTable_container_load",
               "inserted %d records\n", CONTAINER_SIZE(container)));

    return MFD_SUCCESS;
}                               /* udpEndpointTable_container_load */

/**
 * container clean up
 *
 * @param container container with all current items
 *
 *  This optional callback is called prior to all
 *  item's being removed from the container. If you
 *  need to do any processing before that, do it here.
 *
 * @note
 *  The MFD helper will take care of releasing all the row contexts.
 *
 */
void
udpEndpointTable_container_free(netsnmp_container *container)
{
    DEBUGMSGTL(("verbose:udpEndpointTable:udpEndpointTable_container_free",
                "called\n"));

    /*
     * TODO:380:M: Free udpEndpointTable container data.
     */
}                               /* udpEndpointTable_container_free */

/**
 * prepare row for processing.
 *
 *  When the agent has located the row for a request, this function is
 *  called to prepare the row for processing. If you fully populated
 *  the data context during the index setup phase, you may not need to
 *  do anything.
 *
 * @param rowreq_ctx pointer to a context.
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 */
int
udpEndpointTable_row_prep(udpEndpointTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("verbose:udpEndpointTable:udpEndpointTable_row_prep",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    /*
     * TODO:390:o: Prepare row for request.
     * If populating row data was delayed, this is the place to
     * fill in the row for this request.
     */

    return MFD_SUCCESS;
}                               /* udpEndpointTable_row_prep */

/** @} */
