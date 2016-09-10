#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP

#include "priority_queue.h"

class FibonacciHeap : public PriorityQueue {
 private:
  int x;

 public:
  FibonacciHeap() : x(0) {}
  int X();
};

#endif // FIBONACCI_HEAP
