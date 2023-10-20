#include "desc.h"

obj_trait __c99_desc_trait				    = {
	.init		   = &__c99_desc_init		  ,
	.init_as_clone = &__c99_desc_init_as_clone,
	.init_as_ref   = &__c99_desc_init_as_ref  ,
	.deinit		   = &__c99_desc_deinit	      ,
	.size		   = &__c99_desc_size		  ,
	.name		   = 0
};

bool_t
	__c99_desc_init
		(__c99_desc* par_ctx, u32_t par_count, va_list par) {
			par_ctx->err = 0;
			return str_init(&par_ctx->ctx, 0);
}

bool_t
	__c99_desc_init_as_clone
		(__c99_desc* par, __c99_desc* par_clone) {
			str_init_as_clone(&par->ctx, &par_clone->ctx);
			par->err = par_clone->err;

			return true_t;
}

bool_t
	__c99_desc_init_as_ref
		(__c99_desc* par) {
			return true_t;
}

void
	__c99_desc_deinit
		(__c99_desc* par) {
			str_deinit(&par->ctx);
}

u64_t
	__c99_desc_size() {
		return sizeof(__c99_desc);
}