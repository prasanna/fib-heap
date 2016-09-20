#include "heap.h"

void Heap::add(int element) {
  this->element = element;
  if(size == 0 || element < min) {
    min = element;
  }
  size++;
}

int Heap::get() const {
  return element;
}

int Heap::rank() {
  return size-1;
}

int Heap::find_min() {
  return min;
}

Heap* Heap::children() {
  Heap *children = new Heap[2];
  children[0].add(2);
  children[1].add(3);
  return children;
}

Heap::Heap() {
  size = 0;
}


bool Heap::operator==( Heap const & other) const {return this->get() == other.get();}
bool Heap::operator!=(const Heap& other) {return !operator==(other);}
bool Heap::operator< (const Heap& other) {return this->get() < other.get();}
bool Heap::operator> (const Heap& other) {return  operator< (other);}
bool Heap::operator<=(const Heap& other) {return !operator> (other);}
bool Heap::operator>=(const Heap& other) {return !operator< (other);}
