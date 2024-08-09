#ifndef AP_COND_HPP
#define AP_COND_HPP

#include <ap/meta/meta.hpp>
#include <ap/core/core.hpp>
#include <ap/trait.hpp>

namespace ap                                             {
    // For if (...) {}
    template <is::op_t C>
        requires can::move<ap::var<ap::types::bool_t>, C>
    struct op<opc::cond, C>                   {
        using src_t = std::optional<meta::src>;
        src_t src;

        using  cond_t = C;
        cond_t cond;

        op(cond_t cond, auto func)
            : cond (cond)        {
                meta::src::push();
                func();

                src = meta::src::pop();
        }

    };

    // For if (...) {} else {}
    template <is::op_t C, typename... T>
        requires can::move<ap::var<ap::types::bool_t>, C>
    struct op<opc::cond, C, op<opc::cond, T...>> {
        using src_t = std::optional<meta::src>;
        src_t src;

        using  next_t = op<opc::cond, T...>;
        using  cond_t = C;
        next_t next;
        cond_t cond;

        op(cond_t cond, auto func, next_t next)
            : cond (cond),
              next (next)        {
                meta::src::push();
                func();
                
                src = meta::src::pop();
        }
    };

    template <>
    struct op<opc::cond>                      {
        using src_t = std::optional<meta::src>;
        src_t src;

        op(auto func)        {
            meta::src::push();
            func();

            src = meta::src::pop();
        }
    };
}

#endif
