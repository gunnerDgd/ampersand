#ifndef AMPERSAND_DESC_STRT_H
#define AMPERSAND_DESC_STRT_H

#include "desc.h"

bool_t ap_desc_strt				   (obj*, obj*)				 ;
bool_t ap_desc_strt_begin		   (obj*, str*)				 ;
bool_t ap_desc_strt_begin_from_cstr(obj*, const char*, u64_t);
bool_t ap_desc_strt_elem		   (obj*, obj*)				 ;
bool_t ap_desc_strt_end			   (obj*)				     ;

#endif