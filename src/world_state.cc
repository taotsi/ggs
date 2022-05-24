#include <string>
#include "ggs/world_state.h"

namespace ggs
{
  void WorldState::add_command(const std::string &cmd)
  {
    commands_.push(std::vector<Command>{Command{cmd}});
  }
}
