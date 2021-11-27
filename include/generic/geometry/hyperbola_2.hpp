#pragma once

#include "hyperbola.hpp"
#include "parametric_curve_2.hpp"
#include "../math/frame_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class hyperbola_2 : public parametric_curve_2<float_system>, public hyperbola<float_system> {
public:
    declare_circular_curve(parametric_curve_2<float_system>);
    typedef frame_2<float_system> frame_t;

public:
    frame_t frame;

    dynamic_reflectible(hyperbola_2, {
        register_super(parametric_curve_2<float_system>);
        register_super(hyperbola<float_system>);
        register_field(frame);
    });

public:
    inline hyperbola_2() : hyperbola<float_system>(), frame() {}
    inline hyperbola_2(float_t a, float_t b, const frame_t &frame) : 
        hyperbola<float_system>(a, b), frame(frame) {}

public:
    virtual vector_t operator()(domain_value_t t) const override {
        return this->frame(hyperbola<float_system>::operator()(t));
    }
};

}
}