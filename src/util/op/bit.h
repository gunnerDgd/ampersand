#ifndef __AP_UTIL_OP_BIT_H__
#define __AP_UTIL_OP_BIT_H__

#include <obj.h>

bool_t ap_can_shl       (obj*, obj*);
obj*   ap_ret_shl       (obj*, obj*);

bool_t ap_can_shl_eq    (obj*, obj*);
obj*   ap_ret_shl_eq    (obj*, obj*);

bool_t ap_can_shr       (obj*, obj*);
obj*   ap_ret_shr       (obj*, obj*);

bool_t ap_can_shr_eq    (obj*, obj*);
obj*   ap_ret_shr_eq    (obj*, obj*);

bool_t ap_can_bit_and   (obj*, obj*);
obj*   ap_ret_bit_and   (obj*, obj*);

bool_t ap_can_bit_and_eq(obj*, obj*);
obj*   ap_ret_bit_and_eq(obj*, obj*);

bool_t ap_can_bit_or    (obj*, obj*);
obj*   ap_ret_bit_or    (obj*, obj*);

bool_t ap_can_bit_or_eq (obj*, obj*);
obj*   ap_ret_bit_or_eq (obj*, obj*);

bool_t ap_can_bit_xor   (obj*, obj*);
obj*   ap_ret_bit_xor   (obj*, obj*);

bool_t ap_can_bit_xor_eq(obj*, obj*);
obj*   ap_ret_bit_xor_eq(obj*, obj*);

bool_t ap_can_bit_not   (obj*)      ;
obj*   ap_ret_bit_not   (obj*)      ;

#endif