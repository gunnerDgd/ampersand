#ifndef __AP_C_OP_H__
#define __AP_C_OP_H__

#include <obj.h>

extern  obj_trait *ap_c_op_t  ;
typedef obj       *ap_c_op    ;
typedef void      *ap_c_op_arg;

ap_c_op_arg ap_c_op_arg_next  (ap_c_op, ap_c_op_arg);
str*        ap_c_op_arg_as_str(ap_c_op_arg)         ;
str*        ap_c_op_as_str    (ap_c_op)             ;

#endif