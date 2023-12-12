#ifndef __AP_OP_H__
#define __AP_OP_H__

#include <obj.h>

#include "type.h"
#include "cls.h"
#include "var.h"
#include "val.h"

#include "op/arith.h"
#include "op/cmp.h"
#include "op/bit.h"
#include "op/logical.h"
#include "op/push.h"
#include "op/pop.h"
#include "op/mov.h"

#define ap_opcode_none       0

#define ap_opcode_add        1
#define ap_opcode_add_eq     2

#define ap_opcode_sub        3
#define ap_opcode_sub_eq     4

#define ap_opcode_mul        5
#define ap_opcode_mul_eq     6

#define ap_opcode_div        7
#define ap_opcode_div_eq     8

#define ap_opcode_mod        9
#define ap_opcode_mod_eq     10

#define ap_opcode_shl        11
#define ap_opcode_shl_eq     12

#define ap_opcode_shr        13
#define ap_opcode_shr_eq     14

#define ap_opcode_bit_and    15
#define ap_opcode_bit_and_eq 16

#define ap_opcode_bit_or     17
#define ap_opcode_bit_or_eq  18

#define ap_opcode_bit_xor    19
#define ap_opcode_bit_xor_eq 20

#define ap_opcode_bit_not    21

#define ap_opcode_eq         22
#define ap_opcode_neq        23

#define ap_opcode_gt         24
#define ap_opcode_gt_eq      25

#define ap_opcode_lt         26
#define ap_opcode_lt_eq      27

#define ap_opcode_and        28
#define ap_opcode_or         29
#define ap_opcode_not        30

#define ap_opcode_push       31
#define ap_opcode_pop        32
#define ap_opcode_mov        33

#define ap_opcode_call       34
#define ap_opcode_ret        35

typedef void      *ap_op_arg;
extern  obj_trait *ap_op_t  ;
typedef obj       *ap_op    ;

ap_type   ap_op_ret        (ap_op)           ;
u64_t     ap_op_opcode     (ap_op)           ;
ap_op_arg ap_op_arg_next   (ap_op, ap_op_arg);
ap_op     ap_op_arg_as_op  (ap_op_arg);
ap_var    ap_op_arg_as_var (ap_op_arg);
ap_val    ap_op_arg_as_val (ap_op_arg);
ap_type   ap_op_arg_as_type(ap_op_arg);
ap_cls    ap_op_arg_as_cls (ap_op_arg);

#endif