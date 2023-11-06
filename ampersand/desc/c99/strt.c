#include "strt.h"
#include "c99.h"

#include "details/type.h"
#include "details/obj.h"

#include <ampersand/meta/elem.h>
#include <ampersand/meta/type.h>

bool_t
	c99_desc_strt
		(obj* par_context, obj* par) {
			if (trait_of(par_context) != c99_t)        return false_t;
			if (trait_of(par)		  != ap_type_t)    return false_t;
			if (ap_type_idx(par)	  != ap_type_strt) return false_t;

			if (!c99_desc_strt_begin(par_context, name_of(par))) return false_t;
			it elem	    = ap_type_elem_begin(par),
			   elem_end = ap_type_elem_end  (par);

			for ( ; neq(elem, elem_end) ; next(elem))
				if (!c99_desc_strt_elem(par_context, get(elem)))
					return false_t;

			c99_desc_strt_end(par_context);
			return true_t;
}

bool_t
	c99_desc_strt_begin
		(obj* par_context, str* par_name) {
			if (trait_of(par_context) != c99_t) 
				return false_t;
			
			str_push_back_cstr(c99_get_str(par_context), "struct ", 7);
			str_push_back	  (c99_get_str(par_context), par_name)	  ;
			str_push_back_cstr(c99_get_str(par_context), "{\n"    , 2);
			return true_t;
}

bool_t
	c99_desc_strt_begin_from_cstr
		(obj* par_context, const char* par, u64_t par_len) {
			if (trait_of(par_context) != c99_t) 
				return false_t;

			str_push_back_cstr(c99_get_str(par_context), par, par_len);
			return true_t;
}

bool_t
	c99_desc_strt_elem
		(obj* par_context, obj* par) {
			if (trait_of(par_context) != c99_t)     return false_t;
			if (trait_of(par)		  != ap_elem_t) return false_t;

			__c99_desc_type   (c99_get_str(par_context), ap_elem_type(par));
			str_push_back     (c99_get_str(par_context), name_of(par))	   ;
			str_push_back_cstr(c99_get_str(par_context), ";\n", 2)		   ;

			return true_t;
}

bool_t
	c99_desc_strt_end
		(obj* par) {
			if (trait_of(par) != c99_t) return false_t;
			str_push_back_cstr(c99_get_str(par), "};\n", 3);

			return true_t;
}