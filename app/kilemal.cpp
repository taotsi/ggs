#include <spdlog/spdlog.h>
#include "world.h"
#include "world_state.h"

int main()
{
  spdlog::set_level(spdlog::level::debug);

  ggs::WorldState state{};
  state.add_command("nop");
  state.add_command("pause");
  state.add_command("nop");
  state.add_command("resume");
  state.add_command("nop");
  state.add_command("stop");

  ggs::World w{state};
  w.loop();

  return 0;
}
