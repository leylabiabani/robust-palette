cmake_minimum_required(VERSION 3.16)

project(robust_palette CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(robust_palette
    src/main.cpp
    src/point.cpp
)

target_include_directories(robust_palette PRIVATE include)