#include "push.h"

#include "../../type.h"
#include "../../cls.h"
#include "../../var.h"

bool_t 
    c_op_as_push_type
        (c_op* par, ap_c_var par_var, ap_op_arg par_arg)                         {
            str_push_back     (&par->str, ap_c_type_name(ap_c_var_type(par_var)));
            str_push_back_cstr(&par->str, " ", 1)                                ;
            str_push_back     (&par->str, ap_c_var_as_str(par_var))              ;
            str_push_back_cstr(&par->str, " = ", 3)                              ;

            c_op_arg *arg = make (&c_op_arg_t) from (1, par_arg); 
            if      (!arg) return false_t;

            str_push_back (&par->str, &arg->str);
            list_push_back(&par->arg, par_var)  ;
            return true_t;
}

bool_t 
    c_op_as_push_cls
        (c_op* par, ap_c_var par_var, ap_op_arg par_arg)                        {
            str_push_back     (&par->str, ap_c_cls_name(ap_c_var_type(par_var)));
            str_push_back_cstr(&par->str, " ", 1)                               ;
            str_push_back     (&par->str, ap_c_var_as_str(par_var))             ;
            str_push_back_cstr(&par->str, " = {\n", 5)                          ;
                                    
            ap_c_cls_elem elem = ap_c_cls_next(ap_c_var_type(par_var), 0);
            for ( ; elem; elem = ap_c_cls_next(ap_c_var_type(par_var), elem)) {
                str_push_back_cstr(&par->str, "."  , 1)                ;
                str_push_back     (&par->str, ap_c_cls_elem_name(elem));
                str_push_back_cstr(&par->str, " = ", 3)                ;

                c_op_arg* arg = make (&c_op_arg_t) from (1, par_arg);
                if (!arg)         {
                    del (arg)     ;
                    return false_t;
                }

                str_push_back     (&par->str, &arg->str);
                str_push_back_cstr(&par->str, ",\n", 2) ;
                list_push_back    (&par->arg, arg)      ; del (arg);

                par_arg = ap_op_arg_next(par->op, par_arg);
            }

            if (str_ends_cstr(&par->str, ",\n", 2))
                str_pop_back (&par->str, 2);

            str_push_back_cstr(&par->str, "\n}", 2);
            return true_t;
}

bool_t 
    c_op_as_push
        (c_op* par)                                                                  {
            ap_op_arg push_op = ap_op_arg_next(par->op, 0)                           ; if (!push_op) return false_t;
            ap_c_var  push    = make (ap_c_var_t) from (1, ap_op_arg_as_var(push_op)); if (!push)    return false_t;

            list_push_back(&par->arg, push);
            if (trait_of(ap_c_var_type(push)) == ap_c_type_t)                        {
                if (!c_op_as_push_type(par, push, ap_op_arg_next(par->op, push_op))) {
                    del(push)     ;
                    return false_t;
                }

                return true_t;
            }

            if (trait_of(ap_c_var_type(push)) == ap_c_cls_t)                        {
                if (!c_op_as_push_cls(par, push, ap_op_arg_next(par->op, push_op))) {
                    del(push)     ;
                    return false_t;
                }

                return true_t;
            }

            return false_t;
}