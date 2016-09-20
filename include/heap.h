#ifndef HEAP
#define HEAP

class Heap {
 private:
  int size;
  int min;
  int element;
 public:
  Heap();
  void add(int);
  int get() const;
  int rank();
  int find_min();
  Heap* children();

  bool operator==( Heap const & other) const;
  bool operator!=(const Heap&);
  bool operator< (const Heap&);
  bool operator> (const Heap&);
  bool operator<=(const Heap&);
  bool operator>=(const Heap&);
};

#endif // HEAP
