#ifndef __STR_H__
#define __STR_H__

#include "alloc.h"
#include "ptr.h"

extern struct obj_trait* str_t;
typedef struct			 str  { u64_t handle[10]; } str;

bool_t str_init		    (str*, alloc*);
bool_t str_init_as_clone(str*, str*)  ;
bool_t str_deinit		(str*)        ;

void str_rsv_back (str*, u64_t);
void str_rsv_front(str*, u64_t);

void str_push_back	    (str*, str*);
void str_push_back_cstr (str*, const char*, u64_t);
void str_push_front	    (str*, str*);
void str_push_front_cstr(str*, const char*, u64_t);
void str_push_at		(str*, u64_t, str*);
void str_push_at_cstr	(str*, u64_t, const char*, u64_t);

void str_pop_front(str*, u64_t)		  ;
void str_pop_back (str*, u64_t)		  ;
void str_pop_at   (str*, u64_t, u64_t);

u64_t str_find			(str*, u64_t, str*)				 ;
u64_t str_find_from_cstr(str*, u64_t, const char*, u64_t);

bool_t str_eq		   (str*, str*)				 ;
bool_t str_eq_from_cstr(str*, const char*, u64_t);
bool_t str_gt		   (str*, str*);
bool_t str_gt_from_cstr(str*, const char*, u64_t);
bool_t str_lt		   (str*, str*);
bool_t str_lt_from_cstr(str*, const char*, u64_t);

bool_t str_start_with		   (str*, str*);
bool_t str_start_with_from_cstr(str*, const char*, u64_t);
bool_t str_end_with			   (str*, str*);
bool_t str_end_with_from_cstr  (str*, const char*, u64_t);

u64_t str_len(str*);
ptr   str_ptr(str*);

#endif