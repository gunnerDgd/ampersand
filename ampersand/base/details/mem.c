#include "mem.h"
#include "alloc.h"

__mem*
    __mem_init
        (__alloc* par_alloc, u64_t par_alloc_size) {
            return par_alloc->handle_trait->mem_init(par_alloc, par_alloc_size);
}

__mem*
    __mem_init_as_clone
        (__mem* par_mem_clone) {
            __alloc *ret_alloc = par_mem_clone->alloc;
            __mem   *ret       = ret_alloc->handle_trait->mem_init_as_clone(ret_alloc, par_mem_clone);
            return   ret;
}

void
    __mem_deinit
        (__mem *par_mem) {
            __alloc *ret_alloc = par_mem->alloc;
                     ret_alloc->handle_trait->mem_deinit(ret_alloc, par_mem);
}