#include "func.h"
#include "details/func.h"

obj_trait* ap_func_t = &__ap_func_trait;

obj*
	ap_func_script
		(obj* par) {
			if(trait_of(par) != ap_func_t)
				return 0;

			return ((__ap_func*)par)->script;
}

obj*
	ap_func_ret
		(obj* par) {
			if(trait_of(par) != ap_func_t)
				return 0;

			return ((__ap_func*)par)->ret;
}

it
	ap_func_arg_begin
		(obj* par) {
			if(trait_of(par) != ap_func_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_begin(&((__ap_func*)par)->arg);
}

it
	ap_func_arg_end
		(obj* par) {
			if(trait_of(par) != ap_func_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_end(&((__ap_func*)par)->arg);
}

obj*
	ap_func_strt
		(obj* par) {
			if(trait_of(par) != ap_func_t)
				return 0;

			return ((__ap_func*)par)->strt;
}