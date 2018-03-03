#include <iostream>
#include <vector>
#include <matrix.h>
#include <vector.h>
#include <helpers.h>
#include <heat1d.h>
#include <heat2d.h>

void heat1d_test()
{
  std::cout << "Testing heat1d" << std::endl;
  double alpha = 0.3125;
  int m = 3;
  double dt = 0.1;
  Heat1D heat(alpha, m, dt);
  heat.mat.print();
  std::cout << heat.exact(1) << std::endl;
  std::cout << heat.solve(1) << std::endl;
  // std::cout << heat.exact(0.5) << std::endl;
  // std::cout << heat.solve(0.5) << std::endl;
}

void heat2d_test()
{
  std::cout << "Testing heat2d" << std::endl;

  double alpha = 0.3125;
  int m = 3;
  double dt = 0.1;
  Heat2D heat(alpha, m, dt);
  heat.mat.print();
  std::cout << heat.exact(1) << std::endl;
  std::cout << heat.solve(1) << std::endl;
}

void cg_test()
{
  std::cout << "Testing cg" << std::endl;

  // Check solution from wikipedia
  Matrix<double> A(2, 2);
  A[{0, 0}] = 4;
  A[{0, 1}] = 1;
  A[{1, 0}] = 1;
  A[{1, 1}] = 3;
  Vector<double> x(2); // empty solution, passed as reference
  Vector<double> b({1, 2});
  cg<double>(A, b, x, 0.001, 50);
  std::cout << x << std::endl;
}

void matrix_test()
{
  std::cout << "Testing matrix" << std::endl;

  Matrix<double> M(2, 2);
  M[{0, 0}] = 1;
  M[{1, 0}] = 1;
  M[{0, 1}] = 1;
  M[{1, 1}] = 1;

  Vector<double> v = {1, 2};
  Vector<double> v2 = M.matvec(v);
  std::cout << v2 << std::endl;
}

void vector_test()
{
  std::cout << "Testing vector" << std::endl;

  Vector<int> v1;
  Vector<int> v2 = {1, 2, 3, 4, 5};
  Vector<int> v3(v2);
  Vector<int> v4;
  v4 = v2;
  // std::cout << v2.data[1] << std::endl;
  Vector<int> v5 = v4 + v2;
  std::cout << v2 << std::endl;
  std::cout << v4 << std::endl;
  std::cout << v5 << std::endl;
  std::cout << v5 * 3 << std::endl;
  std::cout << dot(v2, v3) << std::endl;
}

int main(int, char **)
{

  vector_test();
  matrix_test();
  cg_test();
  heat1d_test();
  heat2d_test();
}
