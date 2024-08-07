#include <ap/meta/ope/func.hpp>
#include <ap/core/fn.hpp>

namespace ap::meta                 {
    std::string_view
        name(ap::meta::func& func) {
            return func.name;
    }
}