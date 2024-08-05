#ifndef AP_TRNAS_ARI_HPP
#define AP_TRANS_ARI_HPP

#include <ap/trans/trans.hpp>
#include <string_view>


namespace ap::trans                        {
    template <typename Trait>
    class ari<Trait>                       {
    public:
        using trait = typename Trait;
        using ret_t = typename Trait::ret_t;
        using str_t = std::string_view;

    public:
        ret_t add_eq(auto ops) { return trait::add_eq(ops); }
        ret_t sub_eq(auto ops) { return trait::sub_eq(ops); }
        ret_t mul_eq(auto ops) { return trait::mul_eq(ops); }
        ret_t div_eq(auto ops) { return trait::div_eq(ops); }
        ret_t mod_eq(auto ops) { return trait::mod_eq(ops); }

        ret_t add(auto ops) { return trait::add(ops); }
        ret_t sub(auto ops) { return trait::sub(ops); }
        ret_t mul(auto ops) { return trait::mul(ops); }
        ret_t div(auto ops) { return trait::div(ops); }
        ret_t mod(auto ops) { return trait::mod(ops); }
    };
}

#endif
