#include "ctx.h"

obj_trait __c99_ctx_trait				   = {
	.init		   = &__c99_ctx_init		 ,
	.init_as_clone = &__c99_ctx_init_as_clone,
	.init_as_ref   = &__c99_ctx_init_as_ref  ,
	.deinit		   = &__c99_ctx_deinit	     ,
	.size		   = &__c99_ctx_size		 ,
	.name		   = 0
};

bool_t
	__c99_ctx_init
		(__c99_ctx* par_ctx, u32_t par_count, va_list par) {
			par_ctx->err = 0;
			return str_init(&par_ctx->ctx, 0);
}

bool_t
	__c99_ctx_init_as_clone
		(__c99_ctx* par, __c99_ctx* par_clone) {
			str_init_as_clone(&par->ctx, &par_clone->ctx);
			par->err = par_clone->err;

			return true_t;
}

bool_t
	__c99_ctx_init_as_ref
		(__c99_ctx* par) {
			return true_t;
}

void
	__c99_ctx_deinit
		(__c99_ctx* par) {
			str_deinit(&par->ctx);
}

u64_t
	__c99_ctx_size() {
		return sizeof(__c99_ctx);
}