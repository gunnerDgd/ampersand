#ifndef AMPERSAND_DESC_C99_DETAILS_DESC_H
#define AMPERSAND_DESC_C99_DETAILS_DESC_H

#include <ampersand/base/obj.h>

extern obj_trait __c99_desc_trait;
typedef struct   __c99_desc	     {
	obj			head;
	str			ctx ;
	const char* err ;
}	__c99_desc		;

bool_t
	__c99_desc_init
		(__c99_desc*, u32_t, va_list);

bool_t
	__c99_desc_init_as_clone
		(__c99_desc*, __c99_desc*);

bool_t
	__c99_desc_init_as_ref
		(__c99_desc*);

void
	__c99_desc_deinit
		(__c99_desc*);

u64_t
	__c99_desc_size
		();

#endif