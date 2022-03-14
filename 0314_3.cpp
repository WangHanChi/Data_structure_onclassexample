#include <iostream>
#include <fstream>

using namespace std;

int main(){

  int n, sum, c = 0;
  char s;
  sum = 0;
  ifstream infile("data.txt");

  
  while(1){
    
    if(infile >> n){
      if(c != 0){
	cout << "+";
	c++;
      }
      cout << n;
      sum +=n;
      
    }else{
      if(infile.eof()) break;
      infile.clear();
      infile >> s;
      
    }
  }
  
 
  
  cout << "=" << sum << endl;

  return 0;
}
