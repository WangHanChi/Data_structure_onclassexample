#include <iostream>
#include <string>
#include <sstream>
using namespace std;


  string itos(int a){

    ostringstream ostr;
    ostr << a;
    return ostr.str();
  }



int main(){
  int num;
  while(1){
    cout << " >  ";
    cin >> num;

    cout << num << ":" << itos(static_cast<int>(num.size())) <<endl;
  }

  return 0;
}
