#pragma once

#include "vector_2.hpp"
#include "euclidean_space.hpp"

namespace gfx {
namespace generic {

template<typename float_system>
class euclidean_space_2 : public euclidean_space<vector_2<float_system> > {
};

}
}