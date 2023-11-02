#include "ops.h"

#include "../../../meta/type.h"
#include "../../../meta/elem.h"
#include "../../../meta/obj.h"
#include "../../../meta/val.h"
#include "../../../meta/ops.h"
#include "../../../meta/func.h"

#include "../../../meta/details/ops.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

bool_t (*__c99_desc_ops_tbl[])(str*, obj*)      = {
	[__ap_ops_add]        = __c99_desc_ops_arith  ,
	[__ap_ops_add_eq]     = __c99_desc_ops_arith  ,
	[__ap_ops_sub]        = __c99_desc_ops_arith  ,
	[__ap_ops_sub_eq]     = __c99_desc_ops_arith  ,
	[__ap_ops_mul]        = __c99_desc_ops_arith  ,
	[__ap_ops_mul_eq]     = __c99_desc_ops_arith  ,
	[__ap_ops_div]        = __c99_desc_ops_arith  ,
	[__ap_ops_div_eq]     = __c99_desc_ops_arith  ,
	[__ap_ops_mod]        = __c99_desc_ops_arith  ,
	[__ap_ops_mod_eq]     = __c99_desc_ops_arith  ,

	[__ap_ops_gt]         = __c99_desc_ops_cmp    ,
	[__ap_ops_gt_eq]      = __c99_desc_ops_cmp    ,
	[__ap_ops_lt]         = __c99_desc_ops_cmp    ,
	[__ap_ops_lt_eq]      = __c99_desc_ops_cmp    ,
	[__ap_ops_eq]         = __c99_desc_ops_cmp    ,
	[__ap_ops_neq]		  = __c99_desc_ops_cmp    ,

	[__ap_ops_log_and]    = __c99_desc_ops_logical,
	[__ap_ops_log_or]     = __c99_desc_ops_logical,
	[__ap_ops_log_not]    = __c99_desc_ops_logical,

	[__ap_ops_bit_and]    = __c99_desc_ops_bit    ,
	[__ap_ops_bit_and_eq] = __c99_desc_ops_bit    ,
	[__ap_ops_bit_or]     = __c99_desc_ops_bit    ,
	[__ap_ops_bit_or_eq]  = __c99_desc_ops_bit    ,
	[__ap_ops_bit_xor]    = __c99_desc_ops_bit    ,
	[__ap_ops_bit_xor_eq] = __c99_desc_ops_bit    ,
	[__ap_ops_bit_not]    = __c99_desc_ops_bit    ,

	[__ap_ops_push]		  = __c99_desc_ops_obj    ,
	[__ap_ops_pop]		  = __c99_desc_ops_obj    ,
	[__ap_ops_bind]		  = __c99_desc_ops_obj    ,

	[__ap_ops_call]		  = __c99_desc_ops_func   ,
	[__ap_ops_ret]		  = __c99_desc_ops_func   ,
};

bool_t
	__c99_desc_ops
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_ops_t)  return false_t;

			u64_t  op = ap_ops_op(par);
			if (!__c99_desc_ops_tbl[op](par_str, par))
				return false_t;

			return __c99_desc_ops_tbl[op](par_str, par);
}

bool_t
	__c99_desc_ops_arg
		(str* par_str, obj* par) {
			__c99_ctx* desc = par;

			if(trait_of(par) == ap_val_t)		   {
				u64_t val_t      = ap_val_type(par);
				char  val  [255] =		  { 0x00, };

				if      (val_t == ap_type_f32) sprintf(par_str, "%f"  , ap_val_as_f32(par));
				else if (val_t == ap_type_f64) sprintf(par_str, "%lf" , ap_val_as_f64(par));
				else						   sprintf(par_str, "%lld", ap_val_as_int(par));

				str_push_back_cstr(par_str, val, strlen(val));
				return true_t;
			}

			if (trait_of(par) == ap_obj_t)			{
				str_push_back(par_str, name_of(par));
				return true_t;
			}

			if(trait_of(par) == ap_ops_t)
				return __c99_desc_ops(par_str, par);

			return false_t;
}

bool_t
	__c99_desc_ops_arith
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_ops_t) return false_t;
			
			__ap_ops *ops = par;
			if (ops->op < __ap_ops_add || ops->op > __ap_ops_mod_eq)
				return false_t;

			it op_arg = list_begin(&ops->op_arg);
			str_push_back_cstr(par_str, "(", 1);

			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg))) return false_t;
			switch (ops->op)		{
				case __ap_ops_add   : str_push_back_cstr(par_str, " + ",  3); break;
				case __ap_ops_add_eq: str_push_back_cstr(par_str, " += ", 4); break;
				case __ap_ops_sub	: str_push_back_cstr(par_str, " - " , 3); break;
				case __ap_ops_sub_eq: str_push_back_cstr(par_str, " -= ", 4); break;
				case __ap_ops_mul	: str_push_back_cstr(par_str, " * " , 3); break;
				case __ap_ops_mul_eq: str_push_back_cstr(par_str, " *= ", 4); break;
				case __ap_ops_div   : str_push_back_cstr(par_str, " / " , 3); break;
				case __ap_ops_div_eq: str_push_back_cstr(par_str, " /= ", 4); break;
				case __ap_ops_mod	: str_push_back_cstr(par_str, " % " , 3); break;
				case __ap_ops_mod_eq: str_push_back_cstr(par_str, " %= ", 4); break;
			}

			it_next(&op_arg);
			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg)))
				return false_t;

			str_push_back(par_str, ")", 1);
			return true_t;
}

bool_t
	__c99_desc_ops_bit
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_ops_t) return false_t;

			__ap_ops *ops = par;
			if (ops->op < __ap_ops_bit_and || ops->op > __ap_ops_bit_not)
				return false_t;

			it op_arg = list_begin(&ops->op_arg);
			str_push_back_cstr(par_str, "(", 1);
			
			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg))) return false_t;
			switch (ops->op)		    {
				case __ap_ops_bit_and   : str_push_back_cstr(par_str, " & ",  3); break;
				case __ap_ops_bit_and_eq: str_push_back_cstr(par_str, " &= ", 4); break;
				case __ap_ops_bit_or	: str_push_back_cstr(par_str, " | " , 3); break;
				case __ap_ops_bit_or_eq : str_push_back_cstr(par_str, " |= ", 4); break;
				case __ap_ops_bit_xor	: str_push_back_cstr(par_str, " ^ " , 3); break;
				case __ap_ops_bit_xor_eq: str_push_back_cstr(par_str, " ^= ", 4); break;
				case __ap_ops_bit_not   : str_push_back_cstr(par_str, " ~ " , 3); break;
			}

			it_next(&op_arg);
			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg)))
				return false_t;

			str_push_back(par_str, ")", 1);
			return true_t;
}

bool_t
	__c99_desc_ops_cmp
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_ops_t) return false_t;

			__ap_ops *ops = par;
			if (ops->op < __ap_ops_gt || ops->op > __ap_ops_neq)
				return false_t;

			it op_arg = list_begin(&ops->op_arg);
			str_push_back_cstr(par_str, "(", 1);

			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg))) return false_t;
			switch (ops->op)	   {
				case __ap_ops_gt   : str_push_back_cstr(par_str, " > " , 3); break;
				case __ap_ops_gt_eq: str_push_back_cstr(par_str, " >= ", 4); break;
				case __ap_ops_lt   : str_push_back_cstr(par_str, " < " , 3); break;
				case __ap_ops_lt_eq: str_push_back_cstr(par_str, " <= ", 4); break;
				case __ap_ops_eq   : str_push_back_cstr(par_str, " == ", 4); break;
				case __ap_ops_neq  : str_push_back_cstr(par_str, " != ", 4); break;
			}

			it_next(&op_arg);
			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg)))
				return false_t;

			str_push_back_cstr(par_str, ")", 1) ;
			return true_t;
}

bool_t
	__c99_desc_ops_logical
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_ops_t) return false_t;

			__ap_ops *ops = par;
			if (ops->op < __ap_ops_add || ops->op > __ap_ops_mod_eq)
				return false_t;

			it op_arg = list_begin(&ops->op_arg);
			str_push_back_cstr(par_str, "(", 1);

			if(ops->op == __ap_ops_log_not)        {
				str_push_back_cstr(par_str, "!", 1);
				if (!__c99_desc_ops_arg(par_str, it_get(&op_arg)))
					return false_t;

				str_push_back_cstr(par_str, ")", 1);
				return true_t;
			}

			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg)))
				return false_t;

			switch (ops->op)		  {
				case __ap_ops_log_and : str_push_back_cstr(par_str, " && ", 4); break;
				case __ap_ops_log_or  : str_push_back_cstr(par_str, " || ", 4); break;
			}

			it_next(&op_arg);
			if (!__c99_desc_ops_arg(par_str, it_get(&op_arg)))
				return false_t;

			str_push_back_cstr(par_str, ")", 1) ;
			return true_t;
}

bool_t
	__c99_desc_ops_push
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_ops_t) return false_t;
}

bool_t
	__c99_desc_ops_func
		(str* par_str, obj* par) {
			if (trait_of(par) != ap_ops_t) return false_t;

			__ap_ops *ops = par;
			if (ops->op != __ap_ops_call && ops->op != __ap_ops_ret)
				return false_t;
			
			switch(ops->op)			{
				case __ap_ops_call: {
					it   ops_arg	 = list_begin(&ops->op_arg),
						 ops_arg_end = list_end  (&ops->op_arg);
					obj *func        = it_get    (&ops_arg)    ; it_next(&ops_arg);
					
					if (!func || trait_of(func) != ap_func_t)
						return false_t;

					str_push_back	  (par_str, name_of(func));
					str_push_back_cstr(par_str, "(", 1)		;

					for ( ; !it_eq(&ops_arg, &ops_arg_end) ; it_next(&ops_arg)) {
						if (!__c99_desc_ops_arg(par_str, it_get(&ops_arg)))
							return false_t;

						str_push_back_cstr(par_str, ", ", 2);
					}

					break;
				}
				case __ap_ops_ret : {
					it   ops_arg_it = list_begin(&ops->op_arg);
					obj *ops_arg    = it_get	(&ops_arg_it) ;

					str_push_back(par_str, "return ");
					
					if(ops_arg)
						if (!__c99_desc_ops_arg(par_str, it_get(&ops_arg)))
							return false_t;
					
					break;
				}
				default: return false_t;
			}

			return true_t;
}