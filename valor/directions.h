#ifndef INCLUDED_VALOR_DIRECTIONS
#define INCLUDED_VALOR_DIRECTIONS

#include <iostream>
#include <map>
#include <string>

namespace valor {

enum class Direction { STAY, NORTH, EAST, SOUTH, WEST };

std::ostream & operator << (std::ostream & stream, Direction direction);

}

#endif
