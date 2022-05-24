#pragma once

#include <string>
#include <vector>

namespace ggs
{
  enum class Operator
  {
    STOP,
    PAUSE,
    RESUME,
    QUERY_STATE,
    SET_VELOCITY,
    UNKNOWN
  };

  std::ostream& operator<<(std::ostream &os, const Operator &token);

  class Command
  {
  private:
    static constexpr char SEPARATOR = ' ';

    Operator op_ = Operator::UNKNOWN;
    std::vector<std::string> operands_;
    std::string cmd_str_;

  public:
    explicit Command(const std::string &cmd_str);

    [[nodiscard]] Operator op() const;
    [[nodiscard]] const std::vector<std::string>& operands() const;
    [[nodiscard]] std::string original_cmd() const;

  private:
    static Operator string_to_op(const std::string &token_str);
  };
}
