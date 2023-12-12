#include "val.h"

#include <string.h>
#include <stdio.h>

obj_trait c_val_t         = {
    .on_new   = &c_val_new  ,
    .on_clone = &c_val_clone,
    .on_ref   = 0           ,
    .on_del   = &c_val_del  ,
    .size     = sizeof(c_val)
};

bool_t
    c_val_new
        (c_val* par_val, u32_t par_count, va_list par) {
            par_val->val = va_arg(par, ap_val);
            if (!par_val->val)                          return false_t;
            if (trait_of(par_val->val) != ap_val_t)     return false_t;
            
            u64_t   val_type  =    ap_type_id(ap_val_type(par_val->val));
            char    val[1024] =    { 0x00, };
            switch (val_type)      {
                case ap_type_id_i8 : snprintf(val, 1024, "%u\0"  , ap_val_as_i8 (par_val->val)); break;
                case ap_type_id_u8 : snprintf(val, 1024, "%d\0"  , ap_val_as_u8 (par_val->val)); break;

                case ap_type_id_i16: snprintf(val, 1024, "%hd\0" , ap_val_as_i16(par_val->val)); break;
                case ap_type_id_u16: snprintf(val, 1024, "%hu\0" , ap_val_as_u16(par_val->val)); break;

                case ap_type_id_i32: snprintf(val, 1024, "%u\0"  , ap_val_as_i32(par_val->val)); break;
                case ap_type_id_u32: snprintf(val, 1024, "%d\0"  , ap_val_as_u32(par_val->val)); break;

                case ap_type_id_i64: snprintf(val, 1024, "%lld\0", ap_val_as_i64(par_val->val)); break;
                case ap_type_id_u64: snprintf(val, 1024, "%llu\0", ap_val_as_u64(par_val->val)); break;

                case ap_type_id_f32: snprintf(val, 1024, "%f\0"  , ap_val_as_f64(par_val->val)); break;
                case ap_type_id_f64: snprintf(val, 1024, "%lf\0" , ap_val_as_f64(par_val->val)); break;
                default            : return false_t;
            }

            if (!make_at(&par_val->str, str_t) from(0)) return false_t;
            str_push_back_cstr(&par_val->str, val, strlen(val));

            par_val->val = ref(par_val->val);
            return true_t;
}

bool_t 
    c_val_clone
        (c_val* par, c_val* par_clone)                               {
            if (!clone_at(&par->str, &par_clone->str)) return false_t;
            if (!(par->val = ref(par_clone->val)))                   {
                del(&par->str);
                return false_t;
            }

            return true_t;
}

void
    c_val_del
        (c_val* par)      {
            del(&par->str);
            del (par->val);
}