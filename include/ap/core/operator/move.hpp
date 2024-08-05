#ifndef AP_OPERATOR_MOVE_HPP
#define AP_OPERATOR_MOVE_HPP

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trait.hpp>

namespace ap                                 {
    template <opc C, typename... T> struct op;
}

namespace ap             {
    template <typename T>
    class move          {
        using sub_t = T&;
        sub_t sub;
    public:
        move (sub_t self)       : sub (self)     {}
        move (const move& copy) : sub (copy.sub) {}
    public:
        template <typename U> auto operator=(U);
        auto operator=(const move&);
    };

    template <typename T>
    auto
        move<T>::operator=
            (const move& copy)      {
                return move { copy };
    }

    template <typename T>
    template <typename U>
    auto
        move<T>::operator=
            (U arg)                             {
                auto ret = meta::move (sub, arg);
                meta::src::push(ret);

                return op<opc::move, T, U> { sub, arg };
    }
}

#endif
