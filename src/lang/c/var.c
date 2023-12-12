#include "var.h"
#include "details/var.h"

obj_trait* ap_c_var_t = &c_var_t;

obj* 
    ap_c_var_type
        (ap_c_var par)                               {
            if (!par)                        return 0;
            if (trait_of(par) != ap_c_var_t) return 0; c_var* var = par;

            return var->type;
}

str* 
    ap_c_var_as_str
        (ap_c_var par)                               {
            if (!par)                        return 0;
            if (trait_of(par) != ap_c_var_t) return 0; c_var* var = par;

            return &var->str;
}