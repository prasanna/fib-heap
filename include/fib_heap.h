#include "priority_queue.h"
#include "tree_factory.h"

#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP

class FibonacciHeap : public PriorityQueue {
 private:
  TreeFactory * tree_factory;
 public:
  FibonacciHeap(TreeFactory *);
  virtual ~FibonacciHeap();
  virtual void insert(int);
  virtual int  find_min();
  virtual void delete_min();
  virtual void delete_element(int);
};

#endif // FIBONACCI_HEAP
