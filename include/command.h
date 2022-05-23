#pragma once

#include <string>

namespace ggs
{
  class Command
  {
  public:
    std::string cmd_;
  public:
    Command(std::string cmd_str);
  };
}
