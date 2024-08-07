#ifndef AP_FN_HPP
#define AP_FN_HPP

#include <ap/core/operator/call.hpp>

#include <ap/trans/trans.hpp>
#include <ap/meta/meta.hpp>
#include <ap/meta/src.hpp>
#include <ap/trait.hpp>

#include <string_view>
#include <optional>
#include <tuple>

namespace ap                                 {
    template <opc C, typename... T> struct op;
}

namespace ap                         {
    template <typename... T> class fn;

    template <is::type_t R, is::var_t... A>
    class fn<R(A...)> 
        : public call<fn<R(A...)>>                                               
                                                                                 {
        using arg_t = std::optional <std::tuple <A...>>;
        using src_t = std::optional <meta::src>;
        using str_t = std::string_view;
        
        template <std::size_t I, typename... T> friend auto arg (const fn<T...>&);
        template                <typename... T> friend auto name(const fn<T...>&);

        template <typename... F>
        friend class trans::fn;
        friend class meta ::fn;

        str_t name;
        arg_t arg;
        src_t src;
    public:
        fn(str_t, auto, A...);
        fn(str_t);
    };

    template <is::type_t R>
    class fn<R()> 
        : public call<fn<R()>>       
                                                                  {
        using src_t = std::optional <meta::src>;
        using str_t = std::string_view;
        
        template <typename... T> friend auto name(const fn<T...>&);
        template <typename... F>
        friend class trans::fn;
        friend class meta ::fn;

        str_t name;
        src_t src;
    public:
        fn(str_t, auto);
        fn(str_t);
    };

    template <is::var_t... A>
    class fn<void(A...)> 
        : public call<fn<void(A...)>>          
                                                                                 {

        using arg_t = std::optional <std::tuple <A...>>;
        using src_t = std::optional <meta::src>;
        using str_t = std::string_view;
        
        template <std::size_t I, typename... T> friend auto arg (const fn<T...>&);
        template                <typename... T> friend auto name(const fn<T...>&);
        template <typename... F>
        friend class trans::fn;
        friend class meta ::fn;

        str_t name;
        arg_t arg;
        src_t src;
    public:
        fn(str_t, auto, A...);
        fn(str_t);
    };

    template <>
    class fn<void()> 
        : public call<fn<void()>> 
                                                                  {
        using src_t = std::optional <meta::src>;
        using str_t = std::string_view;
        
        template <typename... T> friend auto name(const fn<T...>&);
        template <typename... F>
        friend class trans::fn;
        friend class meta ::fn;

        str_t name;
        src_t src;
    public:
        fn(str_t, auto);
        fn(str_t);
    };
}

// Friend Function Declaration
namespace ap                       {
    template <typename... T>
    auto name (const fn<T...>& fn) {
        return fn.name;
    }

    template <std::size_t I, typename... T>
    auto arg(const fn<T...>& fn)          {
        return std::get<I>(fn.arg.value());
    }
}

// For Return and Argument all exists
namespace ap                                       {
    template <is::type_t R, is::var_t... A>
    fn<R(A...)>::fn
        (str_t name, auto func, A... arg)
            : call<fn<R(A...)>>(*this),

              arg  (std::make_tuple(arg...)),
              name (name)                     
                                                   {
        meta::src::push();

        auto ret = func(arg...);
        static_assert (can::move<ap::var<R>, decltype(ret)>);
        meta::ret (ret);

        this->src = meta::src::pop();
        meta::src::push(*this);
    }

    template <is::type_t R, is::var_t... A>
    fn<R(A...)>::fn
        (str_t name) 
            : call<fn<R(A...)>>(*this),
              name(name),
              
              arg (std::nullopt),
              src (std::nullopt)  {
        meta::src::push(*this);
    }
}

namespace ap                                        {
    template <is::type_t  R>
    fn<R()>::fn(str_t name, auto func)
        : call<fn<R()>>(*this),
          name (name)                       
                                                            {
        meta::src::push();
        auto ret = func();

        static_assert (can::move<ap::var<R>, decltype(ret)>);
        meta::ret (ret);

        this->src = meta::src::pop();
        meta::src::push(*this);
    }

    template <is::type_t R>
    fn<R()>::fn
        (str_t name) 
            : call<fn<R()>>(*this),
              name(name),
              src ()              {
        meta::src::push(*this);
    }
}




namespace ap                                    {
    template <is::var_t... A>
    fn<void(A...)>::fn
        (str_t name, auto func, A... arg)
            : call<fn<void(A...)>>(*this),

              arg  (std::make_tuple (arg...)),
              name (name)                  
                                                {
        meta::src::push();

        this->src = meta::src::pop();
        meta::src::push(*this);
    }

    template <is::var_t... A>
    fn<void(A...)>::fn
        (str_t name) 
            : call<fn<void(A...)>>(*this),
              name(name),
              
              arg (std::nullopt),
              src (std::nullopt) {
        meta::src::push(*this);
    }
}

namespace ap                                     {
    fn<void()>::fn
        (str_t name, auto func)
            : call<fn<void()>>(*this),
              name (name)                    
                                     {
        meta::src::push ();

        this->src = meta::src::pop();
        meta::src::push(*this);
    }
}

#endif
