#pragma once

#include "vector_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class range_2 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;
    typedef vector_2<float_system_t> vector_t;

public:
    vector_t min;
    vector_t max;
    reflectible(range_2, {
        register_field(min);
        register_field(max);
    });

public:
    inline range_2() : min(vector_t::zero()), max(vector_t::zero()) {} 
    inline range_2(const vector_t &min, const vector_t &max) : min(min), max(max) {}

public:
    inline bool in(const vector_t &v) const {
        return (this->min.x <= v.x) && (v.x <= this->max.x) &&
               (this->min.y <= v.y) && (v.y <= this->max.y);
    }
};

}
}