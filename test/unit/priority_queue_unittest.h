#include "gtest/gtest.h"
#include "priority_queue.h"

using testing::Types;

template <class T>
PriorityQueue* CreatePriorityQueue();

template <class T>
class PriorityQueueTest : public testing::Test {
 protected:
  PriorityQueueTest() : queue(CreatePriorityQueue<T>()) {}

  virtual ~PriorityQueueTest() { delete queue; }

  PriorityQueue* const queue;
};

TYPED_TEST_CASE_P(PriorityQueueTest);

TYPED_TEST_P(PriorityQueueTest, MinOfQueueOfOneIsTheOneElement) {
  this->queue->insert(1);

  EXPECT_TRUE(1 == this->queue->find_min());
}

TYPED_TEST_P(PriorityQueueTest, MinOfQueueOfThreeIsTheMinElement) {
  this->queue->insert(30);
  this->queue->insert(10);
  this->queue->insert(20);

  EXPECT_TRUE(10 == this->queue->find_min());
}

TYPED_TEST_P(PriorityQueueTest, MinWorksWhenInitialMaxSizeIsLessThanEventualSize) {
  this->queue->insert(20);
  this->queue->insert(30);
  this->queue->insert(10);

  EXPECT_TRUE(10 == this->queue->find_min());
}

TYPED_TEST_P(PriorityQueueTest, CanDeleteArbitraryElement) {
  this->queue->insert(20);
  this->queue->insert(30);
  this->queue->insert(10);
  this->queue->delete_element(10);
  
  EXPECT_TRUE(20 == this->queue->find_min());
}


TYPED_TEST_P(PriorityQueueTest, CanDeleteMinimumElement) {
  this->queue->insert(20);
  this->queue->insert(30);
  this->queue->insert(10);
  this->queue->insert(8);
  this->queue->delete_min();
  
  EXPECT_TRUE(10 == this->queue->find_min());
}


REGISTER_TYPED_TEST_CASE_P(
  PriorityQueueTest,
  MinOfQueueOfOneIsTheOneElement, MinOfQueueOfThreeIsTheMinElement, MinWorksWhenInitialMaxSizeIsLessThanEventualSize, CanDeleteArbitraryElement, CanDeleteMinimumElement);
