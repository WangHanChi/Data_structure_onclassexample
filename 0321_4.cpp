#include <iostream>
#include <sstream>
using namespace std;

int main(){
  istringstream istr;
  string line;
  int n, sum;

  while(getline(cin, line)){
    istr.str(line);
    sum = 0;
    while(istr >> n) sum +=n;
    istr.clear();
    cout <<sum << endl;
  }
  return 0;
}
