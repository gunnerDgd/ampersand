#ifndef AMPERSAND_DESC_C99_DETAILS_OPS_H
#define AMPERSAND_DESC_C99_DETAILS_OPS_H

#include <ampersand/base/obj.h>

bool_t __c99_desc_ops_arith  (str*, u64_t);
bool_t __c99_desc_ops_bit    (str*, u64_t);
bool_t __c99_desc_ops_cmp    (str*, u64_t);
bool_t __c99_desc_ops_logical(str*, u64_t);

#endif