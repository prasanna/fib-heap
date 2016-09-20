#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "priority_queue_unittest.h"
#include "fib_heap.h"
#include "mocks/mock_heap_factory.h"

using ::testing::Return;

template <>
PriorityQueue* CreatePriorityQueue<FibonacciHeap>() {
return new FibonacciHeap(new list<Heap *>(), new HeapFactory());
}

typedef Types<FibonacciHeap> PriorityQueueImplementations;

INSTANTIATE_TYPED_TEST_CASE_P(FibonacciHeapPriorityQueueTests,
			      PriorityQueueTest,
			      PriorityQueueImplementations);


TEST(FibonacciHeapTest, CreatesNewHeapWhenInserting) {
  MockHeapFactory mock_heap_factory;
  list<Heap *> * root_list = new list<Heap *>();
  Heap * heap = new Heap();

  EXPECT_CALL(mock_heap_factory, create()).WillOnce(Return(heap));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_heap_factory);
  fib_heap->insert(1);
}

TEST(FibonacciHeapTest, AddsNewlyCreatedHeapToRootList) {
  MockHeapFactory mock_heap_factory;
  list<Heap *> * root_list = new list<Heap *>();
  Heap * heap = new Heap();

  EXPECT_CALL(mock_heap_factory, create()).WillOnce(Return(heap));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_heap_factory);
  fib_heap->insert(1);

  EXPECT_EQ(heap, root_list->front());
}

TEST(FibonacciHeapTest, ElementIsAddedToNewlyCreatedHeap) {
  MockHeapFactory mock_heap_factory;
  list<Heap *> * root_list = new list<Heap *>();
  Heap * heap = new Heap();

  EXPECT_CALL(mock_heap_factory, create()).WillOnce(Return(heap));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_heap_factory);
  fib_heap->insert(1);

  EXPECT_EQ(1, heap->get());
}
