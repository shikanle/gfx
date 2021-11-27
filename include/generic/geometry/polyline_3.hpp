#pragma once

#include "../math/vector_3.hpp"
#include "polyline.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class polyline_3 : public polyline< vector_3<float_system> > {
public:
    dynamic_reflectible(polyline_3, {
        register_super(polyline< vector_3<float_system> >);
    });
};

}
}