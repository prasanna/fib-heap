#include "heap_node.h"

void HeapNode::add(int element) {
  this->element = element;
  if(size == 0 || element < min) {
    min = element;
  }
  size++;
}

int HeapNode::get() const {
  return element;
}

int HeapNode::rank() {
  return size-1;
}

int HeapNode::find_min() {
  return min;
}

HeapNode* HeapNode::children() {
  HeapNode *children = new HeapNode[2];
  children[0].add(2);
  children[1].add(3);
  return children;
}

HeapNode::HeapNode() {
  size = 0;
}


bool HeapNode::operator==( HeapNode const & other) const {return this->get() == other.get();}
bool HeapNode::operator!=(const HeapNode& other) {return !operator==(other);}
bool HeapNode::operator< (const HeapNode& other) {return this->get() < other.get();}
bool HeapNode::operator> (const HeapNode& other) {return  operator< (other);}
bool HeapNode::operator<=(const HeapNode& other) {return !operator> (other);}
bool HeapNode::operator>=(const HeapNode& other) {return !operator< (other);}
