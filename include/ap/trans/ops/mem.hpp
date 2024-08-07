#ifndef AP_TRANS_MOVE_HPP
#define AP_TRANS_MOVE_HPP

#include <ap/trans/trans.hpp>
#include <ap/meta/meta.hpp>
#include <string_view>

namespace ap::trans {
    template <typename Trait> 
    class mem <Trait>                           {
    public:
        using str_t = std::string_view;
        using trait = Trait;
    public:
        void push(auto ops, meta::type_id type) { trait::push(ops, type); }
        void push(auto ops, str_t         type) { trait::push(ops, type); }
        void move(auto ops) { trait::move (ops); }
        void pop (auto ops) { trait::pop  (ops); }
    };
}

#endif