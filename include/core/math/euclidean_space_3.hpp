#pragma once

#include "vector_3.hpp"
#include "euclidean_space.hpp"

template<typename float_system>
class euclidean_space_3 : public euclidean_space<vector_3<float_system> > {
};
