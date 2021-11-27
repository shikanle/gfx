#pragma once

#include "intersection.hpp"
#include "../geometry/line_2.hpp"

namespace gfx {
namespace generic {
namespace intersection {

template <typename float_system>
class line_2_line_2 {
public:
    typedef line_2<float_system> line_2_t;

public:
    static void intersect(const line_2_t &a, const line_2_t &b) {
    }
};

}
}
}
