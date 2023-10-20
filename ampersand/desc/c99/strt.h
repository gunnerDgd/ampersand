#ifndef AMPERSAND_DESC_C99_STRT_H
#define AMPERSAND_DESC_C99_STRT_H

#include "desc.h"

bool_t
	c99_desc_strt_begin
		(obj*, str*);

bool_t
	c99_desc_strt_end
		(obj*);

bool_t
	c99_desc_strt_elem
		(obj*, obj*);

bool_t
	c99_desc_strt
		(obj*, obj*);

#endif