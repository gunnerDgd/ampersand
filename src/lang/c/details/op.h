#ifndef __AP_C_DETAILS_OP_H__
#define __AP_C_DETAILS_OP_H__

#include <obj.h>
#include <list.h>

#include "../../../op.h"
#include "../var.h"
#include "../val.h"

extern obj_trait c_op_arg_t;
typedef struct   c_op_arg  {
    obj  head;
    obj* arg ;
    str  str ;
}   c_op_arg ;

bool_t c_op_arg_new  (c_op_arg*, u32_t, va_list);
bool_t c_op_arg_clone(c_op_arg*, c_op_arg*)     ;
void   c_op_arg_del  (c_op_arg*)                ;

extern obj_trait c_op_t;
typedef struct   c_op  {
    obj   head;
    ap_op op  ;
    list  arg ;
    str   str ;
}   c_op      ;

bool_t c_op_new  (c_op*, u32_t, va_list);
bool_t c_op_clone(c_op*, c_op*)         ;
void   c_op_del  (c_op*)                ;

#endif