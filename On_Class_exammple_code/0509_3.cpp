#include <iostream>
#include <set>
using namespace std;


struct by_last_digital{
  bool operator() (int a, int b)const {
    return a%10 < b%10;
  }

};


int main(){
  int a[] = {33,51,62,26,14,2,91,37,54, 87, 65};

  //set<int, greater<int> > foo( a, a+8);
  multiset<int, by_last_digital> foo(a,a+8);

  
  for(auto itr = foo.begin(); itr!=foo.end(); ++itr){
  cout << *itr << " ";
  }
  cout <<endl;


  int n ;

  typedef multiset<int, by_last_digital >::iterator MITER;
  //pair<MITER, MITER> iters;
  
  while(cin >> n){
    auto iters = foo.equal_range(n);
    //pair iters = foo.equal_range(n);
    for(auto iter = iters.first; iter != iters.second; ++iter){
      cout << *iter << " ";

      
    }
    cout << endl;
    cout << "> ";
  }
  
  return 0;


}
