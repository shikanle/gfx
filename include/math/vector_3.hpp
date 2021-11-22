#pragma once

template <typename float_system>
class vector_3 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    float_t x;
    float_t y;
    float_t z;
    reflectible(vector_3, {
        register_field(x);
        register_field(y);
        register_field(z);
    });

public:
    inline vector_3() : x(float_system_t::zero()), y(float_system_t::zero()), z(float_system_t::zero()) {}
    inline vector_3(float_t x, float_t y, float_t z) : x(x), y(y), z(z) {}

public:
    inline vector_3 operator+(const vector_3 &v) const {
        return vector_3(this->x + v.x, this->y + v.y, this->z + v.z);
    }
    inline vector_3 operator-(const vector_3 &v) const {
        return vector_3(this->x - v.x, this->y - v.y, this->z - v.z);
    }
    inline vector_3 operator-() const {
        return vector_3(-this->x, -this->y, -this->z);
    }
    inline vector_3 operator*(float_t scale) const {
        return vector_3(this->x * scale, this->y * scale, this->z * scale);
    }
    inline float_t operator*(const vector_3 &v) const {
        return this->x * v.x + this->y * v.y + this->z * v.z;
    }
    static inline vector_3 zero() {
        return vector_3(float_system_t::zero(), float_system_t::zero(), float_system_t::zero());
    }
};
