#include "op.h"
#include "details/op.h"

#include "type.h"
#include "val.h"

obj_trait* ap_op_t = &op_t;

ap_type
    ap_op_ret
        (ap_op par)                             {
            if (!par)                   return 0;
            if (trait_of(par) != &op_t) return 0; op* op = par;

            return op->ret;
}

u64_t     
    ap_op_opcode
        (ap_op par)                             {
            if (!par)                   return 0;
            if (trait_of(par) != &op_t) return 0; op* op = par;
            
            return op->op;
}

ap_op_arg 
    ap_op_arg_next
        (ap_op par, ap_op_arg par_arg) {
            if (!par)                   return 0;
            if (trait_of(par) != &op_t) return 0; op* op = par;

            if (!par_arg)                           {
                ap_op_arg ret = list_begin(&op->arg); if (ret == list_end(&op->arg)) return 0;
                return    ret;
            }

            ap_op_arg ret = list_next(par_arg); if (ret == list_end(&op->arg)) return 0;
            return    ret;
}

ap_op
    ap_op_arg_as_op
        (ap_op_arg par)                        {
            if (!par)                  return 0; obj* op = list_get(par);
            if (trait_of(op) != &op_t) return 0;

            return op;
}

ap_var    
    ap_op_arg_as_var
        (ap_op_arg par)                            {
            if (!par)                      return 0; obj* var = list_get(par);
            if (trait_of(var) != ap_var_t) return 0;

            return var;
}

ap_val
    ap_op_arg_as_val
        (ap_op_arg par)                            {
            if (!par)                      return 0; obj* val = list_get(par);
            if (trait_of(val) != ap_val_t) return 0;

            return val;
}

ap_type
    ap_op_arg_as_type
        (ap_op_arg par)                              {
            if (!par)                        return 0; obj* type = list_get(par);
            if (trait_of(type) != ap_type_t) return 0;

            return type;
}

ap_cls
    ap_op_arg_as_cls
        (ap_op_arg par)                             {
            if (!par)                       return 0; obj* cls = list_get(par);
            if (trait_of(cls) != ap_type_t) return 0;

            return cls;
}