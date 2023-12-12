#ifndef __AP_UTIL_VAR_H__
#define __AP_UTIL_VAR_H__

#include <obj.h>

bool_t ap_is_var     (obj*);
bool_t ap_is_cls_var (obj*);
bool_t ap_is_type_var(obj*);

bool_t ap_var_eq     (obj*, obj*);
bool_t ap_var_neq    (obj*, obj*);

#endif