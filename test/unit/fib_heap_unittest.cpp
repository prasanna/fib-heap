#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "priority_queue_unittest.h"
#include "fib_heap.h"
#include "mocks/mock_tree_factory.h"

template <>
PriorityQueue* CreatePriorityQueue<FibonacciHeap>() {
return new FibonacciHeap(new MockTreeFactory());
}

typedef Types<FibonacciHeap> PriorityQueueImplementations;

/*
INSTANTIATE_TYPED_TEST_CASE_P(FibonacciHeapPriorityQueueTests,
			      PriorityQueueTest,
			      PriorityQueueImplementations);
*/

TEST(FibonacciHeapTest, CreatesNewTreeWhenInserting) {
  MockTreeFactory mock_tree_factory;

  EXPECT_CALL(mock_tree_factory, create()).Times(1);

  FibonacciHeap * fib_heap = new FibonacciHeap(&mock_tree_factory);
  fib_heap->insert(1);
}


