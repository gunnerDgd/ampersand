#include "str.h"

bool_t
	__str_obj_init
		(__str* par_str, u32_t par_count, va_list par) {
			__alloc*    alloc = va_arg(par, __alloc*);
			if (!alloc) alloc = global_alloc;
			if (!alloc) return false_t;

			return __str_init(par_str, alloc);
}

bool_t
	__str_obj_init_as_clone
		(__str* par, __str* par_clone) {
			return __str_init_as_clone(par, par_clone);
}

void
	__str_obj_deinit
		(__str* par) {
			__str_deinit(par);
}

u64_t
	__str_obj_size() {
		return sizeof(__str);
}

__obj_trait __str_trait					   = {
	.init		   = &__str_obj_init		 ,
	.init_as_clone = &__str_obj_init_as_clone,
	.init_as_ref   =						0,
	.deinit		   = &__str_obj_deinit		 ,
	.name		   =						0,
	.size		   = &__str_obj_size
};

bool_t
	__str_init
		(__str* par, __alloc* par_alloc) {
			par->alloc = par_alloc;
			par->mem   = __mem_init(par->alloc, 16); if (!par->mem) return false_t;
		
			par->front = 0; par->back  = 0;
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

			par_str->alloc = 0; par_str->mem = 0;
			return true_t;
}

void
	__str_rsv_back
		(__str* par, u64_t par_rsv)		   {
			__mem *mem = par->mem, *mem_new;

			par_rsv = (mem->alloc_size > par_rsv) 
					? (mem->alloc_size << 1) 
					: (mem->alloc_size + par_rsv);
	
			mem_new = __mem_init(par->alloc, par_rsv); if (!mem_new) return;
			mem_new->trait->copy			  (
				mem_new->ptr  + par->front,
				mem    ->ptr  + par->front,
				par->back - par->front
			);
		
			__mem_deinit(mem)   ;
			par->mem =   mem_new;
}

void
	__str_rsv_front
		(__str* par, u64_t par_rsv)		   {
			__mem *mem = par->mem, *mem_new;
		
			par_rsv = (mem->alloc_size > par_rsv) 
					? (mem->alloc_size << 1) 
					: (mem->alloc_size + par_rsv);

			mem_new = __mem_init(par->alloc, par_rsv); if (!mem_new) return;
			mem_new->trait->copy					    (
				mem_new->ptr  + par->front + par_rsv,
				mem    ->ptr  + par->front			,
				par->back - par->front
			);
		
			__mem_deinit(mem);
			par->mem    = mem_new;
			par->front += par_rsv;
			par->back  += par_rsv;
}

void
	__str_push_back
		(__str* par, __str* par_push)       {
			__mem  *mem	     = par	   ->mem,
				   *mem_push = par_push->mem;
			u64_t   len_push = par_push->back - par_push->front;

			if ((mem->alloc_size - par->back) <= len_push)
				__str_rsv_back(par, len_push);

			par->mem->trait->copy		 		    (
				par	    ->mem->ptr + par	 ->back ,
				par_push->mem->ptr + par_push->front,
				len_push
			);

			par->back += len_push;
			char* pop = par->mem->ptr;
				  pop[par->back]  = 0;
}

void
	__str_push_back_cstr
		(__str* par, const char* par_push, u64_t par_len) {
			__mem  *mem = par->mem;
			u64_t   len	= par->back - par->front;

			if ((mem->alloc_size - par->back) <= par_len)
				__str_rsv_back(par, par_len);

			par->mem->trait->copy		 (
				par->mem->ptr + par->back,
				par_push			     ,
				par_len
			);

			par->back += par_len;
			char* pop = par->mem->ptr;
				  pop[par->back]  = 0;
}

void
	__str_push_front
		(__str* par, __str* par_push)		{
			__mem  *mem	     = par	   ->mem,
				   *mem_push = par_push->mem;

			u64_t   len		 = par->back	  - par->front,
					len_push = par_push->back - par_push->front;

			if (par->front <= len_push)
				__str_rsv_front(par, len_push);

			par->front -= len_push;
			par->mem->trait->copy			   (
				par->mem->ptr + par     ->front,
				mem_push->ptr + par_push->front,
				len_push
			);

			char* pop = par->mem->ptr;
				  pop[par->back]  = 0;
}

void
	__str_push_front_cstr
		(__str* par, const char* par_push, u64_t par_len) {
			__mem *mem = par->mem;
			if (par->front <= par_len)
				__str_rsv_front(par, par_len);

			par->front -= par_len;
			par->mem->trait->copy		  (
				par->mem->ptr + par->front,
				par_push				  ,
				par_len
			);

			char* pop = par->mem->ptr;
				  pop[par->back]  = 0;
}

void
	__str_push_at
		(__str* par, u64_t par_off, __str* par_push) {
			__mem  *mem    = par->mem,
				   *mem_new;

			u64_t   len		 = (par->back	   - par->front)	 ,
				    len_push = (par_push->back - par_push->front);

			mem_new		  = __mem_init(par->alloc, len + len_push); if (!mem_new) return;
			mem_new->trait->copy(mem_new->ptr, mem->ptr + par->front, par_off);
			mem_new->trait->copy(mem_new->ptr + par_off, par_push->mem->ptr + par_push->front, len_push);
			mem_new->trait->copy(mem_new->ptr + par_off + len_push, mem->ptr + par->front + par_off , len - par_off);

			__mem_deinit(mem);
			par->mem   = mem_new	   ;
			par->back  = len + len_push;
			par->front = 0			   ;

			char* pop = par->mem->ptr;
				  pop[par->back]  = 0;
}

void
	__str_push_at_cstr
		(__str* par, u64_t par_off, const char* par_push, u64_t par_len) {
			__mem  *mem    = par->mem,
				   *mem_new;
			u64_t   len    = (par->back - par->front);
			mem_new		   = __mem_init(par->alloc, len + par_len)			  ; if (!mem_new) return;
			mem_new->trait->copy(mem_new->ptr, mem->ptr + par->front, par_off);
			mem_new->trait->copy(mem_new->ptr + par_off, par_push, par_len);
			mem_new->trait->copy(mem_new->ptr + par_off + par_len, mem->ptr + par->front + par_off, len - par_off);

			__mem_deinit(mem);
			par->mem   = mem_new	  ;
			par->back  = len + par_len;
			par->front = 0			  ;

			char* pop = par->mem->ptr;
				  pop[par->back]  = 0;
}

void 
	__str_pop_front
		(__str* par, u64_t par_len) {
			if((par->back - par->front) < par_len) {
				par->back = par->front;
				return;
			}

			par->front += par_len;
}

void 
	__str_pop_back
		(__str* par, u64_t par_len) {
			if((par->back - par->front) < par_len) {
				par->back = par->front;
				return;
			}

			par->back -= par_len;
			char* pop = par->mem->ptr;
				  pop[par->back] = 0;
}

void 
	__str_pop_at
		(__str* par, u64_t par_off, u64_t par_len) {
			if (par_off < par->front || par_off > par->back)  return;
			if ((par_off + par_len + par->front) > par->back) 
				return __str_pop_back(par, (par->back - par->front) - par_off);

			par->mem->trait->copy							  (
				par->mem->ptr + par->front + par_off		  ,
				par->mem->ptr + par->front + par_off + par_len,
				(par->back - par->front) - par_off
			);

			par->back -= par_len;
			char* pop = par->mem->ptr;
				  pop[par->back]  = 0;
}

u64_t
	__str_find
		(__str* par, u64_t par_off, __str* par_find) {
			u64_t len	   = (par->back		 - par->front)	   ,
				  len_find = (par_find->back - par_find->front);

			if (len < len_find) return -1;
		
			char* ptr_str = par->mem->ptr + par->front;
			for(u64_t it = 0 ; it < (len - len_find) ; ++it)
				if (par->mem->trait->eq(ptr_str, par_find->mem->ptr, len_find))
					return it;

			return -1;
}

u64_t
	__str_find_from_cstr
		(__str* par, u64_t par_off, const char* par_find, u64_t par_len) {
			u64_t len = (par->back - par->front);
			if   (len < par_len) return -1;
		
			char* ptr_str = par->mem->ptr + par->front;
			for(u64_t it = 0 ; it < (len - par_len) ; ++it)
				if (par->mem->trait->eq(ptr_str, par_find, par_len))
					return it;

			return -1;
}

bool_t
	__str_eq
		(__str *par, __str* par_cmp) {
			u64_t lhs = (par	->back - par	->front),
				  rhs = (par_cmp->back - par_cmp->front);
			return (lhs != rhs) ? false_t : par->mem->trait->eq(par->mem->ptr, par_cmp->mem->ptr, lhs);
}

bool_t
	__str_eq_from_cstr
		(__str *par, const char* par_cmp, u64_t par_len) {
			u64_t   lhs = (par->back - par->front);
			return (lhs != par_len) ? false_t : par->mem->trait->eq(par->mem->ptr, par_cmp, lhs);
}

bool_t
	__str_gt
		(__str * par, __str* par_cmp) {
			u64_t lhs = (par	->back - par	->front),
				  rhs = (par_cmp->back - par_cmp->front);
			return par->mem->trait->gt(par->mem->ptr, par_cmp->mem->ptr, (lhs < rhs) ? lhs : rhs);
}

bool_t
	__str_gt_from_cstr
		(__str *par, const char* par_cmp, u64_t par_len) {
			u64_t lhs = (par->back - par->front);
			return par->mem->trait->gt(par->mem->ptr, par_cmp, (lhs < par_len) ? lhs : par_len);
}

bool_t
	__str_lt
		(__str * par, __str* par_cmp) {
			u64_t lhs = (par	->back - par	->front),
				  rhs = (par_cmp->back - par_cmp->front);
			return par->mem->trait->lt(par->mem->ptr, par_cmp->mem->ptr, (lhs < rhs) ? lhs : rhs);
}

bool_t
	__str_lt_from_cstr
		(__str * par, const char* par_cmp, u64_t par_len) {
			u64_t  lhs = (par->back - par->front);
			return par->mem->trait->lt(par->mem->ptr, par_cmp, (lhs < par_len) ? lhs : par_len);
}

bool_t 
	__str_start_with
		(__str* par, __str* par_cmp)							   {
			__mem_trait* ops	 = par->mem->trait				   ;
			u64_t		 len	 = (par->back - par->front)		   ,
						 len_cmp = (par_cmp->back - par_cmp->front);

			if (len < len_cmp) return false_t;
			return ops->eq						  (
				par	   ->mem->ptr + par    ->front,
				par_cmp->mem->ptr + par_cmp->front,
				(len < len_cmp) ? len : len_cmp
			);
}


bool_t 
	__str_start_with_from_cstr
		(__str* par, const char* par_cmp, u64_t par_len) {
			__mem_trait* ops = par->mem->trait;
			u64_t		 len = (par->back - par->front);

			if (len < par_len) return false_t;
			return ops->eq				       (
				par->mem->ptr + par->front     ,
				par_cmp					       ,
				(len < par_len) ? len : par_len
			);
}
bool_t 
	__str_end_with
		(__str* par, __str* par_cmp)			  {
			__mem_trait* ops	 = par->mem->trait;
			u64_t		 len	 = par	  ->back - par	  ->front,
						 len_cmp = par_cmp->back - par_cmp->front;

			if (len_cmp > len) return false_t;
			return ops->eq						   (
				par->mem->ptr + par->back - len_cmp,
				par_cmp->mem->ptr				   ,
				len_cmp
			);
			
}
bool_t 
	__str_end_with_from_cstr
		(__str* par, const char* par_cmp, u64_t par_len) {
			__mem_trait* ops = par->mem->trait		 ;
			u64_t		 len = par->back - par->front;

			if (par_len > len) return false_t;
			return ops->eq						   (
				par->mem->ptr + par->back - par_len,
				par_cmp							   ,
				par_len
			);
}