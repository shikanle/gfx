#pragma once

#include "vector_2.hpp"

template <typename float_system>
class unit_vector_2 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;
    typedef vector_2<float_system> vector_t;

protected:
    float_t x;
    float_t y;

public:
    reflectible(unit_vector_2, {
        register_field(x);
        register_field(y);
        register_field(z);
    });

public:
    inline unit_vector_2() : x(float_system_t::one()), y(float_system_t::zero()) {}

    inline unit_vector_2(float_t x, float_t y) {
        auto r = float_system_t::one() / float_system_t::sqrt(x * x + y * y);
        this->x = x * r;
        this->y = y * r;
    }

    inline unit_vector_2(const vector_t &v) {
        auto r = float_system_t::one() / float_system_t::sqrt(
            v.x * v.x + v.y * v.y);
        this->x = v.x * r;
        this->y = v.y * r;
    }

public:
    inline vector_t operator*(float_t scale) const {
        return vector_t(this->x * scale, this->y * scale);
    }

    inline float_t operator*(const unit_vector_2 &v) const {
        return this->x * v.x + this->y * v.y;
    }

    inline float_t operator*(const vector_t &v) const {
        return this->x * v.x + this->y * v.y;
    }

    inline operator vector_t() const {
        return vector_t(this->x, this->y);
    }
};