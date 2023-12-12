#ifndef __AP_CLS_H__
#define __AP_CLS_H__

#include <obj.h>

#include "type.h"
#include "var.h"

extern  obj_trait *ap_cls_t   ;
typedef obj       *ap_cls     ;
typedef void      *ap_cls_elem;

str*        ap_cls_name     (ap_cls)                   ;
ap_cls_elem ap_cls_add      (ap_cls, obj*, const char*);
void        ap_cls_del      (ap_cls, ap_cls_elem)      ;
ap_cls_elem ap_cls_get      (ap_cls, const char*)      ;
ap_cls_elem ap_cls_next     (ap_cls, ap_cls_elem)      ;

str*        ap_cls_elem_name(ap_cls_elem)        ;
obj*        ap_cls_elem_type(ap_cls_elem)        ;
ap_cls      ap_cls_elem_cls (ap_cls_elem)        ;

#endif