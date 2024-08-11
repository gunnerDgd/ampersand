#ifndef AP_OPS_OPC_HPP
#define AP_OPS_OPC_HPP

#include <type_traits>
#include <cstdint>

namespace ap                                                         {
    enum class opc : std::uint64_t                                   {
        err        = (0x00 << 24) | (0x00 << 16) | (0x00 << 8) | 0x00,

        move       = (0x00 << 24) | (0x00 << 16) | (0x02 << 8) | 0x01,
        push       = (0x00 << 24) | (0x00 << 16) | (0x01 << 8) | 0x02,
        pop        = (0x00 << 24) | (0x00 << 16) | (0x01 << 8) | 0x03,

        call       = (0x00 << 24) | (0x00 << 16) | (0xFF << 8) | 0x04,
        ret        = (0x00 << 24) | (0x00 << 16) | (0x01 << 8) | 0x05,


        add        = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x00,
        sub        = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x01,
        mul        = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x02,
        div        = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x03,
        mod        = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x04,

        add_eq     = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x05,
        sub_eq     = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x06,
        mul_eq     = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x07,
        div_eq     = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x08,
        mod_eq     = (0x00 << 24) | (0x01 << 16) | (0x02 << 8) | 0x09,


        bit_and    = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x00,
        bit_or     = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x01,
        bit_xor    = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x02,
        bit_not    = (0x00 << 24) | (0x02 << 16) | (0x01 << 8) | 0x03,

        bit_and_eq = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x04,
        bit_or_eq  = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x05,
        bit_xor_eq = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x06,

        bit_shl    = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x07,
        bit_shr    = (0x00 << 24) | (0x02 << 16) | (0x02 << 8) | 0x08,


        bool_and   = (0x00 << 24) | (0x03 << 16) | (0x02 << 8) | 0x00,
        bool_or    = (0x00 << 24) | (0x03 << 16) | (0x02 << 8) | 0x01,
        bool_not   = (0x00 << 24) | (0x03 << 16) | (0x01 << 8) | 0x02,


        cmp_eq     = (0x00 << 24) | (0x04 << 16) | (0x02 << 8) | 0x00,
        cmp_ne     = (0x00 << 24) | (0x04 << 16) | (0x02 << 8) | 0x01,

        ord_lt     = (0x00 << 24) | (0x05 << 16) | (0x02 << 8) | 0x00,
        ord_le     = (0x00 << 24) | (0x05 << 16) | (0x02 << 8) | 0x01,
        ord_gt     = (0x00 << 24) | (0x05 << 16) | (0x02 << 8) | 0x02,
        ord_ge     = (0x00 << 24) | (0x05 << 16) | (0x02 << 8) | 0x03,

        loop_while = (0x00 << 24) | (0x06 << 16) | (0x02 << 8) | 0x00,
        loop_for   = (0x00 << 24) | (0x06 << 16) | (0x02 << 8) | 0x01,
        cond       = (0x00 << 24) | (0x06 << 16) | (0x02 << 8) | 0x02,
    };
}

namespace ap::is::opc::details                              {
    template <ap::opc C> struct ari_eq  : std::false_type {};
    template <ap::opc C> struct bit_eq  : std::false_type {};

    template <ap::opc C> struct ari     : std::false_type {};
    template <ap::opc C> struct bit     : std::false_type {};
    template <ap::opc C> struct boolean : std::false_type {};
    template <ap::opc C> struct ord     : std::false_type {};
    template <ap::opc C> struct cmp     : std::false_type {};

    template <> struct ari_eq <ap::opc::add_eq> : std::true_type {};
    template <> struct ari_eq <ap::opc::sub_eq> : std::true_type {};
    template <> struct ari_eq <ap::opc::mul_eq> : std::true_type {};
    template <> struct ari_eq <ap::opc::div_eq> : std::true_type {};
    template <> struct ari_eq <ap::opc::mod_eq> : std::true_type {};

    template <> struct ari <ap::opc::add> : std::true_type {};
    template <> struct ari <ap::opc::sub> : std::true_type {};
    template <> struct ari <ap::opc::mul> : std::true_type {};
    template <> struct ari <ap::opc::div> : std::true_type {};
    template <> struct ari <ap::opc::mod> : std::true_type {};


    template <> struct bit_eq <ap::opc::bit_and_eq> : std::true_type {};
    template <> struct bit_eq <ap::opc::bit_or_eq>  : std::true_type {};
    template <> struct bit_eq <ap::opc::bit_xor_eq> : std::true_type {};

    template <> struct bit <ap::opc::bit_and> : std::true_type {};
    template <> struct bit <ap::opc::bit_or>  : std::true_type {};
    template <> struct bit <ap::opc::bit_xor> : std::true_type {};
    template <> struct bit <ap::opc::bit_not> : std::true_type {};

    template <> struct bit <ap::opc::bit_shl> : std::true_type {};
    template <> struct bit <ap::opc::bit_shr> : std::true_type {};

    template <> struct boolean <ap::opc::bool_and> : std::true_type {};
    template <> struct boolean <ap::opc::bool_not> : std::true_type {};
    template <> struct boolean <ap::opc::bool_or>  : std::true_type {};

    template <> struct cmp <ap::opc::cmp_eq> : std::true_type {};
    template <> struct cmp <ap::opc::cmp_ne> : std::true_type {};

    template <> struct ord <ap::opc::ord_gt> : std::true_type {};
    template <> struct ord <ap::opc::ord_ge> : std::true_type {};
    template <> struct ord <ap::opc::ord_lt> : std::true_type {};
    template <> struct ord <ap::opc::ord_le> : std::true_type {};
}

namespace ap::is::opc                                              {
    template <ap::opc C> concept ari_eq = details::ari_eq<C>::value;
    template <ap::opc C> concept bit_eq = details::bit_eq<C>::value;

    template <ap::opc C> concept ari = details::ari<C>::value;
    template <ap::opc C> concept bit = details::bit<C>::value;

    template <ap::opc C> concept boolean = details::boolean<C>::value;
    template <ap::opc C> concept ord     = details::ord    <C>::value;
    template <ap::opc C> concept cmp     = details::cmp    <C>::value;
}

#endif
