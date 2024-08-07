#ifndef AP_META_OP_HPP
#define AP_META_OP_HPP

#include <string_view>
#include <list>

#include <ap/trans/trans.hpp>
#include <ap/core/core.hpp>
#include <ap/meta/meta.hpp>

#include <ap/trait.hpp>


namespace ap::meta                                      {
    class op                                            {
        template <typename... T> friend class trans::ops;
        using arg_t = std::list<ope>;

        opc   opcode;
        arg_t arg;

        template <typename T, typename U>      friend op move(T, U);
        template <typename T>                  friend op push(T);
        template <typename T>                  friend op pop (T);

        template <typename T, typename... Arg> friend op call(T, Arg...);
        template <typename T>                  friend op ret (T);

        template <typename T, typename U>      friend op add_eq(T, U);
        template <typename T, typename U>      friend op sub_eq(T, U);
        template <typename T, typename U>      friend op mul_eq(T, U);
        template <typename T, typename U>      friend op div_eq(T, U);
        template <typename T, typename U>      friend op mod_eq(T, U);

        template <typename T, typename U>      friend op add (T, U);
        template <typename T, typename U>      friend op sub (T, U);
        template <typename T, typename U>      friend op mul (T, U);
        template <typename T, typename U>      friend op div (T, U);
        template <typename T, typename U>      friend op mod (T, U);

        template <typename T, typename U>      friend op bit_and(T, U);
        template <typename T, typename U>      friend op bit_or (T, U);
        template <typename T, typename U>      friend op bit_xor(T, U);
        template <typename T>                  friend op bit_not(T);

        template <typename T, typename U>      friend op bit_shl(T, U);
        template <typename T, typename U>      friend op bit_shr(T, U);

        template <typename T, typename U>      friend op bit_and_eq(T, U);
        template <typename T, typename U>      friend op bit_or_eq (T, U);
        template <typename T, typename U>      friend op bit_xor_eq(T, U);

        template <typename T, typename U>      friend op bool_and(T, U);
        template <typename T, typename U>      friend op bool_or (T, U);
        template <typename T>                  friend op bool_not(T);

        template <typename T, typename U>      friend op cmp_eq(T, U);
        template <typename T, typename U>      friend op cmp_ne(T, U);

        template <typename T, typename U>      friend op ord_lt(T, U);
        template <typename T, typename U>      friend op ord_le(T, U);
        template <typename T, typename U>      friend op ord_gt(T, U);
        template <typename T, typename U>      friend op ord_ge(T, U);

        template <typename... T>
        op (opc opcode, T... ope)
            : opcode (opcode)               {
                (arg.emplace_back(ope), ...);
        }
    public:
        template <typename F, typename... A>          
        op(ap::op<opc::call, F, A...> op)
            requires (sizeof...(A) > 0)
                : opcode(opc::call)          {
                    arg.emplace_back (op.fun);

                    [this, &op]<std::size_t... I> (std::index_sequence<I...>) {
                        (arg.emplace_back(std::get<I>(op.arg)), ...);
                    }   (std::make_index_sequence<sizeof...(A)> {});
        }

        template <typename F>
        op(ap::op<opc::call, F> op)
            : opcode (opc::call)         {
                arg.emplace_back (op.fun);
        }

        template <opc C, typename T, typename U> 
        op(ap::op<C, T, U> op) 
            requires (C != opc::call)     {
                arg.emplace_back (op.self);
                arg.emplace_back (op.arg);
        }

        template <opc C, typename T>             
        op(ap::op<C, T> op)
            requires (C != opc::call)    {
                arg.emplace_back(op.self);
        }
    };
}


namespace ap::meta                                                                                                  {
    template <typename T, typename U>      op move(T self, U arg) { return op (opc::move, self, arg); }
    template <typename T>                  op push(T self)        { return op (opc::push, self); }
    template <typename T>                  op pop (T self)        { return op (opc::pop , self); }

    template <typename T, typename... Arg> op call(T self, Arg... arg) { return op (opc::call, self, arg...); }
    template <typename T>                  op ret (T self)             { return op (opc::ret , self); }

    template <typename T, typename U>      op add_eq(T self, U arg) { return op (opc::add_eq, self, arg); }
    template <typename T, typename U>      op sub_eq(T self, U arg) { return op (opc::sub_eq, self, arg); }
    template <typename T, typename U>      op mul_eq(T self, U arg) { return op (opc::mul_eq, self, arg); }
    template <typename T, typename U>      op div_eq(T self, U arg) { return op (opc::div_eq, self, arg); }
    template <typename T, typename U>      op mod_eq(T self, U arg) { return op (opc::mod_eq, self, arg); }

    template <typename T, typename U>      op add(T self, U arg) { return op(opc::add, self, arg); }
    template <typename T, typename U>      op sub(T self, U arg) { return op(opc::sub, self, arg); }
    template <typename T, typename U>      op mul(T self, U arg) { return op(opc::mul, self, arg); }
    template <typename T, typename U>      op div(T self, U arg) { return op(opc::div, self, arg); }
    template <typename T, typename U>      op mod(T self, U arg) { return op(opc::mod, self, arg); }

    template <typename T, typename U>      op bit_and(T self, U arg) { return op (opc::bit_and, self, arg); }
    template <typename T, typename U>      op bit_or (T self, U arg) { return op (opc::bit_or , self, arg); }
    template <typename T, typename U>      op bit_xor(T self, U arg) { return op (opc::bit_xor, self, arg); }
    template <typename T>                  op bit_not(T self)        { return op (opc::bit_not, self); }
    
    template <typename T, typename U>      op bit_shl(T self, U arg) { return op (opc::bit_shl, self, arg); }
    template <typename T, typename U>      op bit_shr(T self, U arg) { return op (opc::bit_shr, self, arg); }

    template <typename T, typename U>      op bit_and_eq(T self, U arg) { return op (opc::bit_and_eq, self, arg); }
    template <typename T, typename U>      op bit_or_eq (T self, U arg) { return op (opc::bit_or_eq , self, arg); }
    template <typename T, typename U>      op bit_xor_eq(T self, U arg) { return op (opc::bit_xor_eq, self, arg); }

    template <typename T, typename U>      op bool_and(T self, U arg) { return op (opc::bool_and, self, arg); }
    template <typename T, typename U>      op bool_or (T self, U arg) { return op (opc::bool_or , self, arg); }
    template <typename T>                  op bool_not(T self)        { return op (opc::bool_not, self); }

    template <typename T, typename U>      op cmp_eq(T self, U arg) { return op (opc::cmp_eq, self, arg); }
    template <typename T, typename U>      op cmp_ne(T self, U arg) { return op (opc::cmp_ne, self, arg); }

    template <typename T, typename U>      op ord_lt(T self, U arg) { return op (opc::ord_lt, self, arg); }
    template <typename T, typename U>      op ord_le(T self, U arg) { return op (opc::ord_le, self, arg); }
    template <typename T, typename U>      op ord_gt(T self, U arg) { return op (opc::ord_gt, self, arg); }
    template <typename T, typename U>      op ord_ge(T self, U arg) { return op (opc::ord_ge, self, arg); }
}

#endif
