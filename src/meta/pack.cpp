#include <ap/meta/pack.hpp>

namespace ap::meta {
    std::string_view
        name (meta::pack& pack) {
            return pack.name;
    }
}