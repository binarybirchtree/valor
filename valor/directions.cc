#include "valor/directions.h"

#include <map>
#include <string>

namespace valor {

namespace {

typedef std::map<Direction, std::string> DirectionStrings;

static const DirectionStrings DIRECTIONS = {
  { Direction::STAY, "Stay" },
  { Direction::NORTH, "North" },
  { Direction::EAST, "East" },
  { Direction::SOUTH, "South" },
  { Direction::WEST, "West" }
};

} // namespace

std::ostream & operator << (std::ostream & stream, Direction direction) {
  stream << DIRECTIONS.at(direction);
  return stream;
}

}
