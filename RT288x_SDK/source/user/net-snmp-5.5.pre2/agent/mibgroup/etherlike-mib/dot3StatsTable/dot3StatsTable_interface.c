/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 15899 $ of $ 
 *
 * $Id: //WIFI_SOC/MP/SDK_4_3_0_0/RT288x_SDK/source/user/net-snmp-5.5.pre2/agent/mibgroup/etherlike-mib/dot3StatsTable/dot3StatsTable_interface.c#1 $
 */
/*
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 * ***                                                               ***
 * ***  NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE NOTE  ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THIS FILE DOES NOT CONTAIN ANY USER EDITABLE CODE.      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***       THE GENERATED CODE IS INTERNAL IMPLEMENTATION, AND      ***
 * ***                                                               ***
 * ***                                                               ***
 * ***    IS SUBJECT TO CHANGE WITHOUT WARNING IN FUTURE RELEASES.   ***
 * ***                                                               ***
 * ***                                                               ***
 * *********************************************************************
 * *********************************************************************
 * *********************************************************************
 */

/*
 * standard Net-SNMP includes 
 */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/*
 * include our parent header 
 */
#include "dot3StatsTable.h"


#include <net-snmp/agent/table_container.h>
#include <net-snmp/library/container.h>

#include "dot3StatsTable_interface.h"

#include <ctype.h>

/**********************************************************************
 **********************************************************************
 ***
 *** Table dot3StatsTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * EtherLike-MIB::dot3StatsTable is subid 2 of dot3.
 * Its status is Current.
 * OID: .1.3.6.1.2.1.10.7.2, length: 9
 */
typedef struct dot3StatsTable_interface_ctx_s {

    netsnmp_container *container;
    netsnmp_cache  *cache;

    dot3StatsTable_registration *user_ctx;

    netsnmp_table_registration_info tbl_info;

    netsnmp_baby_steps_access_methods access_multiplexer;

} dot3StatsTable_interface_ctx;

static dot3StatsTable_interface_ctx dot3StatsTable_if_ctx;

static void     _dot3StatsTable_container_init(dot3StatsTable_interface_ctx
                                               * if_ctx);
static void    
_dot3StatsTable_container_shutdown(dot3StatsTable_interface_ctx * if_ctx);


netsnmp_container *
dot3StatsTable_container_get(void)
{
    return dot3StatsTable_if_ctx.container;
}

dot3StatsTable_registration *
dot3StatsTable_registration_get(void)
{
    return dot3StatsTable_if_ctx.user_ctx;
}

dot3StatsTable_registration *
dot3StatsTable_registration_set(dot3StatsTable_registration * newreg)
{
    dot3StatsTable_registration *old = dot3StatsTable_if_ctx.user_ctx;
    dot3StatsTable_if_ctx.user_ctx = newreg;
    return old;
}

int
dot3StatsTable_container_size(void)
{
    return CONTAINER_SIZE(dot3StatsTable_if_ctx.container);
}

/*
 * mfd multiplexer modes
 */
static Netsnmp_Node_Handler _mfd_dot3StatsTable_pre_request;
static Netsnmp_Node_Handler _mfd_dot3StatsTable_post_request;
static Netsnmp_Node_Handler _mfd_dot3StatsTable_object_lookup;
static Netsnmp_Node_Handler _mfd_dot3StatsTable_get_values;
/**
 * @internal
 * Initialize the table dot3StatsTable 
 *    (Define its contents and how it's structured)
 */
void
_dot3StatsTable_initialize_interface(dot3StatsTable_registration * reg_ptr,
                                     u_long flags)
{
    netsnmp_baby_steps_access_methods *access_multiplexer =
        &dot3StatsTable_if_ctx.access_multiplexer;
    netsnmp_table_registration_info *tbl_info =
        &dot3StatsTable_if_ctx.tbl_info;
    netsnmp_handler_registration *reginfo;
    netsnmp_mib_handler *handler;
    int             mfd_modes = 0;

    DEBUGMSGTL(("internal:dot3StatsTable:_dot3StatsTable_initialize_interface", "called\n"));


    /*************************************************
     *
     * save interface context for dot3StatsTable
     */
    /*
     * Setting up the table's definition
     */
    netsnmp_table_helper_add_indexes(tbl_info, ASN_INTEGER,
                                               /** index: dot3StatsIndex */
                                     0);

    /*
     * Define the minimum and maximum accessible columns.  This
     * optimizes retrival. 
     */
    tbl_info->min_column = DOT3STATSTABLE_MIN_COL;
    tbl_info->max_column = DOT3STATSTABLE_MAX_COL;

    /*
     * save users context
     */
    dot3StatsTable_if_ctx.user_ctx = reg_ptr;

    /*
     * call data access initialization code
     */
    dot3StatsTable_init_data(reg_ptr);

    /*
     * set up the container
     */
    _dot3StatsTable_container_init(&dot3StatsTable_if_ctx);
    if (NULL == dot3StatsTable_if_ctx.container) {
        snmp_log(LOG_ERR,
                 "could not initialize container for dot3StatsTable\n");
        return;
    }

    /*
     * access_multiplexer: REQUIRED wrapper for get request handling
     */
    access_multiplexer->object_lookup = _mfd_dot3StatsTable_object_lookup;
    access_multiplexer->get_values = _mfd_dot3StatsTable_get_values;

    /*
     * no wrappers yet
     */
    access_multiplexer->pre_request = _mfd_dot3StatsTable_pre_request;
    access_multiplexer->post_request = _mfd_dot3StatsTable_post_request;


    /*************************************************
     *
     * Create a registration, save our reg data, register table.
     */
    DEBUGMSGTL(("dot3StatsTable:init_dot3StatsTable",
                "Registering dot3StatsTable as a mibs-for-dummies table.\n"));
    handler =
        netsnmp_baby_steps_access_multiplexer_get(access_multiplexer);
    reginfo =
        netsnmp_handler_registration_create("dot3StatsTable", handler,
                                            dot3StatsTable_oid,
                                            dot3StatsTable_oid_size,
                                            HANDLER_CAN_BABY_STEP |
                                            HANDLER_CAN_RONLY);
    if (NULL == reginfo) {
        snmp_log(LOG_ERR, "error registering table dot3StatsTable\n");
        return;
    }
    reginfo->my_reg_void = &dot3StatsTable_if_ctx;

    /*************************************************
     *
     * set up baby steps handler, create it and inject it
     */
    if (access_multiplexer->object_lookup)
        mfd_modes |= BABY_STEP_OBJECT_LOOKUP;
    if (access_multiplexer->set_values)
        mfd_modes |= BABY_STEP_SET_VALUES;
    if (access_multiplexer->irreversible_commit)
        mfd_modes |= BABY_STEP_IRREVERSIBLE_COMMIT;
    if (access_multiplexer->object_syntax_checks)
        mfd_modes |= BABY_STEP_CHECK_OBJECT;

    if (access_multiplexer->pre_request)
        mfd_modes |= BABY_STEP_PRE_REQUEST;
    if (access_multiplexer->post_request)
        mfd_modes |= BABY_STEP_POST_REQUEST;

    if (access_multiplexer->undo_setup)
        mfd_modes |= BABY_STEP_UNDO_SETUP;
    if (access_multiplexer->undo_cleanup)
        mfd_modes |= BABY_STEP_UNDO_CLEANUP;
    if (access_multiplexer->undo_sets)
        mfd_modes |= BABY_STEP_UNDO_SETS;

    if (access_multiplexer->row_creation)
        mfd_modes |= BABY_STEP_ROW_CREATE;
    if (access_multiplexer->consistency_checks)
        mfd_modes |= BABY_STEP_CHECK_CONSISTENCY;
    if (access_multiplexer->commit)
        mfd_modes |= BABY_STEP_COMMIT;
    if (access_multiplexer->undo_commit)
        mfd_modes |= BABY_STEP_UNDO_COMMIT;

    handler = netsnmp_baby_steps_handler_get(mfd_modes);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject row_merge helper with prefix rootoid_len + 2 (entry.col)
     */
    handler = netsnmp_get_row_merge_handler(reginfo->rootoid_len + 2);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject container_table helper
     */
    handler =
        netsnmp_container_table_handler_get(tbl_info,
                                            dot3StatsTable_if_ctx.
                                            container,
                                            TABLE_CONTAINER_KEY_NETSNMP_INDEX);
    netsnmp_inject_handler(reginfo, handler);

    /*************************************************
     *
     * inject cache helper
     */
    if (NULL != dot3StatsTable_if_ctx.cache) {
        handler = netsnmp_cache_handler_get(dot3StatsTable_if_ctx.cache);
        netsnmp_inject_handler(reginfo, handler);
    }

    /*
     * register table
     */
    netsnmp_register_table(reginfo, tbl_info);

}                               /* _dot3StatsTable_initialize_interface */

/**
 * @internal
 * Shutdown the table dot3StatsTable
 */
void
_dot3StatsTable_shutdown_interface(dot3StatsTable_registration * reg_ptr)
{
    /*
     * shutdown the container
     */
    _dot3StatsTable_container_shutdown(&dot3StatsTable_if_ctx);
}

void
dot3StatsTable_valid_columns_set(netsnmp_column_info *vc)
{
    dot3StatsTable_if_ctx.tbl_info.valid_columns = vc;
}                               /* dot3StatsTable_valid_columns_set */

/**
 * @internal
 * convert the index component stored in the context to an oid
 */
int
dot3StatsTable_index_to_oid(netsnmp_index * oid_idx,
                            dot3StatsTable_mib_index * mib_idx)
{
    int             err = SNMP_ERR_NOERROR;

    /*
     * temp storage for parsing indexes
     */
    /*
     * dot3StatsIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H
     */
    netsnmp_variable_list var_dot3StatsIndex;

    /*
     * set up varbinds
     */
    memset(&var_dot3StatsIndex, 0x00, sizeof(var_dot3StatsIndex));
    var_dot3StatsIndex.type = ASN_INTEGER;

    /*
     * chain temp index varbinds together
     */
    var_dot3StatsIndex.next_variable = NULL;


    DEBUGMSGTL(("verbose:dot3StatsTable:dot3StatsTable_index_to_oid",
                "called\n"));

    /*
     * dot3StatsIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H 
     */
    snmp_set_var_value(&var_dot3StatsIndex,
                       (u_char *) & mib_idx->dot3StatsIndex,
                       sizeof(mib_idx->dot3StatsIndex));


    err = build_oid_noalloc(oid_idx->oids, oid_idx->len, &oid_idx->len,
                            NULL, 0, &var_dot3StatsIndex);
    if (err)
        snmp_log(LOG_ERR, "error %d converting index to oid\n", err);

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers(&var_dot3StatsIndex);

    return err;
}                               /* dot3StatsTable_index_to_oid */

/**
 * extract dot3StatsTable indexes from a netsnmp_index
 *
 * @retval SNMP_ERR_NOERROR  : no error
 * @retval SNMP_ERR_GENERR   : error
 */
int
dot3StatsTable_index_from_oid(netsnmp_index * oid_idx,
                              dot3StatsTable_mib_index * mib_idx)
{
    int             err = SNMP_ERR_NOERROR;

    /*
     * temp storage for parsing indexes
     */
    /*
     * dot3StatsIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H
     */
    netsnmp_variable_list var_dot3StatsIndex;

    /*
     * set up varbinds
     */
    memset(&var_dot3StatsIndex, 0x00, sizeof(var_dot3StatsIndex));
    var_dot3StatsIndex.type = ASN_INTEGER;

    /*
     * chain temp index varbinds together
     */
    var_dot3StatsIndex.next_variable = NULL;


    DEBUGMSGTL(("verbose:dot3StatsTable:dot3StatsTable_index_from_oid",
                "called\n"));

    /*
     * parse the oid into the individual index components
     */
    err = parse_oid_indexes(oid_idx->oids, oid_idx->len,
                            &var_dot3StatsIndex);
    if (err == SNMP_ERR_NOERROR) {
        /*
         * copy out values
         */
        mib_idx->dot3StatsIndex =
            *((long *) var_dot3StatsIndex.val.string);


    }

    /*
     * parsing may have allocated memory. free it.
     */
    snmp_reset_var_buffers(&var_dot3StatsIndex);

    return err;
}                               /* dot3StatsTable_index_from_oid */


/*
 *********************************************************************
 * @internal
 * allocate resources for a dot3StatsTable_rowreq_ctx
 */
dot3StatsTable_rowreq_ctx *
dot3StatsTable_allocate_rowreq_ctx(void *user_init_ctx)
{
    dot3StatsTable_rowreq_ctx *rowreq_ctx =
        SNMP_MALLOC_TYPEDEF(dot3StatsTable_rowreq_ctx);

    DEBUGMSGTL(("internal:dot3StatsTable:dot3StatsTable_allocate_rowreq_ctx", "called\n"));

    if (NULL == rowreq_ctx) {
        snmp_log(LOG_ERR, "Couldn't allocate memory for a "
                 "dot3StatsTable_rowreq_ctx.\n");
        return NULL;
    }

    rowreq_ctx->oid_idx.oids = rowreq_ctx->oid_tmp;

    rowreq_ctx->dot3StatsTable_data_list = NULL;

    /*
     * if we allocated data, call init routine
     */
    if (!(rowreq_ctx->rowreq_flags & MFD_ROW_DATA_FROM_USER)) {
        if (SNMPERR_SUCCESS !=
            dot3StatsTable_rowreq_ctx_init(rowreq_ctx, user_init_ctx)) {
            dot3StatsTable_release_rowreq_ctx(rowreq_ctx);
            rowreq_ctx = NULL;
        }
    }

    return rowreq_ctx;
}                               /* dot3StatsTable_allocate_rowreq_ctx */

/*
 * @internal
 * release resources for a dot3StatsTable_rowreq_ctx
 */
void
dot3StatsTable_release_rowreq_ctx(dot3StatsTable_rowreq_ctx * rowreq_ctx)
{
    DEBUGMSGTL(("internal:dot3StatsTable:dot3StatsTable_release_rowreq_ctx", "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    dot3StatsTable_rowreq_ctx_cleanup(rowreq_ctx);

    /*
     * free index oid pointer
     */
    if (rowreq_ctx->oid_idx.oids != rowreq_ctx->oid_tmp)
        free(rowreq_ctx->oid_idx.oids);

    SNMP_FREE(rowreq_ctx);
}                               /* dot3StatsTable_release_rowreq_ctx */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dot3StatsTable_pre_request(netsnmp_mib_handler *handler,
                                netsnmp_handler_registration *reginfo,
                                netsnmp_agent_request_info *agtreq_info,
                                netsnmp_request_info *requests)
{
    int             rc;

    DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_pre_request",
                "called\n"));

    if (1 != netsnmp_row_merge_status_first(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:dot3StatsTable",
                    "skipping additional pre_request\n"));
        return SNMP_ERR_NOERROR;
    }

    rc = dot3StatsTable_pre_request(dot3StatsTable_if_ctx.user_ctx);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("dot3StatsTable", "error %d from "
                    "dot3StatsTable_pre_request\n", rc));
        netsnmp_request_set_error_all(requests, SNMP_VALIDATE_ERR(rc));
    }

    return SNMP_ERR_NOERROR;
}                               /* _mfd_dot3StatsTable_pre_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dot3StatsTable_post_request(netsnmp_mib_handler *handler,
                                 netsnmp_handler_registration *reginfo,
                                 netsnmp_agent_request_info *agtreq_info,
                                 netsnmp_request_info *requests)
{
    dot3StatsTable_rowreq_ctx *rowreq_ctx =
        netsnmp_container_table_row_extract(requests);
    int             rc, packet_rc;

    DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_post_request",
                "called\n"));

    /*
     * release row context, if deleted
     */
    if (rowreq_ctx && (rowreq_ctx->rowreq_flags & MFD_ROW_DELETED))
        dot3StatsTable_release_rowreq_ctx(rowreq_ctx);

    /*
     * wait for last call before calling user
     */
    if (1 != netsnmp_row_merge_status_last(reginfo, agtreq_info)) {
        DEBUGMSGTL(("internal:dot3StatsTable",
                    "waiting for last post_request\n"));
        return SNMP_ERR_NOERROR;
    }

    packet_rc = netsnmp_check_all_requests_error(agtreq_info->asp, 0);
    rc = dot3StatsTable_post_request(dot3StatsTable_if_ctx.user_ctx,
                                     packet_rc);
    if (MFD_SUCCESS != rc) {
        /*
         * nothing we can do about it but log it
         */
        DEBUGMSGTL(("dot3StatsTable", "error %d from "
                    "dot3StatsTable_post_request\n", rc));
    }

    return SNMP_ERR_NOERROR;
}                               /* _mfd_dot3StatsTable_post_request */

/**
 * @internal
 * wrapper
 */
static int
_mfd_dot3StatsTable_object_lookup(netsnmp_mib_handler *handler,
                                  netsnmp_handler_registration *reginfo,
                                  netsnmp_agent_request_info *agtreq_info,
                                  netsnmp_request_info *requests)
{
    int             rc = SNMP_ERR_NOERROR;
    dot3StatsTable_rowreq_ctx *rowreq_ctx =
        netsnmp_container_table_row_extract(requests);

    DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_object_lookup", "called\n"));

    /*
     * get our context from mfd
     * dot3StatsTable_interface_ctx *if_ctx =
     *             (dot3StatsTable_interface_ctx *)reginfo->my_reg_void;
     */

    if (NULL == rowreq_ctx) {
        rc = SNMP_ERR_NOCREATION;
    }

    if (MFD_SUCCESS != rc)
        netsnmp_request_set_error_all(requests, rc);
    else
        dot3StatsTable_row_prep(rowreq_ctx);

    return SNMP_VALIDATE_ERR(rc);
}                               /* _mfd_dot3StatsTable_object_lookup */

/***********************************************************************
 *
 * GET processing
 *
 ***********************************************************************/
/*
 * @internal
 * Retrieve the value for a particular column
 */
NETSNMP_STATIC_INLINE int
_dot3StatsTable_get_column(dot3StatsTable_rowreq_ctx * rowreq_ctx,
                           netsnmp_variable_list * var, int column)
{
    int             rc = SNMPERR_SUCCESS;

    DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column",
                "called for %d\n", column));


    netsnmp_assert(NULL != rowreq_ctx);

    switch (column) {

        /*
         * (INDEX) dot3StatsIndex(1)/InterfaceIndex/ASN_INTEGER/long(long)//l/A/w/e/R/d/H 
         */
    case COLUMN_DOT3STATSINDEX:
        var->type = ASN_INTEGER;
        var->val_len = sizeof(long);
        (*var->val.integer) = rowreq_ctx->tbl_idx.dot3StatsIndex;
        break;

        /*
         * dot3StatsAlignmentErrors(2)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSALIGNMENTERRORS:
        if (!
            (COLUMN_DOT3STATSALIGNMENTERRORS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsAlignmentErrors) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsAlignmentErrors_get(rowreq_ctx,
                                          (u_long *) var->val.string);
        break;

        /*
         * dot3StatsFCSErrors(3)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSFCSERRORS:
        if (!
            (COLUMN_DOT3STATSFCSERRORS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsFCSErrors) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsFCSErrors_get(rowreq_ctx,
                                    (u_long *) var->val.string);
        break;

        /*
         * dot3StatsSingleCollisionFrames(4)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSSINGLECOLLISIONFRAMES:
        if (!
            (COLUMN_DOT3STATSSINGLECOLLISIONFRAMES_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsSingleCollisionFrames) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsSingleCollisionFrames_get(rowreq_ctx,
                                                (u_long *) var->val.
                                                string);
        break;

        /*
         * dot3StatsMultipleCollisionFrames(5)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSMULTIPLECOLLISIONFRAMES:
        if (!
            (COLUMN_DOT3STATSMULTIPLECOLLISIONFRAMES_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsMultipleCollisionFrames) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsMultipleCollisionFrames_get(rowreq_ctx,
                                                  (u_long *) var->val.
                                                  string);
        break;

        /*
         * dot3StatsSQETestErrors(6)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSSQETESTERRORS:
        if (!
            (COLUMN_DOT3STATSSQETESTERRORS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsSQETestErrors) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsSQETestErrors_get(rowreq_ctx,
                                        (u_long *) var->val.string);
        break;

        /*
         * dot3StatsDeferredTransmissions(7)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSDEFERREDTRANSMISSIONS:
        if (!
            (COLUMN_DOT3STATSDEFERREDTRANSMISSIONS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsDeferredTransmissions) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsDeferredTransmissions_get(rowreq_ctx,
                                                (u_long *) var->val.
                                                string);
        break;

        /*
         * dot3StatsLateCollisions(8)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSLATECOLLISIONS:
        if (!
            (COLUMN_DOT3STATSLATECOLLISIONS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsLateCollisions) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsLateCollisions_get(rowreq_ctx,
                                         (u_long *) var->val.string);
        break;

        /*
         * dot3StatsExcessiveCollisions(9)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSEXCESSIVECOLLISIONS:
        if (!
            (COLUMN_DOT3STATSEXCESSIVECOLLISIONS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsExcessiveCollisions) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsExcessiveCollisions_get(rowreq_ctx,
                                              (u_long *) var->val.string);
        break;

        /*
         * dot3StatsInternalMacTransmitErrors(10)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSINTERNALMACTRANSMITERRORS:
        if (!
            (COLUMN_DOT3STATSINTERNALMACTRANSMITERRORS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsInternalMacTransmitErrors) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsInternalMacTransmitErrors_get(rowreq_ctx,
                                                    (u_long *) var->val.
                                                    string);
        break;

        /*
         * dot3StatsCarrierSenseErrors(11)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSCARRIERSENSEERRORS:
        if (!
            (COLUMN_DOT3STATSCARRIERSENSEERRORS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsCarrierSenseErrors) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsCarrierSenseErrors_get(rowreq_ctx,
                                             (u_long *) var->val.string);
        break;

        /*
         * dot3StatsFrameTooLongs(13)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSFRAMETOOLONGS:
        if (!
            (COLUMN_DOT3STATSFRAMETOOLONGS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsFrameTooLongs) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsFrameTooLongs_get(rowreq_ctx,
                                        (u_long *) var->val.string);
        break;

        /*
         * dot3StatsInternalMacReceiveErrors(16)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSINTERNALMACRECEIVEERRORS:
        if (!
            (COLUMN_DOT3STATSINTERNALMACRECEIVEERRORS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsInternalMacReceiveErrors) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsInternalMacReceiveErrors_get(rowreq_ctx,
                                                   (u_long *) var->val.
                                                   string);
        break;

        /*
         * dot3StatsEtherChipSet(17)/OBJECTID/ASN_OBJECT_ID/oid(oid)//L/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSETHERCHIPSET:
        if (!
            (COLUMN_DOT3STATSETHERCHIPSET_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsEtherChipSet) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->type = ASN_OBJECT_ID;
        rc = dot3StatsEtherChipSet_get(rowreq_ctx,
                                       (oid **) & var->val.string,
                                       &var->val_len);
        break;

        /*
         * dot3StatsSymbolErrors(18)/COUNTER/ASN_COUNTER/u_long(u_long)//l/A/w/e/r/d/h 
         */
    case COLUMN_DOT3STATSSYMBOLERRORS:
        if (!
            (COLUMN_DOT3STATSSYMBOLERRORS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsSymbolErrors) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_COUNTER;
        rc = dot3StatsSymbolErrors_get(rowreq_ctx,
                                       (u_long *) var->val.string);
        break;

        /*
         * dot3StatsDuplexStatus(19)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h 
         */
    case COLUMN_DOT3STATSDUPLEXSTATUS:
        if (!
            (COLUMN_DOT3STATSDUPLEXSTATUS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsDuplexStatus) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_INTEGER;
        rc = dot3StatsDuplexStatus_get(rowreq_ctx,
                                       (u_long *) var->val.string);
        break;

        /*
         * dot3StatsRateControlAbility(20)/TruthValue/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h 
         */
    case COLUMN_DOT3STATSRATECONTROLABILITY:
        if (!
            (COLUMN_DOT3STATSRATECONTROLABILITY_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsRateControlAbility) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_INTEGER;
        rc = dot3StatsRateControlAbility_get(rowreq_ctx,
                                             (u_long *) var->val.string);
        break;

        /*
         * dot3StatsRateControlStatus(21)/INTEGER/ASN_INTEGER/long(u_long)//l/A/w/E/r/d/h 
         */
    case COLUMN_DOT3STATSRATECONTROLSTATUS:
        if (!
            (COLUMN_DOT3STATSRATECONTROLSTATUS_FLAG & rowreq_ctx->
             column_exists_flags)) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "column %d (dot3StatsRateControlStatus) doesn't exist\n", column));
            return MFD_SKIP;
        }

        var->val_len = sizeof(u_long);
        var->type = ASN_INTEGER;
        rc = dot3StatsRateControlStatus_get(rowreq_ctx,
                                            (u_long *) var->val.string);
        break;

    default:
        if (DOT3STATSTABLE_MIN_COL <= column
            && column <= DOT3STATSTABLE_MAX_COL) {
            DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_column", "assume column %d is reserved\n", column));
            rc = MFD_SKIP;
        } else {
            snmp_log(LOG_ERR,
                     "unknown column %d in _dot3StatsTable_get_column\n",
                     column);
        }
        break;
    }

    return rc;
}                               /* _dot3StatsTable_get_column */

int
_mfd_dot3StatsTable_get_values(netsnmp_mib_handler *handler,
                               netsnmp_handler_registration *reginfo,
                               netsnmp_agent_request_info *agtreq_info,
                               netsnmp_request_info *requests)
{
    dot3StatsTable_rowreq_ctx *rowreq_ctx =
        netsnmp_container_table_row_extract(requests);
    netsnmp_table_request_info *tri;
    u_char         *old_string;
    void            (*dataFreeHook) (void *);
    int             rc;

    DEBUGMSGTL(("internal:dot3StatsTable:_mfd_dot3StatsTable_get_values",
                "called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    DEBUGMSGTL(("9:dot3StatsTable:_mfd_dot3StatsTable_get_values",
                "exists %u\n", rowreq_ctx->column_exists_flags));

    for (; requests; requests = requests->next) {
        /*
         * save old pointer, so we can free it if replaced
         */
        old_string = requests->requestvb->val.string;
        dataFreeHook = requests->requestvb->dataFreeHook;
        if (NULL == requests->requestvb->val.string) {
            requests->requestvb->val.string = requests->requestvb->buf;
            requests->requestvb->val_len =
                sizeof(requests->requestvb->buf);
        } else if (requests->requestvb->buf ==
                   requests->requestvb->val.string) {
            if (requests->requestvb->val_len !=
                sizeof(requests->requestvb->buf))
                requests->requestvb->val_len =
                    sizeof(requests->requestvb->buf);
        }

        /*
         * get column data
         */
        tri = netsnmp_extract_table_info(requests);
        if (NULL == tri)
            continue;

        rc = _dot3StatsTable_get_column(rowreq_ctx, requests->requestvb,
                                        tri->colnum);
        if (rc) {
            if (MFD_SKIP == rc) {
                requests->requestvb->type = SNMP_NOSUCHINSTANCE;
                rc = SNMP_ERR_NOERROR;
            }
        } else if (NULL == requests->requestvb->val.string) {
            snmp_log(LOG_ERR, "NULL varbind data pointer!\n");
            rc = SNMP_ERR_GENERR;
        }
        if (rc)
            netsnmp_request_set_error(requests, SNMP_VALIDATE_ERR(rc));

        /*
         * if the buffer wasn't used previously for the old data (i.e. it
         * was allcoated memory)  and the get routine replaced the pointer,
         * we need to free the previous pointer.
         */
        if (old_string && (old_string != requests->requestvb->buf) &&
            (requests->requestvb->val.string != old_string)) {
            if (dataFreeHook)
                (*dataFreeHook) (old_string);
            else
                free(old_string);
        }
    }                           /* for results */

    return SNMP_ERR_NOERROR;
}                               /* _mfd_dot3StatsTable_get_values */


/***********************************************************************
 *
 * SET processing
 *
 ***********************************************************************/

/*
 * SET PROCESSING NOT APPLICABLE (per MIB or user setting)
 */
/***********************************************************************
 *
 * DATA ACCESS
 *
 ***********************************************************************/
static void     _container_free(netsnmp_container * container);

/**
 * @internal
 */
static int
_cache_load(netsnmp_cache * cache, void *vmagic)
{
    DEBUGMSGTL(("internal:dot3StatsTable:_cache_load", "called\n"));

    if ((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache for dot3StatsTable_cache_load\n");
        return -1;
    }

    /** should only be called for an invalid or expired cache */
    netsnmp_assert((0 == cache->valid) || (1 == cache->expired));

    /*
     * call user code
     */
    return dot3StatsTable_container_load((netsnmp_container *) cache->
                                         magic);
}                               /* _cache_load */

/**
 * @internal
 */
static void
_cache_free(netsnmp_cache * cache, void *magic)
{
    netsnmp_container *container;

    DEBUGMSGTL(("internal:dot3StatsTable:_cache_free", "called\n"));

    if ((NULL == cache) || (NULL == cache->magic)) {
        snmp_log(LOG_ERR, "invalid cache in dot3StatsTable_cache_free\n");
        return;
    }

    container = (netsnmp_container *) cache->magic;

    _container_free(container);
}                               /* _cache_free */

/**
 * @internal
 */
static void
_container_item_free(dot3StatsTable_rowreq_ctx * rowreq_ctx, void *context)
{
    DEBUGMSGTL(("internal:dot3StatsTable:_container_item_free",
                "called\n"));

    if (NULL == rowreq_ctx)
        return;

    dot3StatsTable_release_rowreq_ctx(rowreq_ctx);
}                               /* _container_item_free */

/**
 * @internal
 */
static void
_container_free(netsnmp_container * container)
{
    DEBUGMSGTL(("internal:dot3StatsTable:_container_free", "called\n"));

    if (NULL == container) {
        snmp_log(LOG_ERR,
                 "invalid container in dot3StatsTable_container_free\n");
        return;
    }

    /*
     * call user code
     */
    dot3StatsTable_container_free(container);

    /*
     * free all items. inefficient, but easy.
     */
    CONTAINER_CLEAR(container,
                    (netsnmp_container_obj_func *) _container_item_free,
                    NULL);
}                               /* _container_free */

/**
 * @internal
 * initialize the container with functions or wrappers
 */
void
_dot3StatsTable_container_init(dot3StatsTable_interface_ctx * if_ctx)
{
    DEBUGMSGTL(("internal:dot3StatsTable:_dot3StatsTable_container_init",
                "called\n"));

    /*
     * cache init
     */
    if_ctx->cache = netsnmp_cache_create(30,    /* timeout in seconds */
                                         _cache_load, _cache_free,
                                         dot3StatsTable_oid,
                                         dot3StatsTable_oid_size);

    if (NULL == if_ctx->cache) {
        snmp_log(LOG_ERR, "error creating cache for dot3StatsTable\n");
        return;
    }

    if_ctx->cache->flags = NETSNMP_CACHE_DONT_INVALIDATE_ON_SET;

    dot3StatsTable_container_init(&if_ctx->container, if_ctx->cache);
    if (NULL == if_ctx->container)
        if_ctx->container =
            netsnmp_container_find("dot3StatsTable:table_container");
    if (NULL == if_ctx->container) {
        snmp_log(LOG_ERR, "error creating container in "
                 "dot3StatsTable_container_init\n");
        return;
    }

    if (NULL != if_ctx->cache)
        if_ctx->cache->magic = (void *) if_ctx->container;
}                               /* _dot3StatsTable_container_init */

/**
 * @internal
 * shutdown the container with functions or wrappers
 */
void
_dot3StatsTable_container_shutdown(dot3StatsTable_interface_ctx * if_ctx)
{
    DEBUGMSGTL(("internal:dot3StatsTable:_dot3StatsTable_container_shutdown", "called\n"));

    dot3StatsTable_container_shutdown(if_ctx->container);

    _container_free(if_ctx->container);

}                               /* _dot3StatsTable_container_shutdown */


dot3StatsTable_rowreq_ctx *
dot3StatsTable_row_find_by_mib_index(dot3StatsTable_mib_index * mib_idx)
{
    dot3StatsTable_rowreq_ctx *rowreq_ctx;
    oid             oid_tmp[MAX_OID_LEN];
    netsnmp_index   oid_idx;
    int             rc;

    /*
     * set up storage for OID
     */
    oid_idx.oids = oid_tmp;
    oid_idx.len = sizeof(oid_tmp) / sizeof(oid);

    /*
     * convert
     */
    rc = dot3StatsTable_index_to_oid(&oid_idx, mib_idx);
    if (MFD_SUCCESS != rc)
        return NULL;

    rowreq_ctx = CONTAINER_FIND(dot3StatsTable_if_ctx.container, &oid_idx);

    return rowreq_ctx;
}
