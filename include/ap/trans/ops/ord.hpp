#ifndef AP_TRANS_ORD_HPP
#define AP_TRANS_ORD_HPP

#include <ap/trans/trans.hpp>
#include <string_view>


namespace ap::trans                         {
    template <typename Trait>
    class ord <Trait>                       {
    public:
        using trait = Trait;
    public:
        void ord_gt(auto ops) { trait::ord_gt(ops); }
        void ord_ge(auto ops) { trait::ord_ge(ops); }
        void ord_lt(auto ops) { trait::ord_lt(ops); }
        void ord_le(auto ops) { trait::ord_le(ops); }
    };
}

#endif
