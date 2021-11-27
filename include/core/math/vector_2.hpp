#pragma once

template <typename float_system>
class vector_2 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    float_t x;
    float_t y;
    reflectible(vector_2, {
        register_field(x);
        register_field(y);
    });

public:
    inline vector_2() : x(float_system_t::zero()), y(float_system_t::zero()) {}
    inline vector_2(float_t x, float_t y) : x(x), y(y) {}

public:
    inline vector_2 operator+(const vector_2 &v) const {
        return vector_2(this->x + v.x, this->y + v.y);
    }
    inline vector_2 operator-(const vector_2 &v) const {
        return vector_2(this->x - v.x, this->y - v.y);
    }
    inline vector_2 operator-() const {
        return vector_2(-this->x, -this->y);
    }
    inline vector_2 operator*(float_t scale) const {
        return vector_2(this->x * scale, this->y * scale);
    }
    inline float_t operator*(const vector_2 &v) const {
        return this->x * v.x + this->y * v.y;
    }
    static inline vector_2 zero() {
        return vector_2(float_system_t::zero(), float_system_t::zero());
    }
    static inline int dimension() {
        return 2;
    }
};
