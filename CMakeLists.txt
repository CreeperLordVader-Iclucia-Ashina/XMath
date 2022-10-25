cmake_minimum_required(VERSION 3.23)
project(XMath)

set(CMAKE_CXX_STANDARD 14)

add_executable(XMath Vector.h Matrix.h Numerical.h Numerical.cpp Matrix.cpp main.cpp global.h)
