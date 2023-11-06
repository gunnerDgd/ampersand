#include "ptr.h"
#include "details/ptr.h"
#include "details/mem.h"

ptr
	ptr_seek
		(ptr par_ptr, i64_t par_off) {
			if(!__ptr_seek(&par_ptr, par_off)) {
				((__ptr*)&par_ptr)->mem     = 0;
				((__ptr*)&par_ptr)->cur = 0;
			}

			return par_ptr;
}

void* 
	ptr_raw
		(ptr par) {
			return ((__ptr*)&par)->mem->ptr;
}

bool_t
	ptr_rd8
		(ptr par_ptr, u8_t* par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->rd8		   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_rd16
		(ptr par_ptr, u16_t* par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->rd16	   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_rd32
		(ptr par_ptr, u32_t* par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->rd32	   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_rd64
		(ptr par_ptr, u64_t* par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->rd64	   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_wr8
		(ptr par_ptr, u8_t par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->wr8		   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_wr16
		(ptr par_ptr, u16_t par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->wr16	   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_wr32
		(ptr par_ptr, u32_t par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->wr32	   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_wr64
		(ptr par_ptr, u64_t par_buf) {
			__ptr* ptr = &par_ptr;
			return ptr->mem->trait->wr64	   (
				   ptr->mem->ptr + ptr->cur, 
				   par_buf
			);
}

bool_t
	ptr_copy
		(ptr par_ptr, ptr par_ptr_op, u64_t par_len) {
			__ptr* ptr = &par_ptr, *ptr_op = &par_ptr_op;
			return ptr->mem->trait->copy			 (
				   ptr   ->mem->ptr + ptr   ->cur,
				   ptr_op->mem->ptr + ptr_op->cur,
				   par_len
			);
}

bool_t
	ptr_move
		(ptr par_ptr, ptr par_ptr_op, u64_t par_len) {
			__ptr* ptr = &par_ptr, *ptr_op = &par_ptr_op;
			return ptr->mem->trait->move			 (
				   ptr   ->mem->ptr + ptr   ->cur,
				   ptr_op->mem->ptr + ptr_op->cur,
				   par_len
			);
}

bool_t
	ptr_eq
		(ptr par_ptr, ptr par_ptr_op, u64_t par_len) {
			__ptr* ptr = &par_ptr, *ptr_op = &par_ptr_op;
			return ptr->mem->trait->eq				 (
				   ptr   ->mem->ptr + ptr   ->cur,
				   ptr_op->mem->ptr + ptr_op->cur,
				   par_len
			);
}

bool_t
	ptr_gt
		(ptr par_ptr, ptr par_ptr_op, u64_t par_len) {
			__ptr* ptr = &par_ptr, *ptr_op = &par_ptr_op;
			return ptr->mem->trait->gt				 (
				   ptr   ->mem->ptr + ptr   ->cur,
				   ptr_op->mem->ptr + ptr_op->cur,
				   par_len
			);
}

bool_t
	ptr_lt
		(ptr par_ptr, ptr par_ptr_op, u64_t par_len) {
			__ptr* ptr = &par_ptr, *ptr_op = &par_ptr_op;
			return ptr->mem->trait->lt				 (
				   ptr   ->mem->ptr + ptr   ->cur,
				   ptr_op->mem->ptr + ptr_op->cur,
				   par_len
			);
}