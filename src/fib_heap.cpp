#include "fib_heap.h"

void FibonacciHeap::insert(int element) {
  HeapNode * heap_node = heap_node_factory->create();
  heap_node->add(element);
  root_list->push_back(heap_node);
  if(size == 0 || heap_node->get() < min->get()) {
    min = heap_node;
  }
  size++;
}

int FibonacciHeap::find_min() {
  return min->get();
}

void FibonacciHeap::delete_min() {
  for(list<HeapNode *>::const_iterator iterator = root_list->begin();
      iterator != root_list->end(); ++iterator) {
    
  }
}

void FibonacciHeap::delete_element(int element) {

}

FibonacciHeap::FibonacciHeap(list<HeapNode *> * root_list, HeapNodeFactory * heap_node_factory) {
  this->min = 0;
  this->size = 0;
  this->root_list = root_list;
  this->heap_node_factory = heap_node_factory;
}

FibonacciHeap::~FibonacciHeap() {
  delete heap_node_factory;
}
