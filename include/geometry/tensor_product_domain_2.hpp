#pragma once

#include "domain_1.hpp"
#include "domain_2.hpp"
#include "../math/vector_2.hpp"

template <typename float_system>
class tensor_product_domain_2 : public domain_2<float_system> {
public:
    typedef domain_1<float_system> domain_1_t;

public:
    domain_1_t *axis_x;
    domain_1_t *axis_y;

    dynamic_reflectible(tensor_product_domain_2, {
        register_super(domain_2<float_system>);
        register_field(axis_x);
        register_field(axis_y);
    });

public:
    virtual bool in(const vector_t &v) const {
        return this->axis_x->in(v.x) &&
               this->axis_y->in(v.y);
    }

    virtual bool bounded() const {
        return this->axis_x->bounded() && this->axis_y->bounded();
    }

    virtual bool periodic() const {
        return this->axis_x->periodic() || this->axis_y->periodic();
    }
};
