#ifndef __PTR_H__
#define __PTR_H__

#include "mem.h"

typedef struct ptr { u64_t ptr[2]; } ptr;

ptr
	mem_ptr
		(mem, u64_t);

ptr
	mem_seek
		(ptr, i64_t);

bool_t
	mem_rd8
		(ptr, u8_t*);

bool_t
	mem_rd16
		(ptr, u16_t*);

bool_t
	mem_rd32
		(ptr, u32_t*);

bool_t
	mem_rd64
		(ptr, u64_t*);

bool_t
	mem_wr8
		(ptr, u8_t);

bool_t
	mem_wr16
		(ptr, u16_t);

bool_t
	mem_wr32
		(ptr, u32_t);

bool_t
	mem_wr64
		(ptr, u64_t);

bool_t
	mem_copy
		(ptr, ptr, u64_t);

bool_t
	mem_move
		(ptr, ptr, u64_t);

bool_t
	mem_eq
		(ptr, ptr, u64_t);

bool_t
	mem_gt
		(ptr, ptr, u64_t);

bool_t
	mem_lt
		(ptr, ptr, u64_t);

#endif