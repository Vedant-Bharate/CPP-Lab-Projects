#include "metaverse.h"
#include <iostream>
#include <fstream>

int main() {
  metaverse_t metaverse{};
  int generations{};

  std::string metaverse_filename{"universe.meta"};

  std::ifstream metaverse_file{metaverse_filename};
  if (!metaverse_file.is_open()) {
      std::cout << "Metaverse file could not be opened!\n";
      return 1;
  }

  if (!initialize_metaverse_from_file(metaverse_file, metaverse, generations)) {
    std::cout << "Could not initialize the metaverse!\n";
    return 1;
  }

  model_metaverse(metaverse, generations);

  return 0;
}
