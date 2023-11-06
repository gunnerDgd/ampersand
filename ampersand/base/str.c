#include "str.h"

#include "details/alloc.h"
#include "details/str.h"

#include "obj.h"

obj_trait* str_t = &__str_trait;

bool_t
	str_init
		(str* par, alloc* par_alloc) {
			if(!par_alloc) par_alloc = get_alloc();
			if(!par_alloc) return false_t;

			return __str_init(par, par_alloc);
}

bool_t
	str_init_as_clone
		(str* par, str* par_clone) {
			return __str_init_as_clone(par, par_clone);
}

bool_t
	str_deinit
		(str* par) {
			return __str_deinit(par);
}

void str_rsv_back (str* par, u64_t par_size) { __str_rsv_back (par, par_size); }
void str_rsv_front(str* par, u64_t par_size) { __str_rsv_front(par, par_size); }

void str_push_back	    (str* par, str*  par_size)									   { __str_push_back	   (par, par_size)		  ; }
void str_push_back_cstr (str* par, const char* par_push, u64_t par_len)				   { __str_push_back_cstr (par, par_push, par_len); }
void str_push_front	    (str* par, str* par_push)									   { __str_push_front	  (par, par_push)		  ; }
void str_push_front_cstr(str* par, const char* par_push, u64_t par_len)				   { __str_push_front_cstr(par, par_push, par_len); }
void str_push_at		(str* par, u64_t par_off, str* par_push)					   { __str_push_at		  (par, par_off, par_push); }
void str_push_at_cstr   (str* par, u64_t par_off, const char* par_push, u64_t par_len) { __str_push_at_cstr   (par, par_off, par_push, par_len); }

void str_pop_front(str* par, u64_t par_len)				   { __str_pop_front(par, par_len)		   ; }
void str_pop_back (str* par, u64_t par_len)				   { __str_pop_back (par, par_len)		   ; }
void str_pop_at   (str* par, u64_t par_off, u64_t par_len) { __str_pop_at   (par, par_off, par_len); }

u64_t str_find			(str* par, u64_t par_off, str* par_find)					   { return __str_find(par, par_off, par_find); }
u64_t str_find_from_cstr(str* par, u64_t par_off, const char* par_find, u64_t par_len) { return __str_find_from_cstr(par, par_off, par_find, par_len); }

bool_t str_eq		   (str* par, str* par_cmp)						  { return __str_eq			 (par, par_cmp)			; }
bool_t str_eq_from_cstr(str* par, const char* par_cmp, u64_t par_len) { return __str_eq_from_cstr(par, par_cmp, par_len); }
bool_t str_gt		   (str* par, str* par_cmp)						  { return __str_gt			 (par, par_cmp)			; }
bool_t str_gt_from_cstr(str* par, const char* par_cmp, u64_t par_len) { return __str_gt_from_cstr(par, par_cmp, par_len); }
bool_t str_lt		   (str* par, str* par_cmp)						  { return __str_lt			 (par, par_cmp)			; }
bool_t str_lt_from_cstr(str* par, const char* par_cmp, u64_t par_len) { return __str_lt_from_cstr(par, par_cmp, par_len); }

bool_t str_start_with		   (str* par, str* par_cmp)						  { return __str_start_with			 (par, par_cmp)			; }
bool_t str_start_with_from_cstr(str* par, const char* par_cmp, u64_t par_len) { return __str_start_with_from_cstr(par, par_cmp, par_len); }
bool_t str_end_with			   (str* par, str* par_cmp)						  { return __str_end_with			 (par, par_cmp); }
bool_t str_end_with_from_cstr  (str* par, const char* par_cmp, u64_t par_len) { return __str_end_with_from_cstr  (par, par_cmp, par_len); }

u64_t str_len		   (str* par) { return ((__str*)par)->back - ((__str*)par)->front; }
ptr	  str_ptr		   (str* par) { return mem_ptr(((__str*)par)->mem, 0); }