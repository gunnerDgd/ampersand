#include "cmp.h"

#include "../type.h"
#include "../../type.h"

#include "../var.h"

bool_t 
    ap_can_and
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_bool(par_type))     return false_t;
            if (!ap_is_bool(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_and
        (obj* par, obj* par_arg)                  {
            if (!ap_can_and(par, par_arg)) return 0;
            return ap_bool;
}

bool_t 
    ap_can_or
        (obj* par, obj* par_arg)                   {
            obj* par_type     = ap_type_of(par)    ; if (!par_type)     return false_t;
            obj* par_arg_type = ap_type_of(par_arg); if (!par_arg_type) return false_t;

            if (!ap_is_bool(par_type))     return false_t;
            if (!ap_is_bool(par_arg_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_or
        (obj* par, obj* par_arg)                  {
            if (!ap_can_or(par, par_arg)) return 0;
            return ap_bool;
}

bool_t 
    ap_can_not
        (obj* par)                         {
            obj* par_type = ap_type_of(par); 
            if (!par_type)             return false_t;
            if (!ap_is_bool(par_type)) return false_t;

            return true_t;
}

obj* 
    ap_ret_not
        (obj* par)                        {
            if (!ap_can_not(par)) return 0;
            return ap_bool;
}