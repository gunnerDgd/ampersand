#ifndef AMPERSAND_META_DETAILS_SCRIPT_H
#define AMPERSAND_META_DETAILS_SCRIPT_H

#include <ampersand/base/list.h>

extern obj_trait __ap_script_trait;
typedef struct   __ap_script	  {
	obj  head;
	list ops ;
}	__ap_script;

bool_t
	__ap_script_init
		(__ap_script*, u32_t, va_list);

bool_t
	__ap_script_init_as_clone
		(__ap_script*, __ap_script*);

bool_t
	__ap_script_init_as_ref
		(__ap_script*);

void
	__ap_script_deinit
		(__ap_script*);

u64_t
	__ap_script_size
		();

#endif