#ifndef AP_TRANS_ORD_HPP
#define AP_TRANS_ORD_HPP

#include <ap/trans/trans.hpp>
#include <string_view>


namespace ap::trans                         {
    template <typename Trait>
    class ord <Trait>                       {
    public:
        using trait = typename Trait;
        using ret_t = typename Trait::ret_t;
        using str_t = std::string_view;
    public:
        ret_t ord_gt(auto ops) { return trait::ord_gt(ops); }
        ret_t ord_ge(auto ops) { return trait::ord_ge(ops); }
        ret_t ord_lt(auto ops) { return trait::ord_lt(ops); }
        ret_t ord_le(auto ops) { return trait::ord_le(ops); }
    };
}

#endif
