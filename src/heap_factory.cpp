#include "heap_factory.h"

Heap * HeapFactory::create() {
  return new Heap();
}
