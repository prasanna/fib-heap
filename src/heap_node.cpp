#include "heap_node.h"

void HeapNode::add(int element) {
  this->element = element;
}

int HeapNode::get() {
  return element;
}
