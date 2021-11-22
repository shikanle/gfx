#pragma once

#include "bounded_parametric_curve.hpp"
#include "parametric_curve_2.hpp"

template <typename float_system>
class bounded_parametric_curve_2 : public parametric_curve_2<float_system> {
public:
    typedef typename parametric_curve_2<float_system>::geometry_t geometry_t;

public:
    dynamic_reflectible(bounded_parametric_curve_2, {
        register_super(parametric_curve_2<float_system>);
    });

public:
    bounded_parametric_curve_2() {}
    bounded_parametric_curve_2(geometry_t *geometry) : parametric_curve_2<float_system>(geometry) {}
};
