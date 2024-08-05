#ifndef AP_PACK_HPP
#define AP_PACK_HPP

#include <ap/meta/meta.hpp>
#include <ap/meta/src.hpp>
#include <ap/trait.hpp>

#include <string_view>
#include <tuple>

namespace ap                            {
    template <typename... T> class pack;
    template <typename... T> class var;

    template <typename N, is::var_t... T>
    class pack<N, T...>                          {
        template <typename... F> friend class var;
        using str_t = std::string_view;
        using tup_t = std::tuple<T...>;
        using idx_t = std::size_t;

        template <std::size_t I, typename... V> friend auto sub (const ap::pack<V...>&);
        template <typename... V>                friend auto name(const ap::pack<V...>&);
        str_t name;
        tup_t type;
    public:
        static constexpr idx_t num = sizeof...(T);
        pack(N, T...);
    };


    template <typename N, is::var_t... T>
    ap::pack<N, T...>::pack(N name, T... pack)
        : type (std::make_tuple(pack...)),
          name (N::name())               {
            meta::src::push (*this);
    }

    template <typename N, is::var_t... T> pack (N, T...) -> pack<N, T...>;
}

namespace ap                                {
    template <std::size_t I, typename... V> 
    auto 
        sub (const ap::pack<V...>& pack) { 
            return std::get<I>(pack.type); 
    }

    template <typename... V>
    auto 
        name(const ap::pack<V...>& pack) { 
            return pack.name; 
    }
}
#endif
