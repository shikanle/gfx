#pragma once

#include "periodic_domain_1.hpp"

template <typename float_system>
class circular_domain : public periodic_domain_1<float_system> {
public:
    typedef typename float_system::float_t float_t;

public:
    dynamic_reflectible(circular_domain, {
        register_super(periodic_domain_1<float_system>);
    });

public:
    virtual float_t period() const override {
        return float_system::pi() * 2;
    }
};
