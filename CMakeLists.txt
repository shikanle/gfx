cmake_minimum_required(VERSION 3.1...3.15)

set(CMAKE_CONFIGURATION_TYPES Debug;Release)
set(CMAKE_INSTALL_PREFIX ./bin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_compile_options(-g)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
  set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
  set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
endif()

project(gfx_main)
add_executable(gfx_main "source/main.cpp")
