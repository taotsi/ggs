#include <catch2/catch.hpp>
#include "ggs/command.h"


TEST_CASE("op", "[op]")
{
  ggs::Command cmd1{"dummy"};
  REQUIRE(cmd1.op() == ggs::Operator::UNKNOWN);
  ggs::Command cmd2{"STOP"};
  REQUIRE(cmd2.op() == ggs::Operator::STOP);
  ggs::Command cmd3{"SET_VELOCITY a 1 1"};
  REQUIRE(cmd3.op() == ggs::Operator::SET_VELOCITY);
  const auto &operands3 = cmd3.operands();
  REQUIRE(operands3.size() == 3);
}
