#include <spdlog/spdlog.h>
#include "ggs/world.h"
#include "ggs/world_state.h"

int main()
{
  spdlog::set_level(spdlog::level::debug);

  ggs::WorldState state{};
  state.add_command("DUMMY");
  state.add_command("PAUSE");
  state.add_command("DUMMY");
  state.add_command("RESUME");
  state.add_command("DUMMY");
  state.add_command("STOP");

  ggs::World w{state};
  w.loop();

  return 0;
}
