#ifndef XMATH_NUMERICAL_H
#define XMATH_NUMERICAL_H
#include "Vector.h"
#include "Matrix.h"
namespace xmath
{
    using Vec = Vector<double>;
    void DFT(Vec&);
    void IDFT(Vec&);
    void LUDecompose(const Matrix<Real>&, Matrix<Real>&, Matrix<Real>&, Matrix<Real>&);
    void inverse(const Matrix<Real>&, Matrix<Real>&);
    void QRDecompose(const Matrix<Real>&, Matrix<Real>&, Matrix<Real>&);
    void diagonalize(const Matrix<Real>&, Matrix<Real>&, Matrix<Real>&, bool sortEigen = false);//diag
}
#endif //XMATH_NUMERICAL_H
