#pragma once

#include "geometry.hpp"
#include "../math/euclidean_space_0.hpp"

template <typename float_system>
class point : public geometry<float_system> {
public:
    typedef euclidean_space_0<float_system> domain_space_t;
    typedef typename domain_space_t::vector_t domain_vector_t;
    typedef domain_vector_t domain_value_t;

public:
    dynamic_reflectible(point, {
        register_super(geometry<float_system>);
    });
};
