#include "ops.h"
#include "obj.h"

obj_trait __ap_ops_trait = {
	.init		   = &__ap_ops_init		    ,
	.init_as_clone = &__ap_ops_init_as_clone,
	.init_as_ref   = &__ap_ops_init_as_ref  ,
	.deinit		   = &__ap_ops_deinit		,
	.name		   = 0					    ,
	.size		   = &__ap_ops_size
};

bool_t
	__ap_ops_init
		(__ap_ops* par_ops, u32_t par_count, va_list par) {
			list_init(&par_ops->op_arg, 0);
			
			par_ops->op = va_arg(par, u64_t);
			for(u32_t idx = 0; idx < par_count - 1 ; ++idx) {
				obj		  *arg		 = va_arg  (par, obj*);
				obj_trait *arg_trait = trait_of(arg)	  ;

				if (arg_trait != &__ap_obj_trait && arg_trait != &__ap_ops_trait)
					goto __ap_ops_init_failed;

				list_push_back(&par_ops->op_arg, arg);
			}

			return true_t;
	__ap_ops_init_failed:
			list_deinit(&par_ops->op_arg);
			return false_t;
}

bool_t
	__ap_ops_init_as_clone
		(__ap_ops* par, __ap_ops* par_clone) {
			par->op = par_clone->op;
			list_init_as_clone(&par->op_arg, &par_clone->op_arg);

			return true_t;
}

bool_t
	__ap_ops_init_as_ref
		(__ap_ops* par) {
			return true_t;
}

void
	__ap_ops_deinit
		(__ap_ops* par) {
			list_deinit(&par->op_arg);
}

u64_t
	__ap_ops_size() {
		return sizeof(__ap_ops);
}