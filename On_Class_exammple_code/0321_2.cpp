#include <iostream>
using namespace std;
#include <fstream>



int main(){
  const int S= 5;

  ofstream outfile("0321data", ios_base::out | ios_base::binary);
  double foo[5] = {1.1 , 2.2, 3.3, 4.4, 5.5};
  outfile.write(reinterpret_cast<char*>(foo), S*sizeof(double));
 
  const int N = 6;
  int ifoo[N] = {3,2,1,2,6,7};
  outfile.write(reinterpret_cast<char*>(ifoo), S*sizeof(int));

  outfile.close();

  double bar[5];
  ifstream infile ("0321data",ios_base::in | ios_base::binary);
  infile.read(reinterpret_cast<char*>(bar), S*sizeof(double));

  int ibar[N];
  infile.read(reinterpret_cast<char*>(ibar), S*sizeof(int));


  infile.close();



  for(int i = 0; i < S; i++){

    cout << bar[i] << endl;
  }
  for(int i = 0; i < S; i++){

    cout << ibar[i] << endl;
  }
  
  return 0;
 
}
