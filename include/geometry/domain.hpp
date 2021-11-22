#pragma once

template <typename float_system>
class domain : public object {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    dynamic_reflectible(domain, {});

};