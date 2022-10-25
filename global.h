#ifndef XMATH_GLOBAL_H
#define XMATH_GLOBAL_H
namespace xmath
{
    using uint = unsigned int;
    using Real = double;
    const Real EPS = 1e-14;
    inline bool EqualReals(Real a, Real b)
    {
        return a - b < EPS && a - b > -EPS;
    }
    inline bool EqualZero(Real a)
    {
        return a < EPS && a > -EPS;
    }
}
#endif //XMATH_GLOBAL_H
