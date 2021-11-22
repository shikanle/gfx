#include "../include/gfx.hpp"

int main() {
    using namespace gfx::gfx32;

    // ellipse_3 e = { 3, 4, { {1, 2, 3}, {1, 0, 0}, {0, 1, 0} } };
    // std::cout << e.type().to_code() << std::endl;

    // line_3 l;
    // l.p0 = { 0, 0, 0 };
    // l.p1 = { 1, 2, 3 };
    // std::cout << l.json() << std::endl;
    // std::cout << l(0.5) << std::endl;
    // std::cout << l.domain() << std::endl;
    // std::cout << l.domain().is_bounded() << std::endl;

    polyline_2 pl;
    pl.points.push_back({0, 0});
    pl.points.push_back({1, 1});
    pl.points.push_back({2, 2});
    std::cout << pl.json() << std::endl;

    // std::cout << e << std::endl;
    // std::cout << e(0) << std::endl;

    // circle_3 c = { 3, { {1, 2, 3}, {1, 0, 0}, {0, 1, 0} } };    
    // std::cout << c << std::endl;
    // std::cout << c(0) << std::endl;
    
}