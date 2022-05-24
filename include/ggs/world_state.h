#pragma once

#include <queue>
#include <string>
#include "agent.h"
#include "command.h"

namespace ggs
{
  class WorldState
  {
  private:
    friend class World;

    std::queue<std::vector<Command>> commands_;
    std::vector<Agent> agents_;

  public:
    void add_command(const std::string &cmd);
//    void add_commands(const std::vector<std::string> commands);
  };
}
