#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

void swap(int arr[],int ind1,int ind2){
  int temp = arr[ind1];
  arr[ind1] = arr[ind2];
  arr[ind2] = temp;;
}

void insertionSort(int arr[], int len){
  for(int i=0; i<len; i++){
    for(int j=i; j>0; j--){
      if(arr[j]<arr[j-1]){
        swap(arr,j,j-1);
      }
    }
  }
}

int main(){
  int arr[10] = {2,4,3,6,1,9,7,8,0,5};
  insertionSort(arr,10);
  for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
