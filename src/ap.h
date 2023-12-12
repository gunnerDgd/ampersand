#ifndef __AP_H__
#define __AP_H__

#include "type.h"
#include "cls.h"

#include "op.h"
#include "desc.h"
#include "val.h"
#include "var.h"

void ap_init  ();
void ap_deinit();

#define ap_main()                              \
    int ap_main_run();                         \
    int main()       {                         \
        ap_init    (); int ret = ap_main_run();\
        ap_deinit  ();                         \
        return ret   ;                         \
    }                                          \
    int ap_main_run()                          \

#endif