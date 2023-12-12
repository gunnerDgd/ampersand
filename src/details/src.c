#include "src.h"
#include "op.h"

bool_t 
    src_new
        (src* par_src, u32_t par_count, va_list par) {
            if (!make_at(&par_src->src, list_t) from (0))
                return false_t;

            while (par_count--)                                                   {
                op* op = va_arg(par, obj*);      if (!op) return false_t          ;
                if      (trait_of(op) == &op_t)  list_push_back(&par_src->src, op);
                else if (trait_of(op) == &src_t) list_push_back(&par_src->src, op);
                else                             goto new_failed                  ;
            }

            return true_t;
    new_failed:
            del (&par_src->src);
            return false_t     ;
}

bool_t 
    src_clone
        (src* par, src* par_clone)                     {
            return clone_at(&par->src, &par_clone->src);
}

void   
    src_del
        (src* par)         {
            del (&par->src);
}