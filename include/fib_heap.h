#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP

#include "priority_queue.h"

class FibonacciHeap : public PriorityQueue {
 public:
  FibonacciHeap();
  ~FibonacciHeap();
  virtual void insert(int);
  virtual int find_min();
  virtual void delete_min();
  virtual void delete_element(int);
};

#endif // FIBONACCI_HEAP
