#pragma once

#include "line.hpp"
#include "parametric_curve_3.hpp"

template<typename float_system>
class line_3 : public line< parametric_curve_3<float_system> > {
public:
    typedef typename line< parametric_curve_3<float_system> >::vector_t vector_t;

public:
    dynamic_reflectible(line_3, {
        register_super(line<parametric_curve_3<float_system> >);
    });

public:
    inline line_3() {}
    inline line_3(const vector_t &p0, const vector_t &p1) :
        line< parametric_curve_3<float_system> >(p0, p1) {}
};