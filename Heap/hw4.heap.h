#ifndef HEAP_H
#define HEAP_H
#define MAX_SIZE 2048

class Heap {
 public:
  Heap();
  void Push(int n);
  int Pop();
  void Print();
  // (a) [3 points] Print the first 4 rows of the heap in tree shape.
  // One line per row. Limit each line to 80 characters. Print left child to
  // the left of parent, right child to the right of parent.
  // Assume each item is 1 or 2 digit number. Example:
  //                         53
  //             29                       25
  //       11          28          21            12
  //    4     9    18
  void PrintTree();
  // (b) [4 points] Returns index of array if n is in heap. Returns -1
  // otherwise.
  int Find(int n);
  // (c) [3 points] Insert n into heap if not already on heap. Otherwise do
  // nothing.
  void InsertIfNotFound(int n);
 private:
  int get_parent_index(int i);
  int get_left_child_index(int i);
  int get_right_child_index(int i);
  void sift_down(int i);
  void swap(int i, int j);
  int data[MAX_SIZE];
  int size;
};

#endif
