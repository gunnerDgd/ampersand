#ifndef AMPERSAND_DESC_DETAILS_DESC_H
#define AMPERSAND_DESC_DETAILS_DESC_H

#include <ampersand/base/obj.h>

typedef struct __ap_desc_context			       {
	bool_t (*strt)  (struct __ap_desc*, obj*, obj*);
	bool_t (*func)  (struct __ap_desc*, obj*, obj*);
	bool_t (*ops)   (struct __ap_desc*, obj*, obj*);
	bool_t (*script)(struct __ap_desc*, obj*, obj*);
}	__ap_desc_context;

extern obj_trait __ap_desc_trait;
typedef struct   __ap_desc		{
	obj			       head		;
	obj				  *ctx	    ;
	obj_trait		  *ctx_trait;
	__ap_desc_context *ctx_ops  ;
}	__ap_desc			        ;

bool_t
	__ap_desc_init
		(__ap_desc*, u32_t, va_list);

bool_t
	__ap_desc_init_as_clone
		(__ap_desc*, __ap_desc*);

bool_t
	__ap_desc_init_as_ref
		(__ap_desc*);

void
	__ap_desc_deinit
		(__ap_desc*);

u64_t
	__ap_desc_size
		();

#endif