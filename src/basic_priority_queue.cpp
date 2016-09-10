#include <iostream>
#include "basic_priority_queue.h"

void BasicPriorityQueue::insert(int element) {
  if(size < max_size) {
    elements[size] = element;
    size++;
  } else {
    double_size_of_elements();
    insert(element);
  }
}

int BasicPriorityQueue::find_min() {
  int min = elements[0];
  for(int i = 0; i < size; i++) {
    if(elements[i] < min) {
      min = elements[i];
    }
  }
  return min;
}

void BasicPriorityQueue::delete_min() {
  delete_element(find_min());
}

void BasicPriorityQueue::delete_element(int element) {
  bool element_found = false;
  for(int i = 0; i < size; i++) {
    if(elements[i] == element) {
      element_found = true;
      size -= 1;
    }
    if(element_found && i < size) {
      elements[i] = elements[i+1];
    }
  }
}

void BasicPriorityQueue::double_size_of_elements() {
  max_size = max_size * 2;
  int * new_elements = new int[max_size];
  for(int i = 0; i < size; i++) {
    new_elements[i] = elements[i];
  }
  delete elements;
  elements = new_elements;
}

BasicPriorityQueue::BasicPriorityQueue(int initial_max_size) {
  max_size = initial_max_size;
  size = 0;
  elements = new int[max_size];
}

