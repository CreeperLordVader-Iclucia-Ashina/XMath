//
// Created by creeper on 22-10-29.
//

#include "Interpolation.h"
#include <algorithm>

namespace xmath
{
    void Interpolation::piecewise_interpolate(Point2* p, int n)
    {
        style = Style::PIECE_WISE;
        std::sort(p, p + n);
        for(int i = 0; i < n; i++)
            points[i] = p[i];
    }
    void Interpolation::lagrange(Point2* p, int n)
    {
        style = Style::LAGRANGE;
    }

    void Interpolation::chebyshev(Point2* p, int n)
    {
        style = Style::CHEBYSHEV;
    }

    void Interpolation::fourier(Point2* p, int n)
    {
        style = Style::FOURIER;
    }

    void Interpolation::cubic_spline(Point2* p, int n)
    {
        style = Style::CUBIC_SPLINE;
    }

    int Interpolation::getStyle() const
    {
        return style;
    }

    Real Interpolation::operator()(Real x) const
    {
        if(style == Style::PIECE_WISE)
        {

        }
        else if(style == Style::LAGRANGE)
        {
            return 0;
        }
        else if(style == Style::CHEBYSHEV)
        {
            return 0;
        }
        else if(style == Style::FOURIER)
        {
            return 0;
        }
        else if(style == Style::CUBIC_SPLINE)
        {
            return 0;
        }
    }
}

