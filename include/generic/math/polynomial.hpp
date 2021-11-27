#pragma once

namespace gfx {
namespace generic {

template <typename float_system>
class polynomial {
public:
    typedef float_system float_system_t;
    typedef typename float_system::float_t float_t;

public:
    std::vector<float_t> coefficients;

    reflectible(polynomial, {
        register_field(coefficients);
    });

public:
    polynomial() : coefficients() {}
    polynomial(float_t v) : coefficients() {
        this->coefficients.push_back(v);
    }

public:
    float operator()(float_t v) {
        float_t sum = float_system::zero();
        float_t pwr = float_system::one();
        for (auto &c : this->coefficients) {
            sum += c * pwr;
            pwr *= v;
        }
        return sum;
    }
};

}
}