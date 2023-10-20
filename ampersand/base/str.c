#include "str.h"

#include "details/alloc.h"
#include "details/str.h"

#include "default.h"

bool_t
	str_init
		(str* par_str, alloc* par_alloc) {
			if(!par_alloc)
				par_alloc = get_alloc();
			if(!par_alloc)
				return false_t;

			return __str_init(par_str, par_alloc);
}

bool_t
	str_init_as_clone
		(str* par_str, str* par_str_clone) {
			return __str_init_as_clone(par_str, par_str_clone);
}

bool_t
	str_deinit
		(str* par_str) {
			return __str_deinit(par_str);
}

void
	str_reserve_back
		(str* par_str, u64_t par_size) {
			__str_reserve_back(par_str, par_size);
}

void
	str_reserve_front
		(str* par_str, u64_t par_size) {
			__str_reserve_front(par_str, par_size);
}

void
	str_push_back
		(str* par_str, str* par_size) {
			__str_push_back(par_str, par_size);
}

void
	str_push_back_cstr
		(str* par_str, const char* par_push, u64_t par_len) {
			__str_push_back_cstr(par_str, par_push, par_len);
}

void
	str_push_front
		(str* par_str, str* par_push) {
			__str_push_front(par_str, par_push);
}

void
	str_push_front_cstr
		(str* par_str, const char* par_push, u64_t par_len) {
			__str_push_front_cstr(par_str, par_push, par_len);
}

void
	str_push_at
		(str* par_str, u64_t par_off, str* par_push) {
			__str_push_at(par_str, par_off, par_push);
}

void
	str_push_at_cstr
		(str* par_str, u64_t par_off, const char* par_push, u64_t par_len) {
			__str_push_at_cstr(par_str, par_off, par_push, par_len);
}

u64_t
	str_find
		(str* par_str, u64_t par_off, str* par_find) {
			return __str_find(par_str, par_off, par_find);
}

u64_t
	str_find_from_cstr
		(str* par_str, u64_t par_off, const char* par_find, u64_t par_len) {
			return __str_find_from_cstr(par_str, par_off, par_find, par_len);
}

bool_t
	str_eq
		(str* par_lhs, str* par_rhs) {
			return __str_eq(par_lhs, par_rhs);
}

bool_t
	str_eq_from_cstr
		(str* par_lhs, const char* par_rhs, u64_t par_rhs_len) {
			return __str_eq_from_cstr(par_lhs, par_rhs, par_rhs_len);
}

bool_t
	str_gt
		(str* par_lhs, str* par_rhs) {
			return __str_gt(par_lhs, par_rhs);
}

bool_t
	str_gt_from_cstr
		(str* par_lhs, const char* par_rhs, u64_t par_rhs_len) {
			return __str_gt_from_cstr(par_lhs, par_rhs, par_rhs_len);
}

bool_t
	str_lt
		(str* par_lhs, str* par_rhs) {
			return __str_lt(par_lhs, par_rhs);
}

bool_t
	str_lt_from_cstr
		(str* par_lhs, const char* par_rhs, u64_t par_rhs_len) {
			return __str_lt_from_cstr(par_lhs, par_rhs, par_rhs_len);
}

u64_t
	str_len
		(str* par_str) {
			return ((__str*)par_str)->back - ((__str*)par_str)->front;
}

ptr
	str_ptr
		(str* par_str) {
			return mem_ptr(((__str*)par_str)->mem, 0);
}

const char*
	str_raw_ptr
		(str* par_str) {
			return ((__str*)par_str)->mem->ptr + ((__str*)par_str)->front;
}