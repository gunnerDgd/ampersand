#include "arith.h"

bool_t 
    c_op_as_add
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " + ", 3);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_add_eq
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " += ", 4);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_sub
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " - ", 3);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_sub_eq
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " -= ", 4);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_mul
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " * ", 3);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_mul_eq
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " *= ", 4);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_div
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " / ", 3);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_div_eq
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " /= ", 4);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_mod
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " % ", 3);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}

bool_t 
    c_op_as_mod_eq
        (c_op* par)                                               {
            ap_op_arg op_arg     = ap_op_arg_next(par->op, 0)     ; if (!op_arg)     return false_t;
            ap_op_arg op_arg_rhs = ap_op_arg_next(par->op, op_arg); if (!op_arg_rhs) return false_t;

            c_op_arg* arg        = make (&c_op_arg_t) from (1, op_arg)    ;
            c_op_arg* arg_rhs    = make (&c_op_arg_t) from (1, op_arg_rhs);

            str_push_back(&par->str, &arg    ->str); str_push_back_cstr(&par->str, " %= ", 4);
            str_push_back(&par->str, &arg_rhs->str);

            list_push_back(&par->arg, arg)    ; del(arg)    ;
            list_push_back(&par->arg, arg_rhs); del(arg_rhs);
            return true_t;
}