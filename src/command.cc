#include "command.h"

#include <utility>

namespace ggs
{
  Command::Command(std::string cmd_str)
    : cmd_{std::move(cmd_str)}
  {}
}
