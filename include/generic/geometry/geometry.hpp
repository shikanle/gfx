#pragma once

namespace gfx {
namespace generic {

#define declare_geometry_types(base_type) \
    typedef typename base_type::float_system_t float_system_t; \
    typedef typename float_system_t::float_t float_t; \
    typedef typename base_type::domain_t domain_t; \
    typedef typename base_type::bounded_domain_t bounded_domain_t; \
    typedef typename base_type::domain_value_t domain_value_t; \
    typedef typename base_type::vector_t vector_t

#define declare_domain(base_type, domain_type) \
    virtual const domain_t &domain() const override { \
        static domain_type<typename base_type::float_system_t> domain; \
        return domain; \
    }

#define declare_infinite_curve(base_type)  \
    declare_geometry_types(base_type); \
    declare_domain(base_type, infinite_domain_1)

#define declare_infinite_surface(base_type)  \
    declare_geometry_types(base_type); \
    declare_domain(base_type, infinite_domain_2)

#define declare_circular_curve(base_type)  \
    declare_geometry_types(base_type); \
    declare_domain(base_type, circular_domain)

template <typename float_system>
class geometry : public object {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    dynamic_reflectible(geometry, {});

public:
    inline geometry() {}

public:
    virtual int domain_dimension() const = 0;
};

}
}