#ifndef __AP_C_DETAILS_OP_ARITH_H__
#define __AP_C_DETAILS_OP_ARITH_H__

#include "../op.h"

bool_t c_op_as_add   (c_op*);
bool_t c_op_as_add_eq(c_op*);

bool_t c_op_as_sub   (c_op*);
bool_t c_op_as_sub_eq(c_op*);

bool_t c_op_as_mul   (c_op*);
bool_t c_op_as_mul_eq(c_op*);

bool_t c_op_as_div   (c_op*);
bool_t c_op_as_div_eq(c_op*);

bool_t c_op_as_mod   (c_op*);
bool_t c_op_as_mod_eq(c_op*);

#endif