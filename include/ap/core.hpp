#ifndef AP_CORE_HPP
#define AP_CORE_HPP

#include "core/operator/ari.hpp"
#include "core/operator/bit.hpp"
#include "core/operator/boolean.hpp"
#include "core/operator/move.hpp"
#include "core/operator/ord.hpp"

#include "core/pack.hpp"
#include "core/move.hpp"
#include "core/ari.hpp"
#include "core/bit.hpp"
#include "core/bool.hpp"
#include "core/float.hpp"
#include "core/int.hpp"
#include "core/var.hpp"


namespace ap                                 {
    template <is::type_t T>
    auto let(T& type)                        {
        return [type](std::string_view name) {
            return var<T> { type, name };
        };
    }
}

#endif
