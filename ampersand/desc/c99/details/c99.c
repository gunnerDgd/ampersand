#include "c99.h"

obj_trait __c99_trait				   = {
	.init		   = &__c99_init		 ,
	.init_as_clone = &__c99_init_as_clone,
	.init_as_ref   = &__c99_init_as_ref  ,
	.deinit		   = &__c99_deinit	     ,
	.size		   = &__c99_size		 ,
	.name		   = 0
};

bool_t
	__c99_init
		(__c99* par_ctx, u32_t par_count, va_list par) {
			par_ctx->err = 0;
			return str_init(&par_ctx->str, 0);
}

bool_t
	__c99_init_as_clone
		(__c99* par, __c99* par_clone) {
			str_init_as_clone(&par->str, &par_clone->str);
			par->err	     = par_clone->err        ;
			par->context     = par_clone->context    ;
            par->context_idx = par_clone->context_idx;

			return true_t;
}

bool_t
	__c99_init_as_ref
		(__c99* par) {
			return true_t;
}

void
	__c99_deinit
		(__c99* par) {
			str_deinit(&par->str);
}

u64_t
	__c99_size() {
		return sizeof(__c99);
}