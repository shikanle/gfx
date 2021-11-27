#include "../include/gfx.hpp"
#include "../thirdparty/eigen/Eigen/Dense"

int main() {
    // std::cout << gfx::gfx32::polynomial_equation::solve(1, 3, 1) << std::endl;

    gfx::gfx32::polyline_2 pp;
    pp.points.push_back({ 1, 2 });
    pp.points.push_back({ 3, 4 });
    std::cout << pp.json() << std::endl;

    gfx::gfx32::vec3 v(1, 2, 3);

    gfx::gfx32::polynomial p(100);
    p.coefficients.push_back(1);
    // p.push_back(10);
    // p.push_back(20);
    // p.push_back(30);
    std::cout << p.json() << std::endl;
    std::cout << v.json() << std::endl;
    std::cout << p(10) << std::endl;

    // gfx::float32::polynomial_equation p;

    // expression exp;
    // expression::node n;
    // n.kind = expression::node::kind_type::immediate;
    // n.value = 1;
    // exp.nodes.push_back(n);
    // n.value = 2;
    // exp.nodes.push_back(n);
    // n.kind = expression::node::kind_type::add;
    // n.value = 1;
    // exp.nodes.push_back(n);
    // std::cout << exp(nullptr) << std::endl;

    // hyperbolic_arc_3 r;
    // std::cout << r.json() << std::endl;

    // ellipse_3 e = { 3, 4, { {1, 2, 3}, {1, 0, 0}, {0, 1, 0} } };
    // std::cout << e.type().to_code() << std::endl;

    // line_3 l;
    // l.p0 = { 0, 0, 0 };
    // l.p1 = { 1, 2, 3 };
    // std::cout << l.json() << std::endl;
    // std::cout << l(0.5) << std::endl;
    // std::cout << l.domain() << std::endl;
    // std::cout << l.domain().is_bounded() << std::endl;

    // polyline_2 pl;
    // pl.points.push_back({0, 0});
    // pl.points.push_back({1, 1});
    // pl.points.push_back({2, 2});
    // std::cout << pl.json() << std::endl;

    // std::cout << e << std::endl;
    // std::cout << e(0) << std::endl;

    // circle_3 c = { 3, { {1, 2, 3}, {1, 0, 0}, {0, 1, 0} } };    
    // std::cout << c << std::endl;
    // std::cout << c(0) << std::endl;
    
}