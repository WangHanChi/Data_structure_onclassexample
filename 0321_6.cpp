#include <iostream>
#include <sstream>

using namespace std;

int main(){
  string line;
  string foo;
  int n,sum;
  istringstream istr, istr2;

  
  cout << " > ";
  while( getline(cin, line)){
    istr.str(line);
    sum = 0;
    while(1){
      if(istr >> n){
	sum += n;

      }else{
	if(istr.eof()) break;
	istr.clear(); //清除錯誤非常重要，期中考會考
	istr.ignore();
      }
    }
    istr.clear();
    cout << sum << endl;
    cout << " > ";

    

   
    
  }

  return 0;
}
