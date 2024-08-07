#ifndef AP_TRANS_FUNC_HPP
#define AP_TRANS_FUNC_HPP

#include <ap/trans/trans.hpp>
#include <string_view>

namespace ap::trans                              {
    template <typename Trait>
    class func<Trait>                            {
        using trait = Trait;
    public:
        void call(auto ops) { trait::call (ops); }
        void ret (auto ops) { trait::ret  (ops); }
    };
}

#endif
