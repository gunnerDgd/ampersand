#ifndef AP_TRANS_ARI_HPP
#define AP_TRANS_ARI_HPP

#include <ap/trans/trans.hpp>
#include <string_view>


namespace ap::trans                        {
    template <typename Trait>
    class ari<Trait>                       {
    public:
        using trait = typename Trait;
    public:
        void add_eq(auto ops) { trait::add_eq(ops); }
        void sub_eq(auto ops) { trait::sub_eq(ops); }
        void mul_eq(auto ops) { trait::mul_eq(ops); }
        void div_eq(auto ops) { trait::div_eq(ops); }
        void mod_eq(auto ops) { trait::mod_eq(ops); }

        void add(auto ops) { trait::add(ops); }
        void sub(auto ops) { trait::sub(ops); }
        void mul(auto ops) { trait::mul(ops); }
        void div(auto ops) { trait::div(ops); }
        void mod(auto ops) { trait::mod(ops); }
    };
}

#endif
