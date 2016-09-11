#include "fib_heap.h"

void FibonacciHeap::insert(int element) {
  Tree * tree = tree_factory->create();
  tree->add(element);
  root_list->push_back(tree);
  if(min == NULL || tree->get() < min->get()) {
    min = tree;
  }
}

int FibonacciHeap::find_min() {
  return min->get();
}

void FibonacciHeap::delete_min() {
}

void FibonacciHeap::delete_element(int element) {

}

FibonacciHeap::FibonacciHeap(list<Tree *> * root_list, TreeFactory * tree_factory) {
  this->min = NULL;
  this->root_list = root_list;
  this->tree_factory = tree_factory;
}

FibonacciHeap::~FibonacciHeap() {
  delete tree_factory;
}
