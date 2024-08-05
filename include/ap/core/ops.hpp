#ifndef AP_OPS_HPP
#define AP_OPS_HPP

#include "ap/meta/pack.hpp"
#include "ap/meta/ope/num.hpp"
#include "ap/meta/ope/var.hpp"
#include "ap/trait/opc.hpp"
#include "ap/meta/ope.hpp"
#include "ap/meta/ope/op.hpp"

namespace ap                                     {
    template <ap::opc C, typename... T> struct op;
}

#endif
