#include "heap.h"

#ifndef HEAP_FACTORY
#define HEAP_FACTORY

class HeapFactory {
 public:
  virtual ~HeapFactory() {};
  virtual Heap * create();
};

#endif // HEAP_FACTORY
