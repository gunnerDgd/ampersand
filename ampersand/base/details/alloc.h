#ifndef __DETAILS_ALLOC_H__
#define __DETAILS_ALLOC_H__

#include "../type.h"
#include "../type_atomic.h"

typedef struct __alloc_trait											{
    bool_t        (*init)             (struct __alloc*)					;
    bool_t        (*init_as_clone)    (struct __alloc*, struct __alloc*);
    void          (*deinit)           (struct __alloc*)					;

    struct __mem* (*mem_init)         (struct __alloc*, u64_t)			;
    struct __mem* (*mem_init_as_clone)(struct __alloc*, struct __mem*)  ;
    void          (*mem_deinit)       (struct __alloc*, struct __mem*)  ;
}   __alloc_trait;

typedef struct
	__alloc { __alloc_trait* handle_trait; u8_t handle [248]; }
		__alloc;

bool_t
	__alloc_init
		(__alloc*, __alloc_trait*);

bool_t
	__alloc_init_as_clone
		(__alloc*, __alloc*);

void
	__alloc_deinit
		(__alloc*);

#endif
