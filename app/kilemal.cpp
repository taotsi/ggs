#include <iostream>
#include "ggs.hpp"

int main()
{
  ggs::Ggs g{};
  g.x = 10;
  std::cout << g.x << std::endl;
  return 0;
}
