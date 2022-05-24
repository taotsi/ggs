#include "ggs/agent.h"

#include <utility>

namespace ggs
{
  Agent::Agent() = default;

  Agent::Agent(std::string id, const Vec2d &pos, const Vec2d &vel)
    : id_{std::move(id)}, pos_{pos}, vel_{vel}
  {}

  const std::string &Agent::id() const
  {
    return id_;
  }

  const Vec2d &Agent::pos() const
  {
    return pos_;
  }

  const Vec2d &Agent::vel() const
  {
    return vel_;
  }

  void Agent::vel(const Vec2d &vel)
  {
    vel_ = vel;
  }

  std::ostream &operator<<(std::ostream &os, const Agent &v)
  {
    os << v.id() << " " << v.pos() << " " << v.vel();
    return os;
  }
}
