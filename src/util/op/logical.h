#ifndef __AP_UTIL_OP_LOGICAL_H__
#define __AP_UTIL_OP_LOGICAL_H__

#include <obj.h>

bool_t ap_can_and(obj*, obj*);
obj*   ap_ret_and(obj*, obj*);

bool_t ap_can_or (obj*, obj*);
obj*   ap_ret_or (obj*, obj*);

bool_t ap_can_not(obj*);
obj*   ap_ret_not(obj*);

#endif