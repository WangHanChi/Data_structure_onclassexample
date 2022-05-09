#include <iostream>
#include <set>
using namespace std;


struct by_last_digital{
  bool operator() (int a, int b)const {
    return a%10 < b%10;
  }

};


int main(){
  int a[] = {33,51,62,26,14,2,91,37};

  //set<int, greater<int> > foo( a, a+8);
  multiset<int, by_last_digital> foo(a,a+8);

  
  //multiset<int, mycmp> foo(a,a+8);
  //用set, mulitset所得到的結果會不一樣
  //因為set會把一樣的結果刪除
  //所以只有％10的餘數一樣就會不見

  
  //for(set<int>::iterator itr = foo.begin(); itr!=foo.end(); ++itr){
  for(auto itr = foo.begin(); itr!=foo.end(); ++itr){
  cout << *itr << " ";
  }
  cout <<endl;

  return 0;


}
