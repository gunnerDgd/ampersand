#ifndef AP_TRANS_CMP_HPP
#define AP_TRANS_CMP_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans                         {
    template <typename Trait>
    class cmp<Trait>                        {
    public:
        using trait = Trait;
    public:
        void cmp_eq(auto ops) { trait::cmp_eq(ops); }
        void cmp_ne(auto ops) { trait::cmp_ne(ops); }
    };
}


#endif
