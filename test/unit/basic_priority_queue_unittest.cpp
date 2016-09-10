#include "gtest/gtest.h"
#include "priority_queue_unittest.h"
#include "basic_priority_queue.h"

template <>
PriorityQueue* CreatePriorityQueue<BasicPriorityQueue>() {
  return new BasicPriorityQueue(2);
}

typedef Types<BasicPriorityQueue> PriorityQueueImplementations;

INSTANTIATE_TYPED_TEST_CASE_P(BasicPQ,
			      PriorityQueueTest,
			      PriorityQueueImplementations);

