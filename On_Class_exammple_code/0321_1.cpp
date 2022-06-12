#include <iostream>
using namespace std;

int main(){
  const int N = 3, R = 5, C = 4;
  int bmap[N][R] = {{15,1,15,1,15},{9,9,15,1,1}};
  int i, j ,k,s,t;

  int n = 2;

  for(i = 0; i < R; ++i){
    for(s = 0;s < n; ++s){

    
      for(k = 0;k < N; ++k){
	for(j = C - 1; j>=0; --j){
	  
	    if((bmap[k][i] >> j)%2 ){
	      for(t = 0;t < n; ++t){
		cout << static_cast<char>('3'+k);
	      }
	  }else {
	      for(t = 0; t < n ; ++t){
		cout << " ";
	      }
	  }
	}
	cout << " ";
      }
      cout << endl;
    }
    }
    return 0;
}
