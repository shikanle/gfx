#pragma once

#include "infinite_domain_1.hpp"

namespace gfx {
namespace generic {

template<typename parametric_curve_base>
class line : public parametric_curve_base {
public:
    declare_infinite_curve(parametric_curve_base);

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
    virtual vector_t operator()(domain_value_t t) const override {
        return p0 * (1 - t) + p1 * t;
    }
};

}
}