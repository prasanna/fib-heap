#include "tree.h"

#ifndef TREE_FACTORY
#define TREE_FACTORY

class TreeFactory {
 public:
  virtual ~TreeFactory() {};
  virtual Tree * create();
};

#endif // TREE_FACTORY
