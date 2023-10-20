#ifndef __IT_H__
#define __IT_H__

#include "type.h"
#include "type_atomic.h"

typedef struct it { u64_t it[4]; } it;

bool_t
	it_next
		(it*);

void*
	it_get
		(it*);

void*
	it_set
		(it*, void*);

bool_t
	it_eq
		(it*, it*);

bool_t
	it_lt
		(it*, it*);

bool_t
	it_gt
		(it*, it*);

#endif