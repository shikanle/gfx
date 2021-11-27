#pragma once

#include "vector_0.hpp"
#include "euclidean_space.hpp"

namespace gfx {
namespace generic {

template<typename float_system>
class euclidean_space_0 : public euclidean_space<vector_0<float_system> > {
};

}
}