#ifndef AMPERSAND_DESC_C99_DETAILS_CONTEXT_H
#define AMPERSAND_DESC_C99_DETAILS_CONTEXT_H

#include <ampersand/base/obj.h>

#define __c99_context_idx_strt 0
#define __c99_context_idx_func 1
#define __c99_context_idx_ops  2

extern obj_trait __c99_trait;
typedef struct   __c99	    {
	obj			head        ;
	str			str         ;
	const char* err         ;
    u64_t       context_idx ;
    union                   {
    struct                  { str str; obj* strt; u64_t elem_count; } strt;
    struct                  { str str; obj* func; u64_t arg_count ; } func;
    struct                  { str str; obj* ops ; u64_t ops_op    ; } ops ;
    }   context;
}	__c99;

bool_t __c99_init		  (__c99*, u32_t, va_list);
bool_t __c99_init_as_clone(__c99*, __c99*)		  ;
bool_t __c99_init_as_ref  (__c99*)				  ;
void   __c99_deinit       (__c99*)                ;
u64_t  __c99_size         ()                      ;

#endif