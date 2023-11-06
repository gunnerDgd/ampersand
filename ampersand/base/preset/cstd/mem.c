#include "mem.h"
#include <stdlib.h>
#include <string.h>

__mem_trait cstd_mem_trait = {
    .rd8  = &cstd_mem_rd8 ,
    .rd16 = &cstd_mem_rd16,
    .rd32 = &cstd_mem_rd32,
    .rd64 = &cstd_mem_rd64,
    
    .wr8  = &cstd_mem_wr8 ,
    .wr16 = &cstd_mem_wr16,
    .wr32 = &cstd_mem_wr32,
    .wr64 = &cstd_mem_wr64,

    .copy = &cstd_mem_copy,
    .move = &cstd_mem_move,

    .eq   = &cstd_mem_eq  ,
    .lt   = &cstd_mem_lt  ,
    .gt   = &cstd_mem_gt
};

__mem* 
	cstd_mem_init
		(__alloc* par, u64_t par_size) {
			__mem* ret = malloc(par_size + sizeof(__mem));
			if   (!ret) return 0;

			ret->ptr		= (u8_t*)ret + sizeof(__mem);
			ret->alloc		= par		     ;
			ret->alloc_size = par_size		 ;
			ret->trait		= &cstd_mem_trait;

			return ret;
}

__mem* 
	cstd_mem_init_as_clone
		(__alloc* par, __mem* par_mem) {
			__mem* ret = cstd_mem_init(par, par_mem->alloc_size);
			if   (!ret) return 0;
			
			cstd_mem_copy(ret->ptr, par_mem->ptr, par_mem->alloc_size);
			return ret;
}

void
	cstd_mem_deinit
		(__alloc* par, __mem* par_mem) {
			if(par_mem->alloc == par) free(par_mem);
}

bool_t cstd_mem_rd8 (void* par, u8_t * par_rd) { *par_rd = *((u8_t*) par); return true_t; }
bool_t cstd_mem_rd16(void* par, u16_t* par_rd) { *par_rd = *((u16_t*)par); return true_t; }
bool_t cstd_mem_rd32(void* par, u32_t* par_rd) { *par_rd = *((u32_t*)par); return true_t; }
bool_t cstd_mem_rd64(void* par, u64_t* par_rd) { *par_rd = *((u64_t*)par); return true_t; }

bool_t cstd_mem_wr8 (void* par, u8_t  par_wr)  { *((u8_t*) par) = par_wr ; return true_t; }
bool_t cstd_mem_wr16(void* par, u16_t par_wr)  { *((u16_t*)par) = par_wr ; return true_t; }
bool_t cstd_mem_wr32(void* par, u32_t par_wr)  { *((u32_t*)par) = par_wr ; return true_t; }
bool_t cstd_mem_wr64(void* par, u64_t par_wr)  { *((u64_t*)par) = par_wr ; return true_t; }

u64_t  cstd_mem_copy(void* par, void* par_cp , u64_t par_cp_len) { memcpy(par, par_cp, par_cp_len) ; return par_cp_len; }
u64_t  cstd_mem_move(void* par, void* par_mv , u64_t par_mv_len) { memmove(par, par_mv, par_mv_len); return par_mv_len; }
bool_t cstd_mem_eq  (void* par, void* par_cmp, u64_t par_len)    { return strncmp(par, par_cmp, par_len) == 0; }
bool_t cstd_mem_gt  (void* par, void* par_cmp, u64_t par_len)    { return strncmp(par, par_cmp, par_len) >  0; }
bool_t cstd_mem_lt  (void* par, void* par_cmp, u64_t par_len)    { return strncmp(par, par_cmp, par_len) <  0; }

