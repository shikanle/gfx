#pragma once

#include "domain_1.hpp"

template <typename float_system>
class unbounded_domain_1 : public domain_1<float_system> {
public:
    dynamic_reflectible(unbounded_domain_1, {
        register_super(domain_1<float_system>);
    });

public:
    virtual bool is_valid(float_t v) const override {
        return true;
    }

    virtual bool is_bounded() const override {
        return false;
    }
};
