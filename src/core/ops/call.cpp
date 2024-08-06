#include <ap/core/call.hpp>
#include <ap/meta.hpp>

namespace ap                          {
    op<opc::call, fn<void (void)>>::op
        (fun_t func)
        : fun (func)
            {}
}