#ifndef INCLUDED_VINDICATOR_DIRECTIONS
#define INCLUDED_VINDICATOR_DIRECTIONS

#include <iostream>
#include <map>
#include <string>

namespace vindicator {

enum class Direction { STAY, NORTH, EAST, SOUTH, WEST };

std::ostream & operator << (std::ostream & stream, Direction direction);

}

#endif
