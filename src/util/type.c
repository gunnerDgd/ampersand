#include "type.h"
#include "../type.h"

bool_t
    ap_is_type
        (obj* par)                                        {
            if (!par)                       return false_t;
            if (trait_of(par) != ap_type_t) return false_t;

            return true_t;
}

bool_t  
    ap_is_bool
        (obj* par)                                        {
            if (!par)                       return false_t;
            if (trait_of(par) != ap_type_t) return false_t;

            return ap_type_id(par) == ap_type_id_bool;
}

bool_t  
    ap_is_none
        (obj* par)                                        {
            if (!par)                       return false_t;
            if (trait_of(par) != ap_type_t) return false_t;

            return ap_type_id(par) == ap_type_id_none;
}

bool_t  
    ap_is_any
        (obj* par)                                        {
            if (!par)                       return false_t;
            if (trait_of(par) != ap_type_t) return false_t;

            return ap_type_id(par) == ap_type_id_any;
}

bool_t  
    ap_is_int
        (obj* par)                                        {
            if (!par)                       return false_t;
            if (trait_of(par) != ap_type_t) return false_t;

            return ap_type_id(par) >= ap_type_id_i8 && ap_type_id(par) <= ap_type_id_u64;
}

bool_t
    ap_is_float
        (obj* par)                                        {
            if (!par)                       return false_t;
            if (trait_of(par) != ap_type_t) return false_t;

            return ap_type_id(par) >= ap_type_id_f32 && ap_type_id(par) <= ap_type_id_f64;
}

bool_t
    ap_type_eq
        (obj* par, obj* par_cmp)                                  {
            if (!par)                               return false_t;
            if (!par_cmp)                           return false_t;
            if (trait_of(par) != trait_of(par_cmp)) return false_t;
            if (trait_of(par) != ap_type_t)         return false_t;

            return ap_type_id(par) == ap_type_id(par_cmp);
}


bool_t  
    ap_type_neq
        (obj* par, obj* par_cmp)            {
            return !ap_type_eq(par, par_cmp);
}