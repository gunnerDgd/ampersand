#include "pop.h"
#include "../var.h"

#include "../../var.h"
#include "../../type.h"

bool_t 
    ap_can_pop
        (obj* par)                              {
            if (!ap_is_var(par))  return false_t;
            if (ap_var_self(par)) return false_t;

            return true_t;
}

obj* 
    ap_ret_pop
        (obj* par)        {
            return ap_none;
}