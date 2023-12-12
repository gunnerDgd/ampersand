#include "cls.h"
#include "../cls.h"

bool_t 
    ap_is_cls
        (obj* par)                                       {
            if (!par)                      return false_t;
            if (trait_of(par) != ap_cls_t) return false_t;

            return true_t;
}

bool_t 
    ap_cls_eq
        (obj* par, obj* par_eq)                   {
            if (!ap_is_cls(par))    return false_t;
            if (!ap_is_cls(par_eq)) return false_t;

            return str_eq(ap_cls_name(par), ap_cls_name(par_eq));
}

bool_t 
    ap_cls_neq
        (obj* par, obj* par_neq)           {
            return !ap_cls_eq(par, par_neq);
}