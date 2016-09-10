#ifndef BASIC_PRIORITY_QUEUE
#define BASIC_PRIORITY_QUEUE

#include "priority_queue.h"

class BasicPriorityQueue : public PriorityQueue {
 private:
  int * elements;
  int max_size;
  int size;
  void double_size_of_elements();
  
 public:
  BasicPriorityQueue(int);
  ~BasicPriorityQueue();
  virtual void insert(int);
  virtual int find_min();
  virtual void delete_min();
  virtual void delete_element(int);
};

#endif // BASIC_PRIORITY_QUEUE
