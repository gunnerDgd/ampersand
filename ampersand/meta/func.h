#ifndef AMPERSAND_META_FUNC_H
#define AMPERSAND_META_FUNC_H

#include <ampersand/base/obj.h>
#include <ampersand/base/it.h>

extern obj_trait* ap_func_t;

obj* ap_func_script   (obj*);
obj* ap_func_ret      (obj*);
it   ap_func_arg_begin(obj*);
it   ap_func_arg_end  (obj*);
obj* ap_func_strt	  (obj*);

#endif