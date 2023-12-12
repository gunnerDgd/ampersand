#include "arith.h"

#include "../type.h"
#include "../../type.h"

#include "../var.h"
#include "../../util.h"

bool_t 
    ap_can_add
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_add
        (obj* par, obj* par_arg)                   {
            if (!ap_can_add(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_sub
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_sub
        (obj* par, obj* par_arg)                   {
            if (!ap_can_sub(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_mul
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_mul
        (obj* par, obj* par_arg)                   {
            if (!ap_can_mul(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_div
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_div
        (obj* par, obj* par_arg)                   {
            if (!ap_can_div(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_mod
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_mod
        (obj* par, obj* par_arg)                   {
            if (!ap_can_mod(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}


bool_t 
    ap_can_add_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))                                        return false_t;
            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_add_eq
        (obj* par, obj* par_arg)                      {
            if (!ap_can_add_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_sub_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))                                        return false_t;
            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_sub_eq
        (obj* par, obj* par_arg)                      {
            if (!ap_can_sub_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_mul_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))                                        return false_t;
            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_mul_eq
        (obj* par, obj* par_arg)                      {
            if (!ap_can_mul_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_div_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))                                        return false_t;
            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_div_eq
        (obj* par, obj* par_arg)                      {
            if (!ap_can_div_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_mod_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))          return false_t;
            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_mod_eq
        (obj* par, obj* par_arg)                      {
            if (!ap_can_mod_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}