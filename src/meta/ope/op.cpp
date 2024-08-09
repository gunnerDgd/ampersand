#include <ap/meta/ope.hpp>
#include <ap/meta/src.hpp>

#include <ap/core/cond.hpp>

namespace ap::meta               {
    op::op(ap::op<opc::cond>& op) 
        : opcode (opc::cond)               {
            if (!op.src.has_value()) return;
            auto& src = op.src.value();

            for (auto& pos : src.ops) this->src.push_back(pos);
    }
}