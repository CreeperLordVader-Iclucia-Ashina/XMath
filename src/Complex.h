#ifndef XMATH_COMPLEX_H
#define XMATH_COMPLEX_H
#include "Numerical.h"
#include <utility>
namespace xmath
{
    class Complex
    {
            Real x, y;
            friend Complex conj(const Complex&);
            Complex(Real _x, Real _y) : x(_x), y(_y) {}
            Complex(const Complex&) = default;
            Complex& operator=(const Complex&) = default;
            Complex operator+(const Complex&) const;
            Complex operator-(const Complex&) const;
            Complex operator*(const Complex&) const;
            //Complex operator/(const Complex&);
            Complex conj() const;
    };

    Complex conj(const Complex& z);
}
#endif //XMATH_COMPLEX_H
