#pragma once

#include "unbounded_domain_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class infinite_domain_2 : public unbounded_domain_2<float_system> {
public:
    dynamic_reflectible(infinite_domain_2, {
        register_super(unbounded_domain_2<float_system>);
    });

public:
    virtual bool periodic() const override {
        return false;
    }
};

}
}