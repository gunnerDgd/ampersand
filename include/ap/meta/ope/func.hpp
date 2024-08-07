#ifndef AP_META_OPE_FUNC_HPP
#define AP_META_OPE_FUNC_HPP

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>

namespace ap::meta                    {
    class func                        {
        using str_t = std::string_view;

        friend str_t name(func&);
        str_t name;
    public:
        template <typename... T> func(ap::fn<T...>);
    };
}

namespace ap::meta                        {
    std::string_view name(ap::meta::func&);
}

namespace ap::meta              {
    template <typename... T>
    func::func (ap::fn<T...> fn)
        : name (ap::name (fn))
            {}
}

#endif
