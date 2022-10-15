#include "Numerical.h"
#include <random>
#include <ctime>
int main()
{
    srand(time(nullptr));
    Matrix<Real> A(4, 5);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 5; j++)
            A[i][j] = static_cast<Real>(rand() % 10);
    A.output();
    Matrix<Real> M(4, 5);
    Matrix<Real> L(4, 4), U(5, 5);
    LUDecompose(A, L, M, U);
    L.output();
    U.output();
    M.output();
}