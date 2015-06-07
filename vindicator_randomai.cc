#include <vindicator_randomai.h>

#include <random>
#include <vector>

namespace vindicator {

Direction RandomAI::decide (const State & state) {
  static const std::vector<Direction> directions = {
    Direction::STAY,
    Direction::NORTH,
    Direction::EAST,
    Direction::SOUTH,
    Direction::WEST
  };

  thread_local std::random_device device;
  thread_local std::mt19937 generator(device());
  thread_local std::uniform_int_distribution<> distribution(0, directions.size() - 1);
  return directions[distribution(generator)];
}

}
