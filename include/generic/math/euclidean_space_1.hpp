#pragma once

#include "vector_1.hpp"
#include "euclidean_space.hpp"

namespace gfx {
namespace generic {

template<typename float_system>
class euclidean_space_1 : public euclidean_space<vector_1<float_system> > {
};

}
}