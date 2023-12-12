#ifndef __DETAILS_OP_H__
#define __DETAILS_OP_H__

#include <obj.h>
#include <list.h>

#define opcode_none       0

#define opcode_add        1
#define opcode_add_eq     2

#define opcode_sub        3
#define opcode_sub_eq     4

#define opcode_mul        5
#define opcode_mul_eq     6

#define opcode_div        7
#define opcode_div_eq     8

#define opcode_mod        9
#define opcode_mod_eq     10

#define opcode_shl        11
#define opcode_shl_eq     12

#define opcode_shr        13
#define opcode_shr_eq     14

#define opcode_bit_and    15
#define opcode_bit_and_eq 16

#define opcode_bit_or     17
#define opcode_bit_or_eq  18

#define opcode_bit_xor    19
#define opcode_bit_xor_eq 20

#define opcode_bit_not    21

#define opcode_eq         22
#define opcode_neq        23

#define opcode_gt         24
#define opcode_gt_eq      25

#define opcode_lt         26
#define opcode_lt_eq      27

#define opcode_and        28
#define opcode_or         29
#define opcode_not        30

#define opcode_push       31
#define opcode_pop        32
#define opcode_mov        33

#define opcode_call       34
#define opcode_ret        35

extern obj_trait op_t;
typedef struct   op  {
    obj   head;
    u64_t op  ;
    list  arg ;
    obj*  ret ;
}   op;

bool_t op_new  (op*, u32_t, va_list);
bool_t op_clone(op*, op*)           ;
void   op_del  (op*)                ;

#endif