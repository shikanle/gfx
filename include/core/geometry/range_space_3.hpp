#pragma once

#include "range_space.hpp"
#include "../math/euclidean_space_3.hpp"

template <typename float_system>
class range_space_3 : public range_space<float_system> {
public:
    typedef euclidean_space_3<float_system> range_space_t;
    typedef typename range_space_t::vector_t vector_t;

public:
    dynamic_reflectible(range_space_3, {
        register_super(range_space<float_system>);
    });

public:
    inline int range_dimension() const { return 3; }
};