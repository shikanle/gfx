#pragma once

namespace gfx {
namespace generic {

template <typename float_system>
class domain : public object {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    dynamic_reflectible(domain, {});

public:
    virtual bool bounded() const = 0;
    virtual bool periodic() const = 0;
};

}
}