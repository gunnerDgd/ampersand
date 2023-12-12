#ifndef __AP_VAR_H__
#define __AP_VAR_H__

#include <obj.h>

extern  obj_trait *ap_var_t;
typedef obj       *ap_var  ;

obj*   ap_var_type(ap_var);
str*   ap_var_name(ap_var);
ap_var ap_var_self(ap_var);

#endif