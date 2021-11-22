#pragma once

#include "circle.hpp"
#include "parametric_curve_2.hpp"

template <typename float_system>
class circle_2 : public parametric_curve_2<float_system>, public circle<float_system> {
public:
    declare_unbounded_curve(parametric_curve_2<float_system>);

public:
    vector_t center;

    dynamic_reflectible(circle_2, {
        register_super(parametric_curve_2<float_system>);
        register_super(circle<float_system>);
        register_field(center);
    });

public:
    inline circle_2() : circle<float_system>(), center() {}
    inline circle_2(float_t radius, const vector_t &center) : 
        circle<float_system>(radius), center(center) {}

public:
    virtual vector_t operator()(domain_value_t v) const override {
        return circle<float_system>::operator()(v) + this->center;
    }

    virtual const bounded_domain_t &natural_bounded_domain() const override {
        static bounded_domain_t bounds(-float_system_t::pi(), float_system_t::pi());
        return bounds;
    }
};
