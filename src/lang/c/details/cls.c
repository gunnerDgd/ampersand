#include "cls.h"
#include "type.h"

obj_trait c_cls_elem_t         = {
    .on_new   = &c_cls_elem_new  ,
    .on_clone = &c_cls_elem_clone,
    .on_ref   = 0                ,
    .on_del   = &c_cls_elem_del  ,
    .size     = sizeof(c_cls_elem)
};

bool_t 
    c_cls_elem_new
        (c_cls_elem* par_elem, u32_t par_count, va_list par)                                {
            ap_cls_elem elem      = va_arg(par, ap_cls_elem); if (!elem)      return false_t;
            obj        *elem_type = ap_cls_elem_type(elem)  ; if (!elem_type) return false_t;

            if (!make_at(&par_elem->name     , str_t) from(0)) return false_t;
            if (!make_at(&par_elem->type_name, str_t) from(0)) return false_t;
            if (!make_at(&par_elem->str      , str_t) from(0)) return false_t;

            str_push_back(&par_elem->name, ap_cls_elem_name(elem));
            if      (trait_of(elem_type) == ap_cls_t)               {
                c_cls* cls = make(&c_cls_t) from (1, elem_type)     ; if (!cls) return false_t;
                str_push_back(&par_elem->type_name, &cls->name)     ;
                str_push_back(&par_elem->str      , &cls->name)     ; str_push_back_cstr(&par_elem->str, " ", 1);
                str_push_back(&par_elem->str      , &par_elem->name);

                par_elem->type = cls;
            }
            else if (trait_of(elem_type) == ap_type_t)              {
                c_type* type = make (&c_type_t) from (1, elem_type) ; if (!type) return false_t;
                str_push_back(&par_elem->type_name, &type->name)    ;
                str_push_back(&par_elem->str      , &type->name)    ; str_push_back_cstr(&par_elem->str, " ", 1);
                str_push_back(&par_elem->str      , &par_elem->name);

                par_elem->type = type;
            }

            return true_t;
}

bool_t 
    c_cls_elem_clone
        (c_cls_elem* par, c_cls_elem* par_clone) {
            par->type = ref (par_clone->type);
            if (!clone_at(&par->name     , &par_clone->name))      return false_t;
            if (!clone_at(&par->type_name, &par_clone->type_name)) return false_t;
            if (!clone_at(&par->str      , &par_clone->str))       return false_t;

            return true_t;
}

void
    c_cls_elem_del
        (c_cls_elem* par)        {
            del (&par->name)     ;
            del (&par->type_name);
            del (&par->str)      ;

            del (par->type);
}

obj_trait c_cls_t         = {
    .on_new   = &c_cls_new  ,
    .on_clone = &c_cls_clone,
    .on_ref   = 0           ,
    .on_del   = &c_cls_del  ,
    .size     = sizeof(c_cls)
};

bool_t 
    c_cls_new
        (c_cls* par_cls, u32_t par_count, va_list par)                     {
            par_cls->cls = va_arg(par, ap_cls);
            if (!par_cls->cls)                               return false_t;
            if (trait_of(par_cls->cls) != ap_cls_t)          return false_t;
            if (!make_at(&par_cls->name   , str_t) from(0))  return false_t;
            if (!make_at(&par_cls->cls_str, str_t) from(0))  return false_t;
            if (!make_at(&par_cls->elem   , list_t) from(0)) return false_t;
            
            str_push_back_cstr(&par_cls->name, "struct ", 7)             ;
            str_push_back     (&par_cls->name, ap_cls_name(par_cls->cls));

            str_push_back_cstr(&par_cls->cls_str, "struct ", 7)             ;
            str_push_back     (&par_cls->cls_str, ap_cls_name(par_cls->cls));
            str_push_back_cstr(&par_cls->cls_str, "{\n", 2)                 ;

            ap_cls_elem cls_elem = ap_cls_next(par_cls->cls, 0);
            for ( ; cls_elem ; cls_elem = ap_cls_next(par_cls->cls, cls_elem)) {
                c_cls_elem *elem = make (&c_cls_elem_t) from (1, cls_elem);
                if        (!elem) continue;

                str_push_back     (&par_cls->cls_str, &elem->str);
                str_push_back_cstr(&par_cls->cls_str, ";\n", 2)  ;
                list_push_back    (&par_cls->elem   , elem)      ;
                del                                  (elem)      ;
            }

            str_push_back_cstr(&par_cls->cls_str, "}", 2);

            par_cls->cls = ref(par_cls->cls);
            return true_t;
}

bool_t 
    c_cls_clone
        (c_cls* par, c_cls* par_clone)                                      {
            if(!clone_at(&par->name   , &par_clone->name))    return false_t;
            if(!clone_at(&par->cls_str, &par_clone->cls_str)) return false_t;
            if(!clone_at(&par->elem   , &par_clone->elem))    return false_t;

            par->cls = ref(par_clone->cls);
            return true_t;
}

void
    c_cls_del
        (c_cls* par)          {
            del(&par->name)   ;
            del(&par->elem)   ;
            del(&par->cls_str);
            del (par->cls)    ;
}