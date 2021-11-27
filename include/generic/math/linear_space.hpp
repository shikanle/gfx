#pragma once

namespace gfx {
namespace generic {

template <typename vector>
class linear_space {
public:
    typedef vector vector_t;
    typedef typename vector::float_system_t float_system_t;
    typedef typename float_system_t::float_t float_t;

public:
    static inline vector_t add(const vector_t &a, const vector_t &b) { return a + b; }
    static inline vector_t scale(const vector_t &a, float_t scale) { return a * scale; }
    static inline vector_t zero() { return vector_t::zero(); }
    static inline vector_t negate(const vector_t &a) { return -a; }
};

}
}