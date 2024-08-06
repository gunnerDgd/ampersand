#ifndef AP_CORE_HPP
#define AP_CORE_HPP

#include "core/operator/ari.hpp"
#include "core/operator/bit.hpp"
#include "core/operator/boolean.hpp"
#include "core/operator/move.hpp"
#include "core/operator/call.hpp"
#include "core/operator/ord.hpp"

#include "core/pack.hpp"
#include "core/move.hpp"
#include "core/call.hpp"
#include "core/ari.hpp"
#include "core/bit.hpp"
#include "core/bool.hpp"
#include "core/float.hpp"
#include "core/int.hpp"
#include "core/var.hpp"
#include "core/fn.hpp"


namespace ap                                 {
    template <is::type_t T>
    auto let(T& type)                        {
        return [type](std::string_view name) {
            return var<T> { type, name };
        };
    }
}

namespace ap {
    template <is::type_t R>
    auto func(R)                               {
        return [=]<is::var_t... A>(A... arg)   {
        return [=](const char* name, auto fun) {
        return fn<R(A...)> {
            name ,
            fun  ,
            arg...
        };
        };
        };
    }

    auto func()                                {
        return [=]<is::var_t... A>(A... arg)   {
        return [=](const char* name, auto fun) {
        return fn<void(A...)> {
            name ,
            fun  ,
            arg...
        };
        };
        };
    }
}

#endif
