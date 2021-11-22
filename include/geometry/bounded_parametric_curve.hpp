#pragma once

#include "bounded_domain_1.hpp"
#include "parametric_curve.hpp"

template <typename parametric_curve_base>
class bounded_parametric_curve : public parametric_curve_base {
public:
    typedef parametric_curve_base geometry_t;
    typedef typename parametric_curve_base::domain_t domain_t;
    typedef typename parametric_curve_base::bounded_domain_t bounded_domain_t;

public:
    geometry_t *geometry;
    bounded_domain_t bounds;

    dynamic_reflectible(bounded_parametric_curve, {
        register_super(parametric_curve_base);
        register_field(bounds);
    });

public:
    bounded_parametric_curve() : geometry(nullptr) {}
    bounded_parametric_curve(geometry_t *geometry) : geometry(geometry) {
        // this->bounds = this->geometry->natural_bounded_domain();
    }

public:
    virtual const domain_t &natural_domain() const {
        return this->geometry->natural_domain();
    }

    virtual const domain_t &domain() const {
        return this->bounds;
    }
};
