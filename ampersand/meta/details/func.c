#include "func.h"
#include "script.h"
#include "ops.h"
#include "type.h"
#include "obj.h"

#include <string.h>

obj_trait __ap_func_trait				   = {
	.init		   = &__ap_func_init		 ,
	.init_as_clone = &__ap_func_init_as_clone,
	.init_as_ref   = &__ap_func_init_as_ref  ,
	.deinit		   = &__ap_func_deinit		 ,
	.name		   = &__ap_func_name		 ,
	.size		   = &__ap_func_size
};

bool_t
	__ap_func_init
		(__ap_func* par_func, u32_t par_count, va_list par) {
			const char* name	 = va_arg(par, const char*);
			u64_t		name_len = strlen(name);

			str_init		  (&par_func->name, 0)			   ;
			str_push_back_cstr(&par_func->name, name, name_len);

			par_func->script = ref(va_arg(par, obj*));
			par_func->ret    = ref(va_arg(par, obj*));
			par_func->strt   = 0;

			list_init(&par_func->arg, 0);
			for (u32_t idx = 0 ; idx < par_count - 3; ++idx)
				list_push_back(&par_func->arg, va_arg(par, obj*));

			return true_t;
}

bool_t
	__ap_func_init_as_clone
		(__ap_func* par, __ap_func* par_clone) {
			str_init_as_clone (&par->name, &par_clone->name);
			list_init_as_clone(&par->arg , &par_clone->arg) ;

			par->script = clone(par_clone->script);
			par->ret	= clone(par_clone->ret)   ;
			
			if (par_clone->strt)
				par->strt = ref(par_clone->strt);

			return true_t;
}

bool_t
	__ap_func_init_as_ref
		(__ap_func* par) {
			return true_t;
}

void
	__ap_func_deinit
		(__ap_func* par) {
			str_deinit (&par->name);
			list_deinit(&par->arg) ;

			del(par->script);
			del(par->ret)   ;

			if (par->strt)
				del(par->strt);
}

str*
	__ap_func_name
		(__ap_func* par) {
			return &par->name;
}

u64_t
	__ap_func_size() {
		return sizeof(__ap_func);
}
