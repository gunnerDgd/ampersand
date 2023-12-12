#ifndef __AP_UTIL_TYPE_H__
#define __AP_UTIL_TYPE_H__

#include <obj.h>

bool_t  ap_is_type (obj*);

bool_t  ap_is_int  (obj*);
bool_t  ap_is_float(obj*);
bool_t  ap_is_bool (obj*);
bool_t  ap_is_none (obj*);
bool_t  ap_is_any  (obj*);

bool_t  ap_type_eq (obj*, obj*);
bool_t  ap_type_neq(obj*, obj*);

#endif