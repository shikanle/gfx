#pragma once

#include "vector_3.hpp"

template <typename float_system>
class unit_vector_3 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;
    typedef vector_3<float_system> vector_t;

protected:
    float_t x;
    float_t y;
    float_t z;

public:
    reflectible(unit_vector_3, {
        register_field(x);
        register_field(y);
        register_field(z);
    });

public:
    inline unit_vector_3() : x(float_system_t::one()), y(float_system_t::zero()), 
                        z(float_system_t::zero()) {}

    inline unit_vector_3(float_t x, float_t y, float_t z) {
        auto r = float_system_t::one() / float_system_t::sqrt(x * x + y * y + z * z);
        this->x = x * r;
        this->y = y * r;
        this->z = z * r;
    }

    inline unit_vector_3(const vector_t &v) {
        auto r = float_system_t::one() / float_system_t::sqrt(
            v.x * v.x + v.y * v.y + v.z * v.z);
        this->x = v.x * r;
        this->y = v.y * r;
        this->z = v.z * r;
    }

public:
    inline vector_t operator*(float_t scale) const {
        return vector_t(this->x * scale, this->y * scale, this->z * scale);
    }

    inline float_t operator*(const unit_vector_3 &v) const {
        return this->x * v.x + this->y * v.y + this->z * v.z;
    }

    inline float_t operator*(const vector_t &v) const {
        return this->x * v.x + this->y * v.y + this->z * v.z;
    }

    inline operator vector_t() const {
        return vector_t(this->x, this->y, this->z);
    }
};