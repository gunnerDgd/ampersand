#include "arith.h"
#include "../details/op.h"

#include "../type.h"
#include "../val.h"
#include "../var.h"
#include "../util.h"

obj* 
    ap_op_pop
        (ap_var par)                               {
            if (!par)                      return 0;
            if (!ap_can_pop(par))          return 0;
            if (trait_of(par) != ap_var_t) return 0;

            return make (&op_t) from (
                3         ,
                opcode_pop,
                ap_none   ,
                par
            );
}