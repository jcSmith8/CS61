#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stack>
#include <vector>
using namespace std;


void insertionRecursive(int a[],int len){
  if(len<=1){
    return;
  }
  insertionRecursive(a,len-1);

  int before = len-2;
  int last = a[len-1];
  while((before>=0)&&(a[before]>last)){
    a[before+1]=a[before];
    before--;
  }
  a[before+1] = last;
}

int findBinary(unsigned num){
    if (num == 0)
        return 0;
    else
        return (num % 2 + 10 * findBinary(num / 2));
}

string d2b(unsigned num){
  if(num <= 0){
    return 0;
  } else {
    return to_string(findBinary(num));
  }
}

void merge3(int A[], int lo, int mid1, int mid2, int hi){
  int merged[hi-lo];
  int p0 = lo;
  int p1 = mid1+1;
  int p2 = mid2+1;
  int out_index = 0;

  while((p0 < mid1) || (p1 < mid2) || (p2 < hi)){
    if((p0 >= mid1)&&(p1 >= mid2)){ //only values left in p2->hi
      for(int i=out_index; i<=hi-lo; i++){
        merged[out_index] = A[p2];
        p2++;
      }
    }
    else if((p1 >= mid2)&&(p2 >= hi)){ //only values left in p0->mid1
      for(int i=out_index; i<=hi-lo; i++){
        merged[out_index] = A[p0];
        p0++;
      }
    }
    else if((p0 >= mid1)&&(p2 >= hi)){ //only values left in p1->mid2
      for(int i=out_index; i<=hi-lo; i++){
        merged[out_index] = A[p1];
        p1++;
      }
    }
    else if(p0 >= mid1){
      if(A[p1] < A[p2]){
        merged[out_index] = A[p1];
        p1++;
      }
      else {
        merged[out_index] = A[p2];
        p2++;
      }
      out_index++;
    }
    else if(p2 >= hi){
      if(A[p1] < A[p0]){
        merged[out_index] = A[p1];
        p1++;
      }
      else {
        merged[out_index] = A[p0];
        p0++;
      }
      out_index++;;
    }
    else if(p1 >= mid2){
      if(A[p0] < A[p2]){
        merged[out_index] = A[p0];
        p0++;
      }
      else {
        merged[out_index] = A[p2];
        p2++;
      }
      out_index++;
    }
    else {
      if((A[p0] < A[p1]) && (A[p0] < A[p2])){
        merged[out_index] = A[p0];
        p0++;
      }
      else if((A[p1] < A[p0]) && (A[p1] < A[p2])){
        merged[out_index] = A[p1];
        p1++;
      }
      else {
        merged[out_index] = A[p2];
        p2++;
      }
    }
    out_index++;
  }
  for(int i=lo; i<hi; i++){
    A[i] = merged[i];
  }
}

void merge_sort_3(int A[],int lo,int hi){
  int len = hi-lo+1;
  if(len <= 1){
    return;
  }
  else{
    int mid1 = lo + (len/3);
    int mid2 = lo+((len/3)*2);
    merge_sort_3(A, lo, mid1-1);
    merge_sort_3(A, mid1, mid2-1);
    merge_sort_3(A, mid2, hi);
    merge3(A, lo, mid1, mid2, hi);
  }
}


int main(){
  int arr[10] = {2,4,3,6,1,9,7,8,0,5};
  insertionRecursive(arr,10);
  for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;

  int decimal_number = 10;
  cout<<d2b(decimal_number)<<endl;

  int arr2[10] = {2,4,3,6,1,9,7,8,0,5};
  merge3(arr2,0,3,6,9);
  for(int i=0;i<10;i++){
    cout<<arr2[i]<<" ";
  }
  cout<<endl;

  int arr3[10] = {2,4,3,6,1,9,7,8,0,5};
  merge_sort_3(arr3,0,9);
  for(int i=0;i<10;i++){
    cout<<arr3[i]<<" ";
  }
  cout<<endl;
}
