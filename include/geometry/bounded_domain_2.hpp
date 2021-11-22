#pragma once

#include "domain_2.hpp"
#include "../math/range_2.hpp"

template <typename float_system>
class bounded_domain_2 : public domain_2<float_system> {
public:
    typedef range_2<float_system> range_t;
    typedef typename domain_2<float_system>::vector_t vector_t;

public:
    range_t range;

    dynamic_reflectible(bounded_domain_2, {
        register_super(domain_2<float_system>);
        register_field(range);
    });

public:
    inline bounded_domain_2() : range() {}
    inline bounded_domain_2(const range_t &range) : range(range) {}

public:
    virtual bool is_valid(const vector_t &v) const override {
        return this->range.in(v);
    }

    virtual bool is_bounded() const override {
        return true;
    }

    virtual bool is_periodic() const override {
        return false;
    }
};
