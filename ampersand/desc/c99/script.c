#include "script.h"
#include "c99.h"

#include "ops.h"
#include <ampersand/meta/script.h>

bool_t
	c99_desc_script
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t)       return false_t;
			if(trait_of(par)		 != ap_script_t) return false_t;

			it op     = ap_script_ops_begin(par),
			   op_end = ap_script_ops_end  (par);

			str_push_back_cstr(c99_get_str(par_context), "{\n", 2);

			for( ; neq(op, op_end) ; next(op))		    {
				c99_desc_ops	  (par_context, get(op));
				c99_desc_ops_end  (par_context)		    ;
			}

			str_push_back_cstr(c99_get_str(par_context), "}\n", 2);
			return true_t;
}