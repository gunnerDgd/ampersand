#include "ops.h"
#include "details/ops.h"

obj_trait* ap_ops_t = &__ap_ops_trait;

u64_t
	ap_ops_op
		(obj* par) {
			if(trait_of(par) != ap_ops_t)
				return ap_ops_err;

			return ((__ap_ops*)par)->op;
}

it
	ap_ops_arg_begin
		(obj* par) {
			if (trait_of(par) != ap_ops_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_begin(&((__ap_ops*)par)->op_arg);
}

it
	ap_ops_arg_end
		(obj* par) {
			if (trait_of(par) != ap_ops_t) {
				it	   ret = { .it = { 0, 0, 0, 0 } };
				return ret;
			}

			return list_end(&((__ap_ops*)par)->op_arg);
}