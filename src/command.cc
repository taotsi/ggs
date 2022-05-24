#include "ggs/command.h"

#include <utility>
#include <sstream>

namespace ggs
{
  std::ostream &operator<<(std::ostream &os, const Operator &token)
  {
    switch (token)
    {
      case Operator::STOP:
        os << "STOP";
        break;
      case Operator::PAUSE:
        os << "PAUSE";
        break;
      case Operator::RESUME:
        os << "RESUME";
        break;
      case Operator::SET_VELOCITY:
        os << "SET_VELOCITY";
        break;
      case Operator::UNKNOWN:
        os << "UNKNOWN";
        break;
      case Operator::QUERY_STATE:
        os << "QUERY_STATE";
        break;
    }
    return os;
  }

  Command::Command(const std::string &cmd_str)
    : cmd_str_{cmd_str}
  {
    std::istringstream cmd_is{cmd_str};
    std::string temp;
    getline(cmd_is, temp, SEPARATOR);
    op_ = string_to_op(temp);
    std::vector<std::string> operands;
    if (op_ != Operator::UNKNOWN)
    {
      while (getline(cmd_is, temp, SEPARATOR))
      {
        operands.push_back(temp);
      }
    }
    // TODO: check if operands are valid
    operands_ = std::move(operands);
  }

  Operator Command::op() const
  {
    return op_;
  }

  const std::vector<std::string> &Command::operands() const
  {
    return operands_;
  }

  Operator Command::string_to_op(const std::string &token_str)
  {
    if (token_str == "STOP")
    {
      return Operator::STOP;
    }
    else if (token_str == "PAUSE")
    {
      return Operator::PAUSE;
    }
    else if (token_str == "RESUME")
    {
      return Operator::RESUME;
    }
    else if (token_str == "SET_VELOCITY")
    {
      return Operator::SET_VELOCITY;
    }
    else if (token_str == "QUERY_STATE")
    {
      return Operator::QUERY_STATE;
    }
    return Operator::UNKNOWN;
  }

  std::string Command::original_cmd() const
  {
    return cmd_str_;
  }
}
