#pragma once

#define declare_projection_types(t) \
    typedef projection<t<float_system> > base_t; \
    typedef t<float_system> geometry_t; \
    typedef typename base_t::vector_t vector_t; \
    typedef typename base_t::domain_value_t domain_value_t; \
    projection_##t() : base_t(nullptr) {} \
    projection_##t(const geometry_t *geometry) : base_t(geometry) {}

template <typename geometry_type>
class projection {
public:
    typedef geometry_type geometry_t;
    typedef typename geometry_type::domain_value_t domain_value_t;
    typedef typename geometry_type::vector_t vector_t;

public:
    const geometry_t *geometry;

public:
    projection() : geometry(nullptr) {}
    projection(const geometry_type *geometry) : geometry(geometry) {}

public:
    virtual bool project(const vector_t &v, domain_value_t &result) = 0;
};