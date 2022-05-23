#include <spdlog/spdlog.h>
#include "world.h"
#include "world_state.h"

int main()
{
  spdlog::set_level(spdlog::level::debug);

  ggs::WorldState state{};
  state.add_cmd("nop");
  state.add_cmd("pause");
  state.add_cmd("nop");
  state.add_cmd("resume");
  state.add_cmd("nop");
  state.add_cmd("stop");

  ggs::World w{state};
  w.loop();

  return 0;
}
