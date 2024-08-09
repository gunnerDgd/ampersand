#ifndef AP_VAR_HPP
#define AP_VAR_HPP

#include <ap/core/operator/boolean.hpp>
#include <ap/core/operator/ord.hpp>
#include <ap/core/operator/cmp.hpp>

#include <ap/core/operator/move.hpp>
#include <ap/core/operator/ari.hpp>
#include <ap/core/operator/bit.hpp>

#include <ap/core/float.hpp>
#include <ap/core/int.hpp>
#include <ap/core/pack.hpp>

#include <ap/meta/src.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trait.hpp>

#include <string_view>
#include <list>

namespace ap                          {
    template <typename... T> class var;

    template <is::bool_t T>
    class var<T> 
        : public boolean <var<T>>     {
        using str_t = std::string_view;
        
        template <is::bool_t V> friend auto type(const ap::var<V>&);
        template <is::bool_t V> friend auto name(const ap::var<V>&);
        str_t name;

    public:
        var(T, str_t name)
            : boolean <var<T>> (*this),
              name (name)
        {
            meta::src::push (meta::push(*this));
            meta::src::push (meta::var (*this));
        }
    };

    template <is::int_t T>
    class var<T> 
        : public ari_eq <var<T>>,
          public ari    <var<T>>,
    
          public bit_eq <var<T>>,
          public bit    <var<T>>,
    
          public move   <var<T>>,
          
          public boolean<var<T>>,
          public cmp    <var<T>>,
          public ord    <var<T>>
                                    {
        using str = std::string_view;

        template <is::num_t V> friend auto type(const ap::var<V>&);
        template <is::num_t V> friend auto name(const ap::var<V>&);
        str name;
    public:
        var(T, str name)
            : ari_eq <var <T>> (*this),
              bit_eq <var <T>> (*this),
              
              ari    <var <T>> (*this),
              bit    <var <T>> (*this),

              move   <var <T>> (*this),
              
              boolean<var <T>> (*this),
              cmp    <var <T>> (*this),
              ord    <var <T>> (*this),

              name             (name)
        {
            meta::src::push(meta::push(*this));
            meta::src::push(meta::var (*this));
        }

        auto 
            operator=(auto arg)                                    {
                auto&  self = static_cast<ap::move<var<T>>&>(*this);
                return self = arg;
        }
    };

    template <is::float_t T>
    class var<T> 
        : public ari_eq <var<T>>,
          public ari    <var<T>>,
                    
          public move   <var<T>>,

          public boolean<var<T>>,
          public cmp    <var<T>>,
          public ord    <var<T>>

                                    {
        using str = std::string_view;

        template <is::num_t V> friend auto type(const ap::var<V>&);
        template <is::num_t V> friend auto name(const ap::var<V>&);
        str name;
    public:
        var(T, str name)
            : ari_eq <var <T>> (*this),
              ari    <var <T>> (*this),

              move   <var <T>> (*this),

              boolean<var <T>> (*this),
              cmp    <var <T>> (*this),
              ord    <var <T>> (*this),

              name             (name)
        {
            meta::src::push(meta::push(*this));
            meta::src::push(meta::var (*this));
        }

        auto 
            operator=(auto arg)                                    {
                auto&  self = static_cast<ap::move<var<T>>&>(*this);
                return self = arg;
        }
    };



    template <is::pack_t P, typename T>
    class var <var<P>, var<T>> : public var<T> {
        friend class var<P>;

        using  str = std::string_view;
        var<P> self;

        template <is::pack_t rP, typename rT> friend auto self(const ap::var<ap::var<rP>, ap::var<rT>>&);
        var(var<P>, var<T>);
    };

    template <is::pack_t P, typename T>
    ap::var<var<P>, var<T>>::var(var<P> sup, var<T> var)
        : var<T>(var),
          self  (sup)
    {}
          

    template <is::pack_t T>
    class var<T> : public move <var<T>> {
        using str = std::string_view;

        template <is::pack_t V, std::size_t I> friend auto sub (const ap::var<V>&);
        template <is::pack_t V>                friend auto type(const ap::var<V>&);
        template <is::pack_t V>                friend auto name(const ap::var<V>&);
        str name;
        T   pack;
    public:
        auto 
            operator=(var<T>& arg)                                 {
                auto&  self = static_cast<ap::move<var<T>>&>(*this);
                auto&  move = static_cast<ap::move<var<T>>&>(arg);
                return self = move;
        }

    public:
        var(T pack, str name)
            : move <var<T>> (*this),
              name (name),
              pack (pack)
        {
            meta::src::push(meta::push(*this));
            meta::src::push(meta::var (*this));
        }
    };

    template <is::pack_t P, typename T> var(var<P>, var<T>) -> var <var<P>, var<T>>;

    template <is::pack_t T> var(T, std::string_view) -> var<T>;
    template <is::num_t  T> var(T, std::string_view) -> var<T>;
}

namespace ap                                                                    {
    // For var<is::pack_T T>
    template <is::pack_t T> auto type(const ap::var<T>& var) { return var.pack; }
    template <is::pack_t T> auto name(const ap::var<T>& var) { return var.name; }

    template <is::pack_t V, std::size_t I>
    auto 
        sub (const ap::var<V>& var) {
            auto pack = var .pack;
            auto type = pack.type;

            return ap::var { var, std::get<I>(type) };
    }

    // For var<is::var_t T, is::var_t U>
    template <is::pack_t P, typename T>
    auto 
        self(const ap::var<ap::var<P>, ap::var<T>>& var) {
            return var.self;
    }

    // For var <is::int_t T> and var <is::float_t T>
    template <is::num_t T> auto type(const ap::var<T>& var) { return var.type; }
    template <is::num_t T> auto name(const ap::var<T>& var) { return var.name; }
}

#endif
