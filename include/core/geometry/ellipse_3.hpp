#pragma once

#include "ellipse.hpp"
#include "parametric_curve_3.hpp"
#include "../math/frame_3.hpp"

template <typename float_system>
class ellipse_3 : public parametric_curve_3<float_system>, public ellipse<float_system> {
public:
    declare_circular_curve(parametric_curve_3<float_system>);
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
    inline ellipse_3(float_t a, float_t b, const frame_t &frame) : 
        ellipse<float_system>(a, b), frame(frame) {}

public:
    virtual vector_t operator()(domain_value_t t) const override {
        return this->frame(ellipse<float_system>::operator()(t));
    }
};
