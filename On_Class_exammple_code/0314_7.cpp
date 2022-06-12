#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    string foo;
    const int w = 2;
    string fnames[w] = {"animal1", "animals2"};
    ifstream infile;
    ifstream infile2;

    int n = 1;
    for(int i = 0; i < w; ++i){
      infile.open(fnames[i].c_str());
      while(getline( infile, foo)){
	cout << n << ":" << foo << endl;
	n++;
      }
      infile.close();
    }



  return 0;
}
