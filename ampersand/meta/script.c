#include "script.h"
#include "details/script.h"

obj_trait* ap_script_t = &__ap_script_trait;

it
	ap_script_ops_begin
		(obj* par) {
			if(trait_of(par) != ap_script_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_begin(&((__ap_script*)par)->ops);
}

it
	ap_script_ops_end
		(obj* par) {
			if(trait_of(par) != ap_script_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_end(&((__ap_script*)par)->ops);
}