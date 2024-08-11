#ifndef AP_GRAMMAR_FOR_HPP
#define AP_GRAMMAR_FOR_HPP

#include <ap/meta.hpp>
#include <ap/core.hpp>

namespace ap                                                                  {
    auto For()                                                                {
        meta::src::push();
        return []<is::op_t S, is::op_t C, is::op_t E>(S stmt, C cond, E expr) {
            return [=](auto func)                 {
                return op<opc::loop_for, S, C, E> {
                    stmt,
                    cond,
                    expr,
                    func
                };
            };
        };
    }
}

#endif
