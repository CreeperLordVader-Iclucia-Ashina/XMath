#include "Numerical.h"
#include "Vector.h"
#include <cassert>
namespace xmath
{
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
        for(int i = 0; i < A.getM(); i++)
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
            if(fullZero)
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
                    max_val = std::abs(M[j][i]);
                    idx = j;
                }
            }
            FirstElementaryRowOpt(M, i, idx, i, A.getM());
            FirstElementaryRowOpt(inv, i, idx);
            Real NegInv = -1.0 / M[i][i];
            for(uint j = i + 1; j < A.getM(); j++)
            {
                SecondElementaryRowOpt(inv, i, NegInv * M[j][i], j);
                SecondElementaryRowOpt(M, i, NegInv * M[j][i], j, i, A.getM());
            }
        }// after this, we get L and M turns into an upper triangle matrix, perform row op to calc U
        if(rk < A.getM())
        {
            std::cerr << "WARNING: matrix is not invertible" << std::endl;
            return ;
        }
        for(int i = A.getM() - 1; i >= 0; i--)
        {
            Real NegInv = -1.0 / M[i][i];
            for(int j = i - 1; j >= 0; j--)
            {
                SecondElementaryRowOpt(inv, i, NegInv * M[j][i], j);
                SecondElementaryRowOpt(M, i, NegInv * M[j][i], j, i, i + 1);
            }
            ThirdElementaryRowOpt(M, i, -NegInv, i, i + 1);
            ThirdElementaryRowOpt(inv, i, -NegInv);
        }
    }

    void QRDecompose(const Matrix<Real>& A, Matrix<Real>& Q, Matrix<Real>& R)
    {

    }

    //diagonalize a real symmetric matrix, such that A = PDP^T
    //sortEigen denotes whether to sort the eigen values by absolute value
    void diagonalize(const Matrix<Real>& A, Matrix<Real>& P, Matrix<Real>& D, bool sortEigen)
    {
        if(!isSymmetric(A)) return ;
        P.MakeIdentity();
        D.copyFrom(A);//now we perform row and column operations symmetrically and alternatively
        uint n = A.getM();
        for(int i = 0; i < n; i++)//now we are considering sub-matrix D[i ~ n - 1][i ~ n - 1]
        {
            int idx = i;//idx denotes the row whose ith element has the greatest abs value
            Real maxv = fabs(D[i][i]);
            for(int j = i + 1; j < n; j++)
                if(fabs(D[i][i]) > maxv)
                {
                    maxv = fabs(D[j][j]);
                    idx = j;//maybe more cache friendly
                }
            if(idx != i)
            {
                FirstElementaryRowOpt(D, i, idx, i, n);
                FirstElementaryColumnOpt(D, i, idx, i, n);
                FirstElementaryColumnOpt(P, i, idx);
            }
            if(EqualZero(D[i][i])) continue;
            Real NegInv = -1.0 / D[i][i];
            for(int j = i + 1; j < n ; j++)
            {
                Real k = NegInv * D[i][j];
                if(!EqualZero(k))
                {
                    SecondElementaryRowOpt(D, i, k, j, i, n);
                    SecondElementaryColumnOpt(D, i, k, j, i, n);
                    SecondElementaryColumnOpt(P, j, -k, i);
                }
            }
        }
        if(sortEigen)
        {
            for(int i = 0; i < n - 1; i++)
            {
                int idx = i;
                Real maxv = fabs(D[i][i]);
                for(int j = i + 1; j < n; j++)
                {
                    if(fabs(D[j][j]) > maxv)
                    {
                        maxv = fabs(D[idx][idx]);
                        idx = j;
                    }
                }
                if(i != idx)std::swap(D[i][i], D[idx][idx]);
                FirstElementaryColumnOpt(P, i, idx);
            }
        }
    }
}
