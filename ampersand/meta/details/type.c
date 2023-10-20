#include "type.h"
#include "elem.h"

#include <string.h>

obj_trait __ap_type_trait				   = {
	.init		   = &__ap_type_init		 ,
	.init_as_clone = &__ap_type_init_as_clone,
	.init_as_ref   = &__ap_type_init_as_ref  ,
	.deinit		   = &__ap_type_deinit	     ,
	
	.name		   = &__ap_type_name		 ,
	.size		   = &__ap_type_size
};

bool_t
	__ap_type_init
		(__ap_type* par_type, u32_t par_count, va_list par) {
			par_type->idx = va_arg(par, u16_t);
			
			str_init(&par_type->name, 0);
			if(par_type->idx == __ap_type_strt) {
				const char* name = va_arg(par, const char*);

				list_init		  (&par_type->elem, 0);
				str_push_back_cstr(&par_type->name, name, strlen(name));

				for (u64_t idx = 0; idx < par_count - 2; ++idx) {
					obj *elem = va_arg(par, obj*);
					if (trait_of(elem) != &__ap_elem_trait)
						goto __ap_type_init_failed;

					list_push_back(&par_type->elem, elem);
				}
			}

			return true_t;
	__ap_type_init_failed:
			list_deinit(&par_type->elem);
			str_deinit (&par_type->name);
			return false_t;
}

bool_t
	__ap_type_init_as_clone
		(__ap_type* par_type, __ap_type* par_type_clone)     {
			par_type->idx = par_type_clone->idx;
			
			str_init_as_clone (&par_type->name, &par_type_clone->name);
			list_init_as_clone(&par_type->elem, &par_type_clone->elem);

			if (par_type->idx == __ap_type_strt)
				list_init_as_clone(&par_type->elem, &par_type_clone->elem);

			return true_t;
}

bool_t
	__ap_type_init_as_ref
		(__ap_type* par_type) {
			return true_t;
}

void
	__ap_type_deinit
		(__ap_type* par_type) {
			if(par_type->idx == __ap_type_strt)
				list_deinit(&par_type->elem);

			str_deinit(&par_type->name);
}

str*
	__ap_type_name
		(__ap_type* par_type) {
			return &par_type->name;
}

u64_t
	__ap_type_size() {
		return sizeof(__ap_type);
}