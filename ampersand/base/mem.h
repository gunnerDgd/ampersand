#ifndef __MEM_H__
#define __MEM_H__

#include "alloc.h"
#include "ptr.h"

typedef void* mem;

mem  mem_init         (alloc*, u64_t);
mem  mem_init_as_clone(mem)          ;
void mem_deinit       (mem)          ;

u64_t mem_size(mem);
ptr   mem_ptr (mem);

#endif
