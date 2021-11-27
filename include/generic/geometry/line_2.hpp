#pragma once

#include "line.hpp"
#include "parametric_curve_2.hpp"

namespace gfx {
namespace generic {

template<typename float_system>
class line_2 : public line<parametric_curve_2<float_system> > {
public:
    typedef typename line<parametric_curve_2<float_system> >::vector_t vector_t;
    
public:
    dynamic_reflectible(line_2, {
        register_super(line<parametric_curve_2<float_system> >);
    });

public:
    inline line_2() {}
    inline line_2(const vector_t &p0, const vector_t &p1) :
        line<parametric_curve_2<float_system> >(p0, p1) {}
};

}
}