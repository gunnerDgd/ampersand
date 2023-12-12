#include "type.h"
#include <string.h>

obj_trait c_type_t         = {
    .on_new   = &c_type_new  ,
    .on_clone = &c_type_clone,
    .on_ref   = 0            ,
    .on_del   = &c_type_del  ,
    .size     = sizeof(c_type)
};

bool_t 
    c_type_new
        (c_type* par_type, u32_t par_count, va_list par) {
            par_type->type = va_arg(par, ap_type);
            if (!par_type->type)                       return false_t;
            if (trait_of(par_type->type) != ap_type_t) return false_t;
            
            const char* name = 0;
            switch  (ap_type_id(par_type->type))                        {
                case ap_type_id_i8  : name = "char"              ; break;
                case ap_type_id_i16 : name = "short"             ; break;
                case ap_type_id_i32 : name = "int"               ; break;
                case ap_type_id_i64 : name = "long long"         ; break;

                case ap_type_id_u8  : name = "unsigned char"     ; break;
                case ap_type_id_u16 : name = "unsigned short"    ; break;
                case ap_type_id_u32 : name = "unsigned int"      ; break;
                case ap_type_id_u64 : name = "unsigned long long"; break;

                case ap_type_id_f32 : name = "float"             ; break;
                case ap_type_id_f64 : name = "double"            ; break;
                case ap_type_id_none: name = "void"              ; break;
                default             : return false_t;
            }
            
            if (!make_at(&par_type->name, str_t) from(0)) 
                return false_t;
            str_push_back_cstr(&par_type->name, name, strlen(name));
            
            par_type->type = ref(par_type->type);
            return true_t;
}

bool_t 
    c_type_clone
        (c_type* par, c_type* par_clone)                 {
            if (!clone_at(&par->name, &par_clone->name)) 
                return false_t;

            par->type = ref(par_clone->type);
            return true_t;
}

void
    c_type_del
        (c_type* par)      {
            del (par->type);
            del(&par->name);
}