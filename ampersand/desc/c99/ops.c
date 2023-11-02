#include "ops.h"
#include "details/ops.h"
#include "details/ctx.h"

#include "ctx.h"

bool_t
	c99_desc_ops
		(obj* par_desc, obj* par_ctx, obj* par) {
			if(trait_of(par_desc) != ap_desc_t) return false_t;
			if(trait_of(par_ctx)  != c99_ctx_t) return false_t;

			str	ret;
			str_init(&ret, 0);

			__c99_ctx* ctx = par_ctx;

			if(__c99_desc_ops(&ret, par)) {
				str_push_back_cstr(&ret, ";\n", 2) ;
				str_push_back	  (&ctx->ctx, &ret);
				str_deinit		  (&ret);
				
				return true_t;
			}

			str_deinit(&ret);
			return false_t;
}