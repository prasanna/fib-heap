#include "tree_factory.h"

Tree * TreeFactory::create() {
  return new Tree();
}
