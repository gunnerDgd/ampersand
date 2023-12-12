#include "arith.h"
#include "../details/op.h"

#include "../type.h"
#include "../val.h"
#include "../var.h"
#include "../util.h"

obj*
    ap_op_eq
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_eq(par, par_arg))                                   return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_eq(par, par_arg);

            ap_type type = ap_ret_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4        ,
                opcode_eq,
                type     ,
                par      ,
                par_arg
            );
}

obj*
    ap_op_neq
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_neq(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_neq(par, par_arg);

            ap_type type = ap_ret_neq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_neq,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_gt
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_gt(par, par_arg))                                   return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_gt(par, par_arg);

            ap_type type = ap_ret_gt(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4        ,
                opcode_gt,
                type     ,
                par      ,
                par_arg
            );
}

obj*
    ap_op_gt_eq
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_gt_eq(par, par_arg))                                return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_gt_eq(par, par_arg);

            ap_type type = ap_ret_gt_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4           ,
                opcode_gt_eq,
                type        ,
                par         ,
                par_arg
            );
}

obj*
    ap_op_lt
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_lt(par, par_arg))                                   return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_gt(par, par_arg);

            ap_type type = ap_ret_lt(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4        ,
                opcode_lt,
                type     ,
                par      ,
                par_arg
            );
}

obj*
    ap_op_lt_eq
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_lt_eq(par, par_arg))                                return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_lt_eq(par, par_arg);

            ap_type type = ap_ret_lt_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4           ,
                opcode_lt_eq,
                type        ,
                par         ,
                par_arg
            );
}