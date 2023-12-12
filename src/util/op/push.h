#ifndef __AP_UTIL_OP_PUSH_H__
#define __AP_UTIL_OP_PUSH_H__

#include <obj.h>

bool_t ap_can_push   (obj*, u32_t, ...)    ;
bool_t ap_can_push_va(obj*, u32_t, va_list);
obj*   ap_ret_push   (obj*, u32_t, ...)    ;
obj*   ap_ret_push_va(obj*, u32_t, va_list);

#endif