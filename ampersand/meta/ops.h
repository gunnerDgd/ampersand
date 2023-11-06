#ifndef AMPERSAND_META_OPS_H
#define AMPERSAND_META_OPS_H

#include <ampersand/base/obj.h>
#include <ampersand/base/it.h>

#define ap_ops_none		   0
#define ap_ops_err		  -1

#define ap_ops_add	  	   1
#define ap_ops_add_eq	   2

#define ap_ops_sub		   3
#define ap_ops_sub_eq	   4

#define ap_ops_mul		   5
#define ap_ops_mul_eq	   6

#define ap_ops_div		   7
#define ap_ops_div_eq	   8

#define ap_ops_mod		   9
#define ap_ops_mod_eq	   10

#define ap_ops_gt		   11
#define ap_ops_gt_eq	   12

#define ap_ops_lt		   13
#define ap_ops_lt_eq	   14

#define ap_ops_eq		   15
#define ap_ops_neq		   16

#define ap_ops_log_and	   17
#define ap_ops_log_or 	   18
#define ap_ops_log_not	   19

#define ap_ops_bit_and     20
#define ap_ops_bit_and_eq  21
#define ap_ops_bit_or      22
#define ap_ops_bit_or_eq   23
#define ap_ops_bit_xor     24
#define ap_ops_bit_xor_eq  25
#define ap_ops_bit_not     26

#define ap_ops_push		   27
#define ap_ops_pop		   28
#define ap_ops_bind		   29

#define ap_ops_call		   30
#define ap_ops_ret		   31

#define ap_ops_cond_if	   32
#define ap_ops_cond_elif   33
#define ap_ops_cond_else   34

#define ap_ops_loop_while  35
#define ap_ops_loop_for	   36

#define ap_ops_ref		   37

extern obj_trait* ap_ops_t;

u64_t ap_ops_op		  (obj*);
it    ap_ops_arg_begin(obj*);
it	  ap_ops_arg_end  (obj*);

#endif