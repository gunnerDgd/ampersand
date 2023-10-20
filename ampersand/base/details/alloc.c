#include "alloc.h"

bool_t
	__alloc_init(__alloc* par_alloc, __alloc_trait* par_alloc_trait) {
			   par_alloc->handle_trait = par_alloc_trait;
		return par_alloc->handle_trait->init(par_alloc) ;
}

bool_t
	__alloc_init_as_clone(__alloc* par_alloc, __alloc* par_alloc_clone) {
			   par_alloc->handle_trait = par_alloc_clone->handle_trait;
		return par_alloc->handle_trait->init_as_clone(par_alloc, par_alloc_clone);
}

void
	__alloc_deinit(__alloc* par_alloc) {
		par_alloc->handle_trait->deinit(par_alloc);
		par_alloc->handle_trait = 0;
}