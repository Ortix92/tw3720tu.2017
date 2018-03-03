#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <typeinfo>

template <typename T>
class Vector
{

public:
  // probably should be private
  T *data;
  int length;

  Vector() : data(nullptr), length(0) {}

  // size constructor
  Vector(int size) : data(new T[size]), length(size) {}

  // copy constructor
  Vector(const Vector &other) : Vector(other.length)
  {
    this->length = other.length;
    for (auto i = 0; i < other.length; i++)
    {
      this->data[i] = other.data[i];
    }
  }

  // initializer list
  Vector(std::initializer_list<T> list) : Vector((int)list.size())
  {
    std::uninitialized_copy(list.begin(), list.end(), this->data);
  }

  auto size() const
  {
    return length;
  }
  // Copy assignment operator
  Vector<T> &operator=(const Vector<T> &other)
  {
    if (this != &other)
    {
      delete[] data;
      length = other.length;
      data = new T[length];
      for (auto i = 0; i < length; i++)
      {
        data[i] = other.data[i];
      }
    }
    //std::cout << "Copy assign. " << std::endl;
    return *this;
  }

  // Move assignment operator
	Vector& operator=(Vector&& other) {
		if (this != &other)
		{
			delete[] data;
			data = other.data;
			length = other.length;	other.data = nullptr;
			length = other.length;	other.length = 0;
		}
		return *this;
	}


  template <typename U>
  auto operator+(const Vector<U> &other) const
  {
    Vector<typename std::common_type<T, U>::type> v2(length);
    if (length != other.length)
    {
      throw std::invalid_argument("Vectors are not the same size!");
    }

    for (auto i = 0; i < length; i++)
    {
      v2.data[i] = data[i] + other.data[i];
    }
    return v2;
  }
  template <typename U>
  auto operator-(const Vector<U> &other) const
  {
    Vector<typename std::common_type<T, U>::type> v2(length);
    if (length != other.length)
    {
      throw std::invalid_argument("Vectors are not the same size!");
    }

    for (auto i = 0; i < length; i++)
    {
      v2.data[i] = data[i] - other.data[i];
    }
    return v2;
  }

  template <typename U>
  auto operator*(const U &scalar) const
  {
    Vector<typename std::common_type<T, U>::type> v2(length);
    for (auto i = 0; i < length; i++)
    {
      v2.data[i] = data[i] * scalar; // add.get returns a mutable reference to addition data.
    }
    return v2;
  };
};

template <typename T>
T dot(const Vector<T> &l, const Vector<T> &r)
{
  if (l.length != r.length)
  {
    throw std::invalid_argument("Vectors are not the same size!");
  }
  T out = 0;
  for (auto i = 0; i < l.length; i++)
  {
    out += l.data[i] * r.data[i];
  }
  return out;
};
// left multiplication as non-member function
template <typename U, typename T>
auto operator*(const U &scalar, const Vector<T> &v1)
{
  return v1 * scalar;
};

// Helper to print
template <typename T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &V)
{
  for (auto i = 0; i < V.length; i++)
  {
    if (i > 0)
    {
      os << ',';
    }
    os << V.data[i];
  }
  return os;
}
