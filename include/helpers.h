#pragma once
#include <matrix.h>
template <typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter) //TODO: Check for specific values/conditions
{

  Vector<T> p(maxiter);
  Vector<T> r_k(maxiter);
  Vector<T> r_k1(maxiter);

  p = b - A.matvec(x);
  r_k = b - A.matvec(x);

  //for k = 0, 1, ..., maxiter-1
  for (auto k = 0; k < maxiter; k++)
  {
    auto alpha = dot(r_k, r_k) / dot(p, A.matvec(p));
    x = x + p * alpha;
    r_k1 = r_k - A.matvec(p) * alpha;
    if (dot(r_k1, r_k1) < (tol * tol))
    {
      return k;
    }
    auto beta = dot(r_k1, r_k1) / dot(r_k, r_k);
    p = r_k1 + p * beta;
    r_k = r_k1;
  }
  return -1;
}