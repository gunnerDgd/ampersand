#ifndef PRESET_CSTD_ALLOC_H
#define PRESET_CSTD_ALLOC_H

#ifdef PRESET_ENV_CSTD
#include "../../details/alloc.h"

extern __alloc_trait cstd_alloc_trait;
extern __alloc		 cstd_alloc		 ;

bool_t cstd_alloc_init		   (__alloc*)		   ;
bool_t cstd_alloc_init_as_clone(__alloc*, __alloc*);
bool_t cstd_alloc_deinit	   (__alloc*)		   ;

#endif
#endif