#pragma once

#include "ellipse.hpp"
#include "parametric_curve_2.hpp"
#include "../math/frame_2.hpp"

template <typename float_system>
class ellipse_2 : public parametric_curve_2<float_system>, public ellipse<float_system> {
public:
    declare_circular_curve(parametric_curve_2<float_system>);
    typedef frame_2<float_system> frame_t;

public:
    frame_t frame;

    dynamic_reflectible(ellipse_2, {
        register_super(parametric_curve_2<float_system>);
        register_super(ellipse<float_system>);
        register_field(frame);
    });

public:
    inline ellipse_2() : ellipse<float_system>(), frame() {}
    inline ellipse_2(float_t radius_x, float_t radius_y, const frame_t &frame) : 
        ellipse<float_system>(radius_x, radius_y), frame(frame) {}

public:
    virtual vector_t operator()(domain_value_t v) const override {
        return this->frame(ellipse<float_system>::operator()(v));
    }
};
