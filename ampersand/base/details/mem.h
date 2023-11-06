#ifndef __DETAILS_MEM_H__
#define __DETAILS_MEM_H__

#include "alloc.h"

typedef struct __mem_trait             {
    bool_t (*rd8) (void*, u8_t *)      ;
    bool_t (*rd16)(void*, u16_t*)      ;
    bool_t (*rd32)(void*, u32_t*)      ;
    bool_t (*rd64)(void*, u64_t*)      ;

    bool_t (*wr8) (void*, u8_t)        ;
    bool_t (*wr16)(void*, u16_t)       ;
    bool_t (*wr32)(void*, u32_t)       ;
    bool_t (*wr64)(void*, u64_t)       ;

    u64_t  (*copy)(void*, void*, u64_t);
    u64_t  (*move)(void*, void*, u64_t);

    bool_t (*eq)  (void*, void*, u64_t);
    bool_t (*lt)  (void*, void*, u64_t);
    bool_t (*gt)  (void*, void*, u64_t);
}   __mem_trait;

typedef struct __mem          {
	struct __alloc *alloc	  ;
	u64_t			alloc_size;
    u8_t*           ptr       ;
    __mem_trait    *trait     ;
}	__mem;

__mem* __mem_init         (struct __alloc*, u64_t);
__mem* __mem_init_as_clone(__mem*);
void   __mem_deinit       (__mem*);

#endif