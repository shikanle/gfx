#pragma once

#include "vector_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class range_1 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;
    typedef float_t vector_t;

public:
    float_t min;
    float_t max;
    reflectible(range_1, {
        register_field(min);
        register_field(max);
    });
    
public:
    inline range_1() : min(0), max(0) {} 
    inline range_1(float_t min, float_t max) : min(min), max(max) {}

public:
    inline bool in(float_t v) const {
        return (this->min <= v) && (v <= this->max);
    }
};

}
}