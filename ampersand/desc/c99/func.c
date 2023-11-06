#include "func.h"
#include "script.h"
#include "c99.h"

#include "details/c99.h"

#include "details/type.h"
#include "details/obj.h"

#include <ampersand/meta/func.h>
#include <ampersand/meta/type.h>
#include <ampersand/meta/obj.h>

bool_t
	c99_desc_func
		(obj* par_context, obj* par) {
			if (trait_of(par_context) != c99_t)     return false_t;
			if (trait_of(par)		  != ap_func_t) return false_t;

			c99_desc_func_ret (par_context, par);
			str_push_back_cstr(c99_get_str(par_context), " (", 2);
			
			it arg	   = ap_func_arg_begin(par),
			   arg_end = ap_func_arg_end  (par); 

			for ( ; !it_eq(&arg, &arg_end) ; it_next(&arg)) {
				__c99_desc_type   (c99_get_str(par_context), it_get(&arg));
				__c99_desc_obj	  (c99_get_str(par_context), it_get(&arg));
				str_push_back_cstr(c99_get_str(par_context), ", ", 2);
			}

			str_push_back_cstr(c99_get_str(par_context), ")\n", 2);
			return true_t;
}

bool_t
	c99_desc_func_ret
		(obj* par_context, obj* par) {
			if (trait_of(par_context) != c99_t)     return false_t;
			if (trait_of(par)		  != ap_type_t) return false_t;

            __c99* context = par_context;
                   context->context_idx            = __c99_context_idx_func;
                   context->context.func.arg_count = 0;
                   context->context.func.func      = 0;

			return __c99_desc_type(c99_get_str(par_context), par);
}

bool_t
	c99_desc_func_arg
		(obj* par_context, obj* par) {
			if (trait_of(par_context) != c99_t)    return false_t;
			if (trait_of(par)		  != ap_obj_t) return false_t;

			__c99_desc_type   (c99_get_str(par_context), name_of(ap_obj_type(par)));
			__c99_desc_obj    (c99_get_str(par_context), name_of(par))			   ;
			str_push_back_cstr(c99_get_str(par_context), ", ", 2)				   ;
			
			return true_t;
}

bool_t
	c99_desc_func_arg_from_va
		(obj* par_context, u32_t par_count, va_list par) {
			if (trait_of(par_context) != c99_t)    return false_t;
			if (trait_of(par)		  != ap_obj_t) return false_t;

			for(u32_t it = 0 ; it < par_count ; ++it) {
				obj* arg = va_arg(par, obj*);

				__c99_desc_type   (c99_get_str(par_context), arg)	 ;
				__c99_desc_obj	  (c99_get_str(par_context), arg)    ;
				str_push_back_cstr(c99_get_str(par_context), ", ", 2);
			}

			return true_t;
}