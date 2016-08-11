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
