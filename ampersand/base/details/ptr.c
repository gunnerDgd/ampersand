#include "ptr.h"
#include "mem.h"

bool_t
	__ptr_seek
		(__ptr* par, i64_t par_cur) {
			if ((par->cur + par_cur) > par->mem->alloc_size) return false_t;
			if ((par->cur + par_cur) < 0)					 return false_t;

			par->cur += par_cur;
			return true_t;
}

bool_t
	__ptr_rd8
		(__ptr* par, u8_t* par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->rd8	(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_rd16
		(__ptr* par, u16_t* par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->rd16(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_rd32
		(__ptr* par, u32_t* par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->rd32(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_rd64
		(__ptr* par, u64_t* par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->rd64(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_wr8
		(__ptr* par, u8_t par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->wr8	(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_wr16
		(__ptr* par, u16_t par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->wr16(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_wr32
		(__ptr* par, u32_t par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->wr32(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_wr64
		(__ptr* par, u64_t par_buf) {
			if (!par->mem)										  return false_t;
			if ((par->cur + sizeof(u8_t)) > par->mem->alloc_size) return false_t;
			
			return par->mem->trait->wr64(
				par->mem->ptr + par->cur,
				par_buf
			);
}

bool_t
	__ptr_copy
		(__ptr* par, __ptr* par_copy, u64_t par_len) {
			if (!par->mem)											   return false_t;
			if (!par_copy->mem)										   return false_t;
			if ((par->cur + par_len) > par->mem->alloc_size)		   return false_t;
			if ((par_copy->cur + par_len) > par_copy->mem->alloc_size) return false_t;

			return par->mem->trait->copy		  (
				par	    ->mem->ptr + par	 ->cur,
				par_copy->mem->ptr + par_copy->cur,
				par_len
			);
}

bool_t
	__ptr_move
		(__ptr* par, __ptr* par_copy, u64_t par_len) {
			if (!par->mem)											   return false_t;
			if (!par_copy->mem)										   return false_t;
			if ((par->cur + par_len) > par->mem->alloc_size)		   return false_t;
			if ((par_copy->cur + par_len) > par_copy->mem->alloc_size) return false_t;

			return par->mem->trait->move		  (
				par	    ->mem->ptr + par	 ->cur,
				par_copy->mem->ptr + par_copy->cur,
				par_len
			);
}

bool_t
	__ptr_eq
		(__ptr* par, __ptr* par_copy, u64_t par_len) {
			if (!par->mem)											   return false_t;
			if (!par_copy->mem)										   return false_t;
			if ((par	 ->cur + par_len) > par	    ->mem->alloc_size) return false_t;
			if ((par_copy->cur + par_len) > par_copy->mem->alloc_size) return false_t;

			return par->mem->trait->eq			  (
				par->mem->ptr + par->cur		  ,
				par_copy->mem->ptr + par_copy->cur,
				par_len
			);
}

bool_t
	__ptr_gt
		(__ptr* par, __ptr* par_cmp, u64_t par_len) {
			if (!par->mem)											return false_t;
			if (!par_cmp->mem)										return false_t;
			if((par	   ->cur + par_len) > par	 ->mem->alloc_size)	return false_t;
			if((par_cmp->cur + par_len) > par_cmp->mem->alloc_size) return false_t;

			return par->mem->trait->gt			(
				par	   ->mem->ptr + par->cur	,
				par_cmp->mem->ptr + par_cmp->cur,
				par_len
			);
}

bool_t
	__ptr_lt
		(__ptr* par, __ptr* par_cmp, u64_t par_len) {
			if (!par->mem)											return false_t;
			if (!par_cmp->mem)										return false_t;
			if((par	   ->cur + par_len) > par	 ->mem->alloc_size) return false_t;
			if((par_cmp->cur + par_len) > par_cmp->mem->alloc_size) return false_t;

			return par->mem->trait->lt		    (
				par	   ->mem->ptr + par    ->cur,
				par_cmp->mem->ptr + par_cmp->cur,
				par_len
			);
}