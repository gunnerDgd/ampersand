#ifndef __AP_OP_BIT_H__
#define __AP_OP_BIT_H__

#include <obj.h>

obj* ap_op_shl       (obj*, obj*);
obj* ap_op_shl_eq    (obj*, obj*);

obj* ap_op_shr       (obj*, obj*);
obj* ap_op_shr_eq    (obj*, obj*);

obj* ap_op_bit_and   (obj*, obj*);
obj* ap_op_bit_and_eq(obj*, obj*);

obj* ap_op_bit_or    (obj*, obj*);
obj* ap_op_bit_or_eq (obj*, obj*);

obj* ap_op_bit_xor   (obj*, obj*);
obj* ap_op_bit_xor_eq(obj*, obj*);

obj* ap_op_bit_not   (obj*)      ;

#endif