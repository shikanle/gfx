#pragma once

#include "domain_1.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class unbounded_domain_1 : public domain_1<float_system> {
public:
    dynamic_reflectible(unbounded_domain_1, {
        register_super(domain_1<float_system>);
    });

public:
    virtual bool in(float_t v) const override {
        return true;
    }

    virtual bool bounded() const override {
        return false;
    }
};

}
}