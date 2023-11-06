#include "ops.h"
#include <ampersand/meta/ops.h>

bool_t
	__c99_desc_ops_arith
		(str* par_str, u64_t par) {
			switch (par)		  {
				case ap_ops_add   : str_push_back_cstr(par_str, " + ",  3); break;
				case ap_ops_add_eq: str_push_back_cstr(par_str, " += ", 4); break;
				case ap_ops_sub	  : str_push_back_cstr(par_str, " - " , 3); break;
				case ap_ops_sub_eq: str_push_back_cstr(par_str, " -= ", 4); break;
				case ap_ops_mul	  : str_push_back_cstr(par_str, " * " , 3); break;
				case ap_ops_mul_eq: str_push_back_cstr(par_str, " *= ", 4); break;
				case ap_ops_div   : str_push_back_cstr(par_str, " / " , 3); break;
				case ap_ops_div_eq: str_push_back_cstr(par_str, " /= ", 4); break;
				case ap_ops_mod	  : str_push_back_cstr(par_str, " % " , 3); break;
				case ap_ops_mod_eq: str_push_back_cstr(par_str, " %= ", 4); break;
				default			  : return false_t;
			}

			return true_t;
}

bool_t
	__c99_desc_ops_logical
		(str* par_str, u64_t par)  {
			switch (par)		   {
				case ap_ops_log_and: str_push_back_cstr(par_str, " && ", 4); break;
				case ap_ops_log_or : str_push_back_cstr(par_str, " || ", 4); break;
				case ap_ops_log_not: str_push_back_cstr(par_str, " ! " , 2); break;
				default			   : return false_t;
			}

			return true_t;
}

bool_t
	__c99_desc_ops_cmp
		(str* par_str, u64_t par) {
			switch (par)		  {
				case ap_ops_gt   : str_push_back_cstr(par_str, " > " , 3); break;
				case ap_ops_gt_eq: str_push_back_cstr(par_str, " >= ", 4); break;
				case ap_ops_lt   : str_push_back_cstr(par_str, " < " , 3); break;
				case ap_ops_lt_eq: str_push_back_cstr(par_str, " <= ", 4); break;
				case ap_ops_eq   : str_push_back_cstr(par_str, " == ", 4); break;
				case ap_ops_neq  : str_push_back_cstr(par_str, " != ", 4); break;
			}

			return true_t;
}

bool_t
	__c99_desc_ops_bit
		(str* par_str, u64_t par)	  {
			switch (par)			  {
				case ap_ops_bit_and   : str_push_back_cstr(par_str, " & ",  3); break;
				case ap_ops_bit_and_eq: str_push_back_cstr(par_str, " &= ", 4); break;
				case ap_ops_bit_or	  : str_push_back_cstr(par_str, " | " , 3); break;
				case ap_ops_bit_or_eq : str_push_back_cstr(par_str, " |= ", 4); break;
				case ap_ops_bit_xor	  : str_push_back_cstr(par_str, " ^ " , 3); break;
				case ap_ops_bit_xor_eq: str_push_back_cstr(par_str, " ^= ", 4); break;
				case ap_ops_bit_not   : str_push_back_cstr(par_str, " ~ " , 3); break;
				default				  : return false_t;
			}

			return true_t;
}