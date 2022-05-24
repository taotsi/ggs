#include <thread>
#include <iostream>
#include <spdlog/spdlog.h>
#include "ggs/world.h"

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

      std::vector<Command> commands = collect_commands();
      execute_commands(commands);

      const us t_elapsed = clock::now() - t0;
      std::this_thread::sleep_for(us{loop_duration_us - t_elapsed.count()});
    }

    spdlog::info("world loop stopped");
  }

  std::vector<Command> World::collect_commands()
  {
    std::vector<Command> result{};
    if (!state_.commands_.empty())
    {
      const auto &command_strings = state_.commands_.front();
      for (const auto &cmd_str: command_strings)
      {
        result.emplace_back(cmd_str);
      }
      state_.commands_.pop();
    }
    return result;
  }

  void World::execute_commands(const std::vector<Command> &commands)
  {
    if (!paused_)
    {
      for (const auto &cmd: commands)
      {
        execute_command(cmd);
      }
    }
    else
    {
      spdlog::warn("being paused, commands in this round will be ignored");
      for (auto it = commands.rbegin(); it != commands.rend(); it++)
      {
        if (it->op() == ggs::Operator::PAUSE)
        {
          return;
        }
        if (it->op() == ggs::Operator::RESUME)
        {
          paused_ = false;
          spdlog::info("resumed");
        }
      }
    }
  }

  void World::execute_command(const Command &cmd)
  {
    spdlog::debug("processing cmd: {}", cmd.original_cmd());

    if (cmd.op() == ggs::Operator::STOP)
    {
      done_ = true;
    }
    else if (cmd.op() == ggs::Operator::PAUSE)
    {
      paused_ = false;
      spdlog::info("paused");
    }
    else if (cmd.op() == ggs::Operator::UNKNOWN)
    {
      spdlog::warn("unknown command: {}", cmd.original_cmd());
    }
  }
}
