#include "it.h"
#include "details/it.h"

bool_t
	it_next
		(it* par_it) {
			return __it_next(par_it);
}

void*
	it_get
		(it* par_it) {
			return __it_get(par_it);
}

void*
	it_set
		(it* par_it, void* par_set) {
			return __it_set(par_it, par_set);
}

bool_t
	it_eq
		(it* par_it, it* par_it_cmp) {
			return __it_eq(par_it, par_it_cmp);
}

bool_t
	it_lt
		(it* par_it, it* par_it_cmp) {
			return __it_lt(par_it, par_it_cmp);
}

bool_t
	it_gt
		(it* par_it, it* par_it_cmp) {
			return __it_gt(par_it, par_it_cmp);
}