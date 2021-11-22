#pragma once

template <typename float_system>
class vector_0 {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    reflectible(vector_0, {});

public:
    inline vector_0() {}

public:
    inline vector_0 operator+(const vector_0 &v) const {
        return vector_0();
    }
    inline vector_0 operator-(const vector_0 &v) const {
        return vector_0();
    }
    inline vector_0 operator-() const {
        return vector_0();
    }
    inline vector_0 operator*(float_t scale) const {
        return vector_0();
    }
    inline float_t operator*(const vector_0 &v) const {
        return float_system_t::zero();
    }
    static inline vector_0 zero() {
        return vector_0(float_system_t::zero());
    }
    static inline int dimension() {
        return 0;
    }
};
