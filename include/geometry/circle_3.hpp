#pragma once

#include "circle.hpp"
#include "parametric_curve_3.hpp"
#include "../math/frame_3.hpp"

template <typename float_system>
class circle_3 : public parametric_curve_3<float_system>, public circle<float_system> {
public:
    declare_unbounded_curve(parametric_curve_3<float_system>);
    typedef frame_3<float_system> frame_t;

public:
    frame_t frame;

    dynamic_reflectible(circle_3, {
        register_super(parametric_curve_3<float_system>);
        register_super(circle<float_system>);
        register_field(frame);
    });

public:
    inline circle_3() : circle<float_system>(), frame() {}
    inline circle_3(float_t radius, const frame_t &frame) : 
        circle<float_system>(radius), frame(frame) {}

public:
    virtual vector_t operator()(domain_value_t v) const override {
        return this->frame(circle<float_system>::operator()(v));
    }

    virtual const bounded_domain_t &natural_bounded_domain() const override {
        static bounded_domain_t bounds(-float_system_t::pi(), float_system_t::pi());
        return bounds;
    }
};
