#include "mem.h"
#include "details/mem.h"
#include "details/ptr.h"
mem
    mem_init
        (alloc* par, u64_t par_size) {
        if (!par)      par = get_alloc();
        if (!par)      return 0;
        if (!par_size) return 0;

        __mem*  ret = __mem_init(par, par_size);
        if    (!ret)                             return 0;
        if    (!ret->trait) { __mem_deinit(ret); return 0; }

        return ret;
}

mem
    mem_init_as_clone
        (mem par) {
        if (!par) return 0;
        return __mem_init_as_clone(par);
}

void
    mem_deinit
        (mem par) {
            __mem_deinit(par);
}

u64_t mem_size(mem par) { return ((__mem*)par)->alloc_size; }
ptr   mem_ptr (mem par) {
    ptr    ret;
    __ptr* ret_ptr =     &ret;
           ret_ptr->cur =   0;
           ret_ptr->mem = par;
    return ret;
}