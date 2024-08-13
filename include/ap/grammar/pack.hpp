#ifndef AP_GRAMMAR_PACK_HPP
#define AP_GRAMMAR_PACK_HPP

#include <ap/meta.hpp>
#include <ap/core.hpp>

#define Pack(str)\
    [](auto... var)                           {\
        struct PackType                       {\
            static auto name() { return #str; }\
        };                                     \
        return ap::pack (PackType {}, var...); \
    }

#endif
