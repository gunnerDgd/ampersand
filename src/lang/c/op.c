#include "op.h"
#include "details/op.h"

obj_trait* ap_c_op_t = &c_op_t;

ap_c_op_arg 
    ap_c_op_arg_next
        (ap_c_op par, ap_c_op_arg par_arg)          {
            if (!par)                       return 0;
            if (trait_of(par) != ap_c_op_t) return 0; c_op* op = par;

            if (!par_arg)                              {
                ap_c_op_arg ret = list_begin(&op->arg) ;
                if (!ret)                      return 0;
                if (ret == list_end(&op->arg)) return 0;

                return ret;
            }

            ap_c_op_arg ret = list_next(&op->arg)  ;
            if (!ret)                      return 0;
            if (ret == list_end(&op->arg)) return 0;

            return ret;
}

str* 
    ap_c_op_arg_as_str
        (ap_c_op_arg par)                             {
            if (!par)                         return 0; c_op_arg* arg = list_get(par);
            if (!arg)                         return 0;
            if (trait_of(arg) != &c_op_arg_t) return 0;

            return &arg->str;
}

str* 
    ap_c_op_as_str
        (ap_c_op par)                               {
            if (!par)                       return 0;
            if (trait_of(par) != ap_c_op_t) return 0; c_op* op = par;

            return &op->str;
}