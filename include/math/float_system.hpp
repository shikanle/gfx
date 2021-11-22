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
class default_float_system : public float_system<float> {
public:
    static inline float_t sqrt(float v) { return std::sqrt(v); }
    static inline float_t acos(float v) { return std::acos(v); }
    static inline float_t sin(float v) { return std::sin(v); }
    static inline float_t cos(float v) { return std::cos(v); }
};
