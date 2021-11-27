#pragma once

#include "parametric_curve_3.hpp"
#include "../math/vector_3.hpp"
#include "../math/expression_float_system.hpp"

template <typename float_system>
class expression_curve_3 : public parametric_curve_3<float_system>, public vector_3< expression_float_system<float_system> > {
public:
    declare_parametric_curve_3_concept_types;

public: 
    dynamic_reflectible(expression_curve_3, {
        register_super(parametric_curve_3<float_system>);
        register_super(vector_3< expression_float_system<float_system> >);
    });

public:
    virtual vector_t operator()(domain_value_t t) const {
        return vector_t(this->x(&t), this->y(&t));
    }
};
