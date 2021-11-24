#pragma once

#include "parametric_curve_2.hpp"
#include "../math/vector_2.hpp"
#include "../math/expression_float_system.hpp"
#include "infinite_domain_1.hpp"

template <typename float_system>
class expression_curve_2 : public parametric_curve_2<float_system>, public vector_2< expression_float_system<float_system> > {
public:
    declare_parametric_curve_2_concept_types;

public: 
    dynamic_reflectible(expression_curve_2, {
        register_super(parametric_curve_2<float_system>);
        register_super(vector_2< expression_float_system<float_system> >);
    });

public:
    virtual vector_t operator()(domain_value_t t) const override {
        return vector_t(this->x(&t), this->y(&t));
    }

    virtual const domain_t &domain() const override {
        static infinite_domain_1<float_system> domain;
        return domain;
    }
};
