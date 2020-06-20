#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class HashTable{
private:
  int data[512];
public:
  HashTable(){
    for(int i=0;i<512;i++){
      data[i] = -1;
    }
  }
  int Hash(int n){
    return n % 512;
  }
  void insert(int m){
    int ind = Hash(m);
    for(int i=0;i<512;i++){
      int try_ind = ind+i;
      if(data[try_ind%512]<0){
        data[try_ind%512]=m;
        break;
      }
    }
  }
  int Find(int d){
    int ind = Hash(d);
    for(int i=0;i<512;i++){
      int try_ind = (ind + 1) % 512;
      if(data[try_ind]==d){
        return try_ind;
      }
    }
    return 0;
  }
  void Remove(int index){
    data[index] = -2;
  }
  void Delete(int d){
    int ind = Find(d);
    if(ind >= 0){
      Remove(ind);
    }
  }
};
