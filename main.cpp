#include "Numerical.h"
#include <random>
#include <ctime>
int main()
{
    srand(time(nullptr));
    Matrix<Real> A(3, 3);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            A[i][j] = static_cast<Real>(rand() % 10);
    A.output();
    Matrix<Real> L(3, 3), U(3, 3);
    Matrix<Real> M(3, 3);
    inverse(A, M);
    M.output();
    (A * M).output();
}