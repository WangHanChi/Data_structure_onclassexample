#include <iostream>
#include <map>

using namespace std;

int main(){

  map<char, int> no;
  map<char, int>::iterator iter;

  string DNA = "ACTG";
  for(int i = 1 ; i < DNA.size(); ++i){
    no[DNA[i]] += i;
  }


  for(iter = no.begin(); iter != no.end(); ++iter){
    cout << iter->first << " : " << iter->second << endl; 
  }



}
