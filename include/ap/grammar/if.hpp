#ifndef AP_GRAMMAR_IF_HPP
#define AP_GRAMMAR_IF_HPP

#include <ap/meta.hpp>
#include <ap/core.hpp>

namespace ap::details                                                   {
    template<class... Fn> struct If : Fn... { using Fn::operator()...; };
    template<class... Fn> If(Fn...) -> If<Fn...>;
}

namespace ap                                                                       {
    template <is::op_t C>
    auto If(C cond)           {
        return [=](auto func) {
            // One For Only If(...)
            auto If1 = [=]()                           {
                auto ret = op<opc::cond, C>(cond, func);
                meta::src::push (ret);
            };

            // And One For If (...) Else If (...) / Else (...)
            auto If2 = [=]<typename... T>(op<opc::cond, T...> next)               {
                auto ret = op<opc::cond, C, op<opc::cond, T...>>(cond, func, next);
                meta::src::push (ret);
            };

            return details::If { If1, If2 };
        };
    }

    template <is::op_t C>
    auto ElseIf(C cond)      {
        return [=](auto func) {
            // One For Only If(...)
            auto If1 = [=]()                           {
                auto ret = op<opc::cond, C>(cond, func);
                return ret;
            };

            // And One For If (...) Else If (...) / Else (...)
            auto If2 = [=]<typename... T>(op<opc::cond, T...> next)               {
                auto ret = op<opc::cond, C, op<opc::cond, T...>>(cond, func, next);
                return ret;
            };

            return details::If { If1, If2 };
        };
    }

    auto Else(auto func)          {
        return op<opc::cond>(func);
    }
}

#endif
