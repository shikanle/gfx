#pragma once

#include "parametric_curve.hpp"
#include "range_space_2.hpp"

#define declare_parametric_curve_2_concept_types \
    typedef float_system float_system_t; \
    typedef typename float_system::float_t float_t; \
    typedef vector_2<float_system> vector_t; \
    typedef float_t domain_value_t; \
    typedef domain_1<float_system> domain_t; \
    typedef typename parametric_curve_2<float_system>::bounded_domain_t bounded_domain_t; \

template <typename float_system>
class parametric_curve_2 : public parametric_curve<float_system>, public range_space_2<float_system> {
public:
    typedef typename parametric_curve<float_system>::domain_value_t domain_value_t;
    typedef typename range_space_2<float_system>::vector_t vector_t;

public: 
    dynamic_reflectible(parametric_curve_2, {
        register_super(parametric_curve<float_system>);
        register_super(range_space_2<float_system>);
    });

public:
    virtual vector_t operator()(domain_value_t v) const = 0;
};
