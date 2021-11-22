#include "../include/gfx.hpp"

int main() {
    using namespace gfx::gfx32;

    gfx::gfx32::circle_2 v;
    std::cout << v << std::endl;
    std::cout << v.domain() << std::endl;

    // ellipse_3 e = { 3, 4, { {1, 2, 3}, {1, 0, 0}, {0, 1, 0} } };
    // std::cout << e << std::endl;
    // std::cout << e(0) << std::endl;

    // circle_3 c = { 3, { {1, 2, 3}, {1, 0, 0}, {0, 1, 0} } };    
    // std::cout << c << std::endl;
    // std::cout << c(0) << std::endl;
    
}