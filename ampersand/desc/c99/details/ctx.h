#ifndef AMPERSAND_DESC_C99_DETAILS_DESC_H
#define AMPERSAND_DESC_C99_DETAILS_DESC_H

#include <ampersand/base/obj.h>

extern obj_trait __c99_ctx_trait;
typedef struct   __c99_ctx	    {
	obj			head;
	str			ctx ;
	const char* err ;
}	__c99_ctx	    ;

bool_t
	__c99_ctx_init
		(__c99_ctx*, u32_t, va_list);

bool_t
	__c99_ctx_init_as_clone
		(__c99_ctx*, __c99_ctx*);

bool_t
	__c99_ctx_init_as_ref
		(__c99_ctx*);

void
	__c99_ctx_deinit
		(__c99_ctx*);

u64_t
	__c99_ctx_size
		();

#endif