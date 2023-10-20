#include "str.h"

#include <stdlib.h>
#include <string.h>

bool_t
	__str_init
		(__str* par_str, __alloc* par_str_alloc) {
			par_str->alloc = par_str_alloc;
			par_str->mem   = __mem_init(par_str->alloc, 16); 
		
			if (!par_str->mem) return false_t;
		
			par_str->front = 0;
			par_str->back  = 0;

			return true_t;
}

bool_t
	__str_init_as_clone
		(__str* par_str, __str* par_str_clone)   {
			par_str->alloc = par_str_clone->alloc;
			par_str->mem   = __mem_init(par_str->alloc, par_str->mem->alloc_size);
		
			if (!par_str->mem) return false_t;

			par_str->front = 0;
			par_str->back  = par_str_clone->back - par_str_clone->front;

			par_str->mem->trait->copy						  (
				par_str	     ->mem->ptr					      ,
				par_str_clone->mem->ptr + par_str_clone->front,
				par_str->back
			);

			return true_t;
}

bool_t
	__str_deinit
		(__str* par_str)			  {
			__mem_deinit(par_str->mem);

			par_str->alloc = 0;
			par_str->mem   = 0;

			return true_t;
}

void
	__str_reserve_back
		(__str* par_str, u64_t par_rsv)		   {
			__mem *mem = par_str->mem, *mem_new;

			par_rsv = (mem->alloc_size > par_rsv) 
					? (mem->alloc_size << 1) 
					: (mem->alloc_size + par_rsv);
	
			mem_new = __mem_init(par_str->alloc, par_rsv); if (!mem_new) return;
			mem_new->trait->copy			  (
				mem_new->ptr  + par_str->front,
				mem    ->ptr  + par_str->front,
				par_str->back - par_str->front
			);
		
			__mem_deinit(mem);
			par_str->mem = mem_new;
}

void
	__str_reserve_front
		(__str* par_str, u64_t par_rsv)		   {
			__mem *mem = par_str->mem, *mem_new;
		
			par_rsv = (mem->alloc_size > par_rsv) 
					? (mem->alloc_size << 1) 
					: (mem->alloc_size + par_rsv);

			mem_new = __mem_init(par_str->alloc, par_rsv); if (!mem_new) return;
			mem_new->trait->copy					    (
				mem_new->ptr  + par_str->front + par_rsv,
				mem    ->ptr  + par_str->front			,
				par_str->back - par_str->front
			);
		
			__mem_deinit(mem);
			
			par_str->mem    = mem_new;
			par_str->front += par_rsv;
			par_str->back  += par_rsv;
}

void
	__str_push_back
		(__str* par_str, __str* par_str_push)   {
			__mem *mem_push = par_str_push->mem;
			u64_t  len_push = par_str_push->back - par_str_push->front;

			if ((par_str->mem->alloc_size - par_str->back) < len_push)
				__str_reserve_back(par_str, len_push);

			par_str->mem->trait->copy		 					    (
				par_str	    ->mem->ptr + par_str	 ->back ,
				par_str_push->mem->ptr + par_str_push->front,
				len_push
			);
			par_str->back += len_push;
}

void
	__str_push_back_cstr
		(__str* par_str, const char* par_cstr, u64_t par_cstr_len) {
			u64_t   len	= par_str->back - par_str->front;

			if ((par_str->mem->alloc_size - par_str->back) < par_cstr_len)
				__str_reserve_back(par_str, par_cstr_len);

			par_str->mem->trait->copy		      (
				par_str->mem->ptr + par_str ->back,
				par_cstr				 ,
				par_cstr_len
			);

			par_str->back += par_cstr_len;
}

void
	__str_push_front
		(__str* par_str, __str* par_push)	{
			__mem *mem_push = par_push->mem;
			u64_t  len		= par_str ->back - par_str ->front,
				   len_push = par_push->back - par_push->front;

			if (par_str->front < len_push)
				__str_reserve_front(par_str, len_push);

			par_str->front -= len_push;
			par_str->mem->trait->copy		       (
				par_str->mem->ptr + par_str ->front,
				mem_push	->ptr + par_push->front,
				len_push
			);
}

void
	__str_push_front_cstr
		(__str* par_str, const char* par_push, u64_t par_push_len) {
			if (par_str->front < par_push_len)
				__str_reserve_front(par_str, par_push_len);

			par_str->front -= par_push_len;
			par_str->mem->trait->copy			   (
				par_str->mem->ptr + par_str ->front,
				par_push						   ,
				par_push_len
			);
}

void
	__str_push_at
		(__str* par_str, u64_t par_off, __str* par_push) {
			__mem  *mem    = par_str->mem,
				   *mem_new;

			u64_t   len		 = (par_str ->back - par_str ->front),
				    len_push = (par_push->back - par_push->front);

			mem_new		  = __mem_init(par_str->alloc, len + len_push); if (!mem_new) return;
			mem_new->trait->copy			 (
				mem_new->ptr				 ,
				mem    ->ptr + par_str->front,
				par_off
			);

			mem_new->trait->copy					(
				mem_new->ptr + par_off				,
				par_push->mem->ptr + par_push->front,
				len_push
			);

			mem_new->trait->copy					   (
				mem_new->ptr + par_off + len_push	   ,
				mem    ->ptr + par_str->front + par_off,
				len - par_off
			);

			__mem_deinit(mem);
		
			par_str->mem   = mem_new	   ;
			par_str->back  = len + len_push;
			par_str->front = 0			   ;
}

void
	__str_push_at_cstr
		(__str* par_str, u64_t par_off, const char* par_push, u64_t par_push_len) {
			__mem  *mem    = par_str->mem,
				   *mem_new;
			u64_t   len    = (par_str->back - par_str->front);

			mem_new		  = __mem_init(par_str->alloc, len + par_push_len); if (!mem_new) return;
			mem_new->trait->copy			 (
				mem_new->ptr				 ,
				mem    ->ptr + par_str->front,
				par_off
			);

			mem_new->trait->copy	  (
				mem_new->ptr + par_off,
				par_push			  ,
				par_push_len
			);

			mem_new->trait->copy					   (
				mem_new->ptr + par_off + par_push_len  ,
				mem    ->ptr + par_str->front + par_off,
				len - par_off
			);

		__mem_deinit(mem);
		
		par_str->mem   = mem_new		   ;
		par_str->back  = len + par_push_len;
		par_str->front = 0			       ;
}

u64_t
	__str_find
		(__str* par_str, u64_t par_off, __str* par_find) {
			u64_t len	   = (par_str ->back - par_str ->front),
				  len_find = (par_find->back - par_find->front);

			if (len < len_find) return -1;
		
			char* ptr_str = par_str->mem->ptr + par_str->front;
			for(u64_t it = 0 ; it < (len - len_find) ; ++it)
				if (par_str->mem->trait->eq(ptr_str, par_find->mem->ptr, len_find)) 
					return it;

			return -1;
}

u64_t
	__str_find_from_cstr
		(__str* par_str, u64_t par_off, const char* par_find, u64_t par_find_len) {
			u64_t len = (par_str ->back - par_str ->front);
			if   (len < par_find_len) return -1;
		
			char* ptr_str = par_str->mem->ptr + par_str->front;
			for(u64_t it = 0 ; it < (len - par_find_len) ; ++it)
				if (par_str->mem->trait->eq(ptr_str, par_find, par_find_len))
					return it;

			return -1;
}

bool_t
	__str_eq
		(__str *par_lhs, __str* par_rhs) {
			u64_t lhs = (par_lhs->back - par_lhs->front),
				  rhs = (par_rhs->back - par_rhs->front);

			return 
				(lhs != rhs) 
					? false_t 
					: par_lhs->mem->trait->eq   (
						par_lhs->mem->ptr	    ,
						par_rhs->mem->ptr		,
						lhs
					);
}

bool_t
	__str_eq_from_cstr
		(__str *par_lhs, const char* par_rhs, u64_t par_rhs_len) {
			u64_t lhs = (par_lhs->back - par_lhs->front);

			return 
				(lhs != par_rhs_len)
					? false_t 
					: par_lhs->mem->trait->eq   (
						par_lhs->mem->ptr	    ,
						par_rhs					,
						lhs
					);
}

bool_t
	__str_gt
		(__str *par_lhs, __str* par_rhs) {
			u64_t lhs = (par_lhs->back - par_lhs->front),
				  rhs = (par_rhs->back - par_rhs->front);

			return par_lhs->mem->trait->gt (
				par_lhs->mem->ptr	   ,
				par_rhs->mem->ptr	   ,
				(lhs < rhs) ? lhs : rhs
			);
}

bool_t
	__str_gt_from_cstr
		(__str *par_lhs, const char* par_rhs, u64_t par_rhs_len) {
			u64_t lhs = (par_lhs->back - par_lhs->front);

			return par_lhs->mem->trait->gt			   (
				par_lhs->mem->ptr					   ,
				par_rhs								   ,
				(lhs < par_rhs_len) ? lhs : par_rhs_len
			);
}

bool_t
	__str_lt
		(__str *par_lhs, __str* par_rhs) {
			u64_t lhs = (par_lhs->back - par_lhs->front),
				  rhs = (par_rhs->back - par_rhs->front);

			return par_lhs->mem->trait->lt (
				par_lhs->mem->ptr	   ,
				par_rhs->mem->ptr	   ,
				(lhs < rhs) ? lhs : rhs
			);
}

bool_t
	__str_lt_from_cstr
		(__str *par_lhs, const char* par_rhs, u64_t par_rhs_len) {
			u64_t lhs = (par_lhs->back - par_lhs->front);

			return par_lhs->mem->trait->lt			   (
				par_lhs->mem->ptr					   ,
				par_rhs								   ,
				(lhs < par_rhs_len) ? lhs : par_rhs_len
			);
}