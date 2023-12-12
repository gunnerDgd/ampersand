#ifndef __AP_C_VAR_H__
#define __AP_C_VAR_H__

#include <obj.h>

extern  obj_trait *ap_c_var_t;
typedef obj       *ap_c_var  ;

obj* ap_c_var_type  (ap_c_var);
str* ap_c_var_as_str(ap_c_var);

#endif