#ifndef AP_META_PACK_HPP
#define AP_META_PACK_HPP

#include <string_view>
#include <list>

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trait.hpp>

namespace ap::meta                                       {
    class pack                                           {
        template <typename... T> friend class trans::pack;
        using str_t = std::string_view;
        using var_t = std::list<var>;
        using num_t = std::size_t;

        friend str_t name(meta::pack&);
        str_t name;
        var_t sub;
    public:
        template <typename N, typename... T> pack (ap::pack<N, T...>&);
    };

    template <typename N, typename... T>
    pack::pack (ap::pack<N, T...>& arg)
        : name (ap::name (arg))                                       {
            [this, &arg]<std::size_t... I>(std::index_sequence<I...>) {
                (sub.emplace_back (ap::sub<I> (arg)), ...);
            }   (std::make_index_sequence<sizeof...(T)> {});
    }
}

namespace ap::meta                    {
    std::string_view name(meta::pack&);
}

#endif
