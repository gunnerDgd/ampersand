#include "c99.h"
#include "details/c99.h"

#include "func.h"
#include "ops.h"
#include "script.h"
#include "strt.h"

ap_desc_run c99_run_impl_t = {
	.strt				   = {
		.all			 = &c99_desc_strt				 ,
		.begin			 = &c99_desc_strt_begin			 ,
		.begin_from_cstr = &c99_desc_strt_begin_from_cstr,
		.elem			 = &c99_desc_strt_elem			 ,
		.end			 = &c99_desc_strt_end
	},

	.ops = {
		.all     = &c99_desc_ops	    ,
		.arith   = &c99_desc_ops_arith  ,
		.bit     = &c99_desc_ops_bit    ,
		.cmp     = &c99_desc_ops_cmp    ,
		.func    = &c99_desc_ops_func   ,
		.logical = &c99_desc_ops_logical,
		.push	 = &c99_desc_ops_push   ,
		.pop     = &c99_desc_ops_pop    ,
		.end     = &c99_desc_ops_end
	},

	.func = {
		.all	   = &c99_desc_func			 ,
		.arg_begin = 0,
		.arg	   = &c99_desc_func_arg      ,
		.arg_end   = 0  ,
		.ret	   = &c99_desc_func_ret
	},

	.script = &c99_desc_script
};

obj_trait   *c99_t     = &__c99_trait     ;
ap_desc_run *c99_run_t = &  c99_run_impl_t;

str*
	c99_get_str
		(obj* par) {
			if(trait_of(par) != c99_t)
				return false_t;

			return &((__c99*)par)->str;
}