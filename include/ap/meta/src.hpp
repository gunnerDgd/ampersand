#ifndef AP_META_SRC_HPP
#define AP_META_SRC_HPP

#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <string_view>
#include <unordered_map>
#include <list>


namespace ap::meta                                    {
    class src                                         {
        template <typename... T> friend class ap::pack;
        template <typename... T> friend class ap::var;
        template <typename... T> friend class ap::fn;

        template <typename T>    friend class ari_eq;
        template <typename T>    friend class bit_eq;
        template <typename T>    friend class move;
        using str_t = std::string_view;

        static void push(ap::meta::pack);
        static void push(ap::meta::var);
        static void push(ap::meta::ope);
        static void push(ap::meta::op);
        static void push(ap::meta::fn);
        static void push();

        static std::optional<src> capture();
        static std::optional<src> pop    ();

        src();

        using pack_t = std::unordered_map<str_t, ap::meta::pack>;
        using var_t  = std::unordered_map<str_t, ap::meta::var>;
        using fun_t  = std::unordered_map<str_t, ap::meta::fn>;
        using ops_t  = std::list<ap::meta::op>;
        pack_t pack;
        fun_t  fun;
        var_t  var;
        ops_t  ops;
    };
}

#endif
