#include "gtest/gtest.h"
#include "priority_queue_unittest.h"
#include "fib_heap.h"

template <>
PriorityQueue* CreatePriorityQueue<FibonacciHeap>() {
  return new FibonacciHeap();
}

typedef Types<FibonacciHeap> PriorityQueueImplementations;

INSTANTIATE_TYPED_TEST_CASE_P(FibonacciHeapPriorityQueueTests,
			      PriorityQueueTest,
			      PriorityQueueImplementations);


