#include "push.h"

#include "../type.h"
#include "../../type.h"

#include "../var.h"
#include "../cls.h"
#include "../../cls.h"

#include "../../util.h"

bool_t 
    ap_can_push
        (obj* par_push, u32_t par_count, ...) {
            va_list  par            ;
            va_start(par, par_count); obj* ret = ap_can_push(par_push, par_count, par);
            va_end  (par)           ;
            return   par            ;
}

bool_t 
    ap_can_push_va
        (obj* par_push, u32_t par_count, va_list par) {
            if (ap_var_self(par_push))  return false_t;
            if (ap_is_type(ap_type_of(par_push)))     {
                obj* arg = va_arg(par, obj*);
                if (!arg)                         return false_t;
                if (!ap_is_type(ap_type_of(arg))) return false_t;
                if (!ap_is_none(ap_type_of(arg))) return false_t;

                if (ap_is_none(ap_type_of(par_push)))         return false_t;
                if (ap_is_bool(par_push) && !ap_is_bool(arg)) return false_t;

                return true_t;
            }

            if (ap_is_cls(ap_type_of(par_push)))           {
                ap_cls      cls      = ap_type_of(par_push);
                ap_cls_elem cls_elem = ap_cls_next(cls, 0) ;

                for ( ; cls_elem ; cls_elem = ap_cls_next(cls, cls_elem))           {
                    obj *arg      = va_arg(par, obj*); if (!arg)      return false_t;
                    obj *arg_type = ap_type_of(arg)  ; if (!arg_type) return false_t;

                    if (ap_is_type(ap_cls_elem_type(cls_elem)))                                            {
                        if (ap_is_bool(ap_cls_elem_type(cls_elem)) && !ap_is_bool(arg_type)) return false_t;
                        if (ap_is_none(arg_type))                                            return false_t;
                    }

                    if (ap_is_cls(ap_cls_elem_type(cls_elem))) {
                        if (ap_cls_neq(ap_cls_elem_type(cls_elem), arg_type))
                            return false_t;
                    }
                }

                return true_t;
            }

            return false_t;
}

obj* 
    ap_ret_push
        (obj* par_push, u32_t par_count, ...) {
            va_list  par            ;
            va_start(par, par_count); obj* ret = ap_ret_push(par_push, par_count, par);
            va_end  (par)           ;
            return   par;
}

obj* 
    ap_ret_push_va
        (obj* par_push, u32_t par_count, va_list par) {
            return ap_none;
}