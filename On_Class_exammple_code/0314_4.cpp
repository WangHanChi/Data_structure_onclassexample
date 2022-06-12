#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
  string line;
  /*
  while(getline(cin , line)){
    cout << line.size()<<":"<<line <<endl;
  }
  */

  ifstream infile("data.txt");
  int n = 1;
  while(getline(infile, line)){
    cout << n << ":" << line << endl;
    n++;
  }
  return 0;


}
