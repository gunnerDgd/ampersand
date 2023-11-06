#ifndef __PTR_H__
#define __PTR_H__

#include "type.h"
#include "type_atomic.h"

typedef struct ptr { u64_t ptr[2]; } ptr;

ptr    ptr_seek(ptr, i64_t);
void*  ptr_raw (ptr)	   ;

bool_t ptr_rd8 (ptr, u8_t*);
bool_t ptr_rd16(ptr, u16_t*);
bool_t ptr_rd32(ptr, u32_t*);
bool_t ptr_rd64(ptr, u64_t*);

bool_t ptr_wr8 (ptr, u8_t);
bool_t ptr_wr16(ptr, u16_t);
bool_t ptr_wr32(ptr, u32_t);
bool_t ptr_wr64(ptr, u64_t);

bool_t ptr_copy(ptr, ptr, u64_t);
bool_t ptr_move(ptr, ptr, u64_t);
bool_t ptr_eq  (ptr, ptr, u64_t);
bool_t ptr_gt  (ptr, ptr, u64_t);
bool_t ptr_lt  (ptr, ptr, u64_t);

#endif