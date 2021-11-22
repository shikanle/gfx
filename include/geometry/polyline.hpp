#pragma once

#include "curve.hpp"
#include "bounded_domain_1.hpp"

template <typename point_type>
class polyline : public curve<typename point_type::float_system_t> {
public:
    typedef point_type vector_t;
    typedef typename point_type::float_system_t float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    std::vector<vector_t> points;

    dynamic_reflectible(polyline, {
        register_super(curve<typename point_type::float_system_t>);
        register_field(points);
    });

public:
    polyline() : points() {}
};
