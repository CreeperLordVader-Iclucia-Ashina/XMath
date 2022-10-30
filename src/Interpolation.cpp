//
// Created by creeper on 22-10-29.
//

#include "Interpolation.h"
#include <algorithm>

namespace xmath
{
    void Interpolation::piecewise_interpolate(Real *x, Real *y)
    {
        style = Style::PIECE_WISE;
        for(int i = 0; i < ; i++)
    }
    void Interpolation::lagrange(Real *x, Real *y)
    {
        style = Style::LAGRANGE;
    }

    void Interpolation::chebyshev(Real *x, Real *y)
    {
        style = Style::CHEBYSHEV;
    }

    void Interpolation::fourier(Real *x, Real *y)
    {
        style = Style::FOURIER;
    }

    void Interpolation::cubic_spline(Real *, Real *)
    {
        style = Style::CUBIC_SPLINE;
    }

    int Interpolation::getStyle() const
    {
        return style;
    }

    Real Interpolation::operator()(xmath::Real x) const
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

