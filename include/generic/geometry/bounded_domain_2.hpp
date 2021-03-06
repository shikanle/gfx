#pragma once

#include "domain_2.hpp"
#include "../math/range_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class bounded_domain_2 : public domain_2<float_system>, public range_2<float_system> {
public:
    typedef range_2<float_system> range_t;
    typedef typename domain_2<float_system>::vector_t vector_t;

public:
    dynamic_reflectible(bounded_domain_2, {
        register_super(domain_2<float_system>);
        register_super(range_2<float_system>);
    });

public:
    inline bounded_domain_2() : range_2<float_system>() {}
    inline bounded_domain_2(const range_t &range) : range_2<float_system>(range) {}

public:
    virtual bool in(const vector_t &v) const override {
        return this->range.in(v);
    }

    virtual bool bounded() const override {
        return true;
    }

    virtual bool periodic() const override {
        return false;
    }
};

}
}