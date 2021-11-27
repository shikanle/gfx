#pragma once

#include "../common/reflection.hpp"

namespace gfx {
namespace generic {
namespace intersection {

template <typename float_system>
class intersection {
public:
    typedef float_system float_system_t;
    typedef typename float_system::float_t float_t;

    enum class kind_t {
        normal,
        degenerate,
    };

public:
    kind_t kind;

    reflectible(intersection, {
        register_enum(kind);
    });
};

}
}
}