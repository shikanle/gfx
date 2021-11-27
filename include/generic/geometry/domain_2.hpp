#pragma once

#include "domain.hpp"
#include "../math/vector_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class domain_2 : public domain<float_system> {
public:
    typedef vector_2<float_system> vector_t;

public:
    dynamic_reflectible(domain_2, {
        register_super(domain<float_system>);
    });

public:
    virtual bool in(const vector_t &v) const = 0;
};

}
}