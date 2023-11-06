#ifndef AMPERSAND_DETAILS_META_ELEM_H
#define AMPERSAND_DETAILS_META_ELEM_H

#include <ampersand/base/obj.h>

#define __ap_elem_attr_pub    0
#define __ap_elem_attr_priv   1
#define __ap_elem_attr_prot   2

#define __ap_elem_attr_dyn    0
#define __ap_elem_attr_stat   1

#define __ap_elem_obj  0
#define __ap_elem_func 1

extern obj_trait __ap_elem_trait;
typedef struct   __ap_elem		{
	obj				  head	    ;
	str				  name	    ;
	union					    {
	struct					    {
		u64_t acc  : 3;
		u64_t stor : 3;
	};
		u64_t all;
	}				  attr	  ;
	u64_t			  category;
	union					  {
		struct __ap_type *obj ;
		struct __ap_func *func;
		obj				 *all ;
	}	type;
}	__ap_elem;

bool_t __ap_elem_init		  (__ap_elem*, u32_t, va_list);
bool_t __ap_elem_init_as_clone(__ap_elem*, __ap_elem*)	  ;
bool_t __ap_elem_init_as_ref  (__ap_elem*)				  ;
void   __ap_elem_deinit		  (__ap_elem*)				  ;
str*   __ap_elem_name		  (__ap_elem*)				  ;
u64_t  __ap_elem_size		  ()						  ;

#endif