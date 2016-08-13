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

#include "valor/elementfactory.h"

#include "valor/clearing.h"
#include "valor/obstacle.h"
#include "valor/nourishment.h"
#include "valor/contestant.h"
#include "valor/resource.h"

using namespace valor;

class ElementFactoryTest : public ::testing::Test {};

TEST_F (ElementFactoryTest, CreatesExpectedElementTypes) {
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Obstacle>(ElementFactory::create({{'#', '#'}})));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Clearing>(ElementFactory::create({{' ', ' '}})));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Resource>(ElementFactory::create({{'$', '-'}})));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Resource>(ElementFactory::create({{'$', '1'}})));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Contestant>(ElementFactory::create({{'@', '1'}})));
  ASSERT_NE(nullptr, std::dynamic_pointer_cast<const Nourishment>(ElementFactory::create({{'[', ']'}})));
}

TEST_F (ElementFactoryTest, CreatesElementsWithCorrectOwners) {
  std::shared_ptr<Element> obstacle = ElementFactory::create({{'#', '#'}});
  ASSERT_EQ(0, obstacle->owner());

  std::shared_ptr<Element> clearing = ElementFactory::create({{' ', ' '}});
  ASSERT_EQ(0, clearing->owner());

  std::shared_ptr<Element> resource = ElementFactory::create({{'$', '-'}});
  ASSERT_EQ(0, resource->owner());

  std::shared_ptr<Element> resource_1 = ElementFactory::create({{'$', '1'}});
  ASSERT_EQ(1, resource_1->owner());

  std::shared_ptr<Element> contestant_1 = ElementFactory::create({{'@', '1'}});
  ASSERT_EQ(1, contestant_1->owner());

  std::shared_ptr<Element> nourishment = ElementFactory::create({{'[', ']'}});
  ASSERT_EQ(0, nourishment->owner());
}
