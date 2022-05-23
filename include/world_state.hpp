#pragma once
#include <queue>
#include <string>

namespace ggs
{
  class WorldState
  {
  private:
    std::queue<std::string> commands_;
    friend class World;

  public:
    void add_cmd(const std::string& cmd);
  };
}
