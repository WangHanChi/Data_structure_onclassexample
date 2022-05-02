#include <iostream>
#include <vector>
using namespace std;

int main(){

  int r   = 4 ,c = 5;



  int k = 1;
  vector< vector<int>> foo(r,vector<int>(c,2));
  for(auto&  bar : foo){
    for(auto&  x : bar){
      x += k;
      k++;
    }
    

  }

  
  // vector< vector<int>> foo(r,vector<int>(c,2));
  for(auto bar : foo){
    for(auto x : bar){
      cout << x << " ";
    }
    cout << endl;
  }
  return 0; 
}
