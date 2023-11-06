#ifndef __LIST_H__
#define __LIST_H__

#include "alloc.h"
#include "obj.h"
#include "it.h"

extern obj_trait* list_t;
typedef struct
    list { u64_t handle[16];}
        list;

bool_t list_init         (list*, alloc*);
bool_t list_init_as_clone(list*, list*) ;
void   list_deinit       (list*)        ;

it   list_push_back (list*, obj*)     ;
it   list_push_front(list*, obj*)     ;
it   list_push_at   (list*, obj*, it*);

void list_pop_front(list*)	   ;
void list_pop_back (list*)	   ;
void list_pop_at   (list*, it*);

it list_begin(list*);
it list_end  (list*);

#endif
