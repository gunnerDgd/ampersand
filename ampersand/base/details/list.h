#ifndef __DETAILS_LIST_H__
#define __DETAILS_LIST_H__

#include "obj.h"

typedef struct __list_elem         {
    __mem              *mem        ;
    struct __list_elem *prev, *next;
    struct list_t      *list;
    __obj              *elem;
}   __list_elem;

extern __obj_trait __list_trait;
typedef struct     __list      {
    __obj       head      ;
    __alloc    *alloc     ;
    __list_elem begin, end;
}   __list;

bool_t       __list_init         (__list*, __alloc*);
bool_t       __list_init_as_clone(__list*, __list*) ;
void         __list_deinit       (__list*)          ;

__list_elem* __list_push_back    (__list*, __obj*)              ;
__list_elem* __list_push_front   (__list*, __obj*)              ;
__list_elem* __list_push_at      (__list*, __obj*, __list_elem*);

void         __list_pop_front    (__list*)              ;
void         __list_pop_back     (__list*)              ;
void         __list_pop_at       (__list*, __list_elem*);

#endif
