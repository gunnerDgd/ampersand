#include "ptr.h"

bool_t
	__mem_ptr
		(__ptr* par_ptr, __mem* par_mem, u64_t par_mem_cur) {
			if (!par_mem)						   return false_t;
			if (!par_ptr)						   return false_t;
			if (par_mem_cur > par_mem->alloc_size) return false_t;

			par_ptr->mem	 = par_mem	  ;
			par_ptr->mem_cur = par_mem_cur;

			return true_t;
}

bool_t
	__mem_seek
		(__ptr* par_ptr, i64_t par_ptr_move) {
			if ((par_ptr->mem_cur + par_ptr_move) > par_ptr->mem->alloc_size)
				return false_t;
			if ((par_ptr->mem_cur + par_ptr_move) < 0)
				return false_t;

			par_ptr->mem_cur += par_ptr_move;
			return true_t;
}

bool_t
	__mem_rd8
		(__ptr* par_ptr, u8_t* par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if((par_ptr->mem_cur + sizeof(u8_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->rd8		    (
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_rd16
		(__ptr* par_ptr, u16_t* par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if ((par_ptr->mem_cur + sizeof(u16_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->rd16		(
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_rd32
		(__ptr* par_ptr, u32_t* par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if((par_ptr->mem_cur + sizeof(u32_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->rd32	    (
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_rd64
		(__ptr* par_ptr, u64_t* par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if((par_ptr->mem_cur + sizeof(u64_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->rd64	    (
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_wr8
		(__ptr* par_ptr, u8_t par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if((par_ptr->mem_cur + sizeof(u8_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->wr8		    (
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_wr16
		(__ptr* par_ptr, u16_t par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if((par_ptr->mem_cur + sizeof(u16_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->wr16		(
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_wr32
		(__ptr* par_ptr, u32_t par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if((par_ptr->mem_cur + sizeof(u32_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->wr32	    (
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_wr64
		(__ptr* par_ptr, u64_t par_buf) {
			if (!par_ptr->mem)
				return false_t;
			if((par_ptr->mem_cur + sizeof(u64_t)) > par_ptr->mem->alloc_size)
				return false_t;
			
			return par_ptr->mem->trait->wr64	    (
				par_ptr->mem->ptr + par_ptr->mem_cur,
				par_buf
			);
}

bool_t
	__mem_copy
		(__ptr* par_ptr, __ptr* par_ptr_copy, u64_t par_len) {
			if (!par_ptr	 ->mem)												  return false_t;
			if (!par_ptr_copy->mem)												  return false_t;
			if((par_ptr		->mem_cur + par_len) > par_ptr	   ->mem->alloc_size) return false_t;
			if((par_ptr_copy->mem_cur + par_len) > par_ptr_copy->mem->alloc_size) return false_t;

			return par_ptr->mem->trait->copy				  (
				par_ptr	    ->mem->ptr + par_ptr     ->mem_cur,
				par_ptr_copy->mem->ptr + par_ptr_copy->mem_cur,
				par_len
			);
}

bool_t
	__mem_move
		(__ptr* par_ptr, __ptr* par_ptr_copy, u64_t par_len) {
			if (!par_ptr	 ->mem)												  return false_t;
			if (!par_ptr_copy->mem)												  return false_t;
			if((par_ptr		->mem_cur + par_len) > par_ptr	   ->mem->alloc_size) return false_t;
			if((par_ptr_copy->mem_cur + par_len) > par_ptr_copy->mem->alloc_size) return false_t;

			return par_ptr->mem->trait->move				  (
				par_ptr	    ->mem->ptr + par_ptr     ->mem_cur,
				par_ptr_copy->mem->ptr + par_ptr_copy->mem_cur,
				par_len
			);
}

bool_t
	__mem_eq
		(__ptr* par_ptr, __ptr* par_ptr_copy, u64_t par_len) {
			if (!par_ptr	 ->mem)												   return false_t;
			if (!par_ptr_copy->mem)												   return false_t;
			if ((par_ptr	 ->mem_cur + par_len) > par_ptr	    ->mem->alloc_size) return false_t;
			if ((par_ptr_copy->mem_cur + par_len) > par_ptr_copy->mem->alloc_size) return false_t;

			return par_ptr->mem->trait->eq					  (
				par_ptr	    ->mem->ptr + par_ptr     ->mem_cur,
				par_ptr_copy->mem->ptr + par_ptr_copy->mem_cur,
				par_len
			);
}

bool_t
	__mem_gt
		(__ptr* par_ptr, __ptr* par_ptr_copy, u64_t par_len) {
			if (!par_ptr	 ->mem)												  return false_t;
			if (!par_ptr_copy->mem)												  return false_t;
			if((par_ptr		->mem_cur + par_len) > par_ptr	   ->mem->alloc_size) return false_t;
			if((par_ptr_copy->mem_cur + par_len) > par_ptr_copy->mem->alloc_size) return false_t;

			return par_ptr->mem->trait->gt					  (
				par_ptr	    ->mem->ptr + par_ptr     ->mem_cur,
				par_ptr_copy->mem->ptr + par_ptr_copy->mem_cur,
				par_len
			);
}

bool_t
	__mem_lt
		(__ptr* par_ptr, __ptr* par_ptr_copy, u64_t par_len) {
			if (!par_ptr	 ->mem)												  return false_t;
			if (!par_ptr_copy->mem)												  return false_t;
			if((par_ptr		->mem_cur + par_len) > par_ptr	   ->mem->alloc_size) return false_t;
			if((par_ptr_copy->mem_cur + par_len) > par_ptr_copy->mem->alloc_size) return false_t;

			return par_ptr->mem->trait->lt				      (
				par_ptr	    ->mem->ptr + par_ptr     ->mem_cur,
				par_ptr_copy->mem->ptr + par_ptr_copy->mem_cur,
				par_len
			);
}