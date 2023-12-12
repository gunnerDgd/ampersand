#ifndef __AP_C_DETAILS_VAR_H__
#define __AP_C_DETAILS_VAR_H__

#include <obj.h>

#include "../type.h"
#include "../cls.h"

#include "../../../type.h"
#include "../../../cls.h"
#include "../../../var.h"

extern obj_trait c_var_t;
typedef struct   c_var  {
    obj    head;
    obj   *type;
    ap_var var ;
    str    str ;
}   c_var;

bool_t c_var_from_cls (c_var*, ap_cls)        ;
bool_t c_var_from_type(c_var*, ap_type)       ;
bool_t c_var_new      (c_var*, u32_t, va_list);
bool_t c_var_clone    (c_var*, c_var*)        ;
void   c_var_del      (c_var*)                ;

#endif