#include "elem.h"
#include "type.h"
#include "func.h"

#include <string.h>

obj_trait __ap_elem_trait				   = {
	.init		   = &__ap_elem_init		 ,
	.init_as_clone = &__ap_elem_init_as_clone,
	.init_as_ref   = &__ap_elem_init_as_ref  ,
	.deinit		   = &__ap_elem_deinit		 ,
	.name		   = &__ap_elem_name		 ,
	.size		   = &__ap_elem_size
};

bool_t
	__ap_elem_init
		(__ap_elem* par_elem, u32_t par_count, va_list par) {
			str_init(&par_elem->name, 0);
			
			const char* name	 = va_arg(par, const char*);
			u64_t		name_len = strlen(name);

			str_push_back_cstr(&par_elem->name, name, name_len);

			par_elem->type.all = ref(va_arg(par, obj*));
			if(trait_of(par_elem->type.all) == &__ap_type_trait)
				par_elem->category = __ap_elem_obj;
			else if (trait_of(par_elem->type.all) == &__ap_func_trait)
				par_elem->category = __ap_elem_func;
			else							   {
				str_deinit(&par_elem->name)	   ;
				del		   (par_elem->type.all);

				return false_t;
			}

			par_elem->attr.acc  = va_arg(par, u64_t);
			par_elem->attr.stor = va_arg(par, u64_t);

			return true_t;
}

bool_t
	__ap_elem_init_as_clone
		(__ap_elem* par, __ap_elem* par_clone) {
			str_init_as_clone(&par->name, &par_clone->name);
			par->attr	  = par_clone->attr ;
			par->type.all = ref(par_clone->type.all);
			par->category = par_clone->category;

			return true_t;
}

bool_t
	__ap_elem_init_as_ref
		(__ap_elem* par) {
			return true_t;
}

void
	__ap_elem_deinit
		(__ap_elem* par) {
			str_deinit(&par->name)	  ;
			del		   (par->type.all);
}

str*
	__ap_elem_name
		(__ap_elem* par) {
			return &par->name;
}

u64_t
	__ap_elem_size() {
		return sizeof(__ap_elem);
}