#ifndef __AP_C_CLS_H__
#define __AP_C_CLS_H__

#include <obj.h>
#include "type.h"

extern  obj_trait *ap_c_cls_t   ;
typedef obj       *ap_c_cls     ;
typedef void      *ap_c_cls_elem;

str*          ap_c_cls_name  (ap_c_cls)               ;
ap_c_cls_elem ap_c_cls_next  (ap_c_cls, ap_c_cls_elem);
str*          ap_c_cls_as_str(ap_c_cls)               ;

str*          ap_c_cls_elem_name     (ap_c_cls_elem);
obj*          ap_c_cls_elem_type     (ap_c_cls_elem);
str*          ap_c_cls_elem_type_name(ap_c_cls_elem);
str*          ap_c_cls_elem_as_str   (ap_c_cls_elem);

#endif