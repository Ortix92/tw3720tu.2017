#include <matrix.h>
#include <vector.h>
#include <cmath>
#include <helpers.h>
class Heat1D
{
  const double dt;
  const int m;
  const double alpha;

public:
  Matrix<double> mat;
  // Constructors
public:
  Heat1D(double alpha, int m, double dt) : alpha(alpha), m(m), dt(dt), mat(m, m)
  {
    // the dimension n is 1 (1D)
    // m is passed into the constructor and is the size of the matrix
    // iterate over i and j. They are elements of {0,1,...m^n}
    double dx = 1 / ((double)m + 1);
    for (auto i = 0; i < m; i++)
    {
      for (auto j = 0; j < m; j++)
      {
        if (i == j)
        {
          // The diagonal of the identity matrix is i==j so it's 1-...
          mat[{i, j}] = 1 - alpha * (dt / (pow(dx, 2))) * (-2);
        }
        if ((j + 1) == i || (j - 1) == i || (j - m) == i)
        {
          // All the other values of the identity matrix are 0 so 0-...
          mat[{i, j}] = 0 - alpha * (dt / (pow(dx, 2)));
        }
      }
    }
  }

private:
  Vector<double> grid() const
  {
    Vector<double> v(m);
    for (int k = 1; k < m + 1; k++)
    {
      v.data[k - 1] = k / (double(m) + 1);
    }
    return v;
  }
  // Creating initial conditions function
  Vector<double> init() const
  {
    Vector<double> v(m);
    for (int k = 0; k < m; k++)
    {
      v.data[k] = sin(M_PI * grid().data[k]);
    }
    return v;
  }

public:
  Vector<double> exact(double t) const
  {
    Vector<double> v = init() * exp(-M_PI * M_PI * alpha * t);
    return v;
  }
  Vector<double> solve(double t_end) const
  {
    Vector<double> w_0 = init();
    Vector<double> w_1 = init();
    for (int k = 0; k < t_end / dt; k++)
    {
      int a = cg(mat, w_0, w_1, 0.001, 100);
      w_0 = w_1;
    }
    return w_1;
  }
};
