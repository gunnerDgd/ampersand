#ifndef __DETAILS_PTR_H__
#define __DETAILS_PTR_H__

#include "mem.h"

typedef struct __ptr {
	__mem* mem    ;
	u64_t  mem_cur;
}	__ptr;

bool_t
	__mem_ptr
		(__ptr*, __mem*, u64_t);

bool_t
	__mem_seek
		(__ptr*, i64_t);

bool_t
	__mem_rd8
		(__ptr*, u8_t*);

bool_t
	__mem_rd16
		(__ptr*, u16_t*);

bool_t
	__mem_rd32
		(__ptr*, u32_t*);

bool_t
	__mem_rd64
		(__ptr*, u64_t*);

bool_t
	__mem_wr8
		(__ptr*, u8_t);

bool_t
	__mem_wr16
		(__ptr*, u16_t);

bool_t
	__mem_wr32
		(__ptr*, u32_t);

bool_t
	__mem_wr64
		(__ptr*, u64_t);

bool_t
	__mem_copy
		(__ptr*, __ptr*, u64_t);

bool_t
	__mem_move
		(__ptr*, __ptr*, u64_t);

bool_t
	__mem_eq
		(__ptr*, __ptr*, u64_t);

bool_t
	__mem_gt
		(__ptr*, __ptr*, u64_t);

bool_t
	__mem_lt
		(__ptr*, __ptr*, u64_t);

#endif