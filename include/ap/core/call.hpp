#ifndef AP_CALL_HPP
#define AP_CALL_HPP

#include <ap/core/operator.hpp>

#include <ap/core/fn.hpp>
#include <ap/trait.hpp>

#include <tuple>

namespace ap                                               {
    template <is::int_t R, is::var_t... A, typename... Arg>
        requires can::arg<fn<R(A...)>, Arg...>
    struct op<opc::call,  fn<R(A...)>, Arg...>
        : public ari <op<opc::call, fn<R(A...)>>>,
          public bit <op<opc::call, fn<R(A...)>>>,
          public cmp <op<opc::call, fn<R(A...)>>>,
          public ord <op<opc::call, fn<R(A...)>>>

                                                     {
        using arg_t = std::tuple<Arg...>;
        using fun_t = fn<R(A...)>;

        fun_t fun;
        arg_t arg;

        op (fn<R(A...)> func, Arg... arg)
            : ari <op<opc::call, fn<R(A...)>>> (*this),
              bit <op<opc::call, fn<R(A...)>>> (*this),
              cmp <op<opc::call, fn<R(A...)>>> (*this),
              ord <op<opc::call, fn<R(A...)>>> (*this),

              arg (std::make_tuple (arg...)),
              fun (func)
                {}
    };

    template <is::float_t R, is::var_t... A, typename... Arg>
        requires can::arg<fn<R(A...)>, Arg...>
    struct op<opc::call,  fn<R(A...)>, Arg...>
        : public ari <op<opc::call, fn<R(A...)>>>,
          public cmp <op<opc::call, fn<R(A...)>>>,
          public ord <op<opc::call, fn<R(A...)>>>

                                                     {
        using arg_t = std::tuple<Arg...>;
        using fun_t = fn<R(A...)>;

        fun_t fun;
        arg_t arg;

        op (fn<R(A...)> func, Arg... arg)
            : ari <op<opc::call, fn<R(A...)>>>(*this),
              cmp <op<opc::call, fn<R(A...)>>>(*this),
              ord <op<opc::call, fn<R(A...)>>>(*this),
            
              arg (std::make_tuple (arg...)),
              fun (func)
                {}
    };

    template <is::pack_t R, is::var_t... A, typename... Arg>
        requires can::arg<fn<R(A...)>, Arg...>
    struct op<opc::call,  fn<R(A...)>, Arg...> {
        using arg_t = std::tuple<Arg...>;
        using fun_t = fn<R(A...)>;

        fun_t fun;
        arg_t arg;

        op (fn<R(A...)> func, Arg... arg)
            : arg (std::make_tuple (arg)...),
              fun (func)
                {}
    };
}


namespace ap                                 {
    template <is::int_t R>
    struct op<opc::call, fn <R(void)>> 
        : public ari <op<opc::call, fn<R()>>>,
          public bit <op<opc::call, fn<R()>>>,
          public cmp <op<opc::call, fn<R()>>>,
          public ord <op<opc::call, fn<R()>>>

                                                     {
        using fun_t = fn<R(void)>;
        fun_t fun;

        op (fn<R()> func)
            : ari <op<opc::call, fn<R()>>> (*this),
              bit <op<opc::call, fn<R()>>> (*this),
              cmp <op<opc::call, fn<R()>>> (*this),
              ord <op<opc::call, fn<R()>>> (*this),

              fun (func)
                {}
    };

    template <is::float_t R>
    struct op<opc::call, fn <R(void)>>
        : public ari <op<opc::call, fn<R()>>>,
          public cmp <op<opc::call, fn<R()>>>,
          public ord <op<opc::call, fn<R()>>>
                                                     {
        using fun_t = fn<R(void)>;
        fun_t fun;

        op (fn<R()> func)
            : ari <op<opc::call, fn<R()>>>(*this),
              bit <op<opc::call, fn<R()>>>(*this),
              cmp <op<opc::call, fn<R()>>>(*this),
              ord <op<opc::call, fn<R()>>>(*this),
            
              fun (func)
                {}
    };

    template <is::pack_t R>
    struct op<opc::call, fn <R(void)>>   {
        using fun_t = fn <R(void)>;
        fun_t fun;

        op (fn<R()> func)
            : fun (func)
                {}
    };
}

namespace ap                                       {
    template <is::var_t... A, typename... Arg>
        requires can::arg<fn<void(A...)>, Arg...>
    struct op<opc::call, fn <void(A...)>, Arg...> {
        using arg_t = std::tuple<Arg...>;
        using fun_t = fn<void(A...)>;

        fun_t fun;
        arg_t arg;

        op (fun_t func, Arg... arg)
            : arg (std::make_tuple(arg...)),
              fun (func)
                {}
    };
    
    template <>
    struct op<opc::call, fn <void(void)>> {
        using fun_t = fn <void(void)>;
        fun_t fun;

        op(fun_t);
    };
}

#endif
