#include "type.h"

#include <ampersand/meta/elem.h>
#include <ampersand/meta/type.h>


bool_t
	__c99_desc_type
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_type_t) return false_t;
			switch(ap_type_idx(par)) {
				case ap_type_i8  : str_push_back_cstr(par_str, "char "	   , 5) ; break;
				case ap_type_i16 : str_push_back_cstr(par_str, "short "	   , 6) ; break;
				case ap_type_i32 : str_push_back_cstr(par_str, "int "	   , 4) ; break;
				case ap_type_i64 : str_push_back_cstr(par_str, "long long ", 10); break;

				case ap_type_u8  : str_push_back_cstr(par_str, "unsigned char "	    , 14); break;
				case ap_type_u16 : str_push_back_cstr(par_str, "unsigned short "    , 15); break;
				case ap_type_u32 : str_push_back_cstr(par_str, "unsigned int "	    , 13); break;
				case ap_type_u64 : str_push_back_cstr(par_str, "unsigned long long ", 19); break;

				case ap_type_f32 : str_push_back_cstr(par_str, "float " , 6); break;
				case ap_type_f64 : str_push_back_cstr(par_str, "double ", 7); break;

				case ap_type_none: str_push_back_cstr(par_str, "void "  , 5); break;
				case ap_type_strt: str_push_back_cstr(par_str, "struct ", 7);
								   str_push_back	 (par_str, name_of(par));
								   str_push_back_cstr(par_str, " ", 1)		;
								   break;
			}

			return true_t;
}