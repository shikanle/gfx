#pragma once

#include "common/common.hpp"

namespace gfx {

    #include "common/reflection.hpp"

    #include "math/float32.hpp"
    #include "math/float64.hpp"

    namespace generic {
        #include "math/vector_0.hpp"
        #include "math/vector_1.hpp"
        #include "math/vector_2.hpp"
        #include "math/vector_3.hpp"
        #include "math/vector_4.hpp"
        #include "math/unit_vector_2.hpp"
        #include "math/unit_vector_3.hpp"
        #include "math/unit_vector_4.hpp"
        #include "math/range_1.hpp"
        #include "math/range_2.hpp"
        #include "math/linear_space_2.hpp"
        #include "math/linear_space_3.hpp"
        #include "math/linear_space_4.hpp"
        #include "math/euclidean_space_0.hpp"
        #include "math/euclidean_space_1.hpp"
        #include "math/euclidean_space_2.hpp"
        #include "math/euclidean_space_3.hpp"
        #include "math/euclidean_space_4.hpp"
        #include "math/frame_2.hpp"
        #include "math/frame_3.hpp"
        #include "math/expression.hpp"
        #include "math/expression_float_system.hpp"
        #include "math/matrix.hpp"
        #include "math/polynomial_equation.hpp"
        #include "math/polynomial.hpp"

        #include "geometry/bounded_domain_1.hpp"
        #include "geometry/bounded_domain_2.hpp"
        #include "geometry/segmented_parametric_curve.hpp"

        #include "geometry/point_2.hpp"
        #include "geometry/point_3.hpp"
        #include "geometry/line_2.hpp"
        #include "geometry/line_3.hpp"
        #include "geometry/circle_2.hpp"
        #include "geometry/circle_3.hpp"
        #include "geometry/ellipse_2.hpp"
        #include "geometry/ellipse_3.hpp"
        #include "geometry/hyperbola_2.hpp"
        #include "geometry/hyperbola_3.hpp"
        #include "geometry/parabola_2.hpp"
        #include "geometry/parabola_3.hpp"
        #include "geometry/expression_curve_2.hpp"
        #include "geometry/expression_curve_3.hpp"
        #include "geometry/plane_3.hpp"

        #include "geometry/polyline_2.hpp"
        #include "geometry/polyline_3.hpp"

        #include "algorithm/projection/projection_plane_3.hpp"
    }

#define declare_gfx_class(f, c) typedef generic::c<f> c;
#define declare_gfx_curve(f, c) \
    declare_gfx_class(f, c) \
    typedef generic::segmented_parametric_curve<c> segmented_##c;

#define declare_gtx_classes(name, f) \
    namespace name { \
        typedef f float_system_t; \
        typedef f::float_t float_t; \
        declare_gfx_class(f, vector_0); \
        declare_gfx_class(f, vector_1); \
        declare_gfx_class(f, vector_2); \
        declare_gfx_class(f, vector_3); \
        declare_gfx_class(f, vector_4); \
        declare_gfx_class(f, unit_vector_2); \
        declare_gfx_class(f, unit_vector_3); \
        declare_gfx_class(f, unit_vector_4); \
        declare_gfx_class(f, range_1); \
        declare_gfx_class(f, range_2); \
        declare_gfx_class(f, linear_space_2); \
        declare_gfx_class(f, linear_space_3); \
        declare_gfx_class(f, linear_space_4); \
        declare_gfx_class(f, euclidean_space_0); \
        declare_gfx_class(f, euclidean_space_1); \
        declare_gfx_class(f, euclidean_space_2); \
        declare_gfx_class(f, euclidean_space_3); \
        declare_gfx_class(f, euclidean_space_4); \
        declare_gfx_class(f, frame_2); \
        declare_gfx_class(f, frame_3); \
        declare_gfx_class(f, expression); \
        declare_gfx_class(f, polynomial_equation); \
        declare_gfx_class(f, polynomial); \
        declare_gfx_class(f, bounded_domain_1); \
        declare_gfx_class(f, bounded_domain_2); \
        declare_gfx_class(f, point_2); \
        declare_gfx_class(f, point_3); \
        declare_gfx_curve(f, line_2); \
        declare_gfx_curve(f, line_3); \
        declare_gfx_curve(f, circle_2); \
        declare_gfx_curve(f, circle_3); \
        declare_gfx_curve(f, ellipse_2); \
        declare_gfx_curve(f, ellipse_3); \
        declare_gfx_curve(f, hyperbola_2); \
        declare_gfx_curve(f, hyperbola_3); \
        declare_gfx_curve(f, parabola_2); \
        declare_gfx_curve(f, parabola_3); \
        declare_gfx_curve(f, expression_curve_2); \
        declare_gfx_curve(f, expression_curve_3); \
        declare_gfx_class(f, plane_3); \
        declare_gfx_class(f, polyline_2); \
        declare_gfx_class(f, polyline_3); \
        declare_gfx_class(f, projection_plane_3); \
        typedef vector_1 vec1; \
        typedef vector_2 vec2; \
        typedef vector_3 vec3; \
        typedef vector_4 vec4; \
        typedef unit_vector_2 uvec2; \
        typedef unit_vector_3 uvec3; \
        typedef unit_vector_4 uvec4; \
        typedef segmented_circle_2 circular_arc_2; \
        typedef segmented_circle_3 circular_arc_3; \
        typedef segmented_ellipse_2 elliptic_arc_2; \
        typedef segmented_ellipse_3 elliptic_arc_3; \
        typedef segmented_hyperbola_2 hyperbolic_arc_2; \
        typedef segmented_hyperbola_3 hyperbolic_arc_3; \
        typedef segmented_parabola_2 parabolic_arc_2; \
        typedef segmented_parabola_3 parabolic_arc_3; \
        template<int row, int column> \
        using matrix = generic::matrix<f, row, column>; \
    }
    
    declare_gtx_classes(gfx32, float32)
    declare_gtx_classes(gfx64, float64)

#undef declare_gfx_class
#undef declare_gtx_classes
}
