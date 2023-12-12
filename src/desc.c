#include "desc.h"
#include "details/desc.h"
#include "details/op.h"

obj_trait* ap_desc_t = &desc_t;

bool_t 
    ap_desc_op
        (ap_desc par, ap_op par_op)                          {
            if (!par)                          return false_t; 
            if (!par_op)                       return false_t;

            if (trait_of(par)    != ap_desc_t) return false_t; desc* desc = par;
            if (trait_of(par_op) != &op_t)     return false_t;

            u64_t opcode = ap_op_opcode(par_op);
            if (!desc->run->op_func[opcode])                     return false_t;
            if (!desc->run->op_func[opcode](desc->desc, par_op)) return false_t;

            return true_t;
}

bool_t 
    ap_desc_var
        (ap_desc par, ap_var par_op)                         {
            if (!par)                          return false_t; 
            if (!par_op)                       return false_t;

            if (trait_of(par)    != ap_desc_t) return false_t; desc* desc = par;
            if (trait_of(par_op) != ap_var_t)  return false_t;

            if (!desc->run->var)                     return false_t;
            if (!desc->run->var(desc->desc, par_op)) return false_t;

            return true_t;
}

bool_t 
    ap_desc_type
        (ap_desc par, ap_var par_op)                         {
            if (!par)                          return false_t; 
            if (!par_op)                       return false_t;

            if (trait_of(par)    != ap_desc_t) return false_t; desc* desc = par;
            if (trait_of(par_op) != ap_type_t) return false_t;

            if (!desc->run->type)                     return false_t;
            if (!desc->run->type(desc->desc, par_op)) return false_t;

            return true_t;
}

bool_t 
    ap_desc_cls
        (ap_desc par, ap_var par_op)                         {
            if (!par)                          return false_t; 
            if (!par_op)                       return false_t;

            if (trait_of(par)    != ap_desc_t) return false_t; desc* desc = par;
            if (trait_of(par_op) != ap_cls_t)  return false_t;

            if (!desc->run->cls)                     return false_t;
            if (!desc->run->cls(desc->desc, par_op)) return false_t;

            return true_t;
}

bool_t 
    ap_desc_val
        (ap_desc par, ap_var par_op)                         {
            if (!par)                          return false_t; 
            if (!par_op)                       return false_t;

            if (trait_of(par)    != ap_desc_t) return false_t; desc* desc = par;
            if (trait_of(par_op) != ap_val_t)  return false_t;

            if (!desc->run->val)                     return false_t;
            if (!desc->run->val(desc->desc, par_op)) return false_t;

            return true_t;
}