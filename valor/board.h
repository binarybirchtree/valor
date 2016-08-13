// This file is part of Valor.
// Copyright (C) 2015, 2016 Binary Birch Tree
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef INCLUDED_VALOR_BOARD
#define INCLUDED_VALOR_BOARD

#include <iostream>
#include <memory>
#include <vector>

#include "valor/element.h"

namespace valor {

class Board {
public:
  typedef std::pair<int, int> Coordinates;
  typedef std::vector<Coordinates> Path;

  Board (std::size_t size, const std::string & layout);

  ///
  /// @return Size of the board.
  ///
  std::size_t size () const;

  ///
  /// @param[in] coordinates Specified coordinates.
  /// @return Whether or not the specified coordinates are valid for this board.
  ///
  bool valid (const Coordinates & coordinates) const;

  ///
  /// @param[in] coordinates Specified coordinates.
  /// @return Pointer to the element at the specified coordinates.
  /// @throws std::runtime_error in case of invalid coordinates.
  ///
  std::shared_ptr<const Element> at (const Coordinates & coordinates) const;

  ///
  /// @param[in] start Starting coordinates.
  /// @param[in] destination Destination coordinates.
  /// @return Shortest path to the destination.
  /// @throws std::runtime_error in case of invalid coordinates.
  ///
  Path shortest_path (const Coordinates & start, const Coordinates & destination) const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif
