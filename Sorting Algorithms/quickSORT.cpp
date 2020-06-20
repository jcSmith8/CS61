#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

//swaps two indices in an array
void swap(int arr[], int ind1, int ind2){
  int temp = arr[ind1];
  arr[ind1] = arr[ind2];
  arr[ind2] = temp;
}
int compares = 0;
//Partition point = last value in the (not already sorted) array
//reorganizes values in array until partition index is in the right spot
int Partition(int arr[], int start, int end){
  int last_smaller = start-1;
  for(int i=start; i<end; i++){
    compares++;
    if(arr[i]<arr[end]){
      swap(arr,last_smaller+1,i);
      last_smaller++;
    }
  }
  swap(arr,end,last_smaller+1);
  int length = end-start+1;
  for(int i=0;i<length;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return last_smaller+1;
}

//recursive call to Partition, stops when there are no more values to swap
void QuickSort(int arr[], int start, int end){
  int len = end-start+1;
  if(len<=1){
    return;
  }
  int p = Partition(arr,start,end);
  QuickSort(arr,start,p-1);
  QuickSort(arr,p+1,end);
}


//test main
int main(){

  int arr[4] = {2,4,3,1};
  for(int i=0;i<4;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  QuickSort(arr,0,3);
  for(int i=0;i<4;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  cout<<compares<<endl;
}
