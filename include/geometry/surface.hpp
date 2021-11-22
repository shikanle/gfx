#pragma once

#include "geometry.hpp"
#include "../math/euclidean_space_2.hpp"

template <typename float_system>
class surface : public geometry<float_system> {
public:
    typedef euclidean_space_2<float_system> domain_space_t;
    typedef typename domain_space_t::vector_t domain_vector_t;
    typedef domain_vector_t domain_value_t;

public:
    dynamic_reflectible(surface, {
        register_super(geometry<float_system>);
    });

public:
    virtual int domain_dimension() const override {
        return 2;
    }
};
