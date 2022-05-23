#include <string>
#include "world_state.hpp"

namespace ggs
{
  void WorldState::add_cmd(const std::string &cmd)
  {
    commands_.push(cmd);
  }
}
