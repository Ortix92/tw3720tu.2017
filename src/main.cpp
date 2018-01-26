#include <iostream>
#include <matrix.h>
#include <vector>

int main(int, char **)
{

  Matrix<double> M(2, 2);
  M[{0, 0}] = 1;
  M[{1, 0}] = 1;
  M[{0, 1}] = 1;
  M[{1, 1}] = 1;

  std::vector<int> v = {2, 2, 3};
  std::vector<double> v3 = M.matvec(v);
}
