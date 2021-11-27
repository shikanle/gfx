#pragma once

#include "../math/vector_2.hpp"
#include "parametric_curve_2.hpp"
#include "circular_domain.hpp"

template <typename float_system>
class parabola : public object {
public:
    declare_parametric_curve_2_concept_types;

public:
    float_t p;

    dynamic_reflectible(parabola, {
        register_field(p);
    });

public:
    inline parabola() : p(float_system::one()) {}
    inline parabola(float_t p) :p(p) {}

public:
    vector_t operator()(domain_value_t t) const {
        auto y = 2 * t * this->p;
        return vector_t(y * t, y);
    }
};
