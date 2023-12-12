#include "util.h"

#include "var.h"
#include "val.h"
#include "type.h"
#include "op.h"

bool_t 
    ap_eq
        (obj* par, obj* par_eq)                                {
            if (ap_is_type(par)) return ap_type_eq(par, par_eq);
            if (ap_is_cls (par)) return ap_cls_eq (par, par_eq);
            if (ap_is_var (par)) return ap_var_eq (par, par_eq);

            return false_t;
}

bool_t 
    ap_neq
        (obj* par, obj* par_eq)        {
            return !ap_neq(par, par_eq);
}

obj*
    ap_type_of
        (obj* par)                                                 {
            if (trait_of(par) == ap_var_t)  return ap_var_type(par);
            if (trait_of(par) == ap_val_t)  return ap_val_type(par);
            if (trait_of(par) == ap_type_t) return par             ;
            if (trait_of(par) == ap_op_t)   return ap_op_ret  (par);

            return 0;
}

ap_type 
    ap_type_common
        (ap_type par, ap_type par_cmp)                                                   {
            if (!par)     return 0; if (trait_of(par) != ap_type_t) par = ap_type_of(par);
            if (!par)     return 0;

            if (!par_cmp) return 0; if (trait_of(par_cmp) != ap_type_t) par_cmp = ap_type_of(par_cmp);
            if (!par_cmp) return 0;

            if (ap_is_int  (par) && ap_is_float(par_cmp)) return par_cmp;
            if (ap_is_float(par) && ap_is_int  (par_cmp)) return par    ;
            if (ap_is_int  (par) && ap_is_int  (par_cmp)) return (ap_type_id(par) > ap_type_id(par_cmp)) ? par : par_cmp;
            if (ap_is_float(par) && ap_is_float(par_cmp)) return (ap_type_id(par) > ap_type_id(par_cmp)) ? par : par_cmp;
            if (ap_is_cls  (par) && ap_is_cls  (par_cmp)) {
                if (ap_eq(par, par_cmp))
                    return par;
            }

            return 0;
}