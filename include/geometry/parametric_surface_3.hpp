#pragma once

#include "parametric_surface.hpp"
#include "range_space_3.hpp"

template <typename float_system>
class parametric_surface_3 : public parametric_surface<float_system>, public range_space_3<float_system> {
public:
    typedef float_system float_system_t;
    typedef typename parametric_surface<float_system>::domain_t domain_t;
    typedef typename parametric_surface<float_system>::domain_value_t domain_value_t;
    typedef typename range_space_3<float_system>::vector_t vector_t;
    
public: 
    dynamic_reflectible(parametric_surface_3, {
        register_super(parametric_surface<float_system>);
        register_super(range_space_3<float_system>);
    });

public:
    virtual vector_t operator()(const domain_value_t &v) const = 0;
};
