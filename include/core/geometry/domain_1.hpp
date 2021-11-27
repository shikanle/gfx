#pragma once

#include "domain.hpp"
#include "../math/vector_1.hpp"

template <typename float_system>
class domain_1 : public domain<float_system> {
public:
    typedef vector_1<float_system> vector_t;

public:
    dynamic_reflectible(domain_1, {
        register_super(domain<float_system>);
    });

public:
    virtual bool in(float_t v) const = 0;
};
