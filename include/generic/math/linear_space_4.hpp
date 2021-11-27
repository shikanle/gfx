#pragma once

#include "vector_4.hpp"
#include "linear_space.hpp"

namespace gfx {
namespace generic {

template<typename float_system>
class linear_space_4 : public linear_space<vector_4<float_system> > {
};

}
}