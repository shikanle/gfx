#pragma once

#include "bounded_parametric_curve.hpp"
#include "parametric_curve_3.hpp"

template <typename float_system>
class bounded_parametric_curve_3 : public parametric_curve_3<float_system> {
public:
    typedef typename parametric_curve_3<float_system>::geometry_t geometry_t;

public:
    dynamic_reflectible(bounded_parametric_curve_3, {
        register_super(parametric_curve_3<float_system>);
    });

public:
    bounded_parametric_curve_3() {}
    bounded_parametric_curve_3(geometry_t *geometry) : parametric_curve_3<float_system>(geometry) {}
};
