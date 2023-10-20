#include "mem.h"
#include "details/mem.h"

#include "default.h"

mem
    mem_init(alloc* par_alloc, u64_t par_alloc_size) {
        if (!par_alloc) {
            par_alloc = get_alloc();
            if (!par_alloc) return 0;
        }

        if (!par_alloc_size) return 0;

        __mem*  ret = __mem_init(par_alloc, par_alloc_size);
        if (!ret)
            return 0;
        if (!ret->trait) {
            __mem_deinit(ret);
            return 0;
        }

        return ret;
}

mem
    mem_init_as_clone(mem par_clone) {
        if (!par_clone) return 0;
        return __mem_init_as_clone(par_clone);
}

void
    mem_deinit(mem par_deinit) {
        __mem_deinit(par_deinit);
}

u64_t
    mem_size(mem par_mem) {
        return ((__mem*)par_mem)->alloc_size;
}

u8_t*
    mem_raw_ptr
        (mem par_mem) {
            return ((__mem*)par_mem)->ptr;
}