#include <iostream>
#include <sstream>

using namespace std;

int main(){
  string line;
  string foo;
  int n,sum;

  cout << " > ";
  while( getline(cin, line)){
    istringstream istr(line);

    while(istr >> foo){
      istringstream istr2(foo);
      if( istr2 >> n){
	sum += n;
      }else{
	istr2.clear();
      }
    }

    istr.clear();
    cout << sum << "\n>";
  }

  return 0;
}
