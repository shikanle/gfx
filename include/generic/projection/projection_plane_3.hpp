#pragma once

#include "projection.hpp"
#include "../../geometry/plane_3.hpp"

template <typename float_system>
class projection_plane_3 : public projection<plane_3<float_system> > {
public:
    declare_projection_types(plane_3);

public:
    virtual bool project(const vector_t &p, domain_value_t &result) override {
        auto v = p - this->geometry->center;
        result.x = this->geometry->axis_x * v;
        result.y = this->geometry->axis_y * v;
        return true;
    }
};