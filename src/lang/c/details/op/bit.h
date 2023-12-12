#ifndef __AP_C_DETAILS_OP_BIT_H__
#define __AP_C_DETAILS_OP_BIT_H__

#include "../op.h"

bool_t c_op_as_shl       (c_op*);
bool_t c_op_as_shl_eq    (c_op*);

bool_t c_op_as_shr       (c_op*);
bool_t c_op_as_shr_eq    (c_op*);

bool_t c_op_as_bit_and   (c_op*);
bool_t c_op_as_bit_and_eq(c_op*);

bool_t c_op_as_bit_or    (c_op*);
bool_t c_op_as_bit_or_eq (c_op*);

bool_t c_op_as_bit_xor   (c_op*);
bool_t c_op_as_bit_xor_eq(c_op*);

bool_t c_op_as_bit_not   (c_op*);

#endif