#pragma once
#include <array>
#include <map>
#include <vector.h>

template <typename T>
class Matrix
{
  int rows;
  int cols;

public:
  using key_type = std::array<int, 2>;
  using mapped_type = T;
  using map_type = std::map<key_type, mapped_type>;
  map_type data;
  Matrix() : rows(0), cols(0) {}
  Matrix(const size_t r, const size_t c) : rows(r), cols(c) {}

  // Operator overloads
  const T &operator[](key_type key) const
  {
    return data[key];
  }
  T &operator[](key_type key)
  {
    // if (key[0] > this->rows - 1 || key[1] > this->cols - 1)
    // {
    //   std::cout << "Can not change shape of matrix" << std::endl;
    //   exit(EXIT_FAILURE);
    // }
    return data[key];
  }

  void print()
  {
    int i, j;
    for (i = 0; i < this->rows; i++)
    {
      for (j = 0; j < this->cols; j++)
      {
        if (j == 0)
          std::cout << "[";
        std::cout << this->data[{i, j}] << ",\t";
        if (j == this->cols - 1)
          std::cout << "]";
      }

      std::cout << std::endl;
    }
  }

  template <typename U>
  auto matvec(const Vector<U> &vec) const
  {
    if (vec.length != this->rows)
    {
      std::cout << "Dimension mismatch!" << std::endl;
      exit(EXIT_FAILURE);
    }
    Vector<typename std::common_type<T, U>::type> v2(vec.length);

    // set initially to 0 to add up values
    for (int k = 0; k < rows; k++)
    {
      v2.data[k] = 0;
    }
    for (auto it = data.cbegin(); it != data.cend(); it++)
    {
      v2.data[it->first[0]] += it->second * vec.data[it->first[1]];
    }
    return v2;
  }
};