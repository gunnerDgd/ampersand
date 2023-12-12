#include "cls.h"
#include "details/cls.h"
#include "details/type.h"

obj_trait* ap_c_cls_t = &c_cls_t;

str* 
    ap_c_cls_name
        (ap_c_cls par)                                     {
            if (!par)                        return false_t;
            if (trait_of(par) != ap_c_cls_t) return false_t; c_cls* cls = par;

            return &cls->name;
}

ap_c_cls_elem 
    ap_c_cls_next
        (ap_c_cls par, ap_c_cls_elem par_elem)             {
            if (!par)                        return false_t;
            if (trait_of(par) != ap_c_cls_t) return false_t; c_cls* cls = par;

            if (!par_elem)                                {
                ap_c_cls_elem ret = list_begin(&cls->elem); 
                if (!ret)                         return 0;
                if (ret == list_end(&cls->elem))  return 0;

                return ret;
            }

            ap_c_cls_elem ret   = list_next(par_elem);
            if (!ret)                        return 0;
            if (ret == list_end(&cls->elem)) return 0;

            return ret;
}

str* 
    ap_c_cls_as_str
        (ap_c_cls par)                                     {
            if (!par)                        return false_t;
            if (trait_of(par) != ap_c_cls_t) return false_t; c_cls* cls = par;

            return &cls->cls_str;
}

str* 
    ap_c_cls_elem_name
        (ap_c_cls_elem par)                              {
            if (!par)                            return 0; c_cls_elem* elem = list_get(par);
            if (!elem)                           return 0;
            if (trait_of(elem) != &c_cls_elem_t) return 0;

            return &elem->name;
}

obj* 
    ap_c_cls_elem_type
        (ap_c_cls_elem par)                              {
            if (!par)                            return 0; c_cls_elem* elem = list_get(par);
            if (!elem)                           return 0;
            if (trait_of(elem) != &c_cls_elem_t) return 0;

            return elem->type;
}

str* 
    ap_c_cls_elem_type_name
        (ap_c_cls_elem par)                              {
            if (!par)                            return 0; c_cls_elem* elem = list_get(par);
            if (!elem)                           return 0;
            if (trait_of(elem) != &c_cls_elem_t) return 0;

            return &elem->type_name;
}

str* 
    ap_c_cls_elem_as_str
        (ap_c_cls_elem par)                              {
            if (!par)                            return 0; c_cls_elem* elem = list_get(par);
            if (!elem)                           return 0;
            if (trait_of(elem) != &c_cls_elem_t) return 0;

            return &elem->str;
}