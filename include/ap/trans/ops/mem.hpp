#ifndef AP_TRANS_MOVE_HPP
#define AP_TRANS_MOVE_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans {
    template <typename Trait> 
    class mem <Trait>                           {
    public:
        using trait = Trait;
    public:
        void move(auto ops) { trait::move (ops); }
        void call(auto ops) { trait::call (ops); }
        void ret (auto ops) { trait::ret  (ops); }
    };
}

#endif