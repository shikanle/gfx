#pragma once

#include "intersection.hpp"

namespace gfx {
namespace generic {
namespace intersection {

template <typename float_system>
class intersection_points : public intersection<float_system> {
public:

public:
    reflectible(intersection, {
        register_super(intersection<float_system>);
    });
};

}
}
}