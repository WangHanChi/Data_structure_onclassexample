#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


int main(){


  srand( static_cast<unsigned>(time(NULL)));
  vector<int> a(10);
  for(int i = 0; i < 10 ; ++i){
    a[i] = rand()%100;
  }
  for(int i = 0; i < 10 ; ++i){
    cout << a[i] << " ";
  }
  cout << endl;
  sort(a.begin()+3 , a.begin()+8);

  
  for(int i = 0; i < 10 ; ++i){
    cout << a[i] << " ";
    
  }
  cout << endl;
  
  return 0;
}
