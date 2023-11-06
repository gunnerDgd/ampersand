#include "mem.h"
#include "alloc.h"

__mem*
    __mem_init
        (__alloc* par, u64_t par_size) {
            return par->trait->mem_init(par, par_size);
}

__mem*
    __mem_init_as_clone
        (__mem* par) {
            __alloc *ret_alloc = par->alloc;
            
            if (!ret_alloc)        return false_t;
            if (!ret_alloc->trait) return false_t;

            __mem   *ret = ret_alloc->trait->mem_init_as_clone(ret_alloc, par);
            return   ret;
}

void
    __mem_deinit
        (__mem *par_mem) {
            __alloc *ret = par_mem->alloc;
                     ret->trait->mem_deinit(ret, par_mem);
}