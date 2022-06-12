#include <iostream>

using namespace std;

int main(){
  int n;
  char s;
  if('0' <= cin.peek()&&
     cin.peek() <=  '9'){
    cin >> n;
    cout << "integer";
  }else {
    cin >> s;
    cout << "char";
  }
  cout << endl;



}
