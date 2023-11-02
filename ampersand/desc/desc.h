#ifndef AMPERSAND_DESC_DESC_H
#define AMPERSAND_DESC_DESC_H

#include <ampersand/base/obj.h>

typedef struct ap_desc_context	      {
	bool_t (*strt)  (obj*, obj*, obj*);
	bool_t (*func)  (obj*, obj*, obj*);
	bool_t (*ops)   (obj*, obj*, obj*);
	bool_t (*script)(obj*, obj*, obj*);
}	ap_desc_context;

extern obj_trait* ap_desc_t;

obj*
	ap_desc_ctx
		(obj*);

bool_t
	ap_desc_strt
		(obj*, obj*);

bool_t
	ap_desc_func
		(obj*, obj*);

bool_t
	ap_desc_ops
		(obj*, obj*);

bool_t
	ap_desc_script
		(obj*, obj*);

#endif