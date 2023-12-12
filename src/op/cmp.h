#ifndef __AP_OP_CMP_H__
#define __AP_OP_CMP_H__

#include <obj.h>

obj* ap_op_eq   (obj*, obj*);
obj* ap_op_neq  (obj*, obj*);

obj* ap_op_gt   (obj*, obj*);
obj* ap_op_gt_eq(obj*, obj*);

obj* ap_op_lt   (obj*, obj*);
obj* ap_op_lt_eq(obj*, obj*);

#endif