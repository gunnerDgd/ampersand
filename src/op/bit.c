#include "arith.h"
#include "../details/op.h"

#include "../type.h"
#include "../val.h"
#include "../var.h"
#include "../util.h"

obj*
    ap_op_shl
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_shl(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_shl(par, par_arg);

            ap_type type = ap_ret_shl(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_shl,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_shl_eq
        (obj* par, obj* par_arg)                      {
            if (!par)                         return 0;
            if (!par_arg)                     return 0;
            if (!ap_can_shl_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)    return 0;

            ap_type type = ap_ret_shl_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_shl_eq,
                type         ,
                par          ,
                par_arg
            );
}

obj*
    ap_op_shr
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_shr(par, par_arg))                                  return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_shr(par, par_arg);

            ap_type type = ap_ret_shr(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4         ,
                opcode_shr,
                type      ,
                par       ,
                par_arg
            );
}

obj*
    ap_op_shr_eq
        (obj* par, obj* par_arg)                      {
            if (!par)                         return 0;
            if (!par_arg)                     return 0;
            if (!ap_can_shr_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)    return 0;

            ap_type type = ap_ret_shr_eq(par, par_arg);
            if (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_shr_eq,
                type         ,
                par          ,
                par_arg
            );
}

obj*
    ap_op_bit_and
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_bit_and(par, par_arg))                              return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_bit_and(par, par_arg);

            ap_type type = ap_ret_bit_and(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4             ,
                opcode_bit_and,
                type          ,
                par           ,
                par_arg
            );
}

obj*
    ap_op_bit_and_eq
        (obj* par, obj* par_arg)                          {
            if (!par)                             return 0;
            if (!par_arg)                         return 0;
            if (!ap_can_bit_and_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)        return 0;

            ap_type type = ap_ret_bit_and_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4                ,
                opcode_bit_and_eq,
                type             ,
                par              ,
                par_arg
            );
}

obj*
    ap_op_bit_or
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_bit_or(par, par_arg))                               return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_bit_or(par, par_arg);

            ap_type type = ap_ret_bit_or(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4            ,
                opcode_bit_or,
                type         ,
                par          ,
                par_arg
            );
}

obj*
    ap_op_bit_or_eq
        (obj* par, obj* par_arg)                         {
            if (!par)                            return 0;
            if (!par_arg)                        return 0;
            if (!ap_can_bit_or_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)       return 0;

            ap_type type = ap_ret_bit_or_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4               ,
                opcode_bit_or_eq,
                type            ,
                par             ,
                par_arg
            );
}

obj*
    ap_op_bit_xor
        (obj* par, obj* par_arg)                                                    {
            if (!par)                                                       return 0;
            if (!par_arg)                                                   return 0;
            if (!ap_can_bit_xor(par, par_arg))                              return 0;
            if (trait_of(par) == ap_val_t && trait_of(par_arg) == ap_val_t) return ap_val_bit_xor(par, par_arg);

            ap_type type = ap_ret_bit_xor(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4             ,
                opcode_bit_xor,
                type          ,
                par           ,
                par_arg
            );
}

obj*
    ap_op_bit_xor_eq
        (obj* par, obj* par_arg)                          {
            if (!par)                             return 0;
            if (!par_arg)                         return 0;
            if (!ap_can_bit_xor_eq(par, par_arg)) return 0;
            if (trait_of(par) != ap_var_t)        return 0;

            ap_type type = ap_ret_bit_xor_eq(par, par_arg);
            if    (!type) return 0;
            
            return make (&op_t) from (
                4                ,
                opcode_bit_xor_eq,
                type             ,
                par              ,
                par_arg
            );
}

obj*
    ap_op_bit_not
        (obj* par)                                                   {
            if (!par)                      return 0                  ;
            if (!ap_can_bit_not(par))      return 0                  ;
            if (trait_of(par) == ap_val_t) return ap_val_bit_not(par);

            ap_type type = ap_ret_bit_not(par);
            if    (!type) return 0;
            
            return make (&op_t) from (
                3             ,
                opcode_bit_not,
                type          ,
                par           
            );
}