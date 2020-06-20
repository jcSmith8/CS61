#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
class MyQueue {
public:

  void _push(T val){
    if(_v.size()==0){
      _front==0;
      _v.push_back(val);
    } else {
      if(_v.size() < _size-1){
        _v[(_front+_size-1)%_v.size()] = val;
      } else {
        resize();
        _v[(_front+_size-1)%_v.size()] = val;
      }
    }
  }

  void resize(){
    _size = (_size*2)+1;
    for(int i=0;i<_front;i++){
      int temp = _v[i];
      _v.pushback(temp);
      _v.erase(_v.begin()+i);
    }
  }

  void pop(){
    _v.erase(_v.begin()+_front);
    if(_front<_size-1){
      _front++;
    } else {
      _front==0;
    }
  }
  T front(){
    return _v[_front];
  }
  size_t size(){
    return size;
  }

  bool empty(){
    if(_v.size() == 0){
      return true;
    } else {
      return false;
    }
  }
private:

  std::vector<T> _v;
  std::size_t _size;
  std::size_t _front;
};




int main()
{

std::queue<int> Q;

::queue<int> q;




srand(time(0));



for (int i = 0; i < 10000000; ++i)

{

int choice = rand() % 2;

int r;



switch(choice)

{

case 0:

if (!q.empty())

q.pop();

if (!Q.empty())

Q.pop();



break;



case 1:

r = rand();

q.push(r);

Q.push(r);

break;



default:

break;



}




// verify

assert(q.size() == Q.size() && q.empty() == Q.empty());

if  (!q.empty())

assert(q.front() == Q.front());

}



cout << "Passed!" << endl;



return 0;

}
