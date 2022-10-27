//
// Created by creeper on 22-10-9.
//

#include "Complex.h"
namespace xmath
{
    Complex Complex::operator+(const Complex &z) const
    {
        return {x + z.x, y + z.y};
    }

    Complex Complex::operator-(const Complex &z) const
    {
        return {x - z.x, y - z.y};
    }

    Complex Complex::operator*(const Complex &z) const
    {
        return {x * z.x - y * z.y, x * z.y + y * z.x};
    }

//Complex Complex::operator/(const Complex &z)
//{
//    return {};
//}
    Complex conj(const Complex& z)
    {
        return {z.x, -z.y};
    }
    Complex Complex::conj() const
    {
        return {x, -y};
    }
}