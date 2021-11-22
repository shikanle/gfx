#pragma once

#include "domain_2.hpp"

template <typename float_system>
class unbounded_domain_2 : public domain_2<float_system> {
public:
    typedef typename domain_2<float_system>::vector_t vector_t;

public:
    dynamic_reflectible(unbounded_domain_2, {
        register_super(domain_2<float_system>);
    });

public:
    virtual bool is_valid(const vector_t &v) const {
        return true;
    }

    virtual bool is_x_bounded() const override {
        return false;
    }

    virtual bool is_y_bounded() const override {
        return false;
    }
};
