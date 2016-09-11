#include "heap_node_factory.h"

HeapNode * HeapNodeFactory::create() {
  return new HeapNode();
}
