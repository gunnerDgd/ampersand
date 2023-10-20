#include "obj.h"
#include "type.h"

#include <string.h>

bool_t
	__ap_obj_init
		(__ap_obj* par_obj, u32_t par_count, va_list par) {
			par_obj->type = ref(va_arg(par, __ap_type*));
			str_init(&par_obj->name, 0);
			
			const char* name	 = va_arg(par, const char*);
			u64_t		name_len = strlen(name);

			str_push_back_cstr(&par_obj->name, name, name_len);

			par_obj->attr = va_arg(par, u64_t);
			return true_t;
}

bool_t
	__ap_obj_init_as_clone
		(__ap_obj* par, __ap_obj* par_clone) {
			str_init_as_clone(&par->name, &par_clone->name);
			par->type = ref(par_clone->type);
			par->attr =		par_clone->attr ;

			return true_t;
}

bool_t
	__ap_obj_init_as_ref
		(__ap_obj* par) {
			return true_t;
}

void
	__ap_obj_deinit
		(__ap_obj* par) {
			str_deinit(&par->name);
}

str*
	__ap_obj_name
		(__ap_obj* par) {
			return &par->name;
}

u64_t
	__ap_obj_size() {
		return sizeof(__ap_obj);
}