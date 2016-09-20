#include "priority_queue.h"
#include "heap_node_factory.h"
#include <list>

#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP

using namespace std;

class FibonacciHeap : public PriorityQueue {
 private:
  HeapNode * min;
  int size;
  list<HeapNode *> * root_list;
  HeapNodeFactory * heap_node_factory;
 public:
  FibonacciHeap(list<HeapNode *> *, HeapNodeFactory *);
  virtual ~FibonacciHeap();
  virtual void insert(int);
  virtual int  find_min();
  virtual void delete_min();
  virtual void delete_element(int);
};

#endif // FIBONACCI_HEAP
