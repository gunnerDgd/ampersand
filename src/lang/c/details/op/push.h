#ifndef __AP_C_DETAILS_OP_PUSH_H__
#define __AP_C_DETAILS_OP_PUSH_H__

#include "../op.h"
#include <str.h>

bool_t c_op_as_push_type(c_op*, ap_c_var, ap_op_arg);
bool_t c_op_as_push_cls (c_op*, ap_c_var, ap_op_arg);
bool_t c_op_as_push     (c_op*)                     ;

#endif