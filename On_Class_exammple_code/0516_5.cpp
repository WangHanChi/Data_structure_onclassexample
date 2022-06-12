#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
using namespace std;

int main(){


  list<int> a = {1,2,3,4};
  vector<int> b = {5,6,7,8,9};

  auto itr = a.begin();
  //method1
  while(1){
    itr = find_if(itr, a.end(), bind2nd(greater<int>(), 2) );
    if(itr == a.end()) break;
    
    cout << *itr << " ";
    itr++;
  }


  cout << endl;

  //method2
  for(auto x : a ){
    if( x > 2 )cout << x << " ";
  }

  cout << endl;
  /*
  cout << " ori : " <<endl;
  for(auto x : a) cout << x << "  ";
  cout << endl;

  for(auto x : b) cout << x << "  ";
  cout << endl;

  

  swap_ranges(a.begin(), a.end(), b.begin());

  cout << "after swap : " << endl;
  for(auto x : a) cout << x << "  ";
  cout << endl;

  for(auto x : b) cout << x << "  ";
  cout << endl;


  */

  
  return 0;
}
