#ifndef PRESET_CSTD_MEM_H
#define PRESET_CSTD_MEM_H

#ifdef PRESET_ENV_CSTD
#include "../../details/mem.h"

__mem* cstd_mem_init		 (__alloc*, u64_t) ;
__mem* cstd_mem_init_as_clone(__alloc*, __mem*);
void   cstd_mem_deinit		 (__alloc*, __mem*);

bool_t cstd_mem_rd8 (void*, u8_t *);
bool_t cstd_mem_rd16(void*, u16_t*);
bool_t cstd_mem_rd32(void*, u32_t*);
bool_t cstd_mem_rd64(void*, u64_t*);

bool_t cstd_mem_wr8 (void*, u8_t) ;
bool_t cstd_mem_wr16(void*, u16_t);
bool_t cstd_mem_wr32(void*, u32_t);
bool_t cstd_mem_wr64(void*, u64_t);

u64_t  cstd_mem_copy(void*, void*, u64_t);
u64_t  cstd_mem_move(void*, void*, u64_t);
bool_t cstd_mem_eq  (void*, void*, u64_t);
bool_t cstd_mem_gt  (void*, void*, u64_t);
bool_t cstd_mem_lt  (void*, void*, u64_t);

extern __mem_trait cstd_mem_trait;
#endif

#endif