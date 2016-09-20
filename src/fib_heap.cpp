#include "fib_heap.h"

void FibonacciHeap::insert(int element) {
  Heap * heap = heap_factory->create();
  heap->add(element);
  root_list->push_back(heap);
  if(size == 0 || heap->get() < min->get()) {
    min = heap;
  }
  size++;
}

int FibonacciHeap::find_min() {
  return min->get();
}

void FibonacciHeap::delete_min() {
  for(list<Heap *>::const_iterator iterator = root_list->begin();
      iterator != root_list->end(); ++iterator) {
    
  }
}

void FibonacciHeap::delete_element(int element) {

}

FibonacciHeap::FibonacciHeap(list<Heap *> * root_list, HeapFactory * heap_factory) {
  this->min = 0;
  this->size = 0;
  this->root_list = root_list;
  this->heap_factory = heap_factory;
}

FibonacciHeap::~FibonacciHeap() {
  delete heap_factory;
}
