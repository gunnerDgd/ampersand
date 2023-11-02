#ifndef AMPERSAND_DESC_C99_DETAILS_FUNC_H
#define AMPERSAND_DESC_C99_DETAILS_FUNC_H

#include "ctx.h"

#include <ampersand/desc/desc.h>
#include <ampersand/desc/details/desc.h>

bool_t
	__c99_desc_func_arg
		(str*, obj*);

bool_t
	__c99_desc_func_ret
		(str*, obj*);

bool_t
	__c99_desc_func
		(str*, obj*);

#endif