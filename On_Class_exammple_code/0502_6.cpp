#include <iostream>
#include <queue>

using namespace std;


struct By_Num{
  bool operator() (int x, int y) const {
    return x%10 < y%10;
  }

};




int main(){
  
  priority_queue<int,deque<int>,By_Num() > foo;

  
  foo.push(15);
  foo.push(26);
  foo.push(33);
  foo.push(7);


  while(! foo.empty()){
    cout << foo.top() << " ";
    foo.pop();
  }

  cout << endl;

  return 0;
    
}
