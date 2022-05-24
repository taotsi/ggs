#pragma  once

#include <utility>
#include <atomic>
#include "world_state.h"
#include "command.h"
#include "world_config.h"

namespace ggs
{
  class World
  {
  private:
    std::atomic<bool> done_{false};
    std::atomic<bool> paused_{false};
    WorldConfig config_;
    WorldState state_;

  public:
    World();

    explicit World(const WorldConfig &config);

    void load_state(const WorldState &state);

    void loop();

  private:
    std::vector<Command> collect_commands();

    void execute_commands(const std::vector<Command> &commands);

    void execute_command(const Command &cmd);

    void set_velocity(const std::vector<std::string> &operands);

    void query_state();
  };
}
