#pragma once

#include "point.hpp"
#include "range_space_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class point_2 : public point<float_system>, public range_space_2<float_system> {
public:
    typedef typename range_space_2<float_system>::vector_t vector_t;
    
public:
    vector_t position;

    dynamic_reflectible(point_2, {
        register_super(point<float_system>);
        register_super(range_space_2<float_system>);
        register_field(position);
    });

public:
    inline point_2() : position() {}
    inline point_2(const vector_t &position) : position(position) {}
};

}
}