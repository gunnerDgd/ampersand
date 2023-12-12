#include "op.h"

#include "../type.h"
#include "../cls.h"
#include "../var.h"
#include "../val.h"

obj_trait op_t         = {
    .on_new   = &op_new  ,
    .on_clone = &op_clone,
    .on_ref   = 0        ,
    .on_del   = &op_del  ,
    .size     = sizeof(op)
};

bool_t    
    op_new
        (op* par_op, u32_t par_count, va_list par) {
            if (par_count < 2) return false_t;
            par_op->op  = va_arg(par, u64_t) ;
            par_op->ret = va_arg(par, obj*)  ;

            if (!par_op->ret)                            return false_t; obj_trait* ret = trait_of(par_op->ret);
            if (ret != ap_type_t && ret != ap_cls_t)     return false_t;
            if (!make_at(&par_op->arg, list_t) from (0)) return false_t;

            par_count -= 2;
            while (par_count--) list_push_back(&par_op->arg, va_arg(par, obj*));

            return true_t;
}

bool_t
    op_clone
        (op* par, op* par_clone)                                     {
            if (!clone_at(&par->arg, &par_clone->arg)) return false_t;
            par->op  =     par_clone->op  ;
            par->ret = ref(par_clone->ret);

            return true_t;
}

void
    op_del
        (op* par)         {
            del (par->ret);
            del(&par->arg);
}