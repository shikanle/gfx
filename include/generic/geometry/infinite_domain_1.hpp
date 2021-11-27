#pragma once

#include "unbounded_domain_1.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class infinite_domain_1 : public unbounded_domain_1<float_system> {
public:
    dynamic_reflectible(infinite_domain_1, {
        register_super(unbounded_domain_1<float_system>);
    });

public:
    virtual bool periodic() const override {
        return false;
    }
};

}
}