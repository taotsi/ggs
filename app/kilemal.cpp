#include <spdlog/spdlog.h>
#include "ggs/world.h"
#include "ggs/world_state.h"

int main()
{
  spdlog::set_level(spdlog::level::debug);

  ggs::WorldConfig config{2};

  ggs::WorldState state{};
  ggs::Agent agent1{"agt1", ggs::Vec2d{0, 0}};
  state.add_agent(agent1);

//  state.add_command("DUMMY");
//  state.add_command("PAUSE");
//  state.add_command("DUMMY");
//  state.add_command("RESUME");
//  state.add_command("DUMMY");
  state.add_command("SET_VELOCITY agt1 0.1 0.1");
  state.add_command("QUERY_STATE");
  state.add_command("STOP");

  ggs::World world{config};
  world.load_state(state);
  world.loop();

  return 0;
}
