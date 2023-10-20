#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "alloc.h"
#include "mem.h"
#include "str.h"

typedef struct obj 		 { u64_t obj[4]; } obj;
typedef struct obj_trait {
    bool_t (*init)		   (obj*, u32_t, va_list);
    bool_t (*init_as_clone)(obj*, obj*);
    bool_t (*init_as_ref)  (obj*);
    void   (*deinit)       (obj*);

	u64_t  (*size)		   ()	 ;
	str*   (*name)		   (obj*);
}   obj_trait;

obj*
    obj_init
        (alloc*, obj_trait*, u32_t, ...);

obj*
	obj_init_from_varg
		(alloc*, obj_trait*, u32_t, va_list);

obj*
    obj_init_as_clone
        (obj*);

obj*
    obj_init_as_ref
        (obj*);

void
    obj_deinit
        (obj*);

obj_trait*
	obj_get_trait
		(obj*);

str*
	obj_name
		(obj*);

u64_t
	obj_use_count
		(obj*);

#ifndef __cplusplus
#define make(par_type)  obj_init          (0, par_type, 
#define vmake(par_type) obj_init_from_varg(0, par_type,
#define from(...)      __VA_ARGS__)

#define ref(par_obj)       obj_init_as_ref  (par_obj)
#define clone(par_obj)     obj_init_as_clone(par_obj)
#define del(par_obj)       obj_deinit       (par_obj)
#define name_of(par_obj)   obj_name         (par_obj)
#define use_count(par_obj) obj_use_count    (par_obj)
#define trait_of(par_obj)  obj_get_trait    (par_obj)
#endif

#endif
