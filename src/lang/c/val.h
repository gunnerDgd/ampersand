#ifndef __AP_C_VAL_H__
#define __AP_C_VAL_H__

#include <obj.h>

extern  obj_trait *ap_c_val_t;
typedef obj       *ap_c_val  ;

str* ap_c_val_as_str(ap_c_val);

#endif