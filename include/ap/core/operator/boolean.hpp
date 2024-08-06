#ifndef AP_OPERATOR_BOOLEAN_HPP
#define AP_OPERATOR_BOOLEAN_HPP

#include <ap/trait/opc.hpp>

namespace ap                                     {
    template <ap::opc C, typename... T> struct op;
}

namespace ap                              {
    template <typename T>
    class boolean                         {
        template <typename... F> class var;
        using sub_t = T&;
        sub_t sub;
    public:
        boolean(sub_t self) : sub(self) {}
    public:
        template <typename U> auto operator&& (U arg) { return op<opc::bool_and, T, U> { sub, arg }; }
        template <typename U> auto operator|| (U arg) { return op<opc::bool_or , T, U> { sub, arg }; }
                              auto operator!  ()      { return op<opc::bool_not, T>    { sub }; }
    };
}

#endif
