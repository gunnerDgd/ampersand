#include "var.h"
#include "cls.h"
#include "type.h"

#include "../var.h"

bool_t 
    ap_is_var
        (obj* par)                                       {
            if (!par)                      return false_t;
            if (trait_of(par) != ap_var_t) return false_t;

            return true_t;
}

bool_t 
    ap_is_cls_var
        (obj* par)                              {
            if (!ap_is_var(par))  return false_t; obj* type = ap_var_type(par);
            if (!ap_is_cls(type)) return false_t;

            return true_t;
}

bool_t 
    ap_is_type_var
        (obj* par)                              {
            if (!ap_is_var (par)) return false_t; obj* type = ap_var_type(par);
            if (!ap_is_type(par)) return false_t;

            return true_t;
}

bool_t 
    ap_var_eq
        (obj* par, obj* par_eq)        {
            if (!par)    return false_t; obj* type    = ap_var_type(par)   ;
            if (!par_eq) return false_t; obj* type_eq = ap_var_type(par_eq);

            if (ap_is_type(type)) return ap_type_eq(type, type_eq);
            if (ap_is_cls (type)) return ap_cls_eq (type, type_eq);

            return false_t;
}

bool_t 
    ap_var_neq
        (obj* par, obj* par_eq)           {
            return !ap_var_eq(par, par_eq);
}