#include "mov.h"

#include "../type.h"
#include "../../type.h"

#include "../cls.h"
#include "../var.h"

bool_t 
    ap_can_mov
        (obj* par, obj* par_arg)                   {
            if (!ap_is_var(par))           return 0;
            obj* par_type     = ap_type_of(par)    ;
            obj* par_arg_type = ap_type_of(par_arg);

            if (ap_is_type(par_type))                                                {
                if (ap_is_bool(par_type) && !ap_is_bool(par_arg_type)) return false_t;
                if (ap_is_none(par_arg_type))                          return false_t;

                return true_t;
            }

            if (ap_is_cls(par_type))
                return ap_cls_eq(par_type, par_arg_type);

            return false_t;
}

obj* 
    ap_ret_mov
        (obj* par, obj* par_arg)                         {
            if (!ap_can_mov(par, par_arg)) return false_t;
            return ap_type_of(par);
}