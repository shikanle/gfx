#pragma once

#include "../math/vector_2.hpp"
#include "polyline.hpp"

namespace gfx {
namespace generic {

template <typename float_system>
class polyline_2 : public polyline< vector_2<float_system> > {
public:
    dynamic_reflectible(polyline_2, {
        register_super(polyline< vector_2<float_system> >);
    });
};

}
}