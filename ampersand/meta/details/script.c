#include "script.h"
#include "ops.h"
#include "obj.h"
#include "type.h"

obj_trait __ap_script_trait					 = {
	.init		   = &__ap_script_init		   ,
	.init_as_clone = &__ap_script_init_as_clone,
	.init_as_ref   = &__ap_script_init_as_ref  ,
	.deinit		   = &__ap_script_deinit	   ,
	.name		   = 0						   ,
	.size		   = &__ap_script_size
};

bool_t
	__ap_script_init
		(__ap_script* par_script, u32_t par_count, va_list par) {
			list_init(&par_script->ops, 0);
			
			for (u32_t idx = 0 ; idx < par_count ; ++idx) {
				obj		  *ops		 = va_arg  (par, obj*);
				obj_trait *ops_trait = trait_of(ops);

				if (ops_trait != &__ap_ops_trait && 
					ops_trait != &__ap_obj_trait && 
					ops_trait != &__ap_type_trait) {
					list_deinit(&par_script->ops);
					return false_t;
				}

				list_push_back(&par_script->ops, ops);
			}

			return true_t;
}

bool_t
	__ap_script_init_as_clone
		(__ap_script* par, __ap_script* par_clone) {
			list_init_as_clone(&par->ops, &par_clone->ops);
			return true_t;
}

bool_t
	__ap_script_init_as_ref
		(__ap_script* par) {
			return true_t;
}

void
	__ap_script_deinit
		(__ap_script* par) {
			list_deinit(&par->ops);
}

u64_t
	__ap_script_size() {
		return sizeof(__ap_script);
}