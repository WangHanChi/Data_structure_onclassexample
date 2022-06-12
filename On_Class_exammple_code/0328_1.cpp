#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){

  string foo = { "0x32" , "0x27" , "0b101" , "34" };
  const int N = 4;
  int i , j , n, p;
  istringstream istr;
  for(i = 0; i < N; ++i){
    istr.str(foo[i]);
    if(foo[i][0] == '0'){
      if(foo[i][1] == 'x'){
	istr >> hex >> n;
      }else if(foo[i][1] == 'o'){
	n = 0;
	p = 1;
	for(j = foo[i].size - 1; foo[i][j] != 'o' ; --j ){
	  n = n + (foo[i][j] - '0' ) * p;
	  p = 8*p;
	} 
      }else if(foo[i][1] == 'b'){
	n = 0;
	p = 1;
	for(j = foo[i].size - 1; foo[i][j] != 'b' ; --j ){
	  n = n + (foo[i][j] - '0' ) * p;
	  p = 2*p;
	} 
      }


    }else{
      istr >> dec >> n;

    }
    istr.clear();


    cout << foo[i] << " --> " << n << endl;
  }
  
  return 0;
}
