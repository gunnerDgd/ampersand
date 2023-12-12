#ifndef __AP_C_DETAILS_TYPE_H__
#define __AP_C_DETAILS_TYPE_H__

#include <obj.h>
#include "../../../type.h"

extern obj_trait c_type_t;
typedef struct   c_type  {
    obj     head;
    ap_type type;
    str     name;
}   c_type;

bool_t c_type_new  (c_type*, u32_t, va_list);
bool_t c_type_clone(c_type*, c_type*)       ;
void   c_type_del  (c_type*)                ;

#endif