#include "ops.h"
#include "details/ops.h"
#include "c99.h"

#include "details/obj.h"
#include "details/val.h"

#include <ampersand/meta/ops.h>
#include <ampersand/meta/obj.h>
#include <ampersand/meta/val.h>
#include <ampersand/meta/type.h>


bool_t
	c99_desc_ops
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t)    return false_t;
			if(trait_of(par)		 != ap_ops_t) return false_t;

			u64_t op = ap_ops_op(par);
			if (op >= ap_ops_add	 && op <= ap_ops_mod_eq)  return c99_desc_ops_arith  (par_context, par);
			if (op >= ap_ops_gt		 && op <= ap_ops_neq)	  return c99_desc_ops_cmp    (par_context, par);
			if (op >= ap_ops_log_and && op <= ap_ops_log_not) return c99_desc_ops_logical(par_context, par);
			if (op >= ap_ops_bit_and && op <= ap_ops_bit_not) return c99_desc_ops_bit	 (par_context, par);
			if (op >= ap_ops_call	 && op <= ap_ops_ret)     return c99_desc_ops_func   (par_context, par);

			return false_t;
}

bool_t
	c99_desc_ops_arg
		(obj* par_context, obj* par) {
			if (trait_of(par_context) != c99_t) return false_t;
			if (trait_of(par) == ap_obj_t)	    { 
				__c99_desc_obj(par_context, par);
				return true_t;
			}

			if (trait_of(par) == ap_val_t)		{ 
				__c99_desc_val(par_context, par);
				return true_t;
			}

			if (trait_of(par) == ap_ops_t)							 {
				str_push_back_cstr(c99_get_str(par_context), "(" , 1);
				c99_desc_ops	  (par_context, par)				 ; 
				str_push_back_cstr(c99_get_str(par_context), ")" , 1);

				return true_t;
			}

			return false_t;
			
}

bool_t
	c99_desc_ops_arith
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t)	  return false_t;
			if(trait_of(par)		 != ap_ops_t) return false_t;

			u64_t op	 = ap_ops_op	   (par);
			it    op_arg = ap_ops_arg_begin(par);

			if (op < ap_ops_add || op > ap_ops_mod_eq)
				return false_t;

			c99_desc_ops_arg(par_context, it_get(&op_arg)); __c99_desc_ops_arith(par_context, op); it_next(&op_arg);
			c99_desc_ops_arg(par_context, it_get(&op_arg));

			return true_t;
}

bool_t
	c99_desc_ops_bit
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t  )  return false_t;
			if(trait_of(par)		 != ap_ops_t) return false_t;

			u64_t op	 = ap_ops_op	   (par);
			it    op_arg = ap_ops_arg_begin(par);

			if (op < ap_ops_bit_and || op > ap_ops_bit_not)
				return false_t;

			if (op == ap_ops_bit_not) {
				__c99_desc_ops_bit(par_context, op)				;
				c99_desc_ops_arg  (par_context, it_get(&op_arg));

				return true_t;
				
			}

			c99_desc_ops_arg(par_context, it_get(&op_arg));  __c99_desc_ops_bit(par_context, op); it_next(&op_arg);
			c99_desc_ops_arg(par_context, it_get(&op_arg));

			return true_t;
}

bool_t
	c99_desc_ops_cmp
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t)    return false_t;
			if(trait_of(par)		 != ap_ops_t) return false_t;

			u64_t op	 = ap_ops_op	   (par);
			it    op_arg = ap_ops_arg_begin(par);

			if (op < ap_ops_gt || op > ap_ops_neq)
				return false_t;

			c99_desc_ops_arg(par_context, it_get(&op_arg));  __c99_desc_ops_cmp(par_context, op); it_next(&op_arg);
			c99_desc_ops_arg(par_context, it_get(&op_arg));

			return true_t;
}

bool_t
	c99_desc_ops_logical
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t)    return false_t;
			if(trait_of(par)		 != ap_ops_t) return false_t;

			u64_t op	 = ap_ops_op	   (par);
			it    op_arg = ap_ops_arg_begin(par);

			if (op < ap_ops_log_and || op > ap_ops_log_not)
				return false_t;
			if (op == ap_ops_log_not) {
				__c99_desc_ops_logical(par_context, op);
				c99_desc_ops_arg	  (par_context, it_get(&op_arg));

				return true_t;
			}

			c99_desc_ops_arg(par_context, it_get(&op_arg));  __c99_desc_ops_logical(par_context, op); it_next(&op_arg);
			c99_desc_ops_arg(par_context, it_get(&op_arg));

			return true_t;
}

bool_t
	c99_desc_ops_func
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t)    return false_t;
			if(trait_of(par)		 != ap_ops_t) return false_t;

			u64_t op		 = ap_ops_op	   (par);
			it    op_arg	 = ap_ops_arg_begin(par),
				  op_arg_end = ap_ops_arg_end  (par);

			if (op < ap_ops_call || op > ap_ops_ret)
				return false_t;

			if (op == ap_ops_call) {
				str_push_back(c99_get_str(par_context), name_of(it_get(&op_arg)));
				it_next	     (&op_arg);

				for ( ; !it_eq(&op_arg, &op_arg_end) ; it_next(&op_arg)) {
					if (!c99_desc_ops_arg(par_context, it_get(&op_arg)))
						return false_t;

					str_push_back_cstr(c99_get_str(par_context), ", ", 2);
				}

				return true_t;
			}

			str_push_back_cstr(c99_get_str(par_context), "return ", 7);
			c99_desc_ops_arg  (par_context, it_get(&op_arg))				  ;
			
			return true_t;
}

bool_t
	c99_desc_ops_push
		(obj* par_context, obj* par) {
			if(trait_of(par_context) != c99_t)    return false_t;
			if(trait_of(par)		 != ap_ops_t) return false_t;

			u64_t op		 = ap_ops_op	   (par);
			it    op_arg	 = ap_ops_arg_begin(par),
				  op_arg_end = ap_ops_arg_end  (par);

			obj  *push	     = it_get	  (&op_arg),
				 *push_type  = ap_obj_type(push)   ;

			it_next		 (&op_arg);
			str_push_back(c99_get_str(par_context), name_of(push_type));
			str_push_back(c99_get_str(par_context), name_of(push))	   ;

			
			if (it_eq(&op_arg, &op_arg_end))
				return true_t;

			str_push_back_cstr(c99_get_str(par_context), " = ", 3);
			if(ap_type_idx(push_type) == ap_type_strt)						   {
				str_push_back_cstr(c99_get_str(par_context), " {\n", 2);

				it elem		= ap_type_elem_begin(push_type),
				   elem_end = ap_type_elem_end  (push_type);

				for ( ; !it_eq(&elem, &elem_end) && !it_eq(&op_arg, &op_arg_end) ; it_next(&elem), it_next(&op_arg)) {
					str_push_back_cstr(c99_get_str(par_context), "."  , 1)				;
					str_push_back	  (c99_get_str(par_context), name_of(it_get(&elem)));
					str_push_back_cstr(c99_get_str(par_context), " = ", 3)				;
					c99_desc_ops_arg  (par_context, it_get(&op_arg))							;
					str_push_back_cstr(c99_get_str(par_context), ",\n", 2)				;
				}

				str_push_back_cstr(c99_get_str(par_context), " }\n", 2);
				return true_t;
			}

			c99_desc_ops_arg(c99_get_str(par_context), it_get(&op_arg));
			return true_t;
}

bool_t
	c99_desc_ops_pop
		(obj* par_context, obj* par) {
			return true_t;
}

bool_t
	c99_desc_ops_end
		(obj* par_context) {
			str_push_back_cstr(c99_get_str(par_context), ";\n", 2);
			return true_t;
}