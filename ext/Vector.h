//
// Created by creeper on 22-10-25.
//
#ifndef XMATH_VECTOR_H
#define XMATH_VECTOR_H
#include "global.h"
namespace ImageProc
{
    template<typename T, unsigned int N>
    class Vector
    {

    };
    using Vec3f = Vector<float, 3>;
    using Vec4f = Vector<float, 4>;
    using Vec3d = Vector<double, 3>;
    using Vec4d = Vector<double, 3>;
    using Spectrum = Vector<double, 3>;
}
#endif //XMATH_VECTOR_H
