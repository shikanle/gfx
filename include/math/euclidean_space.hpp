#pragma once

#include "linear_space.hpp"

template <typename vector>
class euclidean_space : public linear_space<vector> {
public:
    typedef linear_space<vector> linear_space_t;
    typedef typename linear_space_t::vector_t vector_t;
    typedef typename linear_space_t::float_system_t float_system_t;
    typedef typename linear_space_t::float_t float_t;

public:
    static inline float_t inner_product(const vector_t &a, const vector_t &b) { return a * b; }
    static inline float_t squared_norm(const vector_t &a) { return a * a; }
    static inline float_t norm(const vector_t &a) { return float_system_t::sqrt(a * a); }
    static inline float_t inner_angle(const vector_t &a, const vector_t &b) { 
        return float_system_t::acos(a * b / norm(a) / norm(b)); 
    }
};
