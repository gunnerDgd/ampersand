 #include "var.h"

#include "../type.h"
#include "../var.h"
#include "../cls.h"

#include <string.h>

obj_trait var_t          = {
    .on_new   = &var_new   ,
    .on_clone = &var_clone ,
    .on_ref   = 0          ,
    .on_del   = &var_del   ,
    .size     = sizeof(var)
};

bool_t 
    var_new
        (var* par_var, u32_t par_count, va_list par)                    {
            obj* par_any = va_arg(par, obj*); 
            if (!par_any)                                 return false_t;
            if (!make_at(&par_var->name, str_t) from (0)) return false_t;
            if (trait_of(par_any) == ap_var_t)             {
                ap_cls_elem elem = va_arg(par, ap_cls_elem); if (!elem)                               goto new_failed;
                var*        self = par_any                 ; if (self->type != ap_cls_elem_cls(elem)) goto new_failed;

                par_var->self = ref(self)                            ;
                par_var->type = ref(ap_cls_elem_type(elem))          ;
                str_push_back(&par_var->name, ap_cls_elem_name(elem));

                return true_t;
            }

            obj*        type = par_any                 ;
            const char* name = va_arg(par, const char*);

            if (!type)                                                     goto new_failed;
            if (!name)                                                     goto new_failed;
            if (trait_of(type) != ap_type_t && trait_of(type) != ap_cls_t) goto new_failed;
            if (ap_type_id(type) == ap_type_id_none)                       goto new_failed;

            str_push_back_cstr(&par_var->name, name, strlen(name));
            par_var->type = ref(type);
            par_var->self = 0        ;

            return true_t;
    new_failed:
            del (&par_var->name);
            return false_t      ;
}

bool_t 
    var_clone
        (var* par, var* par_clone)                      {
            if(!clone_at(&par->name, &par_clone->name))
                return false_t;

            par->type = ref(par_clone->type);
            return true_t;
}

void
    var_del
        (var* par)         {
            del(&par->name);
            del (par->type);
            if  (par->self) del (par->self);
}