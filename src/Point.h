//
// Created by creeper on 22-10-31.
//

#ifndef XMATH_POINT_H
#define XMATH_POINT_H

#include "../core/core.h"

namespace xmath
{
    /**
     * \note this struct is only used as points on the plane, it doesn't support arithmetic operations.
     */

    struct Point2
    {
        Real x, y;
        bool operator<(const Point2& rhs) const { return EqualReals(x, y) ? y < rhs.y : x < rhs.x; }
        bool operator>(const Point2& rhs) const { return EqualReals(x, y) ? y > rhs.y : x > rhs.x; }
    };
}

#endif //XMATH_POINT_H
