#ifndef AP_TRANS_BOOLEAN_HPP
#define AP_TRANS_BOOLEAN_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans                                     {
    template <typename Trait>
    class boolean<Trait>                                {
    public:
        using trait = Trait;
    public:
        void bool_and(auto ops) { trait::bool_and(ops); }
        void bool_or (auto ops) { trait::bool_or (ops); }
        void bool_not(auto ops) { trait::bool_not(ops); }
    };
}

#endif
