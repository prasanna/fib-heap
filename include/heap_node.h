#ifndef HEAP_NODE
#define HEAP_NODE

class HeapNode {
 private:
  int size;
  int min;
  int element;
 public:
  HeapNode();
  void add(int);
  int get() const;
  int rank();
  int find_min();
  HeapNode* children();

  bool operator==( HeapNode const & other) const;
  bool operator!=(const HeapNode&);
  bool operator< (const HeapNode&);
  bool operator> (const HeapNode&);
  bool operator<=(const HeapNode&);
  bool operator>=(const HeapNode&);
};

#endif // HEAP_NODE
