#pragma once

#include "parabola.hpp"
#include "parametric_curve_2.hpp"
#include "../math/frame_2.hpp"

template <typename float_system>
class parabola_2 : public parametric_curve_2<float_system>, public parabola<float_system> {
public:
    declare_circular_curve(parametric_curve_2<float_system>);
    typedef frame_2<float_system> frame_t;

public:
    frame_t frame;

    dynamic_reflectible(parabola_2, {
        register_super(parametric_curve_2<float_system>);
        register_super(parabola<float_system>);
        register_field(frame);
    });

public:
    inline parabola_2() : parabola<float_system>(), frame() {}
    inline parabola_2(float_t p, const frame_t &frame) : 
        parabola<float_system>(), frame(frame) {}

public:
    virtual vector_t operator()(domain_value_t t) const override {
        return this->frame(parabola<float_system>::operator()(t));
    }
};
