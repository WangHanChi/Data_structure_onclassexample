#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main(){
  
  vector<int> a = {2,3,6,1,7,9};
  for(auto i = a.begin(); i != a.end(); ++i){
    cout << *i << " ";
  }//auto 是讓編譯器自己判斷i的型別
  //這個功能需要使用C++11才會有
  //所以在編譯的時候需要打 $g++ -std=c++11 0425_3.cpp 才可以編譯成功

  cout << endl;

  cout << "---------------"<< endl;
  list<int> b = {2,3,6,1,7,9};
  for(auto i = b.begin(); i != b.end(); ++i){
    cout << *i << " ";
  }//auto 是讓編譯器自己判斷i的型別
  //這個功能需要使用C++11才會有
  //所以在編譯的時候需要打 $g++ -std=c++11 0425_3.cpp 才可以編譯成功

  cout << endl;
  return 0;
  
}
