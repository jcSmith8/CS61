#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;


void merge(int arr[], int start_ind, int mid, int len){ //make sure you pass mid as the starting position for the second sorted half
  int merged[len];
  int p0 = start_ind;
  int p1 = mid;
  int out_index = 0;
  while((p0 < mid) || (p1 < len-start_ind)){
    if(p0 >= mid){
      for(int i=out_index; out_index < len; out_index++){
          merged[i] = arr[p1];
          p1++;
        }
      }
      else if(p1 >= start_ind+len){
        for(int i=out_index; out_index < len; out_index++){
          merged[i] = arr[p1];
        p0++;
        }
    }
    else {
      if(arr[p0] < arr[p1]){
        merged[out_index] = arr[p0];
        p0++;
      }
      else{
        merged[out_index] = arr[p1];
        p1++;
      }
    }
    out_index++;
  }
for(int i=start_ind; i<len; i++){
  arr[i] = merged[i];
}
}

void mergeSort(int arr[], int start, int end){
  int len = end-start+1;
  if(len<=1){
    return;
  }
  int mid = start + len/2;
  mergeSort(arr,start,mid+1);
  mergeSort(arr,mid,end);
  merge(arr,start,mid,len);
}

int main (){
  int arr[11] = {2,4,3,6,1,9,7,8,0,5,10};
  mergeSort(arr,0,11);
  for(int i=0;i<11;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
