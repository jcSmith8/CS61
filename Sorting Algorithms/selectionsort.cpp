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

void selectionSort(int arr[], int len){
  for(int i=0;i<len;i++){
    int smallest_ind = i;
    for(int j=i+1;j<len;j++){
      if(arr[j]<arr[smallest_ind]){
        smallest_ind = j;
      }
    }
    swap(arr,i,smallest_ind );
  }
}

int main(){
  int arr[10] = {2,4,3,6,1,9,7,8,0,5};
  selectionSort(arr,10);
  for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
