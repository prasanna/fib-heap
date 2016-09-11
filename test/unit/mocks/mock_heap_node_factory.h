#include "gmock/gmock.h"
#include "heap_node_factory.h"

#ifndef MOCK_HEAP_NODE_FACTORY
#define MOCK_HEAP_NODE_FACTORY

class MockHeapNodeFactory : public HeapNodeFactory {
 public:
  MOCK_METHOD0(create, HeapNode*());
};

#endif // MOCK_HEAP_NODE_FACTORY
