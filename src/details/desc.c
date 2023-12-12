#include "desc.h"

obj_trait desc_t         = {
    .on_new   = &desc_new  ,
    .on_clone = &desc_clone,
    .on_ref   = 0          ,
    .on_del   = &desc_del  ,
    .size     = sizeof(desc)
};

bool_t 
    desc_new
        (desc* par_desc, u32_t par_count, va_list par)    {
            par_desc->desc_trait = va_arg(par, obj_trait*); if (!par_desc->desc_trait) return false_t;
            par_desc->run        = va_arg(par, desc_run *); if (!par_desc->run)        return false_t;

            par_desc->desc = vmake  (par_desc->desc_trait) from (par_count - 2, par);
            if (!par_desc->desc)
                return false_t;

            return true_t;
}

bool_t 
    desc_clone
        (desc* par, desc* par_clone)                                 {
            if (!(par->desc = clone(par_clone->desc))) return false_t;
            par->desc_trait = par_clone->desc_trait;
            par->run        = par_clone->run       ;
            
            return true_t;
}

bool_t
    desc_ref
        (desc* par)                   {
            par->desc = ref(par->desc);
            return true_t;
}

void
    desc_del
        (desc* par)       {
            del(par->desc);
}