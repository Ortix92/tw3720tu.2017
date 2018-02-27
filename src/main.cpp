#include <iostream>
#include <vector>
#include <matrix.h>
#include <vector.h>
#include <helpers.h>

void matrix_test()
{
  Matrix<double> M(2, 2);
  M[{0, 0}] = 1;
  M[{1, 0}] = 1;
  M[{0, 1}] = 1;
  M[{1, 1}] = 1;

  std::vector<int> v = {2, 2};
  std::vector<double> v3 = M.matvec(v);
}

void vector_test()
{
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
  std::cout << v5*3 << std::endl;
  std::cout << dot(v2,v3) << std::endl;
}

int main(int, char **)
{

  vector_test();
  // matrix_test();
}
