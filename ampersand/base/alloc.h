#ifndef __ALLOC_H__
#define __ALLOC_H__

#include "type.h"
#include "type_atomic.h"

typedef void*  alloc_trait;
typedef struct alloc { u64_t handle; } alloc;

bool_t alloc_init         (alloc*, alloc_trait);
bool_t alloc_init_as_clone(alloc*, alloc*)     ;
void   alloc_deinit       (alloc*)             ;

u64_t  alloc_unit_size (alloc*);
u64_t  alloc_unit_align(alloc*);
u64_t  alloc_max_size  (alloc*);

alloc*		get_alloc	   ()			;
alloc_trait get_alloc_trait()			;
alloc*		set_alloc	   (alloc*)		;
alloc_trait set_alloc_trait(alloc_trait);

#endif
