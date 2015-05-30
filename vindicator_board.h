#ifndef INCLUDED_VINDICATOR_BOARD
#define INCLUDED_VINDICATOR_BOARD

#include <memory>

#include <vindicator_element.h>

namespace vindicator {

class Board {
public:
  Board (std::size_t size, const std::string & layout);

  ///
  /// @return Size of the board.
  ///
  std::size_t size () const;

private:
  class Implementation;
  std::shared_ptr<Implementation> impl_;
};

}

#endif
