#ifndef INCLUDED_VINDICATOR_BOARD
#define INCLUDED_VINDICATOR_BOARD

#include <iostream>
#include <memory>
#include <vector>

#include <vindicator_element.h>

namespace vindicator {

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
