#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <functional>


using namespace std;


  bool WordSize(vector<string>& foo,int n,int i){
    int count = 0;
    string num;
    for(int j = 0; j < foo[i].size(); ++j){
      if(foo[i][j] == 'a'){
	count++;
      }else if(foo[i][j] == 'e'){
	count++;
      }else if(foo[i][j] == 'i'){
	count++;
      }else if(foo[i][j] == 'o'){
	count++;
      }else if(foo[i][j] == 'u'){
	count++;
      }
    }


  if(count == n){
    return true;
  }else {
    return false;
  }
  
}

template <typename T, typename Q, typename R>
void print_words(T a,Q b, R i){
  if(b == true){
    cout << a[i] << endl;
  }
}






/*
void print_words(vector<string>& foo, bool a, int i){
  if(a == true){
    cout << foo[i] << endl;
  }
}
*/


int main(){


  int n = 1 ; //change here !!!
  string line , word ;
  istringstream istr ;
  vector<string> strs ;
  vector<string> aeiou;
  
  do {
    cout << "> " ;
    getline(cin,line) ;
    istr.str(line) ;
    while ( istr >> word ) strs.push_back(word) ;
    istr.clear() ;
    
    for(int i = 0; i < strs.size(); ++i){
      bool a;
      a = WordSize( strs , n , i);
      print_words(strs, a, i);
	
    }
    
    strs.clear() ;
  } while ( 1 ) ;

  
  return 0;
}


//   He is the leader if the team
