#pragma once

#include "float_system.hpp"
#include "expression.hpp"

template <typename base_float_system>
class expression_float_system : public float_system<base_float_system> {
public:
    typedef base_float_system base_float_t;
    typedef expression<base_float_system> float_t;

public:
    static inline float_t zero() { return float_t(base_float_system::zero()); }
    static inline float_t one() { return float_t(base_float_system::one()); }
    static inline float_t pi() { return float_t(base_float_system::pi()); }
    static inline float_t fmod(const float_t &a, const float_t &b) { return a.fmod(b); }
    static inline float_t power(const float_t &a, const float_t &b) { return a.pow(b); }
    static inline float_t sqrt(const float_t &v) { return v.sqrt(); }
    static inline float_t exp(const float_t &v) { return v.exp(); }
    static inline float_t log(const float_t &v) { return v.log(); }
    static inline float_t sin(const float_t &v) { return v.sin(); }
    static inline float_t cos(const float_t &v) { return v.cos(); }
    static inline float_t tan(const float_t &v) { return v.tan(); }
    static inline float_t sinh(const float_t &v) { return v.sinh(); }
    static inline float_t cosh(const float_t &v) { return v.cosh(); }
    static inline float_t tanh(const float_t &v) { return v.tanh(); }
    static inline float_t asin(const float_t &v) { return v.asin(); }
    static inline float_t acos(const float_t &v) { return v.acos(); }
    static inline float_t atan(const float_t &v) { return v.atan(); }
    static inline float_t asinh(const float_t &v) { return v.asinh(); }
    static inline float_t acosh(const float_t &v) { return v.acosh(); }
    static inline float_t atanh(const float_t &v) { return v.atanh(); }
    static inline float_t floor(const float_t &v) { return v.floor(); }
    static inline float_t ceil(const float_t &v) { return v.ceil(); }
    static inline float_t round(const float_t &v) { return v.round(); }
};
