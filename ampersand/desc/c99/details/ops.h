#ifndef AMPERSAND_DESC_C99_DETAILS_OPS_H
#define AMPERSAND_DESC_C99_DETAILS_OPS_H

#include "ctx.h"

#include <ampersand/desc/desc.h>
#include <ampersand/desc/details/desc.h>

bool_t
	__c99_desc_ops
		(str*, obj*);

bool_t
	__c99_desc_ops_arg
		(str*, obj*);

bool_t
	__c99_desc_ops_arith
		(str*, obj*);

bool_t
	__c99_desc_ops_bit
		(str*, obj*);

bool_t
	__c99_desc_ops_cmp
		(str*, obj*);

bool_t
	__c99_desc_ops_logical
		(str*, obj*);

bool_t
	__c99_desc_ops_push
		(str*, obj*);

bool_t
	__c99_desc_ops_pop
		(str*, obj*);

bool_t
	__c99_desc_ops_func
		(str*, obj*);

#endif