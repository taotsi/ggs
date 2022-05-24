#pragma once

#include <string>
#include "vec2d.h"

namespace ggs
{
  class Agent
  {
  private:
    std::string id_{};
    Vec2d pos_{0, 0};
    Vec2d vel_{0, 0};
  public:
    Agent();

    explicit Agent(std::string id, const Vec2d &pos, const Vec2d &vel = Vec2d{});

    [[nodiscard]] const std::string &id() const;

    [[nodiscard]] const Vec2d &pos() const;

    [[nodiscard]] const Vec2d &vel() const;

    void vel(const Vec2d &vel);
  };

  std::ostream &operator<<(std::ostream &os, const Agent &v);
}
