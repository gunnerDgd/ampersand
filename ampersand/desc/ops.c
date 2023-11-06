#include "ops.h"
#include "details/desc.h"

#include <ampersand/meta/ops.h>

bool_t
	ap_desc_ops
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.all(desc->ctx, par_ops);
}

bool_t
	ap_desc_ops_arith
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.arith(desc->ctx, par_ops);
}

bool_t
	ap_desc_ops_bit
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.bit(desc->ctx, par_ops);
}

bool_t
	ap_desc_ops_cmp
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.cmp(desc->ctx, par_ops);
}

bool_t
	ap_desc_ops_logical
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.logical(desc->ctx, par_ops);
}

bool_t
	ap_desc_ops_func
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.func(desc->ctx, par_ops);
}

bool_t
	ap_desc_ops_push
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.push(desc->ctx, par_ops);
}

bool_t
	ap_desc_ops_pop
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->run->ops.pop(desc->ctx, par_ops);
}