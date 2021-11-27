#pragma once

#include "equation.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class polynomial_equation : public equation<float_system> {
public:
    typedef float_system float_system_t;
    typedef typename float_system::float_t float_t;
    typedef equation<float_system> equation_t;
    typedef typename equation_t::template solution<0> solution_0_t;
    typedef typename equation_t::template solution<1> solution_1_t;
    typedef typename equation_t::template solution<2> solution_2_t;

public:
    // a0 = 0
    inline static solution_0_t solve(float_t a0) {
        solution_0_t sol;
        if (a0 == 0) {
            sol.count = -1;
        } else {
            sol.count = 0;
        }
        return sol;
    }

    // a1 x + a0 = 0
    inline static solution_1_t solve(float_t a0, float_t a1) {
        if (a1 == 0) {
            return solve(a0);
        }
        solution_1_t sol;
        sol.count = 1;
        sol.roots[0] = { -a0 / a1, 1 };
        return sol;
    }

    // a2 x^2 + a1 x + a0 = 0
    inline static solution_2_t solve(float a0, float a1, float a2) {
        if (a2 == 0) {
            return solve(a0, a1);
        }
        auto delta = a1 * a1 - a0 * a2 * 4;
        solution_2_t sol;
        if (delta > 0) {
            delta = float_system::sqrt(delta);
            auto multi = float_t(0.5) / a2;
            sol.count = 2;
            sol.roots[0] = { (delta - a1) * multi, 1 };
            sol.roots[1] = { (-delta - a1) * multi, 1 };
        } else if (delta == 0) {
            sol.count = 1;
            sol.roots[0] = { a1 / a2 * float_t(-0.5), 2 };
        }
        return sol;
    }
};

}
}