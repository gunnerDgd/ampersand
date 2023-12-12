#include "arith.h"
#include "../details/op.h"

#include "../type.h"
#include "../val.h"
#include "../var.h"
#include "../util.h"

obj*
    ap_op_add
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_add(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_add(par, par_arg);

            ap_type type = ap_ret_add(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_add,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_add_eq
        (obj* par, obj* par_arg)                      {
            if (!par)                         return 0;
            if (!par_arg)                     return 0;
            if (!ap_can_add_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)    return 0;

            ap_type type = ap_ret_add_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_add_eq,
                type         ,
                par          ,
                par_arg
            );
}

obj*
    ap_op_sub
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_sub(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_sub(par, par_arg);

            ap_type type = ap_ret_sub(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_sub,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_sub_eq
        (obj* par, obj* par_arg)                      {
            if (!par)                         return 0;
            if (!par_arg)                     return 0;
            if (!ap_can_sub_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)    return 0;

            ap_type type = ap_ret_sub_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_sub_eq,
                type         ,
                par          ,
                par_arg
            );
}

obj*
    ap_op_mul
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_mul(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_mul(par, par_arg);

            ap_type type = ap_ret_mul(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_mul,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_mul_eq
        (obj* par, obj* par_arg)                      {
            if (!par)                         return 0;
            if (!par_arg)                     return 0;
            if (!ap_can_mul_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)    return 0;

            ap_type type = ap_ret_mul_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_mul_eq,
                type         ,
                par          ,
                par_arg
            );
}

obj*
    ap_op_div
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_div(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_div(par, par_arg);

            ap_type type = ap_ret_div(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_div,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_div_eq
        (obj* par, obj* par_arg)                      {
            if (!par)                         return 0;
            if (!par_arg)                     return 0;
            if (!ap_can_div_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)    return 0;

            ap_type type = ap_ret_div_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_div_eq,
                type         ,
                par          ,
                par_arg
            );
}

obj*
    ap_op_mod
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_mod(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_mod(par, par_arg);

            ap_type type = ap_ret_mod(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_mod,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_mod_eq
        (obj* par, obj* par_arg)                      {
            if (!par)                         return 0;
            if (!par_arg)                     return 0;
            if (!ap_can_mod_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)    return 0;

            ap_type type = ap_ret_mod_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_mod_eq,
                type         ,
                par          ,
                par_arg
            );
}