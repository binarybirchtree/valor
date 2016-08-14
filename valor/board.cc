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

#include "valor/board.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stdexcept>
#include <vector>

#include <glog/logging.h>

#include "valor/elementfactory.h"
#include "valor/priorityqueue.h"

namespace valor {

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
    return coordinates.first >= 0
        && coordinates.first < static_cast<int>(size_)
        && coordinates.second >= 0
        && coordinates.second < static_cast<int>(size_);
  }

  std::shared_ptr<const Element> at (const Coordinates & coordinates) const {
    throw_if_invalid(coordinates);
    return board_[coordinates.first][coordinates.second];
  }

  Path shortest_path (const Coordinates & start, const Coordinates & destination) const {
    throw_if_invalid(start);
    throw_if_invalid(destination);

    if (start == destination) {
      return Path();
    }

    // Determine the shortest path using A* search.
    struct Location {
      Location (const Coordinates & coordinates, int total_cost = 0) : coordinates(coordinates), total_cost(total_cost) {}
      Coordinates coordinates;
      int total_cost;
    };

    struct CompareTotalCost {
      bool operator () (const Location & a, const Location & b) {
        return a.total_cost >= b.total_cost;
      }
    };

    struct CompareCoordinates {
      bool operator () (const Location & a, const Location & b) {
        return a.coordinates < b.coordinates;
      }
    };

    // Use the "Manhattan distance" as the heuristic, since diagonal moves are not allowed.
    auto heuristic = [] (const Coordinates & start, const Coordinates & destination) {
      return std::abs(start.first - destination.first) + std::abs(start.second - destination.second);
    };

    std::set<Coordinates> finished;
    PriorityQueue<Location, CompareTotalCost, CompareCoordinates> tentative;
    std::map<Coordinates, int> costs;
    std::map<Coordinates, Coordinates> previous;

    tentative.emplace(start, heuristic(start, destination));

    // A* search loop.
    while (!tentative.empty() && tentative.top().coordinates != destination) {
      // Choose the best location out of those that have been assessed.
      Coordinates current = tentative.top().coordinates;
      tentative.pop();
      finished.insert(current);

      // Assess all passable neighbors.
      for (Coordinates neighbor : passable_neighbors(current)) {
        int cost = costs[current] + 1;

        // Check if a path with a lower cost was found.
        if (tentative.contains(neighbor) && cost < costs[neighbor]) {
          tentative.erase(neighbor);
        }

        // Update values for this neighbor.
        if (!tentative.contains(neighbor) && finished.find(neighbor) == finished.end()) {
          costs[neighbor] = cost;
          tentative.emplace(neighbor, cost + heuristic(neighbor, destination));
          previous[neighbor] = current;
        }
      }
    }

    // Construct the shortest path (working backwards from the destination)
    // by following the entries in the previous coordinates map.
    Path path;
    for (
      Coordinates current = destination;
      current != start;
      current = previous[current]
    ) {
      if (previous.find(current) == previous.end()) {
        LOG(WARNING) << "No path to destination found.";
        return Path();
      }
      path.emplace_back(current);
    }
    std::reverse(path.begin(), path.end());
    return path;
  }

private:
  std::size_t size_;

  typedef std::vector<std::shared_ptr<Element> > Row;
  std::vector<Row> board_;

  ///
  /// @throws std::runtime_error if the provided coordinates are invalid for this board.
  ///
  void throw_if_invalid (const Coordinates & coordinates) const {
    if (!valid(coordinates)) {
      std::stringstream message;
      message <<
        "Coordinates " << coordinates.first << ", " << coordinates.second <<
        " are invalid for a board of size " << size_
      << ".";
      LOG(ERROR) << message.str();
      throw std::runtime_error(message.str());
    }
  }

  ///
  /// @param[in] coordinates Specified coordinates.
  /// @return Set of coordinates that neighbor the specified coordinates and are passable.
  ///
  std::set<Coordinates> passable_neighbors (const Coordinates & coordinates) const {
    std::set<Coordinates> output;
    typedef std::pair<int, int> Offset;
    static const std::set<Offset> offsets = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
    for (const Offset & offset : offsets) {
      Coordinates neighbor(coordinates.first + offset.first, coordinates.second + offset.second);
      if (valid(neighbor) && board_[neighbor.first][neighbor.second]->passable()) {
        output.emplace(neighbor);
      }
    }
    return output;
  }
};

Board::Board (std::size_t size, const std::string & layout)
: impl_(std::make_unique<Implementation>(size, layout)) {}

Board::Board (Board &&) = default;
Board & Board::operator = (Board &&) = default;
Board::~Board () = default;

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
