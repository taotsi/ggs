#pragma  once

#include <utility>
#include <atomic>
#include "world_state.h"
#include "command.h"

namespace ggs
{
  class World
  {
  private:
    std::atomic<bool> done_{false};
    std::atomic<bool> paused_{false};
    static constexpr double max_fps_{2};

    WorldState state_;

  public:
    World();

    explicit World(WorldState state);

    void loop();

  private:
    std::vector<Command> collect_commands();

    void execute_commands(const std::vector<Command> &commands);

    void execute_command(const Command &cmd);
  };
}
