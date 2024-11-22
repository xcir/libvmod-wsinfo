#include "config.h"

#include <stdio.h>
#include <stdlib.h>

#include "cache/cache.h"
#include "vas.h"
#include "vtim.h"

#include "vcc_wsinfo_if.h"

static struct ws *
getws(VRT_CTX, VCL_ENUM workspace)
{
	if(ctx->req != NULL){
		if(workspace == VENUM(request)){
			return ctx->ws;
		}else if(workspace == VENUM(session)){
			return ctx->req->sp->ws;
		}else{
			return ctx->req->wrk->aws;
		}
	}else{
		if(workspace == VENUM(request)){
			return ctx->bo->ws;
		}else if(workspace == VENUM(session)){
			return ctx->bo->sp->ws;
		}else{
			return ctx->bo->wrk->aws;
		}
	}

}


VCL_INT
vmod_size(VRT_CTX,VCL_ENUM workspace)
{
	/*
	if (WS_Overflowed(req->ws)) {
		v1d_error(req, boc, "workspace_client overflow");
		return;
	}

	if (WS_Overflowed(req->sp->ws)) {
		v1d_error(req, boc, "workspace_session overflow");
		return;
	}

	V1L_Open(req->wrk, req->wrk->aws, &req->sp->fd, req->vsl,
	    req->t_prev + SESS_TMO(req->sp, send_timeout),
	    cache_param->http1_iovs);

	if (WS_Overflowed(req->wrk->aws)) {
		v1d_error(req, boc, "workspace_thread overflow");
		return;
	}	
	*/

	return pdiff(getws(ctx, workspace)->s, getws(ctx, workspace)->e);

}
VCL_INT
vmod_free(VRT_CTX,VCL_ENUM workspace)
{
	return pdiff(getws(ctx, workspace)->f, getws(ctx, workspace)->e);


}
VCL_REAL
vmod_per(VRT_CTX,VCL_ENUM workspace)
{
	return vmod_free(ctx, workspace)*100.0/vmod_size(ctx, workspace);
}
