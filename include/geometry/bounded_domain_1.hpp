#pragma once

#include "domain_1.hpp"
#include "../math/range_1.hpp"

template <typename float_system>
class bounded_domain_1 : public domain_1<float_system> {
public:
    typedef typename float_system::float_t float_t;
    typedef range_1<float_system> range_t;

public:
    range_t range;

    dynamic_reflectible(bounded_domain_1, {
        register_super(domain_1<float_system>);
        register_field(range);
    });

public:
    inline bounded_domain_1() : range() {}
    inline bounded_domain_1(const range_t &range) : range(range) {}
    inline bounded_domain_1(float_t min, float_t max) : range(min, max) {}

public:
    virtual bool is_valid(float_t v) const override {
        return this->range.in(v);
    }
};
