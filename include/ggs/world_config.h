#pragma once

namespace ggs
{
  class WorldConfig
  {
  private:
    double max_fps_ = 60;
  public:
    WorldConfig();

    explicit WorldConfig(double max_fps);

    [[nodiscard]] double max_fps() const;
  };
}
