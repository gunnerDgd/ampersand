#include "var.h"
#include "details/var.h"

obj_trait* ap_var_t = &var_t;

obj* 
    ap_var_type
        (ap_var par)                              {
            if (!par)                      return 0;
            if (trait_of(par) != ap_var_t) return 0; var* ret = par;

            return ret->type;
}

str* 
    ap_var_name
        (ap_var par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_var_t) return 0; var* ret = par;

            return &ret->name;
}

ap_var 
    ap_var_self
        (ap_var par)                                     {
            if (!par)                            return 0;
            if (trait_of(par) != ap_var_t)       return 0; var* ret = par;

            if (!ret->self)                      return 0;
            if (trait_of(ret->self) != ap_var_t) return 0;

            return ret->self;
}