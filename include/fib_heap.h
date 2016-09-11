#include "priority_queue.h"
#include "tree_factory.h"
#include <list>

#ifndef FIBONACCI_HEAP
#define FIBONACCI_HEAP

using namespace std;

class FibonacciHeap : public PriorityQueue {
 private:
  Tree * min;
  list<Tree *> * root_list;
  TreeFactory * tree_factory;
 public:
  FibonacciHeap(list<Tree *> *, TreeFactory *);
  virtual ~FibonacciHeap();
  virtual void insert(int);
  virtual int  find_min();
  virtual void delete_min();
  virtual void delete_element(int);
};

#endif // FIBONACCI_HEAP
