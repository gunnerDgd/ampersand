#include "cmp.h"

#include "../type.h"
#include "../../type.h"

#include "../var.h"

bool_t 
    ap_can_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type)     && !ap_is_bool(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type) && !ap_is_bool(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_eq
        (obj* par, obj* par_arg)                  {
            if (!ap_can_eq(par, par_arg)) return 0;
            return ap_bool;
}

bool_t 
    ap_can_neq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type)     && !ap_is_bool(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type) && !ap_is_bool(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_neq
        (obj* par, obj* par_arg)                   {
            if (!ap_can_neq(par, par_arg)) return 0;
            return ap_bool;
}

bool_t 
    ap_can_gt
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_gt
        (obj* par, obj* par_arg)                  {
            if (!ap_can_gt(par, par_arg)) return 0;
            return ap_bool;
}

bool_t
    ap_can_gt_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_gt_eq
        (obj* par, obj* par_arg)                     {
            if (!ap_can_gt_eq(par, par_arg)) return 0;
            return ap_bool;
}

bool_t 
    ap_can_lt
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_lt
        (obj* par, obj* par_arg)                  {
            if (!ap_can_lt(par, par_arg)) return 0;
            return ap_bool;
}

bool_t 
    ap_can_lt_eq
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_int(par_type)     && !ap_is_float(par_type))     return false_t;
            if (!ap_is_int(par_arg_type) && !ap_is_float(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_lt_eq
        (obj* par, obj* par_arg)                  {
            if (!ap_can_lt_eq(par, par_arg)) return 0;
            return ap_bool;
}