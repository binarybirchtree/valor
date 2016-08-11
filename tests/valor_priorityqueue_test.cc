#include <gtest/gtest.h>

#include <valor_priorityqueue.h>

using namespace valor;

class PriorityQueueTest : public ::testing::Test {};

TEST_F (PriorityQueueTest, CanEmplaceAndRetrieve) {
  PriorityQueue<int> queue;
  ASSERT_TRUE(queue.empty());
  queue.emplace(123);
  ASSERT_FALSE(queue.empty());
  ASSERT_EQ(1, queue.size());
  ASSERT_EQ(123, queue.top());
}

TEST_F (PriorityQueueTest, CanEmplaceAndPop) {
  PriorityQueue<int> queue;
  queue.emplace(123);
  ASSERT_EQ(1, queue.size());
  queue.emplace(456);
  ASSERT_EQ(2, queue.size());
  queue.emplace(789);
  ASSERT_EQ(3, queue.size());
  queue.pop();
  ASSERT_EQ(2, queue.size());
}

TEST_F (PriorityQueueTest, HasTheCorrectOrdering) {
  PriorityQueue<int> queue;
  queue.emplace(456);
  ASSERT_EQ(456, queue.top());
  queue.emplace(789);
  ASSERT_EQ(789, queue.top());
  queue.emplace(123);
  ASSERT_EQ(789, queue.top());
  queue.pop();
  ASSERT_EQ(456, queue.top());
  queue.pop();
  ASSERT_EQ(123, queue.top());
}

TEST_F (PriorityQueueTest, ChecksContentsAccurately) {
  PriorityQueue<int> queue;
  ASSERT_FALSE(queue.contains(123));
  ASSERT_FALSE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
  queue.emplace(123);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_FALSE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
  queue.emplace(456);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_TRUE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
  queue.emplace(789);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_TRUE(queue.contains(456));
  ASSERT_TRUE(queue.contains(789));
  queue.pop();
  ASSERT_TRUE(queue.contains(123));
  ASSERT_TRUE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
}

TEST_F (PriorityQueueTest, ErasesCorrectly) {
  PriorityQueue<int> queue;
  ASSERT_FALSE(queue.contains(123));
  ASSERT_FALSE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
  queue.emplace(123);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_FALSE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
  queue.emplace(456);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_TRUE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
  queue.emplace(789);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_TRUE(queue.contains(456));
  ASSERT_TRUE(queue.contains(789));
  queue.erase(321);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_TRUE(queue.contains(456));
  ASSERT_TRUE(queue.contains(789));
  queue.erase(456);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_FALSE(queue.contains(456));
  ASSERT_TRUE(queue.contains(789));
  queue.erase(789);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_FALSE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
  queue.emplace(456);
  ASSERT_TRUE(queue.contains(123));
  ASSERT_TRUE(queue.contains(456));
  ASSERT_FALSE(queue.contains(789));
}
