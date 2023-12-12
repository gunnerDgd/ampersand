#include "push.h"
#include "../details/op.h"

#include "../type.h"
#include "../val.h"
#include "../var.h"
#include "../cls.h"
#include "../util.h"

obj* 
    ap_op_push
        (ap_var par_var, u32_t par_count, ...) {
            va_list  par;
            va_start(par, par_count); obj* ret = ap_op_push_va(par_var, par_count, par);
            va_end  (par);
            return   ret ;
}

obj*
    ap_op_push_va
        (ap_var par_var, u32_t par_count, va_list par) {
            if (!par_var)                      return 0;
            if (trait_of(par_var) != ap_var_t) return 0;
            if (ap_var_self(par_var))          return 0;
            
            va_list par_res      ;
            va_copy(par_res, par);
            
            bool_t res = ap_can_push_va(par_var, par_count - 1, par_res); if (!res) return 0;
            op*    ret = make (&op_t) from (
                3          ,
                opcode_push,
                ap_none    ,
                par_var
            );

            va_end (par_res);
            if     (!ret) return false_t;
            while  (par_count--)                                   {
                if (!list_push_back(&ret->arg, va_arg(par, obj*))) {
                    del      (ret);
                    return false_t;
                }
            }

            return ret;
}