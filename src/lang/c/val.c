#include "val.h"
#include "details/val.h"

obj_trait* ap_c_val_t = &c_val_t;

str* 
    ap_c_val_as_str
        (ap_c_val par)                               {
            if (!par)                        return 0;
            if (trait_of(par) != ap_c_val_t) return 0; c_val* val = par;

            return &val->str;
}