cmake_minimum_required(VERSION 3.23)
project(XMath)

set(CMAKE_CXX_STANDARD 17)

file(GLOB XMATH_SRC src/*)
add_executable(PCA ${XMATH_SRC} ext/ImageProc.h main.cpp ext/Image.cpp ext/Image.h ext/global.h ext/Vector.h)
