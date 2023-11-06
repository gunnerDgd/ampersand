#include "it.h"
#include "details/it.h"

bool_t it_next (it* par)				{ return __it_next(par); }
void*  it_get  (it* par)				{ return __it_get (par); }
void*  it_set  (it* par, void* par_set) { return __it_set(par, par_set); }

bool_t it_eq   (it* par, it* par_cmp)   { return __it_eq(par, par_cmp); }
bool_t it_lt   (it* par, it* par_cmp)   { return __it_lt(par, par_cmp); }
bool_t it_gt   (it* par, it* par_cmp)   { return __it_gt(par, par_cmp); }