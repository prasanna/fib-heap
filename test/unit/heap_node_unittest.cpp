#include <stdlib.h>
#include "gtest/gtest.h"
#include "heap_node.h"

TEST(HeapNodeTest, SingleNodeKnowsItsMin) {
  HeapNode * heap_node = new HeapNode();

  heap_node->add(1);

  EXPECT_EQ(1, heap_node->find_min());
}

TEST(HeapNodeTest, KnowsItsMinWhenMultipleElementsAreAdded) {
  HeapNode * heap_node = new HeapNode();

  heap_node->add(1);
  heap_node->add(2);

  EXPECT_EQ(1, heap_node->find_min());
}


TEST(HeapNodeTest, KnowsItsRankWhenMultipleElementsAreAdded) {
  HeapNode * heap_node = new HeapNode();

  heap_node->add(1);
  EXPECT_EQ(0, heap_node->rank());
  
  heap_node->add(2);
  EXPECT_EQ(1, heap_node->rank());
  
  heap_node->add(3);
  EXPECT_EQ(2, heap_node->rank());
}


TEST(HeapNodeTest, KnowsItsChildrenWhenMultipleElementsAreAdded) {
  HeapNode * heap_node = new HeapNode();
  heap_node->add(2);
  heap_node->add(1);
  heap_node->add(3);

  HeapNode expected_children[2];
  expected_children[0].add(2);
  expected_children[1].add(3);
  
  HeapNode *actual_children = heap_node->children();
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(expected_children[i], actual_children[i]) << "Expected and actual children differ at index " << i;
  }
}

TEST(HeapNodeTest, ChildrenIsAnEmptyArrayWhenThereAreNone) {
  HeapNode * heap_node = new HeapNode();
  HeapNode *actual_children = heap_node->children();
  EXPECT_EQ(0, sizeof(actual_children));
}
