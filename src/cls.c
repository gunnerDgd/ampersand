#include "cls.h"
#include "details/cls.h"
#include "details/var.h"

#include <string.h>

obj_trait* ap_cls_t = &cls_t;

str* 
    ap_cls_name
        (ap_cls par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_cls_t) return 0; cls* ret = par;

            return &ret->name;
}

ap_cls_elem 
    ap_cls_add
        (ap_cls par, obj* par_type, const char* par_var) {
            if (!par)                      return 0;
            if (!par_type)                 return 0;
            if (!par_var)                  return 0;
            if (trait_of(par) != ap_cls_t) return 0; cls* cls = par;
            
            var *ret = make (&var_t) from (2, par_type, par_var);
            if (!ret) return 0;

            ret->self = ref(par);
            return list_push_back(&cls->elem, ret);
}

void
    ap_cls_del
        (ap_cls par, ap_cls_elem par_elem)              {
            if (!par)                           return 0;
            if (trait_of(par) != ap_cls_t)      return 0; cls* cls      = par               ;
            if (!par_elem)                      return 0; var* cls_elem = list_get(par_elem);
            
            if (!cls_elem)                      return 0;
            if (trait_of(cls_elem) != ap_var_t) return 0;
            if (cls_elem->self != par)          return 0;

            list_pop(&cls->elem, par_elem);
}

ap_cls_elem 
    ap_cls_get
        (ap_cls par, const char* par_elem)         {
            if (!par)                      return 0;
            if (trait_of(par) != ap_cls_t) return 0; cls* cls = par;

            list_for (&cls->elem, elem_it)   {
                var* elem = list_get(elem_it);
                if (!elem)                                                continue      ;
                if (trait_of(elem) != ap_var_t)                           continue      ;
                if (str_eq_cstr(&elem->name, par_elem, strlen(par_elem))) return elem_it;
            }

            return 0;
}

ap_cls_elem
    ap_cls_next
        (ap_cls par, ap_cls_elem par_var)          {
            if (!par)                      return 0;
            if (trait_of(par) != ap_cls_t) return 0; 
            
            cls*        ret_cls = par;
            ap_cls_elem ret;

            if (!par_var) ret = list_begin(&ret_cls->elem);
            else          ret = list_next (par_var)       ;

            if (ret == list_end(&ret_cls->elem))
                return 0;

            return ret;
}

str* 
    ap_cls_elem_name
        (ap_cls_elem par)                                {
            if (!par)                      return false_t; var* ret = list_get(par);
            if (!ret)                      return false_t;
            if (trait_of(ret) != ap_var_t) return false_t;

            return &ret->name;
}

obj* 
    ap_cls_elem_type
        (ap_cls_elem par)                                {
            if (!par)                      return false_t; var* ret = list_get(par);
            if (!ret)                      return false_t;
            if (trait_of(ret) != ap_var_t) return false_t;

            return ret->type;
}

ap_cls
    ap_cls_elem_cls
        (ap_cls_elem par)                                {
            if (!par)                      return false_t; var* ret = list_get(par);
            if (!ret)                      return false_t;
            if (trait_of(ret) != ap_var_t) return false_t;

            return ret->self;
}