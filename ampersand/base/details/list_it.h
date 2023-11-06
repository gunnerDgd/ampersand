#ifndef __DETAILS_LIST_IT_H__
#define __DETAILS_LIST_IT_H__

#include "it.h"
#include "list.h"

extern __it_trait __list_it_trait;

void   __list_it_begin(__list*, __it*);
void   __list_it_end  (__list*, __it*);

bool_t __list_it_next (__it*);
void*  __list_it_get  (__it*);
void*  __list_it_set  (__it*, void*);

bool_t __list_it_eq   (__it*, __it*);
bool_t __list_it_lt   (__it*, __it*);
bool_t __list_it_gt   (__it*, __it*);

#endif