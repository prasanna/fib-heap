#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "priority_queue_unittest.h"
#include "fib_heap.h"
#include "mocks/mock_heap_node_factory.h"

using ::testing::Return;

template <>
PriorityQueue* CreatePriorityQueue<FibonacciHeap>() {
return new FibonacciHeap(new list<HeapNode *>(), new HeapNodeFactory());
}

typedef Types<FibonacciHeap> PriorityQueueImplementations;

INSTANTIATE_TYPED_TEST_CASE_P(FibonacciHeapPriorityQueueTests,
			      PriorityQueueTest,
			      PriorityQueueImplementations);


TEST(FibonacciHeapTest, CreatesNewHeapNodeWhenInserting) {
  MockHeapNodeFactory mock_heap_node_factory;
  list<HeapNode *> * root_list = new list<HeapNode *>();
  HeapNode * heap_node = new HeapNode();

  EXPECT_CALL(mock_heap_node_factory, create()).WillOnce(Return(heap_node));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_heap_node_factory);
  fib_heap->insert(1);
}

TEST(FibonacciHeapTest, AddsNewlyCreatedHeapNodeToRootList) {
  MockHeapNodeFactory mock_heap_node_factory;
  list<HeapNode *> * root_list = new list<HeapNode *>();
  HeapNode * heap_node = new HeapNode();

  EXPECT_CALL(mock_heap_node_factory, create()).WillOnce(Return(heap_node));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_heap_node_factory);
  fib_heap->insert(1);

  EXPECT_EQ(heap_node, root_list->front());
}

TEST(FibonacciHeapTest, ElementIsAddedToNewlyCreatedHeapNode) {
  MockHeapNodeFactory mock_heap_node_factory;
  list<HeapNode *> * root_list = new list<HeapNode *>();
  HeapNode * heap_node = new HeapNode();

  EXPECT_CALL(mock_heap_node_factory, create()).WillOnce(Return(heap_node));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_heap_node_factory);
  fib_heap->insert(1);

  EXPECT_EQ(1, heap_node->get());
}
