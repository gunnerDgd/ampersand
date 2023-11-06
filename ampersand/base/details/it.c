#include "it.h"

bool_t
	__it_next
		(__it* par_it) {
			if(!par_it->it)		   return false_t;
			if(!par_it->it_parent) return false_t;

			return par_it->trait->on_next(par_it);
}

void*
	__it_get
		(__it* par_it) {
			if(!par_it->it)		   return 0;
			if(!par_it->it_parent) return 0;

			return par_it->trait->on_get(par_it);
}

void*
	__it_set
		(__it* par_it, void* par_set) {
			if(!par_it->it)		   return 0;
			if(!par_it->it_parent) return 0;

			return par_it->trait->on_set(par_it, par_set);
}

bool_t
	__it_eq
		(__it* par_it, __it* par_it_cmp) {
			if(!par_it->it)		   return 0;
			if(!par_it->it_parent) return 0;

			if(par_it->it_parent != par_it_cmp->it_parent)
				return false_t;

			return par_it->trait->on_eq(par_it, par_it_cmp);
}

bool_t
	__it_lt
		(__it* par_it, __it* par_it_cmp) {
			if(!par_it->it)		   return 0;
			if(!par_it->it_parent) return 0;

			if(par_it->it_parent != par_it_cmp->it_parent)
				return false_t;

			return par_it->trait->on_lt(par_it, par_it_cmp);
}

bool_t
	__it_gt
		(__it* par_it, __it* par_it_cmp) {
			if(!par_it->it)		   return 0;
			if(!par_it->it_parent) return 0;

			if(par_it->it_parent != par_it_cmp->it_parent)
				return false_t;

			return par_it->trait->on_gt(par_it, par_it_cmp);
}