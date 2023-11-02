#ifndef AMPERSAND_META_DETAILS_OPS_H
#define AMPERSAND_META_DETAILS_OPS_H

#include <ampersand/base/list.h>

#define __ap_ops_none		 0
#define __ap_ops_err		-1

#define __ap_ops_add	  	 1
#define __ap_ops_add_eq		 2

#define __ap_ops_sub		 3
#define __ap_ops_sub_eq		 4

#define __ap_ops_mul		 5
#define __ap_ops_mul_eq		 6

#define __ap_ops_div		 7
#define __ap_ops_div_eq		 8

#define __ap_ops_mod		 9
#define __ap_ops_mod_eq		 10

#define __ap_ops_gt			 11
#define __ap_ops_gt_eq		 12

#define __ap_ops_lt			 13
#define __ap_ops_lt_eq		 14

#define __ap_ops_eq			 15
#define __ap_ops_neq		 16

#define __ap_ops_log_and	 17
#define __ap_ops_log_or 	 18
#define __ap_ops_log_not	 19

#define __ap_ops_bit_and     20
#define __ap_ops_bit_and_eq  21
#define __ap_ops_bit_or      22
#define __ap_ops_bit_or_eq   23
#define __ap_ops_bit_xor     24
#define __ap_ops_bit_xor_eq  25
#define __ap_ops_bit_not     26

#define __ap_ops_push		 27
#define __ap_ops_pop	     28
#define __ap_ops_bind		 29

#define __ap_ops_call		 30
#define __ap_ops_ret		 31

#define __ap_ops_cond_if	 32
#define __ap_ops_cond_elif	 33
#define __ap_ops_cond_else	 34

#define __ap_ops_loop_while	 35
#define __ap_ops_loo_for	 36

#define __ap_ops_ref		 37

extern obj_trait __ap_ops_trait;
typedef struct   __ap_ops	   {
	obj   head  ;
	u64_t op    ;
	list  op_arg;
}	__ap_ops;

bool_t
	__ap_ops_init
		(__ap_ops*, u32_t, va_list);

bool_t
	__ap_ops_init_as_clone
		(__ap_ops*, __ap_ops*);

bool_t
	__ap_ops_init_as_ref
		(__ap_ops*);

void
	__ap_ops_deinit
		(__ap_ops*);

u64_t
	__ap_ops_size
		();

#endif