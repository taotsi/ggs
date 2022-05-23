#pragma  once
#include <utility>
#include <atomic>
#include "world_state.h"

namespace ggs
{
  class World
  {
  private:
    std::atomic<bool> done_{false};
    std::atomic<bool> paused_{false};
    static constexpr double max_fps_{1};
    WorldState state_;

  public:
    World();
    explicit World(WorldState state);

    void loop();

  private:

    void process_commands();

    void expect_resume_command();
  };
}
