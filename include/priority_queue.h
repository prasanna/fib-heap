#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

class PriorityQueue {
 public:
  virtual void insert(int) = 0;
  virtual int find_min() = 0;
  virtual void delete_min() = 0;
  virtual void delete_element(int) = 0;
};


#endif // PRIORITY_QUEUE
