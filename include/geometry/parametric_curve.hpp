#pragma once

#include "curve.hpp"
#include "domain_1.hpp"
#include "bounded_domain_1.hpp"

template <typename float_system>
class parametric_curve : public curve<float_system> {
public:
    typedef domain_1<float_system> domain_t;
    typedef bounded_domain_1<float_system> bounded_domain_t;

public: 
    dynamic_reflectible(parametric_curve, {
        register_super(curve<float_system>);
    });

public:
    virtual const domain_t &natural_domain() const = 0;
    virtual const domain_t &domain() const = 0;
};
