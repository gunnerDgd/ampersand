#include "strt.h"
#include "details/desc.h"

#include <ampersand/meta/type.h>
#include <ampersand/meta/elem.h>

bool_t
	ap_desc_strt
		(obj* par, obj* par_type) {
			if (trait_of(par)      != ap_desc_t) return false_t;
			if (trait_of(par_type) != ap_type_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->run->strt.all(desc->ctx, par_type);
}

bool_t
	ap_desc_strt_begin
		(obj* par, str* par_name) {
			if (trait_of(par) != ap_desc_t) 
				return false_t;

			__ap_desc* desc = par;
			return	   desc->run->strt.begin(desc->ctx, par_name);
}

bool_t
	ap_desc_strt_begin_from_cstr
		(obj* par, const char* par_name, u64_t par_name_len) {
			if (trait_of(par) != ap_desc_t) 
				return false_t;

			__ap_desc* desc = par;
			return	   desc->run->strt.begin_from_cstr(desc->ctx, par_name, par_name_len);
}

bool_t
	ap_desc_strt_elem
		(obj* par, obj* par_elem) {
			if (trait_of(par)      != ap_desc_t) return false_t;
			if (trait_of(par_elem) != ap_elem_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->run->strt.elem(desc->ctx, par_elem);
}

bool_t
	ap_desc_strt_end
		(obj* par) {
			if (trait_of(par) != ap_desc_t) 
				return false_t;

			__ap_desc* desc = par;
			return	   desc->run->strt.end(desc->ctx);
}