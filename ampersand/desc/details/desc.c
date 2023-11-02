#include "desc.h"

obj_trait __ap_desc_trait				   = {
	.init		   = &__ap_desc_init		 ,
	.init_as_clone = &__ap_desc_init_as_clone,
	.init_as_ref   = &__ap_desc_init_as_ref  ,
	.deinit		   = &__ap_desc_deinit		 ,
	.size		   = &__ap_desc_size		 ,
	.name		   = 0
};

bool_t
	__ap_desc_init
		(__ap_desc* par_desc, u32_t par_count, va_list par)  {
			par_desc->ctx_trait = va_arg			(par, obj_trait*)	     ;
			par_desc->ctx_ops   = va_arg			(par, __ap_desc_context*);
			par_desc->ctx		= obj_init_from_varg(
				0				   ,
				par_desc->ctx_trait,
				par_count - 2	   ,
				par
			);

			if (!par_desc->ctx)		return false_t;
			if (!par_desc->ctx_ops) return false_t;

			return true_t;
}

bool_t
	__ap_desc_init_as_clone
		(__ap_desc* par, __ap_desc* par_clone)    {
			par->ctx_trait = par_clone->ctx_trait ;
			par->ctx_ops   = par_clone->ctx_ops   ;
			par->ctx	   = clone(par_clone->ctx);

			if (!par->ctx) return false_t;
			return true_t;
}

bool_t
	__ap_desc_init_as_ref
		(__ap_desc* par) {
			ref(par->ctx);
			return true_t;
}

void
	__ap_desc_deinit
		(__ap_desc* par) {
			del(par->ctx);
}

u64_t
	__ap_desc_size() {
		return sizeof(__ap_desc);
}