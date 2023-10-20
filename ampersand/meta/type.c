#include "type.h"
#include "details/type.h"

#include <string.h>

obj_trait* ap_type_t = &__ap_type_trait;

u64_t
	ap_type_idx
		(obj* par) {
			if(trait_of(par) != ap_type_t)
				return -1;

			return ((__ap_type*)par)->idx;
}

it
	ap_type_elem_begin
		(obj* par) {
			if(trait_of(par) != ap_type_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_begin(&((__ap_type*)par)->elem);
}

it
	ap_type_elem_end
		(obj* par) {
			if(trait_of(par) != ap_type_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_end(&((__ap_type*)par)->elem);
}