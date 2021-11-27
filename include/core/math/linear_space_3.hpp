#pragma once

#include "vector_3.hpp"
#include "linear_space.hpp"

template<typename float_system>
class linear_space_3 : public linear_space<vector_3<float_system> > {
};