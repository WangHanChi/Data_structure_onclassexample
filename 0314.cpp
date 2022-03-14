#include <iostream>
#include <fstream>

using namespace std;

int main(){

  ifstream infile("data.txt");
  int sum = 0;
  int n;

  
  while(1){
    infile >> n;
    sum +=n;
    if(infile.eof()  ) break;
   
    }
  
 
  
  cout << sum << endl;

  return 0;
}
