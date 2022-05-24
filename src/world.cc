#include <thread>
#include <iostream>
#include <spdlog/spdlog.h>
#include "ggs/world.h"

using namespace std::chrono_literals;

namespace ggs
{
  World::World(const WorldConfig &config)
    : config_{config}
  {}

  World::World() = default;

  void World::loop()
  {
    using clock = std::chrono::system_clock;
    using us = std::chrono::duration<double, std::micro>;

    spdlog::info("world loop started");

    auto loop_duration_us = static_cast<int>(1'000'000.0 / config_.max_fps());
    spdlog::info("max fps: {}, duration: {:.1f} ms", config_.max_fps(), loop_duration_us / 1000.0);

    while (!done_)
    {
      const auto t0 = clock::now();

      auto commands = collect_commands();
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
        if (it->op() == Operator::PAUSE)
        {
          return;
        }
        if (it->op() == Operator::RESUME)
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

    if (cmd.op() == Operator::STOP)
    {
      done_ = true;
    }
    else if (cmd.op() == Operator::PAUSE)
    {
      paused_ = false;
      spdlog::info("paused");
    }
    else if (cmd.op() == Operator::SET_VELOCITY)
    {
      set_velocity(cmd.operands());
    }
    else if (cmd.op() == Operator::QUERY_STATE)
    {
      query_state();
    }
    else if (cmd.op() == Operator::UNKNOWN)
    {
      spdlog::warn("unknown command: {}", cmd.original_cmd());
    }
  }

  void World::load_state(const WorldState &state)
  {
    state_ = state;
  }

  void World::set_velocity(const std::vector<std::string> &operands)
  {
    const std::string &agent_id = operands[0];
    if (state_.agents_.contains(agent_id))
    {
      auto &agent = state_.agents_[agent_id];
      agent.vel(Vec2d{std::stod(operands[1]),
                      std::stod(operands[2])});
    }
    else
    {
      spdlog::warn("agent {} not found", agent_id);
    }
  }

  void World::query_state()
  {
    std::ostringstream oss{};
    for (const auto &[_, agent]: state_.agents_)
    {
      oss << agent << ", ";
    }
    spdlog::debug(oss.str());
  }
}
