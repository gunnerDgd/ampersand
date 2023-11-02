#include "script.h"

#include <ampersand/meta/script.h>
#include <ampersand/meta/details/script.h>

bool_t
	__c99_desc_script
		(str* par_str, obj* par) {
			if(trait_of(par) != ap_script_t) return false_t;

			it op     = ap_script_ops_begin(par),
			   op_end = ap_script_ops_end  (par);

			str_push_back_cstr(par_str, "{\n", 2);

			for( ; !it_eq(&op, &op_end) ; it_next(&op)) {
				if(!__c99_desc_ops(par_str, it_get(&op)))
					return false_t;

				str_push_back_cstr(par_str, ";\n", 2);
			}

			str_push_back_cstr(par_str, "}\n", 2);
			return true_t;
}