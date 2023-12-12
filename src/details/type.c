#include "type.h"

obj_trait type_t         = {
    .on_new   = &type_new  ,
    .on_clone = &type_clone,
    .on_ref   = 0          ,
    .on_del   = &type_del  ,
    .size     = sizeof(type)
};

bool_t 
    type_new
        (type* par_type, u32_t par_count, va_list par) {
            par_type->type = va_arg(par, u64_t);
            return true_t;
}

bool_t 
    type_clone
        (type* par, type* par_clone)   {
            par->type = par_clone->type; 
            return true_t; 
}

void   
    type_del  
        (type* par) {
}