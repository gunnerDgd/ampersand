#include <ap/core/fn.hpp>
#include <ap/meta/fn.hpp>

#include <ap/meta/pack.hpp>
#include <ap/meta/ope.hpp>

namespace ap::meta              {
    fn::fn(ap::fn<void(void)> fn)
        : name (ap::name (fn)),
          src  (fn.src)
    {}
          
}

namespace ap::meta         {
    std::string_view
        name(meta::fn& fn) {
            return fn.name;
    }
}