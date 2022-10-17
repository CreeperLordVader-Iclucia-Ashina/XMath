#include "Numerical.h"
#include "Vector.h"
#include <cassert>

void DFT(Vec& F)
{

}

void IDFT(Vec& F)
{

}

void LUDecompose(const Matrix<Real>& A, Matrix<Real>& L, Matrix<Real>& M, Matrix<Real>& U)
{
    assert(A.getM() == L.getM() && A.getN() == U.getN());
    M = A;
    L.MakeIdentity();
    U.MakeIdentity();
    uint start_up = 0, rk = 0;
    for(int i = 0; i < A.getN(); i++)
    {
        bool fullZero = true;
        for(int j = 0; j < A.getM(); j++)
        {
            if(A[j][i] != 0)
            {
                fullZero = false;
                break;
            }
        }
        if(!fullZero) break;
        start_up++;
    }
    for(uint i = 0, p = start_up; i < A.getM() && p < A.getN(); i++, p++, rk++)
    {
        Real max_val = std::abs(M[i][p]);
        uint idx = i;
        for(uint j = i + 1; j < A.getM(); j++)
        {
            if(std::abs(M[j][p]) > max_val)
            {
                max_val =std::abs(M[j][p]);
                idx = j;
            }
        }
        FirstElementaryRowOpt(M, i, idx, p, A.getN());
        FirstElementaryRowOpt(L, i, idx);
        Real NegInv = -1.0 / M[i][p];
        for(uint j = i + 1; j < A.getM(); j++)
        {
            SecondElementaryRowOpt(L, i, NegInv * M[j][p], j);
            SecondElementaryRowOpt(M, i, NegInv * M[j][p], j, p, A.getN());
        }
    }// after this, we get L and M turns into an upper triangle matrix, perform row op to calc U
    for(uint i = 0, p = start_up; i < rk; i++, p++)
    {
        Real NegInv = -1.0 / M[i][p];
        for(uint j = p + 1; j < A.getN(); j++)
        {
            SecondElementaryColumnOpt(U, p, NegInv * M[i][j], j);
            SecondElementaryColumnOpt(M, p, NegInv * M[i][j], j, i, i + 1);
        }
        ThirdElementaryColumnOpt(M, i, -NegInv, p, p + 1);
        ThirdElementaryColumnOpt(U, i, -NegInv);
    }
}

void inverse(const Matrix<Real>& A, Matrix<Real> &inv)
{
    if(!A.isSquare())
    {
        std::cerr << "WARNING: only squares are invertible" << std::endl;
        return ;
    }
    Matrix<Real> M(A);
    inv.MakeIdentity();
    uint rk = 0;
    for(int i = 0; i < A.getN(); i++)
    {
        bool fullZero = true;
        for(int j = 0; j < A.getM(); j++)
        {
            if(A[j][i] != 0)
            {
                fullZero = false;
                break;
            }
        }
        if(!fullZero)
        {
            std::cerr << "WARNING: matrix is not invertible" << std::endl;
            return ;
        }
    }
    for(uint i = 0; i < A.getM(); i++, rk++)
    {
        Real max_val = std::abs(M[i][i]);
        uint idx = i;
        for(uint j = i + 1; j < A.getM(); j++)
        {
            if(std::abs(M[j][i]) > max_val)
            {
                max_val =std::abs(M[j][i]);
                idx = j;
            }
        }
        FirstElementaryRowOpt(M, i, idx, i, A.getN());
        FirstElementaryRowOpt(inv, i, idx);
        Real NegInv = -1.0 / M[i][i];
        for(uint j = i + 1; j < A.getM(); j++)
        {
            SecondElementaryRowOpt(inv, i, NegInv * M[j][i], j);
            SecondElementaryRowOpt(M, i, NegInv * M[j][i], j, i, A.getN());
        }
    }// after this, we get L and M turns into an upper triangle matrix, perform row op to calc U
    if(rk < A.getM())
    {
        std::cerr << "WARNING: matrix is not invertible" << std::endl;
        return ;
    }
    for(uint i = 0; i < A.getM(); i++)
    {
        Real NegInv = -1.0 / M[i][i];
        for(uint j = i + 1; j < A.getN(); j++)
        {
            SecondElementaryColumnOpt(inv, i, NegInv * M[i][j], j);
            SecondElementaryColumnOpt(M, i, NegInv * M[i][j], j, i, i + 1);
        }
        ThirdElementaryColumnOpt(M, i, -NegInv, i, i + 1);
        ThirdElementaryColumnOpt(inv, i, -NegInv);
    }
}
