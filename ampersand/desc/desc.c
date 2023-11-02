#include "desc.h"
#include "details/desc.h"

#include <ampersand/meta/type.h>
#include <ampersand/meta/func.h>
#include <ampersand/meta/obj.h>
#include <ampersand/meta/val.h>
#include <ampersand/meta/ops.h>
#include <ampersand/meta/script.h>

extern obj_trait* ap_desc_t = &__ap_desc_trait;

obj*
	ap_desc_ctx
		(obj* par) {
			if(trait_of(par) != ap_desc_t)
				return 0;

			return ((__ap_desc*)par)->ctx;
}

bool_t
	ap_desc_strt
		(obj* par, obj* par_type) {
			if (trait_of(par)      != ap_desc_t) return false_t;
			if (trait_of(par_type) != ap_type_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->ctx_ops->strt(desc, desc->ctx, par_type);
}

bool_t
	ap_desc_func
		(obj* par, obj* par_func) {
			if (trait_of(par)      != ap_desc_t) return false_t;
			if (trait_of(par_func) != ap_func_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->ctx_ops->func(desc, desc->ctx, par_func);
}

bool_t
	ap_desc_ops
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t) return false_t;
			if (trait_of(par_ops) != ap_ops_t)  return false_t;

			__ap_desc* desc = par;
			return	   desc->ctx_ops->ops(desc, desc->ctx, par_ops);
}

bool_t
	ap_desc_script
		(obj* par, obj* par_ops) {
			if (trait_of(par)     != ap_desc_t)   return false_t;
			if (trait_of(par_ops) != ap_script_t) return false_t;

			__ap_desc* desc = par;
			return	   desc->ctx_ops->script(desc, desc->ctx, par_ops);
}