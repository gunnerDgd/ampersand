#ifndef __IT_H__
#define __IT_H__

#include "type.h"
#include "type_atomic.h"

typedef struct it { u64_t it[4]; } it;

bool_t it_next(it*);

void*  it_get (it*);
void*  it_set (it*, void*);

bool_t it_eq  (it*, it*);
bool_t it_lt  (it*, it*);
bool_t it_gt  (it*, it*);

#ifndef __cplusplus
#define next(par)		      it_next(&par)
#define get(par)		      it_get (&par)
#define get_as(par, par_type) ((par_type)get(par))
#define set(par)		      it_set (&par)
#define eq(par, par_cmp)      it_eq  (&par, &par_cmp)
#define neq(par, par_cmp)    !it_eq  (&par, &par_cmp)
#define lt(par, par_cmp)      it_lt  (&par, &par_cmp)
#define gt(par, par_cmp)      it_gt  (&par, &par_cmp)
#endif

#endif