#include <vindicator_board.h>

#include <cmath>
#include <stdexcept>
#include <vector>

#include <glog/logging.h>

#include <vindicator_elementfactory.h>

namespace vindicator {

class Board::Implementation {
public:
  Implementation (std::size_t size, const std::string & layout) {
    if (layout.size() != std::pow(size, 2) * 2) {
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
      for (std::size_t column_index = 0; column_index < size; ++column_index) {
        std::size_t layout_index = row_index * size + column_index;
        std::string type = layout.substr(layout_index, layout_index + 2);
        std::shared_ptr<Element> element = ElementFactory::create(type);
        if (!element) {
          std::stringstream message;
          message <<
            "Could not create an element of type '" << type
          << "'.";
          LOG(ERROR) << message.str();
          throw std::runtime_error(message.str());
        }
        row.emplace_back(*element);
      }
      board_.emplace_back(row);
    }
  }

  std::size_t size () const {
    return board_.size();
  }

private:
  typedef std::vector<Element> Row;
  std::vector<Row> board_;
};

Board::Board (std::size_t size, const std::string & layout)
: impl_(std::make_shared<Implementation>(size, layout)) {}

std::size_t Board::size () const {
  return impl_->size();
}

}
