#include "mov.h"

bool_t 
    c_op_as_mov
        (c_op* par)                                               {
            ap_op_arg op_mov     = ap_op_arg_next(par->op, 0)     ;
            ap_op_arg op_mov_arg = ap_op_arg_next(par->op, op_mov);

            c_op_arg* mov     = make (&c_op_arg_t) from (1, op_mov)    ; if (!mov) return false_t;
            c_op_arg* mov_arg = make (&c_op_arg_t) from (1, op_mov_arg);

            if (!mov_arg)     {
                del (mov)     ;
                return false_t;
            }

            list_push_back(&par->arg, mov)    ; del (mov)    ;
            list_push_back(&par->arg, mov_arg); del (mov_arg);

            str_push_back(&par->str, &mov    ->str); str_push_back_cstr(&par->str, " = ", 3);
            str_push_back(&par->str, &mov_arg->str);

            return true_t;
}