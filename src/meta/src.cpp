#include <ap/meta/meta.hpp>

#include <ap/meta/pack.hpp>
#include <ap/meta/src.hpp>
#include <ap/meta/ope.hpp>

#include <stack>

namespace ap::meta::builtin                            {
    thread_local static std::stack<ap::meta::src> scope;
}

namespace ap::meta {
    src::src() {}
}

// src::push implemenetation
namespace ap::meta                                  {
    void
        src::push
            (ap::meta::pack pack)                   {
                auto& ret = ap::meta::builtin::scope;
                auto  str = ap::meta::name(pack);
                
                if (ret.empty()) return;
                if (str.empty()) return;

                auto& cur = ret.top();
                cur.pack.insert({ str, pack });
    }

    void
        src::push
            (ap::meta::src src)                     {
                auto& ret = ap::meta::builtin::scope;
                ret.push (meta::src {});
    }

    void
        src::push
            (ap::meta::var var)                     {
                auto& src = ap::meta::builtin::scope;
                auto  opt = ap::meta::name(var);

                if (src.empty()) return;
                if (!opt)        return;

                auto& cur = src.top();
                auto& ret = cur.var;
                
                ret.insert ({ opt.value(), var });
    }

    void
        src::push
            (ap::meta::ope op)                      {
                auto& src = ap::meta::builtin::scope;
                auto  ope = ap::meta::as_op(op);

                if (src.empty()) return;
                if (!ope)        return;

                auto& cur = src.top();
                auto& ret = cur.ops;
                
                ret.push_back (ope.value());
    }

    void
        src::push
            (ap::meta::op op)                       {
                auto& src = ap::meta::builtin::scope;
                if (src.empty()) return;

                auto& cur = src.top();
                auto& ret = cur.ops;
                
                ret.push_back (op);
    }
}


namespace ap::meta {
    auto
        src::pop ()                             {
            auto &src = ap::meta::builtin::scope;

            if (src.empty()) return std::optional <meta::src> { std::nullopt };
            auto &ret = src.top();
            src.pop ();

            return std::optional <meta::src> { ret };
    }

    auto
        src::capture()                          {
            auto &src = ap::meta::builtin::scope;

            if (src.empty()) return std::optional <meta::src> { std::nullopt };
            auto &ret = src.top();

            return std::optional<meta::src> { ret };
    }
}