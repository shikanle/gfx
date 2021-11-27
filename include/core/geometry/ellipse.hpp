#pragma once

#include "../math/vector_2.hpp"
#include "parametric_curve_2.hpp"
#include "circular_domain.hpp"

template <typename float_system>
class ellipse : public object {
public:
    declare_parametric_curve_2_concept_types;

public:
    float_t a; // radius x
    float_t b; // radius y

    dynamic_reflectible(ellipse, {
        register_field(a);
        register_field(b);
    });

public:
    inline ellipse() : a(float_system::one()), b(float_system::one()) {}
    inline ellipse(float_t a, float_t b) : a(a), b(b) {}

public:
    vector_t operator()(domain_value_t t) const {
        return vector_t(
            float_system::cos(t) * this->a,
            float_system::sin(t) * this->b);
    }
};
