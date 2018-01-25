#include <iostream>
#include <matrix.h>

int main(int, char **)
{

  Matrix<double> M(10, 20);
  M[{1, 2}] = 10;
  std::cout << M[{1, 2}];
  std::cout << "Hello, world!\n";
}
