
#include <iostream>
#include <cmath>
#include "hw4.heap.h"

using namespace std;

Heap::Heap() {
  size = 0;
}

void Heap::PrintTree(){
  int spacing = 8;
  int spacingInside = 2;
  for(int a=0; a<spacing-1; a++){
    cout<<" ";
  }
  cout<<data[0]<<endl;
  int numParents = 1;
  int j;
  for(int i=0; i<6; i=j){
    for(j=i; j<numParents+i;j++){
      for(int j=0; j<spacing/2; j++){
        cout<<" ";
      }
      cout<< data[get_left_child_index(j)];
      for(int k=0; k<(spacing/2)+spacingInside; k++){
        cout<<" ";
      }
      cout<<data[get_right_child_index(j)];
    }
    cout<<endl;
    numParents*=2;
    spacing/=2;
    spacingInside--;
  }
}

int Heap::Find(int n){
  for(int i=0;i<=size;i++){
    if(data[i]==n){
      return true;
    }
  }
  return false;
}

// (b) [4 points] Returns index of array if n is in heap. Returns -1
// otherwise.

void Heap::Push(int n) {
  if (size >= MAX_SIZE) return;
  data[size] = n;
  // Sift up.
  int child = size;
  int parent = get_parent_index(child);
  // While not at top of heap and parent smaller than child, sift up.
  while ((child > 0) && (data[child] > data[parent])) {
    swap(parent, child);
    child = parent;
    parent = get_parent_index(child);
  }
  size++;
}

void Heap::InsertIfNotFound(int n){
  if(Find(n)){
    return;
  } else {
    Push(n);
  }
}

// (c) [3 points] Insert n into heap if not already on heap. Otherwise do
// nothing.


int Heap::Pop() {
  if (size == 0) return 0;
  int top = data[0];
  swap(0, size - 1);
  size--;
  sift_down(0);
  return top;
}

void Heap::Print() {
  for (int i = 0; i < size; i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

int Heap::get_parent_index(int i) {
  return (i - 1) / 2;
}

int Heap::get_left_child_index(int i) {
  return 2 * i + 1;
}

int Heap::get_right_child_index(int i) {
  return 2 * i + 2;
}

void Heap::swap(int i, int j) {
  int temp = data[i];
  data[i] = data[j];
  data[j] = temp;
}

void Heap::sift_down(int i) {
  cout << "sift down: " << i << endl;
  int parent = i;
  while (parent < size) {
    cout << "sift down parent: " << parent << endl;
    int left_child = get_left_child_index(parent);
    int right_child = get_right_child_index(parent);
    int left_child_val = 0;
    if (left_child < size) left_child_val = data[left_child];
    int right_child_val = 0;
    if (right_child < size) right_child_val = data[right_child];
    if ((left_child_val <= data[parent]) &&
        (right_child_val <= data[parent])) {
      break;
    }
    if (left_child_val > right_child_val) {
      swap(left_child, parent);
      parent = left_child;
    } else {
      swap(right_child, parent);
      parent = right_child;
    }
  }
  Print();
}

int main(){
  Heap h;
  for(int i=0;i<15;i++){
    h.Push(i);
  }
  h.Print();
  cout<<endl;
  h.PrintTree();
  cout<<endl;
  cout<<h.Find(11)<<"   "<<h.Find(20)<<endl;
  h.InsertIfNotFound(12);
  h.InsertIfNotFound(25);
  h.Print();
  h.InsertIfNotFound(-2);
  h.Print();
  return 0;
}
