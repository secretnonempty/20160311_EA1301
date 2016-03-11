/* client functions auto-generated by pidl */

#include "includes.h"
#include <tevent.h>
#include "lib/util/tevent_ntstatus.h"
#include "autoconf/librpc/gen_ndr/ndr_frsapi.h"
#include "autoconf/librpc/gen_ndr/ndr_frsapi_c.h"

/* frsapi - client functions generated by pidl */

struct dcerpc_frsapi_SetDsPollingIntervalW_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_SetDsPollingIntervalW_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_SetDsPollingIntervalW_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct frsapi_SetDsPollingIntervalW *r)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_SetDsPollingIntervalW_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_SetDsPollingIntervalW_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_SETDSPOLLINGINTERVALW, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_SetDsPollingIntervalW_r_done, req);

	return req;
}

static void dcerpc_frsapi_SetDsPollingIntervalW_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_SetDsPollingIntervalW_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_frsapi_SetDsPollingIntervalW_r_state *state =
		tevent_req_data(req,
		struct dcerpc_frsapi_SetDsPollingIntervalW_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_SetDsPollingIntervalW_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct frsapi_SetDsPollingIntervalW *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_SETDSPOLLINGINTERVALW, mem_ctx, r);

	return status;
}

struct dcerpc_frsapi_SetDsPollingIntervalW_state {
	struct frsapi_SetDsPollingIntervalW orig;
	struct frsapi_SetDsPollingIntervalW tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_SetDsPollingIntervalW_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_SetDsPollingIntervalW_send(TALLOC_CTX *mem_ctx,
							    struct tevent_context *ev,
							    struct dcerpc_binding_handle *h,
							    uint32_t _CurrentInterval /* [in]  */,
							    uint32_t _DsPollingLongInterval /* [in]  */,
							    uint32_t _DsPollingShortInterval /* [in]  */)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_SetDsPollingIntervalW_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_SetDsPollingIntervalW_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.CurrentInterval = _CurrentInterval;
	state->orig.in.DsPollingLongInterval = _DsPollingLongInterval;
	state->orig.in.DsPollingShortInterval = _DsPollingShortInterval;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_frsapi_SetDsPollingIntervalW_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_SetDsPollingIntervalW_done, req);
	return req;
}

static void dcerpc_frsapi_SetDsPollingIntervalW_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_frsapi_SetDsPollingIntervalW_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_SetDsPollingIntervalW_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_frsapi_SetDsPollingIntervalW_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_SetDsPollingIntervalW_recv(struct tevent_req *req,
						  TALLOC_CTX *mem_ctx,
						  WERROR *result)
{
	struct dcerpc_frsapi_SetDsPollingIntervalW_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_SetDsPollingIntervalW_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_SetDsPollingIntervalW(struct dcerpc_binding_handle *h,
					     TALLOC_CTX *mem_ctx,
					     uint32_t _CurrentInterval /* [in]  */,
					     uint32_t _DsPollingLongInterval /* [in]  */,
					     uint32_t _DsPollingShortInterval /* [in]  */,
					     WERROR *result)
{
	struct frsapi_SetDsPollingIntervalW r;
	NTSTATUS status;

	/* In parameters */
	r.in.CurrentInterval = _CurrentInterval;
	r.in.DsPollingLongInterval = _DsPollingLongInterval;
	r.in.DsPollingShortInterval = _DsPollingShortInterval;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_frsapi_SetDsPollingIntervalW_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_frsapi_GetDsPollingIntervalW_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_GetDsPollingIntervalW_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_GetDsPollingIntervalW_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct frsapi_GetDsPollingIntervalW *r)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_GetDsPollingIntervalW_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_GetDsPollingIntervalW_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_GETDSPOLLINGINTERVALW, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_GetDsPollingIntervalW_r_done, req);

	return req;
}

static void dcerpc_frsapi_GetDsPollingIntervalW_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_GetDsPollingIntervalW_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_frsapi_GetDsPollingIntervalW_r_state *state =
		tevent_req_data(req,
		struct dcerpc_frsapi_GetDsPollingIntervalW_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_GetDsPollingIntervalW_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct frsapi_GetDsPollingIntervalW *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_GETDSPOLLINGINTERVALW, mem_ctx, r);

	return status;
}

struct dcerpc_frsapi_GetDsPollingIntervalW_state {
	struct frsapi_GetDsPollingIntervalW orig;
	struct frsapi_GetDsPollingIntervalW tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_GetDsPollingIntervalW_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_GetDsPollingIntervalW_send(TALLOC_CTX *mem_ctx,
							    struct tevent_context *ev,
							    struct dcerpc_binding_handle *h,
							    uint32_t *_CurrentInterval /* [out] [ref] */,
							    uint32_t *_DsPollingLongInterval /* [out] [ref] */,
							    uint32_t *_DsPollingShortInterval /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_GetDsPollingIntervalW_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_GetDsPollingIntervalW_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */

	/* Out parameters */
	state->orig.out.CurrentInterval = _CurrentInterval;
	state->orig.out.DsPollingLongInterval = _DsPollingLongInterval;
	state->orig.out.DsPollingShortInterval = _DsPollingShortInterval;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_frsapi_GetDsPollingIntervalW_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_frsapi_GetDsPollingIntervalW_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_GetDsPollingIntervalW_done, req);
	return req;
}

static void dcerpc_frsapi_GetDsPollingIntervalW_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_frsapi_GetDsPollingIntervalW_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_GetDsPollingIntervalW_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_frsapi_GetDsPollingIntervalW_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.CurrentInterval = *state->tmp.out.CurrentInterval;
	*state->orig.out.DsPollingLongInterval = *state->tmp.out.DsPollingLongInterval;
	*state->orig.out.DsPollingShortInterval = *state->tmp.out.DsPollingShortInterval;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_GetDsPollingIntervalW_recv(struct tevent_req *req,
						  TALLOC_CTX *mem_ctx,
						  WERROR *result)
{
	struct dcerpc_frsapi_GetDsPollingIntervalW_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_GetDsPollingIntervalW_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_GetDsPollingIntervalW(struct dcerpc_binding_handle *h,
					     TALLOC_CTX *mem_ctx,
					     uint32_t *_CurrentInterval /* [out] [ref] */,
					     uint32_t *_DsPollingLongInterval /* [out] [ref] */,
					     uint32_t *_DsPollingShortInterval /* [out] [ref] */,
					     WERROR *result)
{
	struct frsapi_GetDsPollingIntervalW r;
	NTSTATUS status;

	/* In parameters */

	/* Out parameters */
	r.out.CurrentInterval = _CurrentInterval;
	r.out.DsPollingLongInterval = _DsPollingLongInterval;
	r.out.DsPollingShortInterval = _DsPollingShortInterval;

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_frsapi_GetDsPollingIntervalW_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_CurrentInterval = *r.out.CurrentInterval;
	*_DsPollingLongInterval = *r.out.DsPollingLongInterval;
	*_DsPollingShortInterval = *r.out.DsPollingShortInterval;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_frsapi_InfoW_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_InfoW_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_InfoW_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct frsapi_InfoW *r)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_InfoW_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_InfoW_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_INFOW, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_InfoW_r_done, req);

	return req;
}

static void dcerpc_frsapi_InfoW_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_InfoW_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_frsapi_InfoW_r_state *state =
		tevent_req_data(req,
		struct dcerpc_frsapi_InfoW_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_InfoW_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct frsapi_InfoW *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_INFOW, mem_ctx, r);

	return status;
}

struct dcerpc_frsapi_InfoW_state {
	struct frsapi_InfoW orig;
	struct frsapi_InfoW tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_InfoW_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_InfoW_send(TALLOC_CTX *mem_ctx,
					    struct tevent_context *ev,
					    struct dcerpc_binding_handle *h,
					    uint32_t _length /* [in] [range(0,0x10000)] */,
					    struct frsapi_Info *_info /* [in,out] [unique] */)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_InfoW_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_InfoW_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.length = _length;
	state->orig.in.info = _info;

	/* Out parameters */
	state->orig.out.info = _info;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_frsapi_InfoW_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_frsapi_InfoW_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_InfoW_done, req);
	return req;
}

static void dcerpc_frsapi_InfoW_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_frsapi_InfoW_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_InfoW_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_frsapi_InfoW_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	if (state->orig.out.info && state->tmp.out.info) {
		*state->orig.out.info = *state->tmp.out.info;
	}

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_InfoW_recv(struct tevent_req *req,
				  TALLOC_CTX *mem_ctx,
				  WERROR *result)
{
	struct dcerpc_frsapi_InfoW_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_InfoW_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_InfoW(struct dcerpc_binding_handle *h,
			     TALLOC_CTX *mem_ctx,
			     uint32_t _length /* [in] [range(0,0x10000)] */,
			     struct frsapi_Info *_info /* [in,out] [unique] */,
			     WERROR *result)
{
	struct frsapi_InfoW r;
	NTSTATUS status;

	/* In parameters */
	r.in.length = _length;
	r.in.info = _info;

	/* Out parameters */
	r.out.info = _info;

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_frsapi_InfoW_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	if (_info && r.out.info) {
		*_info = *r.out.info;
	}

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_frsapi_IsPathReplicated_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_IsPathReplicated_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_IsPathReplicated_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct frsapi_IsPathReplicated *r)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_IsPathReplicated_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_IsPathReplicated_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_ISPATHREPLICATED, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_IsPathReplicated_r_done, req);

	return req;
}

static void dcerpc_frsapi_IsPathReplicated_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_IsPathReplicated_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_frsapi_IsPathReplicated_r_state *state =
		tevent_req_data(req,
		struct dcerpc_frsapi_IsPathReplicated_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_IsPathReplicated_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct frsapi_IsPathReplicated *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_ISPATHREPLICATED, mem_ctx, r);

	return status;
}

struct dcerpc_frsapi_IsPathReplicated_state {
	struct frsapi_IsPathReplicated orig;
	struct frsapi_IsPathReplicated tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_IsPathReplicated_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_IsPathReplicated_send(TALLOC_CTX *mem_ctx,
						       struct tevent_context *ev,
						       struct dcerpc_binding_handle *h,
						       const char *_path /* [in] [unique,charset(UTF16)] */,
						       enum frsapi_ReplicaSetType _replica_set_type /* [in]  */,
						       uint32_t *_replicated /* [out] [ref] */,
						       uint32_t *_primary /* [out] [ref] */,
						       uint32_t *_root /* [out] [ref] */,
						       struct GUID *_replica_set_guid /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_IsPathReplicated_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_IsPathReplicated_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.path = _path;
	state->orig.in.replica_set_type = _replica_set_type;

	/* Out parameters */
	state->orig.out.replicated = _replicated;
	state->orig.out.primary = _primary;
	state->orig.out.root = _root;
	state->orig.out.replica_set_guid = _replica_set_guid;

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_frsapi_IsPathReplicated_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_frsapi_IsPathReplicated_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_IsPathReplicated_done, req);
	return req;
}

static void dcerpc_frsapi_IsPathReplicated_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_frsapi_IsPathReplicated_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_IsPathReplicated_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_frsapi_IsPathReplicated_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */
	*state->orig.out.replicated = *state->tmp.out.replicated;
	*state->orig.out.primary = *state->tmp.out.primary;
	*state->orig.out.root = *state->tmp.out.root;
	*state->orig.out.replica_set_guid = *state->tmp.out.replica_set_guid;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_IsPathReplicated_recv(struct tevent_req *req,
					     TALLOC_CTX *mem_ctx,
					     WERROR *result)
{
	struct dcerpc_frsapi_IsPathReplicated_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_IsPathReplicated_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_IsPathReplicated(struct dcerpc_binding_handle *h,
					TALLOC_CTX *mem_ctx,
					const char *_path /* [in] [unique,charset(UTF16)] */,
					enum frsapi_ReplicaSetType _replica_set_type /* [in]  */,
					uint32_t *_replicated /* [out] [ref] */,
					uint32_t *_primary /* [out] [ref] */,
					uint32_t *_root /* [out] [ref] */,
					struct GUID *_replica_set_guid /* [out] [ref] */,
					WERROR *result)
{
	struct frsapi_IsPathReplicated r;
	NTSTATUS status;

	/* In parameters */
	r.in.path = _path;
	r.in.replica_set_type = _replica_set_type;

	/* Out parameters */
	r.out.replicated = _replicated;
	r.out.primary = _primary;
	r.out.root = _root;
	r.out.replica_set_guid = _replica_set_guid;

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_frsapi_IsPathReplicated_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_replicated = *r.out.replicated;
	*_primary = *r.out.primary;
	*_root = *r.out.root;
	*_replica_set_guid = *r.out.replica_set_guid;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_frsapi_WriterCommand_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_WriterCommand_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_WriterCommand_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct frsapi_WriterCommand *r)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_WriterCommand_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_WriterCommand_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_WRITERCOMMAND, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_WriterCommand_r_done, req);

	return req;
}

static void dcerpc_frsapi_WriterCommand_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_WriterCommand_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_frsapi_WriterCommand_r_state *state =
		tevent_req_data(req,
		struct dcerpc_frsapi_WriterCommand_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_WriterCommand_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct frsapi_WriterCommand *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_WRITERCOMMAND, mem_ctx, r);

	return status;
}

struct dcerpc_frsapi_WriterCommand_state {
	struct frsapi_WriterCommand orig;
	struct frsapi_WriterCommand tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_WriterCommand_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_WriterCommand_send(TALLOC_CTX *mem_ctx,
						    struct tevent_context *ev,
						    struct dcerpc_binding_handle *h,
						    enum frsapi_WriterCommandsValues _command /* [in]  */)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_WriterCommand_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_WriterCommand_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.command = _command;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_frsapi_WriterCommand_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_WriterCommand_done, req);
	return req;
}

static void dcerpc_frsapi_WriterCommand_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_frsapi_WriterCommand_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_WriterCommand_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_frsapi_WriterCommand_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_WriterCommand_recv(struct tevent_req *req,
					  TALLOC_CTX *mem_ctx,
					  WERROR *result)
{
	struct dcerpc_frsapi_WriterCommand_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_WriterCommand_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_WriterCommand(struct dcerpc_binding_handle *h,
				     TALLOC_CTX *mem_ctx,
				     enum frsapi_WriterCommandsValues _command /* [in]  */,
				     WERROR *result)
{
	struct frsapi_WriterCommand r;
	NTSTATUS status;

	/* In parameters */
	r.in.command = _command;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_frsapi_WriterCommand_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_frsapi_ForceReplication_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_ForceReplication_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_ForceReplication_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct frsapi_ForceReplication *r)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_ForceReplication_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_ForceReplication_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_FORCEREPLICATION, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_ForceReplication_r_done, req);

	return req;
}

static void dcerpc_frsapi_ForceReplication_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_ForceReplication_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_frsapi_ForceReplication_r_state *state =
		tevent_req_data(req,
		struct dcerpc_frsapi_ForceReplication_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_ForceReplication_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct frsapi_ForceReplication *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_frsapi,
			NDR_FRSAPI_FORCEREPLICATION, mem_ctx, r);

	return status;
}

struct dcerpc_frsapi_ForceReplication_state {
	struct frsapi_ForceReplication orig;
	struct frsapi_ForceReplication tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_frsapi_ForceReplication_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_frsapi_ForceReplication_send(TALLOC_CTX *mem_ctx,
						       struct tevent_context *ev,
						       struct dcerpc_binding_handle *h,
						       struct GUID *_replica_set_guid /* [in] [unique] */,
						       struct GUID *_connection_guid /* [in] [unique] */,
						       const char *_replica_set_name /* [in] [unique,charset(UTF16)] */,
						       const char *_partner_dns_name /* [in] [charset(UTF16),unique] */)
{
	struct tevent_req *req;
	struct dcerpc_frsapi_ForceReplication_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_frsapi_ForceReplication_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.replica_set_guid = _replica_set_guid;
	state->orig.in.connection_guid = _connection_guid;
	state->orig.in.replica_set_name = _replica_set_name;
	state->orig.in.partner_dns_name = _partner_dns_name;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_frsapi_ForceReplication_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_frsapi_ForceReplication_done, req);
	return req;
}

static void dcerpc_frsapi_ForceReplication_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_frsapi_ForceReplication_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_ForceReplication_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_frsapi_ForceReplication_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (!NT_STATUS_IS_OK(status)) {
		tevent_req_nterror(req, status);
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_frsapi_ForceReplication_recv(struct tevent_req *req,
					     TALLOC_CTX *mem_ctx,
					     WERROR *result)
{
	struct dcerpc_frsapi_ForceReplication_state *state = tevent_req_data(
		req, struct dcerpc_frsapi_ForceReplication_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_frsapi_ForceReplication(struct dcerpc_binding_handle *h,
					TALLOC_CTX *mem_ctx,
					struct GUID *_replica_set_guid /* [in] [unique] */,
					struct GUID *_connection_guid /* [in] [unique] */,
					const char *_replica_set_name /* [in] [unique,charset(UTF16)] */,
					const char *_partner_dns_name /* [in] [charset(UTF16),unique] */,
					WERROR *result)
{
	struct frsapi_ForceReplication r;
	NTSTATUS status;

	/* In parameters */
	r.in.replica_set_guid = _replica_set_guid;
	r.in.connection_guid = _connection_guid;
	r.in.replica_set_name = _replica_set_name;
	r.in.partner_dns_name = _partner_dns_name;

	/* Out parameters */

	/* Result */
	ZERO_STRUCT(r.out.result);

	status = dcerpc_frsapi_ForceReplication_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

