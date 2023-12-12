#ifndef __AP_C_DETAILS_VAL_H__
#define __AP_C_DETAILS_VAL_H__

#include <obj.h>

#include "../../../val.h"

extern obj_trait c_val_t;
typedef struct   c_val  {
    obj    head;
    ap_val val ;
    str    str ;
}   c_val;

bool_t c_val_new  (c_val*, u32_t, va_list);
bool_t c_val_clone(c_val*, c_val*)        ;
void   c_val_del  (c_val*)                ;

#endif