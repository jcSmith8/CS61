#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


void swap(int arr[], int ind1, int ind2){
  int temp = arr[ind1];
  arr[ind1] = arr[ind2];
  arr[ind2] = temp;
}

class Heap {
private:
  int data[512];
  int size;
public:
  Heap(){
    size=0;
  }
  int get_left_child_index(int ind){
    return (ind*2)+1;
  }
  int get_right_child_index(int ind){
    return (ind*2)+2;
  }
  int get_parent_index(int ind){
    return (ind-1)/2;
  }

  //siftUp moves the object at <ind> up (towards ind=0) the array until it is in the correct spot
  void siftUp(int ind){
    int parent = get_parent_index(ind);
    int child = ind;
    while((child>0)&&(data[child]>data[parent])){
      swap(data,child,parent);
      child = parent;
      parent = get_parent_index(child);
    }
  }

  //heapify organizes any array into a heap
  void heapify(){
    int ind = get_parent_index(size-1);
    for(int i=ind;i>=0;i--){
      siftDown(i);
    }
  }

  //siftDown moves the object at <ind> down (towards ind=size) the array until it satisfies heap
  void siftDown(int ind){
    int parent = ind;
    int left_child = get_left_child_index(parent);
    int right_child = get_right_child_index(parent);
    if((left_child==size)||(right_child==size)){
      return;
    }
    if((data[left_child]>data[parent])||(data[right_child]>data[parent])){
      if(data[left_child]>data[right_child]){
        swap(data,left_child,parent);
        siftDown(left_child);
      } else {
        swap(data,right_child,parent);
        siftDown(right_child);
      }
    }
  }
  //removes last item of heap
  void pop(){
    data[0] = data[size-1];
    size--;
    print();
    siftDown(0);
  }
  void insert(int n){
    data[size] = n;
    size++;
    siftUp(size-1);
  }
  void print(){
    for(int i=0;i<size;i++){
      cout<<data[i]<<" ";
    }
    cout<<endl;
  }
  void insertNoOrder(int arr[],int size1){
    for(int i=0;i<size1;i++){
      data[i]=arr[i];
      size++;
    }
  }
};

int main(){
  /*Heap h;
  h.insert(10);
  h.print();
  h.insert(20);
  h.insert(25);
  h.insert(15);
  h.insert(100);
  h.insert(5);
  h.insert(30);
  h.print();
  h.pop();
  h.print();*/
  int arr1[10] = {3,6,4,8,5,1,9,10,7,2};
  Heap f;
  f.insertNoOrder(arr1,10);
  f.print();
  f.heapify();
  f.print();
  f.insert(7);
  f.print();
  f.insert(8);
  f.print();
  f.insert(12);
  f.print();
  return 0;
}
