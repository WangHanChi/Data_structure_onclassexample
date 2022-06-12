#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ofstream outfile("no_data", ios_base::out | ios_base::binary);

  int i ;
  for(i = 0; i < 10; ++i){
    outfile.write(reinterpret_cast<char*>(&i), sizeof(i) );
  }
  outfile.close();
  


  ifstream infile("no_data", ios_base::in | ios_base::binary);

  int k;
  for(i = 0; i < 10; ++i){
    infile.read( reinterpret_cast<char*>(&k), sizeof(k));
    cout << k << endl;
  }

  return 0;
}
