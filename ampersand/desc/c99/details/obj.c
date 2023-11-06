#include "obj.h"
#include <ampersand/meta/obj.h>

bool_t
	__c99_desc_obj
		(str* par_str, obj* par) {
			if(trait_of(par) != ap_obj_t) return false_t;

			str_push_back	  (par_str, name_of(par));
			str_push_back_cstr(par_str, " ", 1)		 ;
			return true_t;
}