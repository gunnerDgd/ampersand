#ifndef AP_GRAMMAR_FN_HPP
#define AP_GRAMMAR_FN_HPP

#include <ap/core.hpp>

namespace ap                                       {
    template <is::type_t R>
    auto Fn(R)                                     {
        return [=]<is::var_t... A>(A... arg)       {
            return [=](const char* name, auto fun) {
                return fn<R(A...)> {
                    name ,
                    fun  ,
                    arg...
                };
            };
        };
    }

    auto Fn()                                      {
        return [=]<is::var_t... A>(A... arg)       {
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
