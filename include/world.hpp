#pragma  once
#include <utility>
#include <atomic>
#include "world_state.hpp"

namespace ggs
{
  class World
  {
  private:
    std::atomic<bool> done_{false};
    static constexpr double max_fps_{0.5};
    WorldState state_;

  public:
    World();
    explicit World(WorldState state);

    void loop();

  private:

    void process_commands();
  };
}
