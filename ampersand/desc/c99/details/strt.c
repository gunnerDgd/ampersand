#include "strt.h"

#include <ampersand/meta/elem.h>
#include <ampersand/meta/details/elem.h>

#include <ampersand/meta/type.h>
#include <ampersand/meta/details/type.h>

bool_t
	__c99_desc_strt_elem
		(str* par_str, obj* par) {
			if(trait_of(par) != ap_elem_t) return false_t;

			obj* par_t = ap_elem_type(par);
			switch(ap_type_idx(par_t))    {
				case ap_type_i8  : str_push_back_cstr(par_str, "\tchar "	 , 6) ; break;
				case ap_type_i16 : str_push_back_cstr(par_str, "\tshort "	 , 7) ; break;
				case ap_type_i32 : str_push_back_cstr(par_str, "\tint "      , 5) ; break;
				case ap_type_i64 : str_push_back_cstr(par_str, "\tlong long ", 11); break;

				case ap_type_u8  : str_push_back_cstr(par_str, "\tunsigned char "	  , 16); break;
				case ap_type_u16 : str_push_back_cstr(par_str, "\tunsigned short "	  , 17); break;
				case ap_type_u32 : str_push_back_cstr(par_str, "\tunsigned int "      , 15); break;
				case ap_type_u64 : str_push_back_cstr(par_str, "\tunsigned long long ", 21); break;

				case ap_type_f32 : str_push_back_cstr(par_str, "\tfloat " , 7); break;
				case ap_type_f64 : str_push_back_cstr(par_str, "\tdouble ", 8); break;
				case ap_type_strt: str_push_back_cstr(par_str, "\t ", 1);
								   str_push_back     (par_str, name_of(par_t));
								   str_push_back_cstr(par_str, " ", 1);

								   break;
			}

			str_push_back     (par_str, name_of(par));
			str_push_back_cstr(par_str, ";\n", 2)    ;
			return true_t;
}

bool_t
	__c99_desc_strt
		(str* par_str, obj* par) {
			if (trait_of(par)    != ap_type_t)    return false_t;
			if (ap_type_idx(par) != ap_type_strt) return false_t;

			str_push_back_cstr(par_str, "struct ", 8);
			str_push_back	  (par_str, name_of(par));
			str_push_back_cstr(par_str, " {\n", 3)   ;

			it i     = ap_type_elem_begin(par),
			   i_end = ap_type_elem_end  (par);

			for (; !it_eq(&i, &i_end); it_next(&i))
				if (!__c99_desc_strt_elem(par_str, it_get(&i))) 
					return false_t;

			str_push_back_cstr(par_str, "};\n", 3);
			return true_t;
}