#include "alloc.h"

bool_t
	__alloc_init
		(__alloc* par, __alloc_trait* par_trait) {
			if(!par)	   return false_t;
			if(!par_trait) return false_t;
			par->trait = par_trait;

			return par->trait->init(par);
}

bool_t
	__alloc_init_as_clone
		(__alloc* par, __alloc* par_clone)		{
			if(!par_clone)		  return false_t;
			if(!par_clone->trait) return false_t;
			
			par->trait = par_clone->trait;

			return par->trait->init_as_clone(par, par_clone);
}

void
	__alloc_deinit
		(__alloc* par) {
			par->trait->deinit(par);
			par->trait			= 0;
}