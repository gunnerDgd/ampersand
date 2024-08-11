#include "ap/meta/ope/var.hpp"

namespace ap::meta                      {
    std::optional<std::string_view>
        self(var& self)                {
            var::str_t& ret = self.self;

            if (ret.empty()) return std::nullopt;
            return ret;
    }

    std::optional<std::string_view>
        name(var& self)                {
            var::str_t& ret = self.name;

            if (ret.empty()) return std::nullopt;
            return ret;
    }

    std::variant<std::string_view, type_id>
        type(var& self)           {
            auto& type = self.type;
            auto  idx  = self.idx;

            if (!type.empty()) return type;
            return idx;
    }

    std::uint64_t
        len(var& self)     {
            return self.len;
    }
}