//
// Created by creeper on 22-10-29.
//

#ifndef XMATH_INTERPOLATION_H
#define XMATH_INTERPOLATION_H

#include "../core/core.h"
#include <memory>

namespace xmath
{
    class Interpolation
    {
        public:
            virtual void interpolate(const Real*) = 0;
            virtual Real operator()(Real) = 0;
    };

    class LinearInterpolation : public Interpolation
    {
        private:
            int n = 0;
            Real* x = nullptr;
        public:
            void interpolate(const Real*) override;
            Real operator()(Real) override;
    };

    class CubicSpline : public Interpolation
    {

    };

    class NewtonPolynomial : public Interpolation
    {

    };

    class LagrangePolynomial : public Interpolation
    {

    };

    class ChebyshevPolynomial : public Interpolation
    {

    };

    class TriangularInterpolation : public Interpolation
    {

    };

    class VectorInterpolation
    {
        private:

        public:

    };
}

#endif //XMATH_INTERPOLATION_H
