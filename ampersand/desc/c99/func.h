#ifndef AMPERSAND_DESC_C99_FUNC_H
#define AMPERSAND_DESC_C99_FUNC_H

#include "../desc.h"

bool_t c99_desc_func		  (obj*, obj*);
bool_t c99_desc_func_ret	  (obj*, obj*);
bool_t c99_desc_func_arg	  (obj*, obj*);
bool_t c99_desc_func_arg_begin(obj*);
bool_t c99_desc_func_arg_end  (obj*);

#endif