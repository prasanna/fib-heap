#include "gtest/gtest.h"
#include "basic_priority_queue.h"

TEST(BasicPriorityQueueTest, MinOfQueueOfOneIsTheOneElement) {
  BasicPriorityQueue queue(2);

  queue.insert(1);

  EXPECT_TRUE(1 == queue.find_min());
}

TEST(BasicPriorityQueueTest, MinOfQueueOfThreeIsTheMinElement) {
  BasicPriorityQueue queue(4);

  queue.insert(30);
  queue.insert(10);
  queue.insert(20);

  EXPECT_TRUE(10 == queue.find_min());
}

TEST(BasicPriorityQueueTest, MinWorksWhenInitialMaxSizeIsLessThanEventualSize) {
  BasicPriorityQueue queue(2);

  queue.insert(20);
  queue.insert(30);
  queue.insert(10);

  EXPECT_TRUE(10 == queue.find_min());
}

TEST(BasicPriorityQueueTest, CanDeleteArbitraryElement) {
  BasicPriorityQueue queue(2);

  queue.insert(20);
  queue.insert(30);
  queue.insert(10);
  queue.delete_element(10);
  
  EXPECT_TRUE(20 == queue.find_min());
}


TEST(BasicPriorityQueueTest, CanDeleteMinimumElement) {
  BasicPriorityQueue queue(2);

  queue.insert(20);
  queue.insert(30);
  queue.insert(10);
  queue.insert(8);
  queue.delete_min();
  
  EXPECT_TRUE(10 == queue.find_min());
}
