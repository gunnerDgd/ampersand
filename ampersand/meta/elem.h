#ifndef AMPERSAND_META_ELEM_H
#define AMPERSAND_META_ELEM_H

#include <ampersand/base/obj.h>

extern obj_trait* ap_elem_t;

#define ap_elem_attr_pub    0
#define ap_elem_attr_priv   1
#define ap_elem_attr_prot   2

#define ap_elem_attr_dyn    0
#define ap_elem_attr_stat   1

u64_t ap_elem_category (obj*);
obj*  ap_elem_type     (obj*);
u64_t ap_elem_attr     (obj*);
u64_t ap_elem_attr_stor(obj*);
u64_t ap_elem_attr_acc (obj*);

#endif