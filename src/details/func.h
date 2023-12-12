#ifndef __DETAILS_FUNC_H__
#define __DETAILS_FUNC_H__

#include <obj.h>
#include <list.h>

#include "../src.h"

extern obj_trait* func_t;
typedef struct    func  {
    obj    head;
    str    name;
    obj*   ret ;
    list   arg ;
    ap_src src ;
}   func;

bool_t func_new  (func*, u32_t, va_list);
bool_t func_clone(func*, func*)         ;
void   func_del  (func*)                ;

#endif