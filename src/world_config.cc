#include "ggs/world_config.h"

namespace ggs
{

  WorldConfig::WorldConfig() = default;

  WorldConfig::WorldConfig(double max_fps)
    : max_fps_{max_fps}
  {}

  double WorldConfig::max_fps() const
  {
    return max_fps_;
  }
}