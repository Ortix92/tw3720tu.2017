#include <array>
#include <map>

template <typename T>
class Matrix
{
  const size_t rows;
  const size_t cols;

public:
  using key_type = std::array<size_t, 2>;
  using mapped_type = T;
  using map_type = std::map<key_type, mapped_type>;
  map_type data;

  Matrix(size_t r, size_t c) : rows(r), cols(c) {}

  // Operator overloads
  const T &operator[](key_type key) const
  {
    return data[key];
  }
  T &operator[](key_type key)
  {
    if (key[0] > this->rows - 1 || key[1] > this->cols - 1)
    {
      std::cout << "Can not change shape of matrix" << std::endl;
      exit(EXIT_FAILURE);
    }
    return data[key];
  }

  void print()
  {
    size_t i, j;
    for (i = 0; i < this->rows; i++)
    {
      for (j = 0; j < this->cols; j++)
      {
        std::cout << this->data[{i, j}] << ", ";
      }
      std::cout << std::endl;
    }
  }

  template <typename U>
  auto matvec(std::vector<U> vec)
  {
    if (vec.size() != this->rows)
    {
      std::cout << "Dimension mismatch!" << std::endl;
      exit(EXIT_FAILURE);
    }
    std::vector<typename std::common_type<T, U>::type> v2(vec.size());
    T row;
    for (size_t i = 0; i < this->rows; i++)
    {
      row = 0;
      for (size_t j = 0; j < this->cols; j++)
      {
        row += this->data[{i, j}];
      }
      v2[i] = vec[i] * row;
    }
    return v2;
  }
};