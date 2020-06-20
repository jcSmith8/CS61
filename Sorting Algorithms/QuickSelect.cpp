#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;


void swap(int arr[], int ind1, int ind2){
  int temp = arr[ind1];
  arr[ind1] = arr[ind2];
  arr[ind2] = temp;
}

int Partition(int arr[], int start, int end){
  int last_smaller = start-1;
  for(int i=start; i<end; i++){
    if(arr[i]<arr[end]){
      swap(arr,last_smaller+1,i);
      last_smaller++;
    }
  }
  swap(arr,end,last_smaller+1);
  int length = end-start+1;
  return last_smaller+1;
}

double QuickSelect(int arr[],int lo,int hi,int k)
{
  if(lo==hi)
  {
    return arr[lo];
  }
  int pp = Partition(arr,lo,hi);
  int difference = pp - k;
  if(difference==0)
  {
    return arr[pp];
  }
  if(difference>0)
  {
    return QuickSelect(arr,lo,pp-1,k);
  }
  if(difference<0)
  {
    return QuickSelect(arr,pp+1,hi,k);
  }

}

int main(){
  int arr[20] = {2,6,5,4,9,1,7,10,3,8,11,12,13,14,15,16,17,18,19,20};
  cout<<QuickSelect(arr,0,20,10)<<endl;
}
