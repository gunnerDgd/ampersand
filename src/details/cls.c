#include "cls.h"
#include "var.h"

#include <string.h>

obj_trait cls_t          = {
    .on_new   = &cls_new   ,
    .on_clone = &cls_clone ,
    .on_ref   = 0          ,
    .on_del   = &cls_del   ,
    .size     = sizeof(cls)
};

bool_t
    cls_new
        (cls* par_cls, u32_t par_count, va_list par)                    {
            if (!make_at(&par_cls->elem, list_t) from(0)) return false_t;
            if (!make_at(&par_cls->name, str_t)  from(0)) return false_t;

            const char* name = va_arg(par, const char*);
            if        (!name) return false_t;

            str_push_back_cstr(&par_cls->name, name, strlen(name));
            if (!make_at(&par_cls->elem, list_t) from(0)) {
                del(&par_cls->name);
                return false_t     ;
            }

            return true_t;
    new_failed:
            del(&par_cls->elem);
            del(&par_cls->name);

            return false_t;
}

bool_t
    cls_clone
        (cls* par, cls* par_clone)                                     {
            if (!clone_at(&par->name, &par_clone->name)) return false_t;
            if (!clone_at(&par->elem, &par_clone->elem)) {
                del (&par->name);
                return false_t  ;
            }

            return true_t;
}

void      
    cls_del     
        (cls* par)         {
            del(&par->name);
            del(&par->elem);
}