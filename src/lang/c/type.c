#include "type.h"
#include "details/type.h"

obj_trait* ap_c_type_t = &c_type_t;

str* 
    ap_c_type_name
        (ap_c_type par)                               {
            if (!par)                         return 0;
            if (trait_of(par) != ap_c_type_t) return 0; c_type* type = par;

            return &type->name;
}