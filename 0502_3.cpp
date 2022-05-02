#include <iostream>
using namespace std;
#include <vector>
int main(){


  vector<int> foo = {3,2,6,4};


  for(int i = 0; i < foo.size(); ++i){
    foo[i] += 1;
  }

  
  for(auto & x : foo){
    x += 1;
    
  }

    for(auto x : foo){
    cout << x << " ";
    
  }
  cout <<endl;



  vector<int> bar(foo.rbegin(), foo.rend());

  for(auto x : bar){
    cout << x << " ";
  }

  cout << endl;





  for(vector<int>::iterator iter = foo.begin(); iter != foo.end(); ++iter){
    cout << *iter << " ";
    
  }

  cout << endl;


  for(auto iter = foo.begin(); iter != foo.end(); ++iter){
    cout << *iter << " ";
    
  }

  cout << endl;


  for(auto iter = foo.rbegin(); iter != foo.rend(); ++iter){
    cout << *iter << " ";
    
  }

  cout << endl;

  
  return 0;
}
