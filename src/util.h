#ifndef __AP_UTIL_H__
#define __AP_UTIL_H__

#include <obj.h>

#include "util/cls.h"
#include "util/type.h"
#include "util/var.h"
#include "util/op.h"

bool_t ap_eq         (obj*, obj*);
bool_t ap_neq        (obj*, obj*);
obj*   ap_type_of    (obj*)      ;
obj*   ap_type_common(obj*, obj*);

#endif