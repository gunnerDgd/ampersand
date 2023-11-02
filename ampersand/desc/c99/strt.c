#include "strt.h"
#include "details/strt.h"

#include "ctx.h"

#include <ampersand/meta/elem.h>
#include <ampersand/meta/type.h>

bool_t
	c99_desc_strt
		(obj* par_desc, obj* par_context, obj* par) {
			if(trait_of(par_desc)    != ap_desc_t)    return false_t;
			if(trait_of(par_context) != c99_ctx_t)    return false_t;
		
			if(trait_of(par)		 != ap_type_t)    return false_t;
			if(ap_type_idx(par)      != ap_type_strt) return false_t;
		
			str ret;
			str_init(&ret, 0);

			if(!__c99_desc_strt(&ret, par)) {
				str_deinit(&ret);
				return false_t;
			}

			str_push_back(&((__c99_ctx*)par_context)->ctx, &ret);
			return true_t;
}