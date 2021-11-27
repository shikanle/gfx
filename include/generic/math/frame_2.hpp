#pragma once

#include "vector_2.hpp"
#include "unit_vector_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class frame_2 {
public:
    typedef vector_2<float_system> vector_t;
    typedef unit_vector_2<float_system> unit_vector_t;

public:
    vector_t center;
    unit_vector_t axis_x;
    reflectible(frame_2, {
        register_field(center);
        register_field(axis_x);
    });

public:
    inline frame_2() : center(), 
        axis_x(float_system::one(), float_system::zero()) {}

    inline frame_2(const vector_t &center, const unit_vector_t &axis_x) : 
        center(center), axis_x(axis_x) {} 

public:
    inline vector_t operator()(const vector_t &v) const {
        return vector_t(
            this->axis_x.x * v.x - this->axis_x.y * v.y + this->center.x,
            this->axis_x.y * v.x + this->axis_x.x * v.y + this->center.y);
    }
};

}
}
