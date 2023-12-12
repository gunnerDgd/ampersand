#ifndef __AP_OP_ARITH_H__
#define __AP_OP_ARITH_H__

#include <obj.h>

obj* ap_op_add   (obj*, obj*);
obj* ap_op_add_eq(obj*, obj*);

obj* ap_op_sub   (obj*, obj*);
obj* ap_op_sub_eq(obj*, obj*);
 
obj* ap_op_mul   (obj*, obj*);
obj* ap_op_mul_eq(obj*, obj*);

obj* ap_op_div   (obj*, obj*);
obj* ap_op_div_eq(obj*, obj*);

obj* ap_op_mod   (obj*, obj*);
obj* ap_op_mod_eq(obj*, obj*);

#endif