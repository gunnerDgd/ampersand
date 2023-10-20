#include "strt.h"
#include "details/desc.h"

#include <ampersand/meta/elem.h>
#include <ampersand/meta/type.h>

bool_t
	c99_strt_begin
		(obj* par, str* par_name) {
			if(trait_of(par) != c99_desc_t)
				return false_t;

			str_push_back_cstr(&((__c99_desc*)par)->ctx, "struct ", 7);
			str_push_back	  (&((__c99_desc*)par)->ctx, par_name)	  ;
			str_push_back_cstr(&((__c99_desc*)par)->ctx, " {\n", 3)	  ;

			return true_t;
}

bool_t
	c99_strt_end
		(obj* par) {
			if(trait_of(par) != c99_desc_t)
				return false_t;

			str_push_back_cstr(&((__c99_desc*)par)->ctx, "};\n\n", 4);
			return true_t;
}

bool_t
	c99_strt_elem
		(obj* par, obj* par_elem)	   {
			if(trait_of(par)      != c99_desc_t) return false_t;
			if(trait_of(par_elem) != ap_elem_t)  return false_t;

			obj* elem_type = ap_elem_type(par_elem);
			switch(ap_type_idx(elem_type)) {
				case ap_type_i8  : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tchar "	  , 6) ; break;
				case ap_type_i16 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tshort "	  , 7) ; break;
				case ap_type_i32 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tint "      , 5) ; break;
				case ap_type_i64 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tlong long ", 11); break;

				case ap_type_u8  : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tunsigned char "	   , 16); break;
				case ap_type_u16 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tunsigned short "	   , 17); break;
				case ap_type_u32 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tunsigned int "      , 15); break;
				case ap_type_u64 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tunsigned long long ", 21); break;

				case ap_type_f32 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tfloat " , 7); break;
				case ap_type_f64 : str_push_back_cstr(&((__c99_desc*)par)->ctx, "\tdouble ", 8); break;
				case ap_type_strt: 
					str_push_back_cstr(&((__c99_desc*)par)->ctx, "\t ", 1);
					str_push_back	  (&((__c99_desc*)par)->ctx, name_of(elem_type)); break;
			}

			str_push_back	  (&((__c99_desc*)par)->ctx, name_of(par_elem));
			str_push_back_cstr(&((__c99_desc*)par)->ctx, ";\n", 2)		   ;

			return true_t;
}

bool_t
	c99_desc_strt
		(obj* par, obj* par_strt) {
			if (trait_of(par)	      != c99_desc_t)   return false_t;
			if (trait_of(par_strt)    != ap_type_t)    return false_t;
			if (ap_type_idx(par_strt) != ap_type_strt) return false_t;

			if (!c99_strt_begin(par, name_of(par_strt))) return false_t;

			it i     = ap_type_elem_begin(par_strt),
			   i_end = ap_type_elem_end  (par_strt);

			for (; !it_eq(&i, &i_end); it_next(&i))
				if (!c99_strt_elem(par, it_get(&i))) return false_t;

			if (!c99_strt_end(par)) return false_t;
			return true_t;
}