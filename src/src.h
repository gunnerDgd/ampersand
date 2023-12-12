#ifndef __AP_SRC_H__
#define __AP_SRC_H__

#include <obj.h>
#include "op.h"

extern  obj_trait *ap_src_t   ;
typedef obj       *ap_src     ;
typedef void      *ap_src_elem;

ap_src_elem ap_src_next       (ap_src, ap_src_elem);
ap_src      ap_src_elem_as_src(ap_src_elem)        ;
ap_op       ap_src_elem_as_op (ap_src_elem)        ;

#endif