#pragma once

#include "domain_1.hpp"
#include "../math/range_1.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class bounded_domain_1 : public domain_1<float_system>, public range_1<float_system> {
public:
    typedef typename float_system::float_t float_t;
    typedef range_1<float_system> range_t;

public:
    dynamic_reflectible(bounded_domain_1, {
        register_super(domain_1<float_system>);
        register_super(range_1<float_system>);
    });

public:
    inline bounded_domain_1() : range_1<float_system>() {}
    inline bounded_domain_1(const range_t &range) : range_1<float_system>(range) {}
    inline bounded_domain_1(float_t min, float_t max) : range_1<float_system>(min, max) {}

public:
    virtual bool in(float_t v) const override {
        return this->in(v);
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