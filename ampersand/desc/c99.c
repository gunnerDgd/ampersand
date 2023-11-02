#include "c99.h"

#include "c99/func.h"
#include "c99/ops.h"
#include "c99/strt.h"
#include "c99/script.h"

ap_desc_context c99_desc_impl = {
	.func   = &c99_desc_func  ,
	.ops    = &c99_desc_ops   ,
	.script = &c99_desc_script,
	.strt   = &c99_desc_strt
};

ap_desc_context* c99_desc = &c99_desc_impl;