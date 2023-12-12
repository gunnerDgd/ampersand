#include "func.h"
#include "details/func.h"

obj* 
    ap_func_ret
        (ap_func par)                               {
            if (!par)                       return 0;
            if (trait_of(par) != ap_func_t) return 0; func* func = par;

            return func->ret;
}

ap_src
    ap_func_src
        (ap_func par)                               {
            if (!par)                       return 0;
            if (trait_of(par) != ap_func_t) return 0; func* func = par;

            return func->src;
}

ap_func_arg 
    ap_func_arg_next
        (ap_func par, ap_func_arg par_arg)          {
            if (!par)                       return 0;
            if (trait_of(par) != ap_func_t) return 0; func *func = par;
            if (!par_arg)                                {
                ap_func_arg ret = list_begin(&func->arg) ;
                if (!ret)                        return 0;
                if (ret == list_end(&func->arg)) return 0;

                return ret;
            }

            ap_func_arg ret = list_next(par_arg);
            if (!ret)                        return 0;
            if (ret == list_end(&func->arg)) return 0;

            return ret;
}

obj* 
    ap_func_arg_type
        (ap_func_arg par)                          {
            if (!par)                      return 0; obj* ret = list_get(par);
            if (!ret)                      return 0;
            if (trait_of(ret) != ap_var_t) return 0;

            return ap_var_type(ret);
}

str* 
    ap_func_arg_name
        (ap_func_arg par)                          {
            if (!par)                      return 0; obj* ret = list_get(par);
            if (!ret)                      return 0;
            if (trait_of(ret) != ap_var_t) return 0;

            return ap_var_name(ret);
}