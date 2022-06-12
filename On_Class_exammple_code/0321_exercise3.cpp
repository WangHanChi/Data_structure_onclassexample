#include <iostream>
using namespace std;

int main(){
  const int N = 3, R = 5, C = 4;
  int bmap[N][R] = {{15,1,15,1,15},{9,9,15,1,1}};
  int i, j ,k,w,s;
  string foo;
  int n = 2;
  while(1){
    cout <<"> ";
    cin >> foo;
  for(i = 0; i < R; ++i){
    for(s = 0;s < n; ++s){

    
      for(k = 0;k < foo.size() ; ++k){
	for(j = C - 1; j>=0; --j){
	  w = foo[k] - '3';
	    if((bmap[w][i] >> j)%2 ){
	     
	      cout << string(n,static_cast<char>('3' + w));
	      
	  }else {
	     
	      cout << string(n,' ');
	      
	  }
	}
	cout << " ";
      }
      cout << endl;
    }
    }
  }
    return 0;
}
