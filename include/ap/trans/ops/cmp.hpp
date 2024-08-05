#ifndef AP_TRANS_CMP_HPP
#define AP_TRANS_CMP_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans                         {
    template <typename Trait>
    class cmp<Trait>                        {
    public:
        using trait = typename Trait;
        using ret_t = typename Trait::ret_t;
        using str_t = std::string_view;

    public:
        ret_t cmp_eq(auto ops) { return trait::cmp_eq(ops); }
        ret_t cmp_ne(auto ops) { return trait::cmp_ne(ops); }
    };
}


#endif
