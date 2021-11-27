#pragma once

#include "domain_1.hpp"

template <typename float_system>
class periodic_domain_1 : public unbounded_domain_1<float_system> {
public:
    typedef typename float_system::float_t float_t;
public:
    dynamic_reflectible(periodic_domain_1, {
        register_super(unbounded_domain_1<float_system>);
    });

public:
    virtual bool periodic() const override {
        return true;
    }

    virtual float_t period() const = 0;
};
