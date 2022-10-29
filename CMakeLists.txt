cmake_minimum_required(VERSION 3.23)
project(XMath)

set(CMAKE_CXX_STANDARD 17)

file(GLOB XMATH_SRC src/*)
file(GLOB EXT_CORE ext/*.h)
file(GLOB EXT_GRAPHICS ext/Graphics)
file(GLOB EXT_IMAGEPROC ext/ImageProc)
add_executable(PCA core ${XMATH_SRC} ${EXT_CORE} ${EXT_GRAPHICS} ${EXT_IMAGEPROC} ext/Graphics/MathUtils.h src/Interpolation.cpp src/Interpolation.h)
