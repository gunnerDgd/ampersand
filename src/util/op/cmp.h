#ifndef __AP_UTIL_OP_CMP_H__
#define __AP_UTIL_OP_CMP_H__

#include <obj.h>

bool_t ap_can_eq   (obj*, obj*);
obj*   ap_ret_eq   (obj*, obj*);

bool_t ap_can_neq  (obj*, obj*);
obj*   ap_ret_neq  (obj*, obj*);

bool_t ap_can_gt   (obj*, obj*);
obj*   ap_ret_gt   (obj*, obj*);

bool_t ap_can_gt_eq(obj*, obj*);
obj*   ap_ret_gt_eq(obj*, obj*);

bool_t ap_can_lt   (obj*, obj*);
obj*   ap_ret_lt   (obj*, obj*);

bool_t ap_can_lt_eq(obj*, obj*);
obj*   ap_ret_lt_eq(obj*, obj*);

#endif