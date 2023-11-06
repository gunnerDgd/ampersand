#ifndef AMPERSAND_META_DETAILS_FUNC_H
#define AMPERSAND_META_DETAILS_FUNC_H

#include <ampersand/base/obj.h>
#include <ampersand/base/list.h>

extern obj_trait __ap_func_trait;
typedef struct   __ap_func	    {
	obj					head  ;
	str					name  ; 

	struct __ap_type   *strt  ;
	struct __ap_script *script;
	struct __ap_type   *ret	  ;
	list			    arg	  ;
}	__ap_func;

bool_t __ap_func_init		  (__ap_func*, u32_t, va_list);
bool_t __ap_func_init_as_clone(__ap_func*, __ap_func*)	  ;
bool_t __ap_func_init_as_ref  (__ap_func*)				  ;
void   __ap_func_deinit		  (__ap_func*)				  ;
str*   __ap_func_name		  (__ap_func*)				  ;
u64_t  __ap_func_size		  ()						  ;

#endif