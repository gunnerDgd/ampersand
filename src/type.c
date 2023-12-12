#include "type.h"
#include "details/type.h"
#include "details/op.h"

#include "op.h"
#include "var.h"
#include "val.h"

obj_trait *ap_type_t = &type_t;

u64_t 
    ap_type_id
        (ap_type par)                                {
            if (!par)                       return -1;
            if (trait_of(par) != ap_type_t) return -1; type* ret = par;

            return ret->type;
}
