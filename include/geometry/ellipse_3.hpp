#pragma once

#include "ellipse.hpp"
#include "parametric_curve_3.hpp"
#include "../math/frame_3.hpp"

template <typename float_system>
class ellipse_3 : public parametric_curve_3<float_system>, public ellipse<float_system> {
public:
    declare_unbounded_curve(parametric_curve_3<float_system>);
    typedef frame_3<float_system> frame_t;

public:
    frame_t frame;

    dynamic_reflectible(ellipse_3, {
        register_super(parametric_curve_3<float_system>);
        register_super(ellipse<float_system>);
        register_field(frame);
    });

public:
    inline ellipse_3() : ellipse<float_system>(), frame() {}
    inline ellipse_3(float_t radius_x, float_t radius_y, const frame_t &frame) : 
        ellipse<float_system>(radius_x, radius_y), frame(frame) {}

public:
    virtual vector_t operator()(domain_value_t v) const override {
        return this->frame(ellipse<float_system>::operator()(v));
    }

    virtual const bounded_domain_t &natural_bounded_domain() const override {
        static bounded_domain_t bounds(-float_system_t::pi(), float_system_t::pi());
        return bounds;
    }
};
