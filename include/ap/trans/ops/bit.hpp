#ifndef AP_TRANS_BIT_HPP
#define AP_TRANS_BIT_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans                         {
    template <typename Trait> 
    class bit <Trait>                       {
    public:
        using trait = typename Trait;
        using ret_t = typename Trait::ret_t;
        using str_t = std::string_view;

    public:
        ret_t bit_and_eq(auto ops) { return trait::bit_and_eq (ops); }
        ret_t bit_or_eq (auto ops) { return trait::bit_or_eq  (ops); }
        ret_t bit_xor_eq(auto ops) { return trait::bit_xor_eq (ops); }
        
        ret_t bit_and(auto ops) { return trait::bit_and (ops); }
        ret_t bit_or (auto ops) { return trait::bit_or  (ops); }
        ret_t bit_xor(auto ops) { return trait::bit_xor (ops); }
    };
}

#endif
