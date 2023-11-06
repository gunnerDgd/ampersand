#include "func.h"
#include "details/desc.h"

#include <ampersand/meta/script.h>
#include <ampersand/meta/func.h>
#include <ampersand/meta/type.h>

bool_t
	ap_desc_func
		(obj* par, obj* par_func) {
			if (trait_of(par)      != ap_desc_t) return false_t;
			if (trait_of(par_func) != ap_func_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->run->func.all(desc->ctx, par_func);
}

bool_t
	ap_desc_func_ret
		(obj* par, obj* par_ret) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ret) != ap_type_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->run->func.ret(desc->ctx, par_ret);
}

bool_t
	ap_desc_func_arg
		(obj* par, obj* par_arg) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_arg) != ap_type_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->run->func.arg(desc->ctx, par_arg);
}

bool_t
	ap_desc_func_arg_begin
		(obj* par) {
			if (trait_of(par) != ap_desc_t) 
				return false_t;

			__ap_desc* desc = par;
			return	   desc->run->func.arg_begin(desc->ctx);
}


bool_t
	ap_desc_func_arg_end
		(obj* par) {
			if (trait_of(par) != ap_desc_t) 
				return false_t;

			__ap_desc* desc = par;
			return	   desc->run->func.arg_end(desc->ctx);
}
