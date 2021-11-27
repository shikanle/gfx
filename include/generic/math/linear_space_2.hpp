#pragma once

#include "vector_2.hpp"
#include "linear_space.hpp"

namespace gfx {
namespace generic {

template<typename float_system>
class linear_space_2 : public linear_space<vector_2<float_system> > {
};

}
}
