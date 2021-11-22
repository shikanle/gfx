#pragma once

template <typename float_system>
class vector_4 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    float_t x;
    float_t y;
    float_t z;
    float_t w;
    reflectible(vector_4, {
        register_field(x);
        register_field(y);
        register_field(z);
        register_field(w);
    });

public:
    inline vector_4() : x(float_system_t::zero()), y(float_system_t::zero()), 
                        z(float_system_t::zero()), w(float_system_t::zero()) {}
    inline vector_4(float_t x, float_t y, float_t z, float_t w) : x(x), y(y), z(z), w(w) {}

public:
    inline vector_4 operator+(const vector_4 &v) const {
        return vector_4(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
    }
    inline vector_4 operator-(const vector_4 &v) const {
        return vector_4(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w);
    }
    inline vector_4 operator-() const {
        return vector_4(-this->x, -this->y, -this->z, -this->w);
    }
    inline vector_4 operator*(float_t scale) const {
        return vector_4(this->x * scale, this->y * scale, this->z * scale, this->w * scale);
    }
    inline float_t operator*(const vector_4 &v) const {
        return this->x * v.x + this->y * v.y + this->z * v.z + this->w * v.w;
    }
    static inline vector_4 zero() {
        return vector_4(float_system_t::zero(), float_system_t::zero(), 
                        float_system_t::zero(), float_system_t::zero());
    }
};
