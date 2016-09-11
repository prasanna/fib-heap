#include "gmock/gmock.h"
#include "tree_factory.h"

#ifndef MOCK_TREE_FACTORY
#define MOCK_TREE_FACTORY

class MockTreeFactory : public TreeFactory {
 public:
  MOCK_METHOD0(create, Tree*());
};

#endif // MOCK_TREE_FACTORY
