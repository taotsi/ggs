#include <thread>
#include <iostream>
#include <spdlog/spdlog.h>
#include "world.hpp"

using namespace std::chrono_literals;

namespace ggs
{
  World::World(WorldState state)
    : state_{std::move(state)}
  {}

  World::World() = default;

  void World::loop()
  {
    using clock = std::chrono::system_clock;
    using us = std::chrono::duration<double, std::micro>;

    spdlog::info("world loop started");

    static int loop_duration_us = 1'000'000 / max_fps_;
    spdlog::info("max fps: {}, duration: {:.1f} ms", max_fps_, loop_duration_us / 1000.0);

    while (!done_)
    {
      const auto t0 = clock::now();

      process_commands();

      const us t_elapsed = clock::now() - t0;
      std::this_thread::sleep_for(us{loop_duration_us - t_elapsed.count()});
    }

    spdlog::info("world loop stopped");
  }

  void World::process_commands()
  {
    if (state_.commands_.empty()) {
      return;
    }
    const auto& cmd = state_.commands_.front();
    spdlog::debug("processing command: {}", cmd);

    state_.commands_.pop();
    if (cmd == "stop") {
      done_ = true;
    }
  }
}
