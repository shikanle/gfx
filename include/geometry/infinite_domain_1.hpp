#pragma once

#include "unbounded_domain_1.hpp"

template <typename float_system>
class infinite_domain_1 : public unbounded_domain_1<float_system> {
public:
    dynamic_reflectible(infinite_domain_1, {
        register_super(unbounded_domain_1<float_system>);
    });

public:
    virtual bool is_periodic() const override {
        return false;
    }
};
