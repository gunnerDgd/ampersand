#ifndef __DETAILS_STR_H__
#define __DETAILS_STR_H__

#include "mem.h"
#include "alloc.h"
#include "obj.h"

extern __obj_trait __str_trait;
typedef struct	   __str      {
	__obj	 head		;
	__alloc *alloc	    ;
	__mem	*mem		;
	u64_t    front, back;
}	__str;

bool_t __str_init		  (__str*, __alloc*);
bool_t __str_init_as_clone(__str*, __str*)  ;
bool_t __str_deinit		  (__str*)		    ;

void   __str_rsv_back (__str*, u64_t);
void   __str_rsv_front(__str*, u64_t);

void __str_push_back	  (__str*, __str*);
void __str_push_back_cstr (__str*, const char*, u64_t);
void __str_push_front	  (__str*, __str*);
void __str_push_front_cstr(__str*, const char*, u64_t);
void __str_push_at		  (__str*, u64_t, __str*);
void __str_push_at_cstr	  (__str*, u64_t, const char*, u64_t);

void __str_pop_front	  (__str*, u64_t);
void __str_pop_back		  (__str*, u64_t);
void __str_pop_at		  (__str*, u64_t, u64_t);

u64_t __str_find		  (__str*, u64_t, __str*);
u64_t __str_find_from_cstr(__str*, u64_t, const char*, u64_t);

bool_t __str_eq			 (__str*, __str*)			 ;
bool_t __str_eq_from_cstr(__str*, const char*, u64_t);
bool_t __str_gt			 (__str*, __str*)			 ;
bool_t __str_gt_from_cstr(__str*, const char*, u64_t);
bool_t __str_lt			 (__str*, __str*)			 ;
bool_t __str_lt_from_cstr(__str*, const char*, u64_t);

bool_t __str_start_with			 (__str*, __str*)			 ;
bool_t __str_start_with_from_cstr(__str*, const char*, u64_t);
bool_t __str_end_with			 (__str*, __str*)			 ;
bool_t __str_end_with_from_cstr  (__str*, const char*, u64_t);

#endif