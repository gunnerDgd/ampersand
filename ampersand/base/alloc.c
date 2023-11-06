#include "alloc.h"
#include "details/alloc.h"

#include "mem.h"
#include "details/mem.h"

#ifdef PRESET_ENV_CSTD
#include "preset/cstd/alloc.h"
#include "preset/cstd/mem.h"

__alloc_trait *global_alloc_trait = &cstd_alloc_trait;
__alloc       *global_alloc       = &cstd_alloc      ;
#else
__alloc_trait *global_alloc_trait = 0;
__alloc       *global_alloc       = 0;
#endif

bool_t
    alloc_init
        (alloc* par, alloc_trait par_trait) {
            if (!par)       return false_t;
            if (!par_trait) par_trait = global_alloc_trait;
            if (!par_trait) return false_t;

            return (par_trait) ? __alloc_init(par, par_trait) : false_t;
}

bool_t
    alloc_init_as_clone
        (alloc * par, alloc *par_clone) {
            return __alloc_init_as_clone(par, par_clone);
}

void
    alloc_deinit
        (alloc* par) {
            __alloc_deinit(par);
}

u64_t
    alloc_unit_size
        (alloc* par) {
            return ((__alloc*)par)->trait->unit_size;
}

u64_t
    alloc_unit_align
        (alloc* par) {
            return ((__alloc*)par)->trait->unit_align;
}

u64_t
    alloc_max_size
        (alloc* par) {
            return ((__alloc*)par)->trait->max_size;
}

alloc*		 
    get_alloc() {
        return global_alloc;
}

alloc_trait
    get_alloc_trait() {
        return global_alloc_trait;
}

alloc*		 
    set_alloc(alloc* par) {
        alloc* ret = global_alloc;
        
        global_alloc = par;
        return ret;
}

alloc_trait 
    set_alloc_trait(alloc_trait par) {
        alloc_trait ret = global_alloc_trait;

        global_alloc_trait = par;
        return ret;
}