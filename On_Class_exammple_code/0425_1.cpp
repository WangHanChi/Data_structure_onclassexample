#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main(){
  //using list
  list<int> b;
  b.push_back(3);
  b.push_back(8);
  b.push_front(5);
  b.push_front(7);
  b.pop_front();
  b.pop_back();
  b.front() = 9;
  cout << b.front() << ' ' << b.back() << endl;


  cout << "----------";

  //using deque
  deque<int> a;
  for(int i = 1; i <= 5; ++i){
    a.push_front(i);
  }
  for(int i = 0; i <a.size(); ++i){
    cout << a[i] << ' ';
    
  }
  cout << a.front() << endl;
  cout << a.back() << endl;
 return 0;
}
