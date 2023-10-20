#include "alloc.h"
#include "details/alloc.h"

#include "mem.h"
#include "details/mem.h"

#include "default.h"

#ifdef PRESET_DEFAULT_BAREMETAL

alloc       *default_alloc       = 0;
alloc_trait *default_alloc_trait = 0;

alloc* 
    get_alloc() {
        return default_alloc;
}

alloc_trait* 
    get_alloc_trait() {
        return default_alloc_trait;
}

alloc* 
    set_alloc(alloc* par_alloc) {
        alloc* ret    = default_alloc;
        default_alloc = par_alloc    ;

        return ret;
}

alloc_trait* 
    set_alloc_trait(alloc_trait* par_trait) {
        alloc_trait* ret    = default_alloc_trait;
        default_alloc_trait = par_trait          ;

        return ret;
}

#endif

#ifdef PRESET_DEFAULT_CSTD
#include <string.h>
#include <stdlib.h>

bool_t 
    cstd_mem_rd8
        (void* par_ptr, u8_t* par_rd) {
            *par_rd = *((u8_t*)par_ptr);
            return true_t; 
}

bool_t 
    cstd_mem_rd16
        (void* par_ptr, u16_t* par_rd) {
            *par_rd = *((u16_t*)par_ptr);
            return true_t; 
}

bool_t 
    cstd_mem_rd32
        (void* par_ptr, u32_t* par_rd) {
            *par_rd = *((u32_t*)par_ptr);
            return true_t; 
}

bool_t 
    cstd_mem_rd64
        (void* par_ptr, u64_t* par_rd) {
            *par_rd = *((u64_t*)par_ptr);
            return true_t; 
}

bool_t 
    cstd_mem_wr8
        (void* par_ptr, u8_t  par_wr) {
            *((u8_t*)par_ptr) = par_wr; 
            return true_t;
}

bool_t 
    cstd_mem_wr16
        (void* par_ptr, u16_t par_wr) {
            *((u16_t*)par_ptr) = par_wr;
            return true_t;
}

bool_t 
    cstd_mem_wr32
        (void* par_ptr, u32_t par_wr) {
            *((u32_t*)par_ptr) = par_wr;
            return true_t;
}

bool_t 
    cstd_mem_wr64
        (void* par_ptr, u64_t par_wr) {
            *((u64_t*)par_ptr) = par_wr;
            return true_t;
}

u64_t
    cstd_mem_copy
        (void* par_ptr, void* par_cp, u64_t par_cp_len) {
            memcpy(par_ptr, par_cp, par_cp_len);
            return par_cp_len;
}

u64_t
    cstd_mem_move
        (void* par_ptr, void* par_mv, u64_t par_mv_len) {
            memmove(par_ptr, par_mv, par_mv_len);
            return par_mv_len;
}

bool_t
    cstd_mem_eq
        (void* par_ptr, void* par_ptr_cmp, u64_t par_len) {
            return strncmp(par_ptr, par_ptr_cmp, par_len) == 0;
}

bool_t
    cstd_mem_gt
        (void* par_ptr, void* par_ptr_cmp, u64_t par_len) {
            return strncmp(par_ptr, par_ptr_cmp, par_len) > 0;
}

bool_t
    cstd_mem_lt
        (void* par_ptr, void* par_ptr_cmp, u64_t par_len) {
            return strncmp(par_ptr, par_ptr_cmp, par_len) < 0;
}

__mem_trait cstd_trait_mem            = {
    .rd8         = &cstd_mem_rd8        ,
    .rd16        = &cstd_mem_rd16       ,
    .rd32        = &cstd_mem_rd32       ,
    .rd64        = &cstd_mem_rd64       ,
    
    .wr8         = &cstd_mem_wr8        ,
    .wr16        = &cstd_mem_wr16       ,
    .wr32        = &cstd_mem_wr32       ,
    .wr64        = &cstd_mem_wr64       ,

    .copy        = &cstd_mem_copy       ,
    .move        = &cstd_mem_move       ,

    .eq          = &cstd_mem_eq         ,
    .lt          = &cstd_mem_lt         ,
    .gt          = &cstd_mem_gt         ,
};

__mem* 
	cstd_mem_init
		(__alloc* par_alloc, u64_t par_size) {
			__mem* ret = malloc(par_size + sizeof(__mem));
			if (!ret) return 0;

			ret->ptr		= (u8_t*)ret + sizeof(__mem);
			ret->alloc		= par_alloc		 ;
			ret->alloc_size = par_size		 ;
			ret->trait		= &cstd_trait_mem;

			return ret;
}
__mem* 
	cstd_mem_init_as_clone
		(__alloc* par_alloc, __mem* par_mem) {
			__mem* ret = cstd_mem_init(par_alloc, par_mem->alloc_size);
			if (!ret) return 0;
			
			memcpy(ret->ptr, par_mem->ptr, par_mem->alloc_size);
			return ret;
}
void
	cstd_mem_deinit
		(__alloc* par_alloc, __mem* par_mem) {
			if(par_mem->alloc == par_alloc)
				free(par_mem);
}

bool_t 
    cstd_alloc_init
        (__alloc* par_alloc) { 
            return true_t; 
}

bool_t 
    cstd_alloc_init_as_clone
        (__alloc* par_alloc, __alloc* par_alloc_clone) { 
            return true_t; 
}

void
    cstd_alloc_deinit
        (__alloc* par_alloc) 
            { }

__alloc_trait cstd_trait                        = {
    .init              = &cstd_alloc_init         ,
    .init_as_clone     = &cstd_alloc_init_as_clone,
    .deinit            = &cstd_alloc_deinit       ,

    .mem_init          = &cstd_mem_init           ,
    .mem_init_as_clone = &cstd_mem_init_as_clone  ,
    .mem_deinit        = &cstd_mem_deinit
};

__alloc       cstd = {
    .handle_trait  = &cstd_trait
};

alloc       *default_alloc       = &cstd      ;
alloc_trait *default_alloc_trait = &cstd_trait;

alloc* 
    get_alloc() {
        return default_alloc;
}

alloc_trait* 
    get_alloc_trait() {
        return default_alloc_trait;
}

alloc* 
    set_alloc(alloc* par_alloc) {
        alloc* ret    = default_alloc;
        default_alloc = (par_alloc) ? par_alloc : &cstd;

        return ret;
}

alloc_trait* 
    set_alloc_trait(alloc_trait* par_trait) {
        alloc_trait* ret    = default_alloc_trait;
        default_alloc_trait = (par_trait) ? par_trait : &cstd_trait;

        return ret;
}

#endif

bool_t
    alloc_init
        (alloc* par_alloc, alloc_trait par_alloc_trait) {
            if(!par_alloc) return false_t;
            
            return
                (par_alloc_trait)
                    ? __alloc_init(par_alloc, par_alloc_trait)
                    : false_t;
}

bool_t
    alloc_init_as_clone
        (alloc *par_alloc, alloc *par_alloc_clone) {
            return __alloc_init_as_clone(par_alloc, par_alloc_clone);
}

void
    alloc_deinit
        (alloc* par_alloc) {
            __alloc_deinit(par_alloc);
}

