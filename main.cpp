#include "Numerical.h"
#include <random>
#include <ctime>
using namespace xmath;
int main()
{
    srand(time(nullptr));
    Matrix<Real> A(3, 3);
    for(int i = 0; i < 3; i++)
    {
        A[i][i] = static_cast<Real>(rand() % 10);
        for(int j = i + 1; j < 3; j++)
            A[i][j] = A[j][i] = static_cast<Real>(rand() % 10);
    }

    Matrix<Real> P(3, 3), D(3, 3);
    diagonalize(A, P, D, true);
    A.output();
    P.output();
    D.output();
    (P * D * P.transpose()).output();
}