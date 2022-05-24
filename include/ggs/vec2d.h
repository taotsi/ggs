#pragma once

#include <cstddef>
#include <ostream>

namespace ggs
{
  class Vec2d
  {
  public:
    Vec2d();

    Vec2d(double x, double y);

    [[nodiscard]] double x() const;

    [[nodiscard]] double y() const;

  private:
    double x_{0};
    double y_{0};
  };

  std::ostream &operator<<(std::ostream &os, const Vec2d &v);
}
