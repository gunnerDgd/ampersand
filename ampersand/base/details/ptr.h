#ifndef __DETAILS_PTR_H__
#define __DETAILS_PTR_H__

#include "../type.h"
#include "../type_atomic.h"

typedef struct __ptr {
	struct __mem* mem;
	u64_t		  cur;
}	__ptr;

bool_t __ptr_seek(__ptr*, i64_t);

bool_t __ptr_rd8 (__ptr*, u8_t*) ;
bool_t __ptr_rd16(__ptr*, u16_t*);
bool_t __ptr_rd32(__ptr*, u32_t*);
bool_t __ptr_rd64(__ptr*, u64_t*);

bool_t __ptr_wr8 (__ptr*, u8_t) ;
bool_t __ptr_wr16(__ptr*, u16_t);
bool_t __ptr_wr32(__ptr*, u32_t);
bool_t __ptr_wr64(__ptr*, u64_t);

bool_t __ptr_copy(__ptr*, __ptr*, u64_t);
bool_t __ptr_move(__ptr*, __ptr*, u64_t);
bool_t __ptr_eq  (__ptr*, __ptr*, u64_t);
bool_t __ptr_gt  (__ptr*, __ptr*, u64_t);
bool_t __ptr_lt  (__ptr*, __ptr*, u64_t);

#endif