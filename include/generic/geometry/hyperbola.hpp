#pragma once

#include "../math/vector_2.hpp"
#include "parametric_curve_2.hpp"
#include "circular_domain.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class hyperbola : public object {
public:
    declare_parametric_curve_2_concept_types;

public:
    float_t a; // transverse_axis;
    float_t b; // conjugate_axis;

    dynamic_reflectible(hyperbola, {
        register_field(a);
        register_field(b);
    });

public:
    inline hyperbola() : a(float_system::one()), b(float_system::one()) {}
    inline hyperbola(float_t a, float_t b) : a(a), b(b) {}

public:
    vector_t operator()(domain_value_t t) const {
        return vector_t(
            float_system::cosh(t) * this->a,
            float_system::sinh(t) * this->b);
    }
};

}
}