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

#include <gtest/gtest.h>

#include "valor/board.h"

#include "valor/clearing.h"
#include "valor/obstacle.h"
#include "valor/nourishment.h"
#include "valor/contestant.h"
#include "valor/resource.h"

using namespace valor;

class BoardTest : public ::testing::Test {
protected:
  // Initialize the board with the example from http://vindinium.org/starters.
  BoardTest () : size_(18), board_(
    size_,
    "##############        ##############"
    "##############        ##############"
    "################    ################"
    "##############$4    $4##############"
    "##############  @4    ##############"
    "##########  @1##    ##    ##########"
    "##########  []        []  ##########"
    "########        ####        ########"
    "############  $4####$4  ############"
    "############  $4####$4  ############"
    "########        ####        ########"
    "##########  []        []  ##########"
    "##########  @2##    ##@3  ##########"
    "##############        ##############"
    "##############$-    $-##############"
    "################    ################"
    "##############        ##############"
    "##############        ##############"
  ) {}

  std::size_t size_;
  Board board_;
};

TEST_F (BoardTest, HasTheCorrectSize) {
  ASSERT_EQ(size_, board_.size());
}

TEST_F (BoardTest, CorrectlyChecksCoordinateValidity) {
  ASSERT_TRUE(board_.valid({ 0, 0 }));
  ASSERT_TRUE(board_.valid({ size_ - 1, size_ - 1 }));
  ASSERT_TRUE(board_.valid({ size_ / 2, size_ / 2 }));
  ASSERT_FALSE(board_.valid({ 0, -1 }));
  ASSERT_FALSE(board_.valid({ -1, 0 }));
  ASSERT_FALSE(board_.valid({ size_, size_ }));
  ASSERT_FALSE(board_.valid({ size_, 0 }));
  ASSERT_FALSE(board_.valid({ 0, size_ }));
}

TEST_F (BoardTest, ContainsExpectedElementTypes) {
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Obstacle>(board_.at({ 0, 0 })));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Clearing>(board_.at({ 0, 7 })));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Resource>(board_.at({ 3, 7 })));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Contestant>(board_.at({ 4, 8 })));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Nourishment>(board_.at({ 6, 6 })));
}

std::ostream & operator << (std::ostream & stream, const Board::Path & path) {
  for (const Board::Coordinates & coordinates : path) {
    stream << "(" << coordinates.first << ", " << coordinates.second << ") ";
  }
  return stream;
}

TEST_F (BoardTest, FindsShortestPaths) {
  Board::Path path = board_.shortest_path({ 0, 0 }, { 0, 0 });
  ASSERT_TRUE(path.empty());

  path = board_.shortest_path({ 0, 0 }, { 0, 1 });
  ASSERT_TRUE(path.empty());

  path = board_.shortest_path({ 0, 7 }, { 0, 8 });
  ASSERT_EQ(1, path.size());
  ASSERT_EQ(Board::Coordinates(0, 8), path.back());

  path = board_.shortest_path({ 0, 7 }, { 3, 8 });
  ASSERT_EQ(4, path.size());
  ASSERT_EQ(Board::Coordinates(3, 8), path.back());

  path = board_.shortest_path({ 0, 7 }, { 4, 7 });
  ASSERT_TRUE(path.empty());

  path = board_.shortest_path({ 0, 7 }, { 5, 11 });
  ASSERT_EQ(15, path.size());
  ASSERT_EQ(Board::Coordinates(5, 11), path.back());
}
