#include "fib_heap.h"

void FibonacciHeap::insert(int element) {
  tree_factory->create();
}

int FibonacciHeap::find_min() {
  return 1;
}

void FibonacciHeap::delete_min() {
}

void FibonacciHeap::delete_element(int element) {

}

FibonacciHeap::FibonacciHeap(TreeFactory * tree_factory) {
  this->tree_factory = tree_factory;
}

FibonacciHeap::~FibonacciHeap() {
  delete tree_factory;
}
