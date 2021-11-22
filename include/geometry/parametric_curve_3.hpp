#pragma once

#include "parametric_curve.hpp"
#include "range_space_3.hpp"

template <typename float_system>
class parametric_curve_3 : public parametric_curve<float_system>, public range_space_3<float_system> {
public:
    typedef typename parametric_curve<float_system>::domain_value_t domain_value_t;
    typedef typename range_space_3<float_system>::vector_t vector_t;
    
public: 
    dynamic_reflectible(parametric_curve_3, {
        register_super(parametric_curve<float_system>);
        register_super(range_space_3<float_system>);
    });

public:
    virtual vector_t operator()(domain_value_t v) const = 0;
};
