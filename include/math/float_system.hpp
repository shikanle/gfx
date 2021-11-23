#pragma once

template <typename T>
class float_system {
public:
    typedef T float_t;
public:
    static inline float_t zero() { return 0; }
    static inline float_t one() { return 1; }
    static inline float_t pi() { return (float_t)M_PI; }
};

template <typename T>
class default_float_system : public float_system<T> {
public:
    static inline float_t sqrt(float_t v) { return std::sqrt(v); }
    static inline float_t acos(float_t v) { return std::acos(v); }
    static inline float_t sin(float_t v) { return std::sin(v); }
    static inline float_t cos(float_t v) { return std::cos(v); }
    static inline float_t sinh(float_t v) { return std::sinh(v); }
    static inline float_t cosh(float_t v) { return std::cosh(v); }
};
