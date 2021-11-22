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
    virtual bool is_valid(const vector_t &v) const {
        return this->axis_x->is_valid(v.x) &&
               this->axis_y->is_valid(v.y);
    }

    virtual bool is_bounded() const {
        return this->axis_x->is_bounded() && this->axis_y->is_bounded();
    }

    virtual bool is_periodic() const {
        return this->axis_x->is_periodic() || this->axis_y->is_periodic();
    }
};
