#ifndef __DETAILS_VAR_H__
#define __DETAILS_VAR_H__

#include <str.h>
#include <list.h>

extern obj_trait var_t;
typedef struct   var  {
    obj  head;
    obj* type;
    str  name;
    obj* self;
}   var;

bool_t var_new  (var*, u32_t, va_list);
bool_t var_clone(var*, var*)          ;
void   var_del  (var*)                ;

#endif