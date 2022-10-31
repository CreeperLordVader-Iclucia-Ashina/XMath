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
        private:
            enum Style{PIECE_WISE, LAGRANGE, CHEBYSHEV, FOURIER, CUBIC_SPLINE} style;
            int n = 0;
            Real* a = nullptr;
        public:
            void piecewise_interpolate(Vec2*);
            void lagrange(Vec2*);
            void chebyshev(Vec2*);
            void fourier(Vec2*);
            void cubic_spline(Vec2*);
            int getStyle() const;
            Real operator()(Real) const;
    };


}

#endif //XMATH_INTERPOLATION_H
