#pragma once

#include "unbounded_domain_1.hpp"

template<typename parametric_curve_base>
class line : public parametric_curve_base {
public:
    declare_unbounded_curve(parametric_curve_base);

public:
    vector_t p0;
    vector_t p1;

    dynamic_reflectible(line, {
        register_super(parametric_curve_base);
        register_field(p0);
        register_field(p1);
    });

public:
    inline line() : p0(), p1() {}
    inline line(const vector_t &p0, const vector_t &p1) : p0(p0), p1(p1) {}

public:
    virtual vector_t operator()(domain_value_t v) const override {
        return p0 * (1 - v) + p1 * v;
    }

    virtual const bounded_domain_t &natural_bounded_domain() const override {
        static bounded_domain_t bounds(float_system_t::zero(), float_system_t::one());
        return bounds;
    }
};
