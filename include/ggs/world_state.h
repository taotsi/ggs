#pragma once

#include <queue>
#include <string>
#include <unordered_map>
#include "agent.h"
#include "command.h"

namespace ggs
{
  class WorldState
  {
  private:
    friend class World;

    std::queue<std::vector<Command>> commands_;
    std::unordered_map<std::string, Agent> agents_;

  public:
    void add_command(const std::string &cmd);

    void add_agent(const Agent &agent);
  };
}
