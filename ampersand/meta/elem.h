#ifndef AMPERSAND_META_ELEM_H
#define AMPERSAND_META_ELEM_H

#include <ampersand/base/obj.h>

extern obj_trait* ap_elem_t;

u64_t
	ap_elem_category
		(obj*);

obj*
	ap_elem_type
		(obj*);

u64_t
	ap_elem_attr
		(obj*);

u64_t
	ap_elem_attr_stor
		(obj*);

u64_t
	ap_elem_attr_acc
		(obj*);

#endif