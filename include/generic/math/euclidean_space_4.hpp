#pragma once

#include "vector_4.hpp"
#include "euclidean_space.hpp"

namespace gfx {
namespace generic {

template<typename float_system>
class euclidean_space_4 : public euclidean_space<vector_4<float_system> > {
};

}
}