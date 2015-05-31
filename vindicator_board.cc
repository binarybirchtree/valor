#include <vindicator_board.h>

#include <algorithm>
#include <cassert>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <glog/logging.h>

#include <vindicator_elementfactory.h>

namespace vindicator {

class Board::Implementation {
public:
  Implementation (std::size_t size, const std::string & layout) : size_(size) {
    if (layout.size() != std::pow(size, 2) * ElementFactory::TYPE_SIZE) {
      std::stringstream message;
      message <<
        "Layout size of " << layout.size() <<
        " is inconsistent with board size of " << size
      << ".";
      LOG(ERROR) << message.str();
      throw std::runtime_error(message.str());
    }

    for (std::size_t row_index = 0; row_index < size; ++row_index) {
      Row row;
      for (
        std::size_t column_index = 0;
        column_index < size * ElementFactory::TYPE_SIZE;
        column_index += ElementFactory::TYPE_SIZE
      ) {
        // Get the current type identifier from the layout string.
        std::size_t layout_index = (row_index * size * ElementFactory::TYPE_SIZE) + column_index;
        ElementFactory::Type type;
        std::copy_n(layout.begin() + layout_index, ElementFactory::TYPE_SIZE, type.begin());

        // Create the appropriate element for the type.
        std::shared_ptr<Element> element = ElementFactory::create(type);
        if (!element) {
          std::stringstream message;
          message << "Could not create an element of type '" << type << "'.";
          LOG(ERROR) << message.str();
          throw std::runtime_error(message.str());
        }

        row.emplace_back(element);
      }

      assert(row.size() == size);
      board_.emplace_back(row);
    }

    assert(board_.size() == size);
  }

  std::size_t size () const {
    return size_;
  }

  bool valid (const Coordinates & coordinates) const {
    return coordinates.x < size_ && coordinates.y < size_;
  }

  ///
  /// @throws std::runtime_error if the provided coordinates are invalid for this board.
  ///
  void throw_if_invalid (const Coordinates & coordinates) const {
    if (!valid(coordinates)) {
      std::stringstream message;
      message <<
        "Coordinates " << coordinates <<
        " are invalid for a board of size " << size_
      << ".";
      LOG(ERROR) << message;
      throw std::runtime_error(message.str());
    }
  }

  std::shared_ptr<const Element> at (const Coordinates & coordinates) const {
    throw_if_invalid(coordinates);
    return board_[coordinates.x][coordinates.y];
  }

  Board::Path shortest_path (const Coordinates & start, const Coordinates & destination) const {
    throw_if_invalid(start);
    throw_if_invalid(destination);

    // Placeholder implementation.
    return Path();
  }

private:
  std::size_t size_;

  typedef std::vector<std::shared_ptr<Element> > Row;
  std::vector<Row> board_;
};

Board::Board (std::size_t size, const std::string & layout)
: impl_(std::make_shared<Implementation>(size, layout)) {}

std::size_t Board::size () const {
  return impl_->size();
}

bool Board::valid (const Coordinates & coordinates) const {
  return impl_->valid(coordinates);
}

std::shared_ptr<const Element> Board::at (const Coordinates & coordinates) const {
  return impl_->at(coordinates);
}

Board::Path Board::shortest_path (const Coordinates & start, const Coordinates & destination) const {
  return impl_->shortest_path(start, destination);
}

}
