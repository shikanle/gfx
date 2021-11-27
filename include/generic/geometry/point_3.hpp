#pragma once

#include "point.hpp"
#include "range_space_3.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class point_3 : public point<float_system>, public range_space_3<float_system> {
public:
    typedef typename range_space_3<float_system>::vector_t vector_t;
    
public:
    vector_t position;

    dynamic_reflectible(point_3, {
        register_super(point<float_system>);
        register_super(range_space_3<float_system>);
        register_field(position);
    });

public:
    inline point_3() : position() {}
    inline point_3(const vector_t &position) : position(position) {}
};

}
}