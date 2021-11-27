#pragma once

#include "vector_2.hpp"
#include "vector_3.hpp"
#include "unit_vector_3.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class frame_3 {
public:
    typedef vector_3<float_system> vector_t;
    typedef vector_2<float_system> domain_value_t;
    typedef unit_vector_3<float_system> unit_vector_t;

public:
    vector_t center;
    unit_vector_t axis_x;
    unit_vector_t axis_y;
    reflectible(frame_3, {
        register_field(center);
        register_field(axis_x);
        register_field(axis_y);
    });

public:
    inline frame_3() : center(), 
        axis_x(float_system::one(), float_system::zero(), float_system::zero()),
        axis_y(float_system::zero(), float_system::one(), float_system::zero()) {}

    inline frame_3(const vector_t &center, const unit_vector_t &axis_x, const unit_vector_t &axis_y) : 
        center(center), axis_x(axis_x), axis_y(axis_y) {} 

public:
    inline vector_t operator()(const domain_value_t &v) const {
        return this->axis_x * v.x + this->axis_y * v.y + this->center;
    }
};

}
}