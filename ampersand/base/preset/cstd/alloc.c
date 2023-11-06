#include "alloc.h"
#include "mem.h"

#include <stdlib.h>

__alloc_trait cstd_alloc_trait				= {
	.init		   = &cstd_alloc_init		  ,
	.init_as_clone = &cstd_alloc_init_as_clone,
	.deinit		   = &cstd_alloc_deinit		  ,

	.mem_init		   = &cstd_mem_init			,
	.mem_init_as_clone = &cstd_mem_init_as_clone,
	.mem_deinit		   = &cstd_mem_deinit	    ,

	.max_size		   = -1,
	.unit_align		   =  1,
	.unit_size		   =  1
};
__alloc	cstd_alloc		   = {
	.trait = &cstd_alloc_trait
};

bool_t
	cstd_alloc_init
		(__alloc* par) {
			return true_t;
}

bool_t
	cstd_alloc_init_as_clone
		(__alloc* par, __alloc* par_clone) {
			return true_t;
}

bool_t
	cstd_alloc_deinit
		(__alloc* par) {
			return true_t;
}