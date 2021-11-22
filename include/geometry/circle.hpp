#pragma once

#include "../math/vector_2.hpp"
#include "parametric_curve_2.hpp"
#include "circular_domain.hpp"

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
    vector_t operator()(domain_value_t v) const {
        return vector_t(
            float_system::cos(v) * this->radius,
            float_system::sin(v) * this->radius);
    }
};
