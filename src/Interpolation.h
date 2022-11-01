//
// Created by creeper on 22-10-29.
//

#ifndef XMATH_INTERPOLATION_H
#define XMATH_INTERPOLATION_H

#include "../core/core.h"
#include "Point.h"
#include <memory>
#include <vector>

namespace xmath
{
    class Interpolation
    {
        private:
            enum Style{PIECE_WISE, LAGRANGE, CHEBYSHEV, FOURIER, CUBIC_SPLINE} style;
            std::vector<Point2> points;
            std::vector<Real> coeff;
        public:
            void piecewise_interpolate(Point2*, int);
            void lagrange(Point2*, int);
            void chebyshev(Point2*, int);
            void fourier(Point2*, int);
            void cubic_spline(Point2*, int);
            int getStyle() const;
            Real operator()(Real) const;
    };


}

#endif //XMATH_INTERPOLATION_H
