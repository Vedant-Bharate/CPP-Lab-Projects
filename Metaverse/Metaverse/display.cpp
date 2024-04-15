#include <algorithm>
#include "metaverse.h"
#include "display.h"
#include <iostream>

void display_metaverse(std::ostream &os, const metaverse_t &metaverse) {
  std::cout << "|";
  auto dummy{std::vector<bool>(metaverse.size())};
  std::for_each(dummy.begin(), dummy.end(),
                        [](int) { std::cout << "---"; });
  std::cout << "|\n";
  for (auto row : metaverse) {
    std::cout << "|";
    for (auto cell : row) {
      if (cell) {
        os << " "
           << "+"
           << " ";
      } else {
        os << " "
           << " "
           << " ";
      }
    }
    std::cout << "|\n";
  }
  std::cout << "|";
  std::for_each(dummy.begin(), dummy.end(),
                        [](int) { std::cout << "---"; });
  std::cout << "|\n";
}
