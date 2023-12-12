#include "op.h"

#include "op/arith.h"
#include "op/bit.h"
#include "op/cmp.h"
#include "op/logical.h"
#include "op/push.h"
#include "op/pop.h"
#include "op/mov.h"

bool_t (*c_op_as[])(c_op*)                    = {
    [ap_opcode_none]       = 0                  ,

    [ap_opcode_add]        = &c_op_as_add       ,
    [ap_opcode_add_eq]     = &c_op_as_add_eq    ,

    [ap_opcode_sub]        = &c_op_as_sub       ,
    [ap_opcode_sub_eq]     = &c_op_as_sub_eq    ,

    [ap_opcode_mul]        = &c_op_as_mul       ,
    [ap_opcode_mul_eq]     = &c_op_as_mul_eq    ,

    [ap_opcode_div]        = &c_op_as_div       ,
    [ap_opcode_div_eq]     = &c_op_as_div_eq    ,

    [ap_opcode_mod]        = &c_op_as_mod       ,
    [ap_opcode_mod_eq]     = &c_op_as_mod_eq    ,

    [ap_opcode_shl]        = &c_op_as_shl       ,
    [ap_opcode_shl_eq]     = &c_op_as_shl_eq    ,

    [ap_opcode_shr]        = &c_op_as_shr       ,
    [ap_opcode_shr_eq]     = &c_op_as_shr_eq    ,

    [ap_opcode_bit_and]    = &c_op_as_bit_and   ,
    [ap_opcode_bit_and_eq] = &c_op_as_bit_and_eq,

    [ap_opcode_bit_or]     = &c_op_as_bit_or    ,
    [ap_opcode_bit_or_eq]  = &c_op_as_bit_or_eq ,

    [ap_opcode_bit_xor]    = &c_op_as_bit_xor   ,
    [ap_opcode_bit_xor_eq] = &c_op_as_bit_xor_eq,

    [ap_opcode_bit_not]    = &c_op_as_bit_not   ,

    [ap_opcode_eq]         = &c_op_as_eq        ,
    [ap_opcode_neq]        = &c_op_as_neq       ,

    [ap_opcode_gt]         = &c_op_as_gt        ,
    [ap_opcode_gt_eq]      = &c_op_as_gt_eq     ,

    [ap_opcode_lt]         = &c_op_as_lt        ,
    [ap_opcode_lt_eq]      = &c_op_as_lt_eq     ,

    [ap_opcode_and]        = &c_op_as_and       ,
    [ap_opcode_or]         = &c_op_as_or        ,
    [ap_opcode_not]        = &c_op_as_not       ,

    [ap_opcode_push]       = &c_op_as_push      ,
    [ap_opcode_pop]        = &c_op_as_pop       ,
    [ap_opcode_mov]        = &c_op_as_mov       
};

obj_trait c_op_arg_t         = {
    .on_new   = &c_op_arg_new  ,
    .on_clone = &c_op_arg_clone,
    .on_ref   = 0              ,
    .on_del   = &c_op_arg_del  ,
    .size     = sizeof(c_op_arg)
};

bool_t 
    c_op_arg_new
        (c_op_arg* par_arg, u32_t par_count, va_list par) {
            ap_op_arg arg = va_arg(par, ap_op_arg);
            if (!arg)                                    return false_t;
            if (!make_at(&par_arg->str, str_t) from (0)) return false_t;

            par_arg->arg = 0;
            if (ap_op_arg_as_var(arg))                                          {
                par_arg->arg = make (ap_c_var_t) from (1, ap_op_arg_as_var(arg)); if (!par_arg->arg) return false_t;
                str_push_back(&par_arg->str, ap_c_var_as_str(par_arg->arg));

                return true_t;
            }

            if (ap_op_arg_as_val(arg))                                          {
                par_arg->arg = make (ap_c_val_t) from (1, ap_op_arg_as_val(arg)); if (!par_arg->arg) return false_t;
                str_push_back(&par_arg->str, ap_c_val_as_str(par_arg->arg))     ;

                return true_t;
            }

            if (ap_op_arg_as_op(arg))                                   {
                c_op* op = make (&c_op_t) from (1, ap_op_arg_as_op(arg)); if (!op) return false_t;
                str_push_back_cstr(&par_arg->str, "(", 1)               ; str_push_back(&par_arg->str, &op->str);
                str_push_back_cstr(&par_arg->str, ")", 1)               ;

                return true_t;
            }
            
            return false_t;
}

bool_t 
    c_op_arg_clone
        (c_op_arg* par, c_op_arg* par_clone) {
            if (!clone_at(&par->str, &par_clone->str)) 
                return false_t;

            par->arg = clone(par_clone->arg);
            if (!par->arg)     {
                del (&par->str);
                return false_t ;
            }

            return true_t;
}

void
    c_op_arg_del
        (c_op_arg* par)   {
            del (par->arg);
            del(&par->str);
}

obj_trait c_op_t         = {
    .on_new   = &c_op_new  ,
    .on_clone = &c_op_clone,
    .on_ref   = 0          ,
    .on_del   = &c_op_del  ,
    .size     = sizeof(c_op)
};

bool_t 
    c_op_new
        (c_op* par_op, u32_t par_count, va_list par)                  {
            par_op->op = va_arg(par, ap_op);
            if (!par_op->op)                            return false_t;
            if (trait_of(par_op->op) != ap_op_t)        return false_t;

            if (!make_at(&par_op->str, str_t)  from(0)) return false_t;
            if (!make_at(&par_op->arg, list_t) from(0)) return false_t;

            u64_t opcode = ap_op_opcode(par_op->op);
            if (!c_op_as[opcode])         goto new_failed;
            if (!c_op_as[opcode](par_op)) goto new_failed;

            return true_t;
    new_failed:
            del (&par_op->str);
            del (&par_op->arg);
            return false_t;
}

bool_t 
    c_op_clone
        (c_op* par, c_op* par_clone)            {
            par->op = ref(par_clone->op)        ;
            clone_at(&par->arg, &par_clone->arg);
            clone_at(&par->str, &par_clone->str);

            return true_t;
}

void   
    c_op_del
        (c_op* par)       {
            del(&par->arg);
            del(&par->str);
            del (par->op) ;
}