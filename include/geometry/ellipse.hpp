#pragma once

#include "../math/vector_2.hpp"
#include "parametric_curve_2.hpp"
#include "circular_domain.hpp"

template <typename float_system>
class ellipse : public object {
public:
    declare_parametric_curve_2_concept_types;

public:
    float_t radius_x;
    float_t radius_y;

    dynamic_reflectible(ellipse, {
        register_field(radius_x);
        register_field(radius_y);
    });

public:
    inline ellipse() : radius_x(float_system::one()), radius_y(float_system::one()) {}
    inline ellipse(float_t radius_x, float_t radius_y) : radius_x(radius_x), radius_y(radius_y) {}

public:
    vector_t operator()(domain_value_t v) const {
        return vector_t(
            float_system::cos(v) * this->radius_x,
            float_system::sin(v) * this->radius_y);
    }
};
