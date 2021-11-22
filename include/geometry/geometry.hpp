#pragma once

#define declare_geometry_types(base_type) \
    typedef typename base_type::float_system_t float_system_t; \
    typedef typename base_type::domain_t domain_t; \
    typedef typename base_type::bounded_domain_t bounded_domain_t; \
    typedef typename base_type::domain_value_t domain_value_t; \
    typedef typename base_type::vector_t vector_t

#define declare_unbounded_domain(base_type, domain_type) \
    virtual const domain_t &natural_domain() const override { \
        static domain_type<typename base_type::float_system_t> domain; \
        return domain; \
    } \
    virtual const domain_t &domain() const override { \
        return this->natural_domain(); \
    }

#define declare_unbounded_domain_1(base_type) declare_unbounded_domain(base_type, unbounded_domain_1)
#define declare_unbounded_domain_2(base_type) declare_unbounded_domain(base_type, unbounded_domain_2)

#define declare_unbounded_curve(base_type)  \
    declare_geometry_types(base_type); \
    declare_unbounded_domain_1(base_type)

#define declare_unbounded_surface(base_type)  \
    declare_geometry_types(base_type); \
    declare_unbounded_domain_2(base_type)

template <typename float_system>
class geometry : public object {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    dynamic_reflectible(geometry, {});

public:
    inline geometry() {}
};
