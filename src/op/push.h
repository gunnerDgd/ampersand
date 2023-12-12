#ifndef __AP_OP_PUSH_H__
#define __AP_OP_PUSH_H__

#include <obj.h>
#include "../var.h"

obj* ap_op_push   (ap_var, u32_t, ...)    ;
obj* ap_op_push_va(ap_var, u32_t, va_list);

#endif