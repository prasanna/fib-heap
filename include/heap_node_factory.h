#include "heap_node.h"

#ifndef HEAP_NODE_FACTORY
#define HEAP_NODE_FACTORY

class HeapNodeFactory {
 public:
  virtual ~HeapNodeFactory() {};
  virtual HeapNode * create();
};

#endif // HEAP_NODE_FACTORY
