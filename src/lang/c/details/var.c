#include "var.h"
#include "../../../util.h"

obj_trait c_var_t         = {
    .on_new   = &c_var_new  ,
    .on_clone = &c_var_clone,
    .on_ref   = 0           ,
    .on_del   = &c_var_del  ,
    .size     = sizeof(c_var)
};

bool_t 
    c_var_from_cls
        (c_var* par, ap_cls par_cls)                       {
            par->type = make (ap_c_cls_t) from (1, par_cls); 
            
            if (!par->type) return false_t;
            if (ap_var_self(par->var))                                           {
                str_push_back     (&par->str, ap_var_name(ap_var_self(par->var)));
                str_push_back_cstr(&par->str, ".", 1)                            ;
            }
                        
            str_push_back(&par->str, ap_var_name(par->var));
            par->type = make (ap_c_cls_t) from (1, par_cls);
            par->var  = ref(par->var);

            return true_t;
}

bool_t 
    c_var_from_type
        (c_var* par, ap_type par_type)                       {
            par->type = make (ap_c_type_t) from (1, par_type);

            if (!par->type) return false_t;
            if (ap_var_self(par->var))                                           {
                str_push_back     (&par->str, ap_var_name(ap_var_self(par->var)));
                str_push_back_cstr(&par->str, ".", 1)                            ;
            }
                
            str_push_back(&par->str, ap_var_name(par->var))  ;
            par->type = make (ap_c_type_t) from (1, par_type);
            par->var  = ref(par->var)                        ;
                
            return true_t;
}

bool_t 
    c_var_new
        (c_var* par_var, u32_t par_count, va_list par) {
            par_var->var = va_arg(par, ap_var);
            if (!make_at(&par_var->str, str_t) from(0)) return false_t;
            if (!ap_is_var(par_var->var))               return false_t; obj* type = ap_var_type(par_var->var);

            if (ap_is_cls (type)) if (!c_var_from_cls (par_var, type)) goto new_failed;
            if (ap_is_type(type)) if (!c_var_from_type(par_var, type)) goto new_failed;
            
            return true_t;
    new_failed:
            del (&par_var->str);
            return false_t;
}

bool_t 
    c_var_clone
        (c_var* par, c_var* par_clone)                {
            if (!clone_at(&par->str, &par_clone->str))
                return false_t;

            par->type = ref(par_clone->type);
            par->var  = ref(par_clone->var) ;

            return true_t;
}

void
    c_var_del
        (c_var* par)       {
            del (par->type);
            del (par->var) ;
            del(&par->str) ;
}