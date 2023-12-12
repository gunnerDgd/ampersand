#ifndef __DETAILS_CLS_H__
#define __DETAILS_CLS_H__

#include <obj.h>
#include <str.h>
#include <list.h>

extern obj_trait cls_t;
typedef struct   cls  {
    obj  head;
    str  name;
    list elem;
}   cls;

bool_t cls_new  (cls*, u32_t, va_list);
bool_t cls_clone(cls*, cls*)          ;
void   cls_del  (cls*)                ;

#endif