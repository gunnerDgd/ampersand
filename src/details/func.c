#include "func.h"

bool_t 
    func_new
        (func* par_func, u32_t par_count, va_list par)                    {
            if (!make_at(&par_func->name, str_t)  from (0)) return false_t;
            if (!make_at(&par_func->arg , list_t) from (0)) return false_t;

            par_func->src = va_arg(par, ap_src);
            if (!par_func->src)                      return false_t;
            if (trait_of(par_func->src) != ap_src_t) return false_t;

            obj* ret = va_arg(par, obj*); 
            if      (!ret)                       return false_t     ;
            if      (trait_of(ret) == ap_type_t) par_func->ret = ret;
            else if (trait_of(ret) == ap_cls_t)  par_func->ret = ret;
            else                                 return false_t     ;

            par_count -= 2;
            while (par_count--)                 {
                obj *par_arg = va_arg(par, obj*);
                if (!par_arg)                      return false_t;
                if (trait_of(par_arg) != ap_var_t) return false_t;

                obj* arg = clone(par_arg); 
                if (!arg) return false_t ; list_push_back(&par_func->arg, arg); 
                del (arg);
            }

            par_func->ret = ref(par_func->ret);
            par_func->src = ref(par_func->src);
            return true_t;
}

bool_t 
    func_clone
        (func* par, func* par_clone) {
            return false_t;
}

void
    func_del
        (func* par)        {
            del(&par->name);
            del(&par->arg) ;
            del (par->src) ;
            del (par->ret) ;
}