#include "script.h"
#include "details/script.h"

#include "ctx.h"
#include "details/ctx.h"

#include <ampersand/meta/script.h>

bool_t
	c99_desc_script
		(obj* par_desc, obj* par_context, obj* par) {
			if (trait_of(par_desc)    != ap_desc_t)   return false_t;
			if (trait_of(par_context) != c99_ctx_t)   return false_t;
			if (trait_of(par)		  != ap_script_t) return false_t;

			str ret;
			str_init(&ret, 0);

			if(!__c99_desc_script(&ret, par)) {
				str_deinit(&ret);
				return false_t;
			}

			str_push_back(&((__c99_ctx*)par_context)->ctx, &ret);
			return true_t;
}