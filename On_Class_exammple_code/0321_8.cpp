#include <iostream>
#include <sstream>
using namespace std;

int main(){
  string foo, sno;
  istringstream istr;
  double no;
  bool ok;
  int c;
  
  while(1){
    cout << "> ";
    cin >> foo;
    istr.str(foo);

    ok = true;
    c = 0;
    while(1){
      if(istr >> no){
	++c;
      }else{
	if( istr.eof()) break;
	istr.clear();
	cout << "[" << static_cast<char>(istr.peek()) << "]";
	ok = false;
	break;
	
      }
    }
    istr.clear();
    cout << foo << " : " << no << " : " <<( c==1 && ok ? "number" : "string") << endl;
  }
  return 0;
}
