#include <array>
#include <map>

template <typename T>
class Matrix
{
  size_t rows;
  size_t cols;

public:
  using key_type = std::array<size_t, 2>;
  using mapped_type = T;
  using map_type = std::map<key_type, mapped_type>;
  map_type data;

  Matrix(size_t r, size_t c) : rows(r), cols(c) {}

  const T &operator[](key_type key) const { return data[key]; }
  T &operator[](key_type key) { return data[key]; }
};