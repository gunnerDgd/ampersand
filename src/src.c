#include "src.h"
#include "details/src.h"

ap_src_elem 
    ap_src_next
        (ap_src par, ap_src_elem par_elem)         {
            if (!par)                      return 0;
            if (trait_of(par) != ap_src_t) return 0; src* src = par;
            if (!par_elem)                              {
                ap_src_elem ret = list_begin(&src->src) ;
                if (!ret)                       return 0;
                if (ret == list_end(&src->src)) return 0;

                return ret;
            }

            ap_src_elem ret = list_next(par_elem);
            if (!ret)                 return 0;
            if (ret == list_end(ret)) return 0;

            return ret;
}

ap_src
    ap_src_elem_as_src
        (ap_src_elem par)                          {
            if (!par)                      return 0; ap_src src = list_get(par);
            if (!src)                      return 0;
            if (trait_of(src) != ap_src_t) return 0;

            return src;
}

ap_op
    ap_src_elem_as_op
        (ap_src_elem par)                         {
            if (!par)                     return 0; ap_op op = list_get(par);
            if (!op)                      return 0;
            if (trait_of(op) != ap_src_t) return 0;

            return op;
}