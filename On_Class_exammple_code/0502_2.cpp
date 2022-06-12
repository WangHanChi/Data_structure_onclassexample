#include <iostream>
#include <vector>
using namespace std;

int main(){
  
  vector<int> foo(10);
 
  for(int i = 0; i < 20; ++i){
    //foo.at(i) = i + 1;
    foo[i] =  i+1;
  } 

  return 0;
}
