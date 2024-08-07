#ifndef AP_META_OPE_FUNC_HPP
#define AP_META_OPE_FUNC_HPP

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>

namespace ap::meta                                          {
    class func                                              {
        template <typename... T> friend class trans::boolean;
        template <typename... T> friend class trans::func;
        template <typename... T> friend class trans::mem;
        template <typename... T> friend class trans::ari;
        template <typename... T> friend class trans::bit;
        template <typename... T> friend class trans::cmp;
        template <typename... T> friend class trans::ord;

        template <typename... T> friend class trans::pack;
        template <typename... T> friend class trans::var;
        template <typename... T> friend class trans::ops;
        template <typename... T> friend class trans::op;
        template <typename... T> friend class trans::fn;
        using  str_t = std::string_view;
        friend str_t name(func&);
        str_t  name;
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
