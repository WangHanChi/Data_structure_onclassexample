#include <iostream>
#include <string>
using namespace std;

int main(){
  string foo = "abc";
  string::iterator iter;

  for(iter = foo.begin() ; iter != foo.end(); ++iter){
    cout << *iter << "-";
  }
  cout << endl;
  return 0;
}
