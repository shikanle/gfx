#pragma once

template <typename float_system>
class vector_1 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    float_t x;
    reflectible(vector_1, {
        register_field(x);
    });

public:
    inline vector_1() : x(float_system_t::zero()) {}
    inline vector_1(float_t x) : x(x) {}

public:
    inline vector_1 operator+(const vector_1 &v) const {
        return vector_1(this->x + v.x);
    }
    inline vector_1 operator-(const vector_1 &v) const {
        return vector_1(this->x - v.x);
    }
    inline vector_1 operator-() const {
        return vector_1(-this->x);
    }
    inline vector_1 operator*(float_t scale) const {
        return vector_1(this->x * scale);
    }
    inline float_t operator*(const vector_1 &v) const {
        return this->x * v.x;
    }
    static inline vector_1 zero() {
        return vector_1(float_system_t::zero());
    }
    static inline int dimension() {
        return 1;
    }
};
