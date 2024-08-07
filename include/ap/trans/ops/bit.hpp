#ifndef AP_TRANS_BIT_HPP
#define AP_TRANS_BIT_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans                         {
    template <typename Trait> 
    class bit <Trait>                       {
    public:
        using trait = typename Trait;
    public:
        void bit_and_eq(auto ops) { trait::bit_and_eq (ops); }
        void bit_or_eq (auto ops) { trait::bit_or_eq  (ops); }
        void bit_xor_eq(auto ops) { trait::bit_xor_eq (ops); }
        
        void bit_and(auto ops) { trait::bit_and (ops); }
        void bit_or (auto ops) { trait::bit_or  (ops); }
        void bit_xor(auto ops) { trait::bit_xor (ops); }
    };
}

#endif
