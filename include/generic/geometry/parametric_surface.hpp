#pragma once

#include "surface.hpp"
#include "domain_2.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class parametric_surface : public surface<float_system> {
public:
    typedef domain_2<float_system> domain_t;

public: 
    dynamic_reflectible(parametric_surface, {
        register_super(surface<float_system>);
    });

public:
    virtual const domain_t &domain() const = 0;
};

}
}