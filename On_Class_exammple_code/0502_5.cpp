#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(){
  list<int> foo = {3,2,4,6};
  for(auto i = foo.begin();i != foo.end(); ++i ){
    cout << *i << " ";
  }
  cout << endl;

  for(auto x : foo){
    cout << x << " ";
  }

  cout << endl;
}
