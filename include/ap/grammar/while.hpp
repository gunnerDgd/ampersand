#ifndef AP_GRAMMAR_WHILE_HPP
#define AP_GRAMMAR_WHILE_HPP

#include <ap/meta.hpp>
#include <ap/core.hpp>

namespace ap                                      {
    auto While()                                  {
        meta::src::push();
            return []<is::op_t C>(C cond)         {
                return [=](auto func)             {
                    return op<opc::loop_while, C> {
                        cond,
                        func
                    };
                };
        };
    }
}

#endif
