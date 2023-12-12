#include "arith.h"
#include "../details/op.h"

#include "../type.h"
#include "../val.h"
#include "../var.h"

obj* 
    ap_op_mov
        (obj* par, obj* par_arg)                   {
            if (!par)                      return 0;
            if (trait_of(par) != ap_var_t) return 0;

            obj *type_arg = ap_type_of(par_arg),
                *type     = ap_type_of(par)    ;

            if (!type)                                             return false_t;
            if (!type_arg)                                         return false_t;
            if (trait_of(par) != ap_var_t)                         return false_t;

            if (ap_type_cls (type) && ap_type_neq(type_arg, type)) return false_t;
            if (ap_type_none(type))                                return false_t;
            if (ap_type_none(type_arg))                            return false_t;
            
            return make (&op_t) from (
                4         ,
                opcode_mov,
                type      ,
                par       ,
                par_arg
            );
}