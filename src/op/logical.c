#include "arith.h"
#include "../details/op.h"

#include "../type.h"
#include "../val.h"
#include "../var.h"
#include "../util.h"

obj*
    ap_op_and
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_and(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_and(par, par_arg);

            ap_type type = ap_ret_and(par, par_arg);
            if    (!type) return 0;

            return make (&op_t) from (
                4         ,
                opcode_and,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_or
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_or(par, par_arg))                                   return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_or(par, par_arg);

            ap_type type = ap_ret_or(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4        ,
                opcode_or,
                type     ,
                par      ,
                par_arg
            );
}

obj*
    ap_op_not
        (obj* par)                                               {
            if (!par)                      return 0              ;
            if (!ap_can_not(par))          return 0              ;
            if (trait_of(par) == ap_val_t) return ap_val_not(par);

            ap_type type = ap_ret_not(par);
            if    (!type) return 0;
            
            return make (&op_t) from (
                3         ,
                opcode_not,
                type      ,
                par      
            );
}