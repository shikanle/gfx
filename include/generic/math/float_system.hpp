#pragma once

namespace gfx {

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
    static inline float_t fmod(float_t a, float_t b) { return std::fmod(a, b); }
    static inline float_t power(float_t a, float_t b) { return std::pow(a, b); }
    static inline float_t sqrt(float_t v) { return std::sqrt(v); }
    static inline float_t exp(float_t v) { return std::exp(v); }
    static inline float_t log(float_t v) { return std::log(v); }
    static inline float_t sin(float_t v) { return std::sin(v); }
    static inline float_t cos(float_t v) { return std::cos(v); }
    static inline float_t tan(float_t v) { return std::tan(v); }
    static inline float_t sinh(float_t v) { return std::sinh(v); }
    static inline float_t cosh(float_t v) { return std::cosh(v); }
    static inline float_t tanh(float_t v) { return std::tanh(v); }
    static inline float_t asin(float_t v) { return std::asin(v); }
    static inline float_t acos(float_t v) { return std::acos(v); }
    static inline float_t atan(float_t v) { return std::atan(v); }
    static inline float_t asinh(float_t v) { return std::asinh(v); }
    static inline float_t acosh(float_t v) { return std::acosh(v); }
    static inline float_t atanh(float_t v) { return std::atanh(v); }
    static inline float_t floor(float_t v) { return std::floor(v); }
    static inline float_t ceil(float_t v) { return std::ceil(v); }
    static inline float_t round(float_t v) { return std::round(v); }
};

}