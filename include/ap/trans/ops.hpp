#ifndef AP_TRANS_OPS_HPP
#define AP_TRANS_OPS_HPP

#include <ap/meta/meta.hpp>
#include <ap/core/core.hpp>

#include <ap/meta/ope.hpp>

#include "ops/ari.hpp"
#include "ops/bit.hpp"
#include "ops/boolean.hpp"
#include "ops/func.hpp"
#include "ops/cmp.hpp"
#include "ops/ord.hpp"
#include "ops/mem.hpp"

namespace ap::trans                       {
    template <typename T, typename... Arg>
    class ops <T, Arg...> : public Arg... {
    public:
        auto operator()(ap::meta::op op) {
            auto  ops = T::ops();
            auto& arg = op.arg;

            auto pos = arg.begin();
            this->self (ops, *pos);
            this->opc  (ops, op.opcode);

            for (++pos; pos != arg.end(); ++pos) this->arg (ops, *pos);
            return ops;
        }

        void self(auto, std::floating_point auto);
        void self(auto, std::integral       auto);

        void self(auto, ap::meta::func);
        void self(auto, ap::meta::ope&);
        void self(auto, ap::meta::var);
        void self(auto, ap::meta::num);
        void self(auto, ap::meta::op);

        void arg(auto, std::floating_point auto);
        void arg(auto, std::integral       auto);

        void arg(auto, ap::meta::func);
        void arg(auto, ap::meta::ope&);
        void arg(auto, ap::meta::var);
        void arg(auto, ap::meta::num);
        void arg(auto, ap::meta::op);

        void opc(auto, ap::opc);

        ops (T, Arg...) : Arg()... {}
    };

    template <typename T, typename... Arg> ops(T, Arg...) -> ops<T, Arg...>;
}

// For ap::trans::ops::opc
namespace ap::trans                                                       {
    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::opc
            (auto op, ap::opc opc)                                        {
                switch (opc)                                              {
                    case opc::move:       this->move      (op, opc); break;
                    case opc::push:       this->push      (op, opc); break;
                    case opc::pop:        this->pop       (op, opc); break;

                    case opc::call:       this->call      (op, opc); break;
                    case opc::ret:        this->ret       (op, opc); break;

                    case opc::add_eq:     this->add_eq    (op, opc); break;
                    case opc::sub_eq:     this->sub_eq    (op, opc); break;
                    case opc::mul_eq:     this->mul_eq    (op, opc); break;
                    case opc::div_eq:     this->div_eq    (op, opc); break;
                    case opc::mod_eq:     this->mod_eq    (op, opc); break;

                    case opc::add:        this->add       (op, opc); break;
                    case opc::sub:        this->sub       (op, opc); break;
                    case opc::mul:        this->mul       (op, opc); break;
                    case opc::div:        this->div       (op, opc); break;
                    case opc::mod:        this->mod       (op, opc); break;

                    case opc::bit_and:    this->bit_and   (op, opc); break;
                    case opc::bit_or:     this->bit_or    (op, opc); break;
                    case opc::bit_xor:    this->bit_xor   (op, opc); break;
                    case opc::bit_not:    this->bit_not   (op, opc); break;

                    case opc::bit_shl:    this->bit_shl   (op, opc); break;
                    case opc::bit_shr:    this->bit_shr   (op, opc); break;
    
                    case opc::bit_and_eq: this->bit_and_eq(op, opc); break;
                    case opc::bit_or_eq:  this->bit_or_eq (op, opc); break;
                    case opc::bit_xor_eq: this->bit_xor_eq(op, opc); break;

                    case opc::bool_and:   this->bool_and  (op, opc); break;
                    case opc::bool_or :   this->bool_or   (op, opc); break;
                    case opc::bool_not:   this->bool_not  (op, opc); break;

                    case opc::cmp_eq:     this->cmp_eq    (op, opc); break;
                    case opc::cmp_ne:     this->cmp_ne    (op, opc); break;

                    case opc::ord_lt:     this->ord_lt    (op, opc); break;
                    case opc::ord_le:     this->ord_le    (op, opc); break;
                    case opc::ord_gt:     this->ord_gt    (op, opc); break;
                    case opc::ord_ge:     this->ord_ge    (op, opc); break;
            }
    }
}

// For ap::trans::ops::self
namespace ap::trans                                  {
    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::self
            (auto op, std::floating_point auto self) {
                T::self(op, self);
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::self
            (auto op, std::integral auto self) {
                T::self(op, self);
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::self
            (auto op, ap::meta::func self)                      {
                T::self(op, meta::type_id::func, ap::name(self));
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::self
            (auto op, ap::meta::var self)  {
                auto type = ap::type (self);
                
                if (type.index() == 0) T::self(op, std::get<0>(type), ap::name(self));
                if (type.index() == 1) T::self(op, std::get<1>(type), ap::name(self));
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::self
            (auto op, ap::meta::op self)  {
                T::self(op, (*this)(self));
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::self
            (auto op, ap::meta::ope& self)                                                        {
                switch (ap::meta::type(self))                                                     {
                    case meta::ope::type::func: this->self(op, meta::as_func(self).value()); break;
                    case meta::ope::type::var:  this->self(op, meta::as_var (self).value()); break;
                    case meta::ope::type::num:  this->self(op, meta::as_num (self).value()); break;
                    case meta::ope::type::op:   this->self(op, meta::as_op  (self).value()); break;
                }
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::self
            (auto op, ap::meta::num self)                                          {
                switch (ap::meta::type(self))                                      {
                    case meta::type_id::f64: T::self(op, meta::as_f64(self)); break;
                    case meta::type_id::f32: T::self(op, meta::as_f32(self)); break;

                    case meta::type_id::u64: T::self(op, meta::as_u64(self)); break;
                    case meta::type_id::u32: T::self(op, meta::as_u32(self)); break;
                    case meta::type_id::u16: T::self(op, meta::as_u16(self)); break;
                    case meta::type_id::u8 : T::self(op, meta::as_u8 (self)); break;

                    case meta::type_id::i64: T::self(op, meta::as_i64(self)); break;
                    case meta::type_id::i32: T::self(op, meta::as_i32(self)); break;
                    case meta::type_id::i16: T::self(op, meta::as_i16(self)); break;
                    case meta::type_id::i8 : T::self(op, meta::as_i8 (self)); break;
                }
    }

}

// For ap::trans::ops::arg
namespace ap::trans                                                          {
    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::arg
            (auto op, ap::meta::num arg)                                     {
                switch (ap::meta::type(arg))                                 {
                    case meta::type_id::f64: T::arg(meta::as_f64(arg)); break;
                    case meta::type_id::f32: T::arg(meta::as_f32(arg)); break;

                    case meta::type_id::u64: T::arg(meta::as_u64(arg)); break;
                    case meta::type_id::u32: T::arg(meta::as_u32(arg)); break;
                    case meta::type_id::u16: T::arg(meta::as_u16(arg)); break;
                    case meta::type_id::u8 : T::arg(meta::as_u8 (arg)); break;

                    case meta::type_id::i64: T::arg(meta::as_i64(arg)); break;
                    case meta::type_id::i32: T::arg(meta::as_i32(arg)); break;
                    case meta::type_id::i16: T::arg(meta::as_i16(arg)); break;
                    case meta::type_id::i8 : T::arg(meta::as_i8 (arg)); break;
                }
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::arg
            (auto op, std::floating_point auto arg) {
                T::arg(op, arg);
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::arg
            (auto op, std::integral auto arg) {
                T::arg(op, arg);
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::arg
            (auto op, ap::meta::func arg)                      {
                T::arg (op, meta::type_id::func, ap::name(arg));
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::arg
            (auto op, ap::meta::var arg) {
                auto type = ap::type(self);

                if (type.index() == 0) T::arg(op, std::get<0>(type), ap::name(self));
                if (type.index() == 1) T::arg(op, std::get<1>(type), ap::name(self));
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::arg
            (auto op, ap::meta::op arg)  {
                T::arg(op, (*this)(arg));
    }

    template <typename T, typename... Arg>
    void
        ops<T, Arg...>::arg
            (auto op, ap::meta::ope& arg)                                                       {
                switch (ap::meta::type(arg))                                                    {
                    case meta::ope::type::func: this->arg(op, meta::as_func(arg).value()); break;
                    case meta::ope::type::var:  this->arg(op, meta::as_var (arg).value()); break;
                    case meta::ope::type::num:  this->arg(op, meta::as_num (arg).value()); break;
                    case meta::ope::type::op:   this->arg(op, meta::as_op  (arg).value()); break;
                }
    }
}
#endif
