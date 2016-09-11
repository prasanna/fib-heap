#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "priority_queue_unittest.h"
#include "fib_heap.h"
#include "mocks/mock_tree_factory.h"

using ::testing::Return;

template <>
PriorityQueue* CreatePriorityQueue<FibonacciHeap>() {
return new FibonacciHeap(new list<Tree *>(), new MockTreeFactory());
}

typedef Types<FibonacciHeap> PriorityQueueImplementations;

/*
INSTANTIATE_TYPED_TEST_CASE_P(FibonacciHeapPriorityQueueTests,
			      PriorityQueueTest,
			      PriorityQueueImplementations);
*/

TEST(FibonacciHeapTest, CreatesNewTreeWhenInserting) {
  MockTreeFactory mock_tree_factory;
  list<Tree *> * root_list = new list<Tree *>();
  Tree * tree = new Tree();

  EXPECT_CALL(mock_tree_factory, create()).WillOnce(Return(tree));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_tree_factory);
  fib_heap->insert(1);
}

TEST(FibonacciHeapTest, AddsNewlyCreatedTreeToRootList) {
  MockTreeFactory mock_tree_factory;
  list<Tree *> * root_list = new list<Tree *>();
  Tree * tree = new Tree();

  EXPECT_CALL(mock_tree_factory, create()).WillOnce(Return(tree));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_tree_factory);
  fib_heap->insert(1);

  EXPECT_EQ(tree, root_list->front());
}

TEST(FibonacciHeapTest, ElementIsAddedToNewlyCreatedTree) {
  MockTreeFactory mock_tree_factory;
  list<Tree *> * root_list = new list<Tree *>();
  Tree * tree = new Tree();

  EXPECT_CALL(mock_tree_factory, create()).WillOnce(Return(tree));

  FibonacciHeap * fib_heap = new FibonacciHeap(root_list, &mock_tree_factory);
  fib_heap->insert(1);

  EXPECT_EQ(1, tree->get());
}
