#pragma once

#include "../math/vector_2.hpp"
#include "parametric_curve_2.hpp"
#include "circular_domain.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class circle : public object {
public:
    declare_parametric_curve_2_concept_types;

public:
    float_t radius;

    dynamic_reflectible(circle, {
        register_field(radius);
    });

public:
    inline circle() : radius(float_system::one()) {}
    inline circle(float_t radius) : radius(radius) {}

public:
    vector_t operator()(domain_value_t t) const {
        return vector_t(
            float_system::cos(t) * this->radius,
            float_system::sin(t) * this->radius);
    }
};

}
}