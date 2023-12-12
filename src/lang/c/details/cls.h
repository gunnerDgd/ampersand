#ifndef __AP_C_DETAILS_CLS_H__
#define __AP_C_DETAILS_CLS_H__

#include <obj.h>
#include <list.h>

#include "../../../cls.h"
#include "../type.h"

extern obj_trait c_cls_elem_t;
typedef struct   c_cls_elem  {
    obj  head                ;
    str  name, type_name, str;
    obj *type                ;
}   c_cls_elem;

bool_t c_cls_elem_new  (c_cls_elem*, u32_t, va_list);
bool_t c_cls_elem_clone(c_cls_elem*, c_cls_elem*)   ;
void   c_cls_elem_del  (c_cls_elem*)                ;

extern obj_trait c_cls_t;
typedef struct   c_cls  {
    obj    head   ;
    str    name   ;
    ap_cls cls    ;
    str    cls_str;
    list   elem   ;
}   c_cls;

bool_t c_cls_new  (c_cls*, u32_t, va_list);
bool_t c_cls_clone(c_cls*, c_cls*)        ;
void   c_cls_del  (c_cls*)                ;

#endif