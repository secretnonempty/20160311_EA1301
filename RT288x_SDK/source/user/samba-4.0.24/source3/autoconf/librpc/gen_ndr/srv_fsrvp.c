/*
 * Unix SMB/CIFS implementation.
 * server auto-generated by pidl. DO NOT MODIFY!
 */

#include "includes.h"
#include "ntdomain.h"
#include "autoconf/librpc/gen_ndr/srv_fsrvp.h"

static bool api_fss_GetSupportedVersion(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_GetSupportedVersion *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_GETSUPPORTEDVERSION];

	r = talloc(talloc_tos(), struct fss_GetSupportedVersion);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_GetSupportedVersion, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.MinVersion = talloc_zero(r, uint32_t);
	if (r->out.MinVersion == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.MaxVersion = talloc_zero(r, uint32_t);
	if (r->out.MaxVersion == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _fss_GetSupportedVersion(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_GetSupportedVersion, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_SetContext(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_SetContext *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_SETCONTEXT];

	r = talloc(talloc_tos(), struct fss_SetContext);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_SetContext, NDR_IN, r);
	}

	r->out.result = _fss_SetContext(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_SetContext, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_StartShadowCopySet(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_StartShadowCopySet *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_STARTSHADOWCOPYSET];

	r = talloc(talloc_tos(), struct fss_StartShadowCopySet);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_StartShadowCopySet, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.pShadowCopySetId = talloc_zero(r, struct GUID);
	if (r->out.pShadowCopySetId == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _fss_StartShadowCopySet(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_StartShadowCopySet, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_AddToShadowCopySet(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_AddToShadowCopySet *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_ADDTOSHADOWCOPYSET];

	r = talloc(talloc_tos(), struct fss_AddToShadowCopySet);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_AddToShadowCopySet, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.pShadowCopyId = talloc_zero(r, struct GUID);
	if (r->out.pShadowCopyId == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _fss_AddToShadowCopySet(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_AddToShadowCopySet, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_CommitShadowCopySet(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_CommitShadowCopySet *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_COMMITSHADOWCOPYSET];

	r = talloc(talloc_tos(), struct fss_CommitShadowCopySet);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_CommitShadowCopySet, NDR_IN, r);
	}

	r->out.result = _fss_CommitShadowCopySet(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_CommitShadowCopySet, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_ExposeShadowCopySet(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_ExposeShadowCopySet *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_EXPOSESHADOWCOPYSET];

	r = talloc(talloc_tos(), struct fss_ExposeShadowCopySet);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_ExposeShadowCopySet, NDR_IN, r);
	}

	r->out.result = _fss_ExposeShadowCopySet(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_ExposeShadowCopySet, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_RecoveryCompleteShadowCopySet(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_RecoveryCompleteShadowCopySet *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_RECOVERYCOMPLETESHADOWCOPYSET];

	r = talloc(talloc_tos(), struct fss_RecoveryCompleteShadowCopySet);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_RecoveryCompleteShadowCopySet, NDR_IN, r);
	}

	r->out.result = _fss_RecoveryCompleteShadowCopySet(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_RecoveryCompleteShadowCopySet, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_AbortShadowCopySet(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_AbortShadowCopySet *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_ABORTSHADOWCOPYSET];

	r = talloc(talloc_tos(), struct fss_AbortShadowCopySet);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_AbortShadowCopySet, NDR_IN, r);
	}

	r->out.result = _fss_AbortShadowCopySet(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_AbortShadowCopySet, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_IsPathSupported(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_IsPathSupported *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_ISPATHSUPPORTED];

	r = talloc(talloc_tos(), struct fss_IsPathSupported);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_IsPathSupported, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.SupportedByThisProvider = talloc_zero(r, uint32_t);
	if (r->out.SupportedByThisProvider == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.OwnerMachineName = talloc_zero(r, const char *);
	if (r->out.OwnerMachineName == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _fss_IsPathSupported(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_IsPathSupported, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_IsPathShadowCopied(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_IsPathShadowCopied *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_ISPATHSHADOWCOPIED];

	r = talloc(talloc_tos(), struct fss_IsPathShadowCopied);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_IsPathShadowCopied, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.ShadowCopyPresent = talloc_zero(r, uint32_t);
	if (r->out.ShadowCopyPresent == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.ShadowCopyCompatibility = talloc_zero(r, int32_t);
	if (r->out.ShadowCopyCompatibility == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _fss_IsPathShadowCopied(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_IsPathShadowCopied, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_GetShareMapping(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_GetShareMapping *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_GETSHAREMAPPING];

	r = talloc(talloc_tos(), struct fss_GetShareMapping);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_GetShareMapping, NDR_IN, r);
	}

	ZERO_STRUCT(r->out);
	r->out.ShareMapping = talloc_zero(r, union fssagent_share_mapping);
	if (r->out.ShareMapping == NULL) {
		talloc_free(r);
		return false;
	}

	r->out.result = _fss_GetShareMapping(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_GetShareMapping, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_DeleteShareMapping(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_DeleteShareMapping *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_DELETESHAREMAPPING];

	r = talloc(talloc_tos(), struct fss_DeleteShareMapping);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_DeleteShareMapping, NDR_IN, r);
	}

	r->out.result = _fss_DeleteShareMapping(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_DeleteShareMapping, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}

static bool api_fss_PrepareShadowCopySet(struct pipes_struct *p)
{
	const struct ndr_interface_call *call;
	struct ndr_pull *pull;
	struct ndr_push *push;
	enum ndr_err_code ndr_err;
	struct fss_PrepareShadowCopySet *r;

	call = &ndr_table_FileServerVssAgent.calls[NDR_FSS_PREPARESHADOWCOPYSET];

	r = talloc(talloc_tos(), struct fss_PrepareShadowCopySet);
	if (r == NULL) {
		return false;
	}

	pull = ndr_pull_init_blob(&p->in_data.data, r);
	if (pull == NULL) {
		talloc_free(r);
		return false;
	}

	pull->flags |= LIBNDR_FLAG_REF_ALLOC;
	if (p->endian) {
		pull->flags |= LIBNDR_FLAG_BIGENDIAN;
	}
	ndr_err = call->ndr_pull(pull, NDR_IN, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_PrepareShadowCopySet, NDR_IN, r);
	}

	r->out.result = _fss_PrepareShadowCopySet(p, r);

	if (p->fault_state) {
		talloc_free(r);
		/* Return true here, srv_pipe_hnd.c will take care */
		return true;
	}

	if (DEBUGLEVEL >= 10) {
		NDR_PRINT_FUNCTION_DEBUG(fss_PrepareShadowCopySet, NDR_OUT | NDR_SET_VALUES, r);
	}

	push = ndr_push_init_ctx(r);
	if (push == NULL) {
		talloc_free(r);
		return false;
	}

	/*
	 * carry over the pointer count to the reply in case we are
	 * using full pointer. See NDR specification for full pointers
	 */
	push->ptr_count = pull->ptr_count;

	ndr_err = call->ndr_push(push, NDR_OUT, r);
	if (!NDR_ERR_CODE_IS_SUCCESS(ndr_err)) {
		talloc_free(r);
		return false;
	}

	p->out_data.rdata = ndr_push_blob(push);
	talloc_steal(p->mem_ctx, p->out_data.rdata.data);

	talloc_free(r);

	return true;
}


/* Tables */
static struct api_struct api_FileServerVssAgent_cmds[] = 
{
	{"FSS_GETSUPPORTEDVERSION", NDR_FSS_GETSUPPORTEDVERSION, api_fss_GetSupportedVersion},
	{"FSS_SETCONTEXT", NDR_FSS_SETCONTEXT, api_fss_SetContext},
	{"FSS_STARTSHADOWCOPYSET", NDR_FSS_STARTSHADOWCOPYSET, api_fss_StartShadowCopySet},
	{"FSS_ADDTOSHADOWCOPYSET", NDR_FSS_ADDTOSHADOWCOPYSET, api_fss_AddToShadowCopySet},
	{"FSS_COMMITSHADOWCOPYSET", NDR_FSS_COMMITSHADOWCOPYSET, api_fss_CommitShadowCopySet},
	{"FSS_EXPOSESHADOWCOPYSET", NDR_FSS_EXPOSESHADOWCOPYSET, api_fss_ExposeShadowCopySet},
	{"FSS_RECOVERYCOMPLETESHADOWCOPYSET", NDR_FSS_RECOVERYCOMPLETESHADOWCOPYSET, api_fss_RecoveryCompleteShadowCopySet},
	{"FSS_ABORTSHADOWCOPYSET", NDR_FSS_ABORTSHADOWCOPYSET, api_fss_AbortShadowCopySet},
	{"FSS_ISPATHSUPPORTED", NDR_FSS_ISPATHSUPPORTED, api_fss_IsPathSupported},
	{"FSS_ISPATHSHADOWCOPIED", NDR_FSS_ISPATHSHADOWCOPIED, api_fss_IsPathShadowCopied},
	{"FSS_GETSHAREMAPPING", NDR_FSS_GETSHAREMAPPING, api_fss_GetShareMapping},
	{"FSS_DELETESHAREMAPPING", NDR_FSS_DELETESHAREMAPPING, api_fss_DeleteShareMapping},
	{"FSS_PREPARESHADOWCOPYSET", NDR_FSS_PREPARESHADOWCOPYSET, api_fss_PrepareShadowCopySet},
};

void FileServerVssAgent_get_pipe_fns(struct api_struct **fns, int *n_fns)
{
	*fns = api_FileServerVssAgent_cmds;
	*n_fns = sizeof(api_FileServerVssAgent_cmds) / sizeof(struct api_struct);
}

NTSTATUS rpc_FileServerVssAgent_init(const struct rpc_srv_callbacks *rpc_srv_cb)
{
	return rpc_srv_register(SMB_RPC_INTERFACE_VERSION, "FileServerVssAgent", "FileServerVssAgent", &ndr_table_FileServerVssAgent, api_FileServerVssAgent_cmds, sizeof(api_FileServerVssAgent_cmds) / sizeof(struct api_struct), rpc_srv_cb);
}

NTSTATUS rpc_FileServerVssAgent_shutdown(void)
{
	return rpc_srv_unregister(&ndr_table_FileServerVssAgent);
}
