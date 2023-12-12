#ifndef __AP_FUNC_H__
#define __AP_FUNC_H__

#include <obj.h>
#include "src.h"

extern  obj_trait *ap_func_t  ;
typedef obj       *ap_func    ;
typedef void      *ap_func_arg;

obj*        ap_func_ret     (ap_func)             ;
ap_src      ap_func_src     (ap_func)             ;
ap_func_arg ap_func_arg_next(ap_func, ap_func_arg);
obj*        ap_func_arg_type(ap_func_arg)         ;
str*        ap_func_arg_name(ap_func_arg)         ;

#endif