#ifndef __AP_C_DETAILS_OP_CMP_H__
#define __AP_C_DETAILS_OP_CMP_H__

#include "../op.h"

bool_t c_op_as_eq   (c_op*);
bool_t c_op_as_neq  (c_op*);

bool_t c_op_as_gt   (c_op*);
bool_t c_op_as_gt_eq(c_op*);

bool_t c_op_as_lt   (c_op*);
bool_t c_op_as_lt_eq(c_op*);

#endif