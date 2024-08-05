#ifndef AP_TRANS_MOVE_HPP
#define AP_TRANS_MOVE_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans {
    template <typename Trait> 
    class move <Trait>                     {
    public:
        using trait = typename Trait;
        using ret_t = typename Trait::ret_t;
        using str_t = std::string_view;

    public:
        ret_t mov(auto ops) { return trait::mov (ops); }
    };
}

#endif