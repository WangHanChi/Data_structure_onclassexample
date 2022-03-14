#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    string foo;
    ifstream infile("animals1.txt");
    ifstream infile2("animals2.txt");

    int n = 1;
    while(getline(infile, foo)){
    cout << n << ":" << foo << endl;
    n++;
    }
    while(getline(infile2, foo)){
    cout << n << ":" << foo << endl;
    n++;
    }



  return 0;
}
