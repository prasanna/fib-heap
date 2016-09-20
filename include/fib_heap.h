#include "priority_queue.h"
#include "heap_factory.h"
#include <list>

#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP

using namespace std;

class FibonacciHeap : public PriorityQueue {
 private:
  Heap * min;
  int size;
  list<Heap *> * root_list;
  HeapFactory * heap_factory;
 public:
  FibonacciHeap(list<Heap *> *, HeapFactory *);
  virtual ~FibonacciHeap();
  virtual void insert(int);
  virtual int  find_min();
  virtual void delete_min();
  virtual void delete_element(int);
};

#endif // FIBONACCI_HEAP
