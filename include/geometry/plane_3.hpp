#pragma once

#include "../math/unit_vector_3.hpp"
#include "parametric_surface_3.hpp"
#include "infinite_domain_2.hpp"

template<typename float_system>
class plane_3 : public parametric_surface_3<float_system> {
public:
    declare_infinite_surface(parametric_surface_3<float_system>);
    typedef frame_3<float_system> frame_t;

public:
    frame_t frame;

    dynamic_reflectible(plane_3, {
        register_super(parametric_surface_3<float_system>);
        register_field(frame);
    });

public:
    inline plane_3() : frame() {}
    inline plane_3(const frame_t &frame) 
        : frame(frame) {}

public:
    virtual vector_t operator()(const domain_value_t &v) const override {
        return this->frame(v);
    }
};
