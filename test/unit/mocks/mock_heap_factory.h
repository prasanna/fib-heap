#include "gmock/gmock.h"
#include "heap_factory.h"

#ifndef MOCK_HEAP_FACTORY
#define MOCK_HEAP_FACTORY

class MockHeapFactory : public HeapFactory {
 public:
  MOCK_METHOD0(create, Heap*());
};

#endif // MOCK_HEAP_FACTORY
