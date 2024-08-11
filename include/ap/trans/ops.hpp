#ifndef AP_TRANS_OPS_HPP
#define AP_TRANS_OPS_HPP

#include <ap/trans/trans.hpp>
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

namespace ap::trans                                {
    template <typename... Arg>
    class ops : public Arg...                      {
    public:
        auto  operator()(ap::meta::op);

        void  arg(auto&&, std::floating_point auto);
        void  arg(auto&&, std::integral       auto);

        void  arg(auto&&, ap::meta::func);
        void  arg(auto&&, ap::meta::ope&);
        void  arg(auto&&, ap::meta::var);
        void  arg(auto&&, ap::meta::num);
        void  arg(auto&&, ap::meta::op);

        void  src(auto&&, ap::meta::op&);
        auto  opc(ap::opc);

        ops (Arg...) : Arg()... {}
    };

    template <typename... Arg> ops(Arg...) -> ops<Arg...>;
}

namespace ap::trans                             {
    template <typename... Arg>
    auto
        ops<Arg...>::operator()
            (ap::meta::op op)                   {
                auto  ops = this->opc(op.opcode);
                auto& arg = op.arg;
                auto& src = op.src;
                
                for (auto& pos : arg) this->arg (ops, pos);
                for (auto& pos : src) this->src (ops, pos);
                return     ops;
    }
}

// For ap::trans::ops::opc
namespace ap::trans                                                {
    template <typename... Arg>
    auto
        ops<Arg...>::opc
            (ap::opc opc)                                          {
                switch (opc)                                       {
                    case opc::move:       return this->move      ();
                    case opc::push:       return this->push      ();
                    case opc::pop:        return this->pop       ();
                    case opc::idx:        return this->idx       ();

                    case opc::call:       return this->call      ();
                    case opc::ret:        return this->ret       ();

                    case opc::add_eq:     return this->add_eq    ();
                    case opc::sub_eq:     return this->sub_eq    ();
                    case opc::mul_eq:     return this->mul_eq    ();
                    case opc::div_eq:     return this->div_eq    ();
                    case opc::mod_eq:     return this->mod_eq    ();

                    case opc::add:        return this->add       ();
                    case opc::sub:        return this->sub       ();
                    case opc::mul:        return this->mul       ();
                    case opc::div:        return this->div       ();
                    case opc::mod:        return this->mod       ();

                    case opc::bit_and:    return this->bit_and   ();
                    case opc::bit_or:     return this->bit_or    ();
                    case opc::bit_xor:    return this->bit_xor   ();
                    case opc::bit_not:    return this->bit_not   ();

                    case opc::bit_shl:    return this->bit_shl   ();
                    case opc::bit_shr:    return this->bit_shr   ();
    
                    case opc::bit_and_eq: return this->bit_and_eq();
                    case opc::bit_or_eq:  return this->bit_or_eq ();
                    case opc::bit_xor_eq: return this->bit_xor_eq();

                    case opc::bool_and:   return this->bool_and  ();
                    case opc::bool_or :   return this->bool_or   ();
                    case opc::bool_not:   return this->bool_not  ();

                    case opc::cmp_eq:     return this->cmp_eq    ();
                    case opc::cmp_ne:     return this->cmp_ne    ();

                    case opc::ord_lt:     return this->ord_lt    ();
                    case opc::ord_le:     return this->ord_le    ();
                    case opc::ord_gt:     return this->ord_gt    ();
                    case opc::ord_ge:     return this->ord_ge    ();

                    case opc::loop_while: return this->loop_while();
                    case opc::loop_for:   return this->loop_for  ();
                    case opc::cond:       return this->cond      ();
            }
    }
}

// For ap::trans::ops::arg
namespace ap::trans                                                          {
    template <typename... Arg>
    void
        ops<Arg...>::arg
            (auto&& op, ap::meta::num arg)                                   {
                switch (ap::meta::type(arg))                                 {
                    case meta::type_id::f64: op.arg(meta::as_f64(arg)); break;
                    case meta::type_id::f32: op.arg(meta::as_f32(arg)); break;

                    case meta::type_id::u64: op.arg(meta::as_u64(arg)); break;
                    case meta::type_id::u32: op.arg(meta::as_u32(arg)); break;
                    case meta::type_id::u16: op.arg(meta::as_u16(arg)); break;
                    case meta::type_id::u8 : op.arg(meta::as_u8 (arg)); break;

                    case meta::type_id::i64: op.arg(meta::as_i64(arg)); break;
                    case meta::type_id::i32: op.arg(meta::as_i32(arg)); break;
                    case meta::type_id::i16: op.arg(meta::as_i16(arg)); break;
                    case meta::type_id::i8 : op.arg(meta::as_i8 (arg)); break;
                }
    }

    template <typename... Arg>
    void
        ops<Arg...>::arg
            (auto&& op, std::floating_point auto arg) {
                op.arg(op, arg);
    }

    template <typename... Arg>
    void
        ops<Arg...>::arg
            (auto&& op, std::integral auto arg) {
                op.arg (op, arg);
    }

    template <typename... Arg>
    void
        ops<Arg...>::arg
            (auto&& op, ap::meta::func arg)                      {
                op.arg (meta::type_id::func, ap::meta::name(arg));
    }

    template <typename... Arg>
    void
        ops<Arg...>::arg
            (auto&& op, ap::meta::var arg)     {
                auto type = ap::meta::type(arg);
                auto name = ap::meta::name(arg);

                auto self = ap::meta::self(arg);
                auto len  = ap::meta::len (arg);
                if (!name.has_value()) return;

                if (type.index() == 0) goto do_pack;
                if (type.index() == 1) goto do_num;
                return;

    do_pack:    if (!self.has_value() && len >  1) op.arg (std::get<0>(type), len, name.value());
                if (!self.has_value() && len == 1) op.arg (std::get<0>(type),      name.value());

                if (self.has_value() && len >  1)  op.arg (std::get<0>(type), len, name.value(), self.value());
                if (self.has_value() && len == 1)  op.arg (std::get<0>(type),      name.value(), self.value());
                return;

    do_num:     if (!self.has_value() && len >  1) op.arg (std::get<1>(type), len, name.value());
                if (!self.has_value() && len == 1) op.arg (std::get<1>(type),      name.value());

                if (self.has_value() && len >  1)  op.arg (std::get<1>(type), len, name.value(), self.value());
                if (self.has_value() && len == 1)  op.arg (std::get<1>(type),      name.value(), self.value());
                return;
    }

    template <typename... Arg>
    void
        ops<Arg...>::arg
            (auto&& op, ap::meta::op arg) {
                op.arg((*this)(arg));
    }

    template <typename... Arg>
    void
        ops<Arg...>::arg
            (auto&& op, ap::meta::ope& arg)                                                     {
                switch (ap::meta::type(arg))                                                    {
                    case meta::ope::type::func: this->arg(op, meta::as_func(arg).value()); break;
                    case meta::ope::type::var:  this->arg(op, meta::as_var (arg).value()); break;
                    case meta::ope::type::num:  this->arg(op, meta::as_num (arg).value()); break;
                    case meta::ope::type::op:   this->arg(op, meta::as_op  (arg).value()); break;
                }
    }
}

namespace ap::trans                        {
    template <typename... Arg>
    void  
        ops<Arg...>::src
            (auto&& op, ap::meta::op& src) {
                op.src ((*this)(src));
    }

}

#endif
