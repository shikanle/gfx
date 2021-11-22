#pragma once

#include "geometry.hpp"
#include "../math/euclidean_space_1.hpp"

template <typename float_system>
class curve : public geometry<float_system> {
public:
    typedef euclidean_space_1<float_system> domain_space_t;
    typedef typename domain_space_t::vector_t domain_vector_t;
    typedef float_t domain_value_t;

public:
    dynamic_reflectible(curve, {
        register_super(geometry<float_system>);
    });

public:
    virtual int domain_dimension() const override {
        return 1;
    }
};
