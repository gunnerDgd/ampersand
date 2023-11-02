#include "func.h"
#include "details/func.h"

#include <ampersand/meta/func.h>
#include "../desc.h"
#include "ctx.h"

bool_t
	c99_desc_func
		(obj* par_desc, obj* par_context, obj* par) {
			if (trait_of(par_desc)    != ap_desc_t) return false_t;
			if (trait_of(par_context) != c99_ctx_t) return false_t;
			if (trait_of(par)		  != ap_func_t) return false_t;

			str ret;
			str_init(&ret, 0);

			if(!__c99_desc_func(&ret, par)) {
				str_deinit(&ret);
				return false_t;
			}
			
			str_deinit(&ret);
			return true_t;
}