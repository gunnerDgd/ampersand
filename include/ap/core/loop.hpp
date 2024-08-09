#ifndef AP_LOOP_HPP
#define AP_LOOP_HPP

#include <ap/meta/meta.hpp>
#include <ap/core/core.hpp>
#include <ap/trait.hpp>

namespace ap                                            {

    // This is matched into for loop
    template <is::op_t S, is::op_t C, is::op_t E>
        requires can::move<ap::var<ap::types::bool_t>, C>
    struct op<opc::loop, S, C, E>                       {
        using  cond_t = C;
        using  stmt_t = S;
        using  expr_t = E;
        stmt_t stmt;
        cond_t cond;
        expr_t expr;

        using src_t = std::optional<meta::src>;
        src_t src;
        

        op(stmt_t stmt, cond_t cond, expr_t expr, auto func)
            : stmt(stmt),
              cond(cond),
              expr(expr)         {
                meta::src::push();
                func();
                
                src = meta::src::pop();
                meta::src::push(*this);
        }
    };

    // This is matched into while loop
     template <is::op_t C>
         requires can::move<ap::var<ap::types::bool_t>, C>
    struct op<opc::loop, C>                              {
        using src_t = std::optional<meta::src>;
        src_t src;

        using  cond_t = C;
        cond_t cond;

        op(cond_t cond, auto func)
            : cond(cond)         {
                meta::src::push();
                func();
                
                src = meta::src::pop();
                meta::src::push(*this);
        }
    };
}

#endif
