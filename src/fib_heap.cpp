#include "fib_heap.h"

void FibonacciHeap::insert(int element) {
  Tree * tree = tree_factory->create();
  tree->add(element);
  root_list->push_back(tree);
}

int FibonacciHeap::find_min() {
  return 1;
}

void FibonacciHeap::delete_min() {
}

void FibonacciHeap::delete_element(int element) {

}

FibonacciHeap::FibonacciHeap(list<Tree *> * root_list, TreeFactory * tree_factory) {
  this->root_list = root_list;
  this->tree_factory = tree_factory;
}

FibonacciHeap::~FibonacciHeap() {
  delete tree_factory;
}
