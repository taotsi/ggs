#include "ggs/vec2d.h"

namespace ggs
{
  Vec2d::Vec2d() = default;

  Vec2d::Vec2d(double x, double y)
    : x_{x}, y_{y}
  {}

  double Vec2d::x() const
  {
    return x_;
  }

  double Vec2d::y() const
  {
    return y_;
  }

  std::ostream &operator<<(std::ostream &os, const Vec2d &v)
  {
    os << "(" << v.x() << ", " << v.y() << ")";
    return os;
  }
}
