#ifndef AMPERSAND_DESC_OPS_H
#define AMPERSAND_DESC_OPS_H

#include "desc.h"

bool_t ap_desc_ops		  (obj*, obj*);
bool_t ap_desc_ops_arith  (obj*, obj*);
bool_t ap_desc_ops_bit    (obj*, obj*);
bool_t ap_desc_ops_cmp    (obj*, obj*);
bool_t ap_desc_ops_logical(obj*, obj*);
bool_t ap_desc_ops_func   (obj*, obj*);
bool_t ap_desc_ops_push	  (obj*, obj*);
bool_t ap_desc_ops_pop	  (obj*, obj*);
bool_t ap_desc_ops_end	  (obj*);

#endif