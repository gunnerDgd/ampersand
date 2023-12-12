#include "bit.h"

#include "../type.h"
#include "../../type.h"

#include "../var.h"
#include "../../util.h"

bool_t 
    ap_can_shl
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_shl
        (obj* par, obj* par_arg)                   {
            if (!ap_can_shl(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_shl_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))          return false_t;
            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_shl_eq
        (obj* par, obj* par_arg)                      {
            if (!ap_can_shl_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_shr
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_shr
        (obj* par, obj* par_arg)                   {
            if (!ap_can_shl(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_shr_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))          return false_t;
            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_shr_eq
        (obj* par, obj* par_arg)                      {
            if (!ap_can_shr_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_bit_and
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_bit_and
        (obj* par, obj* par_arg)                       {
            if (!ap_can_bit_and(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_bit_and_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))          return false_t;
            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_bit_and_eq
        (obj* par, obj* par_arg)                          {
            if (!ap_can_bit_and_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_bit_or
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_bit_or
        (obj* par, obj* par_arg)                       {
            if (!ap_can_bit_or(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_bit_or_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))          return false_t;
            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_bit_or_eq
        (obj* par, obj* par_arg)                         {
            if (!ap_can_bit_or_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_bit_xor
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_bit_xor
        (obj* par, obj* par_arg)                       {
            if (!ap_can_bit_xor(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_bit_xor_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_var(par))          return false_t;
            if (!ap_is_int(par_type))     return false_t;
            if (!ap_is_int(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_bit_xor_eq
        (obj* par, obj* par_arg)                          {
            if (!ap_can_bit_xor_eq(par, par_arg)) return 0;
            return ap_type_common(par, par_arg);
}

bool_t 
    ap_can_bit_not
        (obj* par)                         {
            obj* par_type = ap_type_of(par);

            if (!par_type)            return false_t;
            if (!ap_is_int(par_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_bit_not
        (obj* par)                            {
            if (!ap_can_bit_not(par)) return 0;
            return ap_type_of(par);
}