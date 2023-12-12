#ifndef __AP_UTIL_OP_ARITH_H__
#define __AP_UTIL_OP_ARITH_H__

#include <obj.h>

bool_t ap_can_add   (obj*, obj*);
obj*   ap_ret_add   (obj*, obj*);

bool_t ap_can_add_eq(obj*, obj*);
obj*   ap_ret_add_eq(obj*, obj*);

bool_t ap_can_sub   (obj*, obj*);
obj*   ap_ret_sub   (obj*, obj*);

bool_t ap_can_sub_eq(obj*, obj*);
obj*   ap_ret_sub_eq(obj*, obj*);

bool_t ap_can_mul   (obj*, obj*);
obj*   ap_ret_mul   (obj*, obj*);

bool_t ap_can_mul_eq(obj*, obj*);
obj*   ap_ret_mul_eq(obj*, obj*);

bool_t ap_can_div   (obj*, obj*);
obj*   ap_ret_div   (obj*, obj*);

bool_t ap_can_div_eq(obj*, obj*);
obj*   ap_ret_div_eq(obj*, obj*);

bool_t ap_can_mod   (obj*, obj*);
obj*   ap_ret_mod   (obj*, obj*);

bool_t ap_can_mod_eq(obj*, obj*);
obj*   ap_ret_mod_eq(obj*, obj*);

#endif