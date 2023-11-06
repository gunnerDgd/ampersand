#ifndef __DETAILS_OBJECT_H__
#define __DETAILS_OBJECT_H__

#include "../type.h"
#include "../type_atomic.h"

#include "mem.h"
#include "alloc.h"

typedef struct __obj_trait {
	bool_t 	     (*init)		 (struct __obj*, u32_t, va_list);
    bool_t 	     (*init_as_clone)(struct __obj*, struct __obj*) ;
    bool_t 	     (*init_as_ref)  (struct __obj*);
    void   	     (*deinit)       (struct __obj*);

	u64_t  	     (*size)		 ()			    ;
	struct __str*(*name)    	 (struct __obj*);
}   __obj_trait;

typedef struct __obj  { 
    __mem       *mem  ; 
    atomic_u64_t ref  ; 
    __obj_trait *trait; 
}   __obj;

__obj* __obj_init         (__alloc*, __obj_trait*, u32_t, va_list);
__obj* __obj_init_as_clone(__obj*);
__obj* __obj_init_as_ref  (__obj*);
void   __obj_deinit       (__obj*);

#endif
