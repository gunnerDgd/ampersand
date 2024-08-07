#include <ap/meta/ope.hpp>

namespace ap::meta                   {
    ope::ope(func& arg) : sub (arg) {}
    ope::ope(var&  arg) : sub (arg) {}
    ope::ope(num&  arg) : sub (arg) {}
    ope::ope(op &  arg) : sub (arg) {}

    std::optional<var>
        as_var(ope& self)       {
            auto& sub = self.sub;

            if (sub.index() != 0) return std::nullopt;
            return std::get<0>(sub);
    }

    std::optional<num>
        as_num(ope& self)       {
            auto& sub = self.sub;

            if (sub.index() != 1) return std::nullopt;
            return std::get<1>(sub);
    }

    std::optional<op>
        as_op(ope& self)        {
            auto& sub = self.sub;

            if (sub.index() != 2) return std::nullopt;
            return std::get<2>(sub);
    }

    std::optional<func>
        as_func(ope& self)      {
            auto& sub = self.sub;

            if (sub.index() != 3) return std::nullopt;
            return std::get<3>(sub);
    }
}

namespace ap::meta                                         {
    ope::type
        type(ope& ope)                                     {
            if (ope.sub.index() == 0) return ope::type::var;
            if (ope.sub.index() == 1) return ope::type::num;
            if (ope.sub.index() == 2) return ope::type::op;
            if (ope.sub.index() == 3) return ope::type::func;
            return ope::type::none;
    }
}