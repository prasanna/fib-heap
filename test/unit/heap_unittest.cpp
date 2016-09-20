#include <stdlib.h>
#include "gtest/gtest.h"
#include "heap.h"

TEST(HeapTest, SingleHeapKnowsItsMin) {
  Heap * heap = new Heap();

  heap->add(1);

  EXPECT_EQ(1, heap->find_min());
}

TEST(HeapTest, KnowsItsMinWhenMultipleElementsAreAdded) {
  Heap * heap = new Heap();

  heap->add(1);
  heap->add(2);

  EXPECT_EQ(1, heap->find_min());
}


TEST(HeapTest, KnowsItsRankWhenMultipleElementsAreAdded) {
  Heap * heap = new Heap();

  heap->add(1);
  EXPECT_EQ(0, heap->rank());
  
  heap->add(2);
  EXPECT_EQ(1, heap->rank());
  
  heap->add(3);
  EXPECT_EQ(2, heap->rank());
}


TEST(HeapTest, KnowsItsChildrenWhenMultipleElementsAreAdded) {
  Heap * heap = new Heap();
  heap->add(2);
  heap->add(1);
  heap->add(3);

  Heap expected_children[2];
  expected_children[0].add(2);
  expected_children[1].add(3);
  
  Heap *actual_children = heap->children();
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(expected_children[i], actual_children[i]) << "Expected and actual children differ at index " << i;
  }
}

TEST(HeapTest, ChildrenIsAnEmptyArrayWhenThereAreNone) {
  Heap * heap = new Heap();
  Heap *actual_children = heap->children();
  EXPECT_EQ(0, sizeof(actual_children));
}
